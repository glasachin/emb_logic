#include <iostream>
#include <queue>
#include <mutex>
#include <atomic>
#include <thread>
#include <chrono>

template <typename T>
class GenericQueue
{
private:
    std::queue<T> queue;
    mutable std::mutex queueMutex;
    std::atomic<size_t> itemCount;

public:
    GenericQueue();

    bool enqueue(const T &item);
    bool dequeue(T &item);
    bool isEmpty(void);
    size_t size(void);
};

template <typename T>
GenericQueue<T>::GenericQueue()
{
    itemCount = 0;
}

template <typename T>
bool GenericQueue<T>::enqueue(const T &item)
{
    queueMutex.lock(); // manual lock
    queue.push(item);
    itemCount.fetch_add(1, std::memory_order_release);
    queueMutex.unlock(); // manual unlock
    return true;
}

template <typename T>
bool GenericQueue<T>::dequeue(T &item)
{
    queueMutex.lock(); // manual lock
    if (queue.empty())
    {
        queueMutex.unlock();
        return false;
    }
    item = queue.front();
    queue.pop();
    itemCount.fetch_sub(1, std::memory_order_release);
    queueMutex.unlock(); // manual unlock
    return true;
}

template <typename T>
bool GenericQueue<T>::isEmpty(void)
{
    return (itemCount.load(std::memory_order_acquire) == 0);
}

template <typename T>
size_t GenericQueue<T>::size(void)
{
    return itemCount.load(std::memory_order_acquire);
}

int main()
{
    std::cout << "hello" << std::endl;

    GenericQueue<std::string> strqueue;
    GenericQueue<std::string> *dbMsgQueue = new GenericQueue<std::string>();

    strqueue.enqueue("hello, this is sachin");
    strqueue.enqueue("hello, this is Avinash");
    strqueue.enqueue("hello, India");
    strqueue.enqueue("hello, Uttarpradesh");
    std::cout << "Size: " << strqueue.size() << std::endl;
    std::string value;
    while (!strqueue.isEmpty())
    {
        strqueue.dequeue(value);
        std::cout << value << std::endl;
        std::cout << "Size: " << strqueue.size() << std::endl;
    }

    std::string insetValue;
    insetValue = "hello, this is sachin";
    dbMsgQueue->enqueue(insetValue);
    insetValue = "hello, this is Avinash";
    dbMsgQueue->enqueue(insetValue);
    insetValue = "hello, India";
    dbMsgQueue->enqueue(insetValue);
    dbMsgQueue->enqueue("hello, Uttarpradesh");
    std::cout << "Size: " << dbMsgQueue->size() << std::endl;

    while (!dbMsgQueue->isEmpty())
    {
        dbMsgQueue->dequeue(value);
        std::cout << value << std::endl;
        std::cout << "Size: " << dbMsgQueue->size() << std::endl;
    }

    return 0;
}