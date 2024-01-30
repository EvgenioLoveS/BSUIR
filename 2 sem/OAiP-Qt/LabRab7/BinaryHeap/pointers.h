#ifndef POINTERS_H
#define POINTERS_H
#include <memory>

template<typename T>
class Shared_ptr {
private:
    struct SharedPtrData {
        T* _ptr;
        size_t* _refCount;
        size_t* _weakCount;
    };

    SharedPtrData* sharedptrdata;

public:
    Shared_ptr() : sharedptrdata(nullptr) {}

    ~Shared_ptr() {
        release();
    }

    explicit Shared_ptr(T* ptr) {
        if (ptr) {
            sharedptrdata = new SharedPtrData;
            sharedptrdata->_ptr = ptr;
            sharedptrdata->_refCount = new size_t(1);
            sharedptrdata->_weakCount = new size_t(0);
        }
        else {
            sharedptrdata = nullptr;
        }
    }

    Shared_ptr(const Shared_ptr& other) : sharedptrdata(other.sharedptrdata) {
        if (sharedptrdata) {
            ++(*sharedptrdata->_refCount);
        }
    }

    Shared_ptr& operator=(const Shared_ptr& other) {
        if (this != &other) {
            release();

            sharedptrdata = other.sharedptrdata;
            if (sharedptrdata) {
                ++(*sharedptrdata->_refCount);
            }
        }
        return *this;
    }

    T& operator*() const {
        return *(sharedptrdata->_ptr);
    }

    T* operator->() const {
        return sharedptrdata->_ptr;
    }

    operator bool() const {
        return sharedptrdata && sharedptrdata->_ptr;
    }

private:
    void release() {
        if (sharedptrdata) {
            if (--(*sharedptrdata->_refCount) == 0) {
                delete sharedptrdata->_ptr;
                delete sharedptrdata->_refCount;
                if (*sharedptrdata->_weakCount == 0) {
                    delete sharedptrdata->_weakCount;
                    delete sharedptrdata;
                }
                else {
                    --(*sharedptrdata->_weakCount);
                }
            }
        }
    }
};

#endif // POINTERS_H
