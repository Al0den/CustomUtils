#pragma once

#include <vector>
#include <mutex>
#include <stdexcept>

template <typename T>
class ThreadSafeVector {
private:
    mutable std::mutex mtx;
    std::vector<T> vec;

public:
    ThreadSafeVector() = default;
    ThreadSafeVector(const ThreadSafeVector<T>& other) {
        std::lock_guard<std::mutex> lock(other.mtx);
        vec = other.vec;
    }

    ThreadSafeVector<T>& operator=(const ThreadSafeVector<T>& other) {
        if(this == &other) { return *this; }
        std::scoped_lock lock(mtx, other.mtx);
        vec = other.vec;
        return *this;
    }

    void push_back(const T& value) {
        std::lock_guard<std::mutex> lock(mtx);
        vec.push_back(value);
    }

    T pop_back() {
        std::lock_guard<std::mutex> lock(mtx);
        if (vec.empty()) {
            throw std::out_of_range("Vector is empty");
        }
        T value = vec.back();
        vec.pop_back();
        return value;
    }

    T& operator[](size_t index) {
        std::lock_guard<std::mutex> lock(mtx);
        return vec[index];
    }

    size_t size() const {
        std::lock_guard<std::mutex> lock(mtx);
        return vec.size();
    }

    bool empty() const {
        std::lock_guard<std::mutex> lock(mtx);
        return vec.empty();
    }
};
