#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class MyVector {
private:
    T* data;
    size_t sz;
    size_t cap;

    void reallocate(size_t new_cap) {
        T* new_data = new T[new_cap];

        for (size_t i = 0; i < sz; i++) {
            new_data[i] = std::move(data[i]);
        }

        delete[] data;
        data = new_data;
        cap = new_cap;
    }

public:
    // Constructor
    MyVector() : data(nullptr), sz(0), cap(0) {}

    // Destructor
    ~MyVector() {
        delete[] data;
    }

    // Copy Constructor
    MyVector(const MyVector& other) {
        sz = other.sz;
        cap = other.cap;
        data = new T[cap];

        for (size_t i = 0; i < sz; i++) {
            data[i] = other.data[i];
        }
    }

    // Move Constructor
    MyVector(MyVector&& other) noexcept {
        data = other.data;
        sz = other.sz;
        cap = other.cap;

        other.data = nullptr;
        other.sz = 0;
        other.cap = 0;
    }

    // Copy Assignment
    MyVector& operator=(const MyVector& other) {
        if (this == &other) return *this;

        delete[] data;

        sz = other.sz;
        cap = other.cap;
        data = new T[cap];

        for (size_t i = 0; i < sz; i++) {
            data[i] = other.data[i];
        }

        return *this;
    }

    // Move Assignment
    MyVector& operator=(MyVector&& other) noexcept {
        if (this == &other) return *this;

        delete[] data;

        data = other.data;
        sz = other.sz;
        cap = other.cap;

        other.data = nullptr;
        other.sz = 0;
        other.cap = 0;

        return *this;
    }

    // Push back
    void push_back(const T& value) {
        if (sz == cap) {
            size_t new_cap = (cap == 0) ? 1 : cap * 2;
            reallocate(new_cap);
        }
        data[sz++] = value;
    }

    // Move version
    void push_back(T&& value) {
        if (sz == cap) {
            size_t new_cap = (cap == 0) ? 1 : cap * 2;
            reallocate(new_cap);
        }
        data[sz++] = std::move(value);
    }

    // Access
    T& operator[](size_t index) {
        return data[index];
    }

    const T& operator[](size_t index) const {
        return data[index];
    }

    // Safe access
    T& at(size_t index) {
        if (index >= sz) throw out_of_range("Index out of range");
        return data[index];
    }

    // Size
    size_t size() const {
        return sz;
    }

    // Capacity
    size_t capacity() const {
        return cap;
    }

    // Empty
    bool empty() const {
        return sz == 0;
    }

    // Clear
    void clear() {
        sz = 0;
    }
};
