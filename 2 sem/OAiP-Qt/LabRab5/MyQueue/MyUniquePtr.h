#ifndef MYUNIQUEPTR_H
#define MYUNIQUEPTR_H
#include <memory>

template <class T>
class MyUniquePtr
{

private:
    T* _ptr; // Указатель на объект типа T

public:

    // Конструкторы
    MyUniquePtr() : _ptr(nullptr) {}
    explicit MyUniquePtr(T* unObj) : _ptr(unObj) {}
    MyUniquePtr(const MyUniquePtr&) = delete; // Запрещаем копирование
    MyUniquePtr(MyUniquePtr&& other) : _ptr(other.release()) {}

    // Деструктор
    ~MyUniquePtr() {
        reset();
    }

    // Операторы присваивания
    MyUniquePtr& operator=(const MyUniquePtr&) = delete; // Запрещаем копирование
    MyUniquePtr& operator=(MyUniquePtr&& other) {
        if (this != &other) {
            reset();
            _ptr = other.release();
        }
        return *this;
    }

    // Операторы разыменования
    T& operator*() const noexcept {
        return *_ptr;
    }
    T* operator->() const noexcept {
        return _ptr;
    }

    // Методы
    T* get() const {
        return _ptr;
    }
    void reset() {
        delete _ptr;
        _ptr = nullptr;
    }
    void reset(T* ptr) {
        if (_ptr != ptr) {
            reset();
            _ptr = ptr;
        }
    }
    T* release() {
        T* ptr = _ptr;
        _ptr = nullptr;
        return ptr;
    }

    // Оператор приведения к bool
    operator bool() const noexcept { return static_cast<bool>(_ptr); }

    // Метод make_unique
    template<typename... Args>
    static MyUniquePtr<T> make_unique(Args&&... args) {
        return MyUniquePtr<T>(new T(std::forward<Args>(args)...));
    }

};


#endif // MYUNIQUEPTR_H
