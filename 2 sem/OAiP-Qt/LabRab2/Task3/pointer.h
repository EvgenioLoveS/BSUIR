#ifndef POINTER_H
#define POINTER_H
#include <QDebug>

template<class T>
class unique_ptr
{
private:
    T* ptr;
public:
    unique_ptr()
        : ptr(nullptr) {}

    unique_ptr(const unique_ptr& other) {
        reset(other.release());
    }

    unique_ptr(T* unObj)
        : ptr(unObj) {}


    unique_ptr(unique_ptr&& other) noexcept
        : ptr(other.release()) {}

    void reset(T* ptr)
    {
        delete this->ptr;
        this->ptr = ptr;
    }

    T* release()
    {
        T* tmp = ptr;
        ptr = nullptr;
        return tmp;
    }

    T* get() const
    {
        return ptr;
    }

    ~unique_ptr()
    {
        delete ptr;
    }

    T* operator->() const noexcept
    {
        return ptr;
    }

    T& operator*() const noexcept
    {
        return *ptr;
    }

    unique_ptr& operator=(unique_ptr&& other) noexcept
    {
        reset(other.release());
        return *this;
    }

    operator bool() const noexcept
    {
        return static_cast<bool>(ptr);
    }
};
#endif // POINTER_H
