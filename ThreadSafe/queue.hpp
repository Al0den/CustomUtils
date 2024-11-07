#pragma once

#include <queue>
#include <mutex>

template <typename T>
class ThreadSafeQueue {

private:
    std::mutex mtx;
    std::queue<T> queue;

public:
    ThreadSafeQueue() = default;
    ~ThreadSafeQueue() = default;

    // Delete copy constructor and copy assignment operator
    ThreadSafeQueue(const ThreadSafeQueue&) = delete;
    ThreadSafeQueue& operator=(const ThreadSafeQueue&) = delete;

    // Move constructor and move assignment operator
    ThreadSafeQueue(ThreadSafeQueue&& other) = delete;
    ThreadSafeQueue& operator=(ThreadSafeQueue&& other) = delete;

    void push(T value) {
        std::lock_guard<std::mutex> lock(mtx);
        queue.push(value);
    }

    bool empty() {
        std::lock_guard<std::mutex> lock(mtx);
        return queue.empty();
    }

    T front() {
        std::lock_guard<std::mutex> lock(mtx);
        return queue.front();
    }

    void pop() {
        std::lock_guard<std::mutex> lock(mtx);
        queue.pop();
    }

    size_t size() {
        std::lock_guard<std::mutex> lock(mtx);
        return queue.size();
    }

    void emplace(T value) {
        std::lock_guard<std::mutex> lock(mtx);
        queue.emplace(value);
    }

    void clear() {
        std::lock_guard<std::mutex> lock(mtx);
        while (!queue.empty()) {
            queue.pop();
        }
    }

    void swap(std::queue<T>& other) {
        if(this == &other) { return; }
        std::scoped_lock(mtx, other.mtx);
        queue.swap(other);
    }
};
