#pragma once

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
