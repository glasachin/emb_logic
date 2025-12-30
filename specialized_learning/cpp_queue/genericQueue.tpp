#include "genericQueue.hpp"

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
