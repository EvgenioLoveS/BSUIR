#ifndef POINTERS_H
#define POINTERS_H

template <class T>
class unique_ptr
{
private:
    T* _ptr; // Указатель на объект типа T
public:
    // Конструкторы
    unique_ptr() : _ptr(nullptr) {}
    explicit unique_ptr(T* unObj) : _ptr(unObj) {}
    unique_ptr(const unique_ptr&) = delete; // Запрещаем копирование
    unique_ptr(unique_ptr&& other) : _ptr(other.release()) {}

    // Деструктор
    ~unique_ptr() {
        reset();
    }

    // Операторы присваивания
    unique_ptr& operator=(const unique_ptr&) = delete; // Запрещаем копирование
    unique_ptr& operator=(unique_ptr&& other) {
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
};

template <class T>
class shared_ptr
{
private:
    T* _ptr;
    int* counter;
public:
    // Конструктор по умолчанию
    shared_ptr() :
        _ptr(nullptr), counter(nullptr) {}

    // Конструктор с параметром ptr
    explicit shared_ptr(T* ptr)
        : _ptr(ptr), counter(new int(1)) {};

    // Конструктор копирования
    shared_ptr(const shared_ptr& other) noexcept
        : _ptr(other._ptr), counter(other.counter){
        if(counter != nullptr){
            ++*counter;
        }
    }

    // Конструктор перемещения
    shared_ptr(shared_ptr&& other) noexcept
        : _ptr(other._ptr), counter(other.counter){
        other._ptr = nullptr;
        other.counter = nullptr;
    }

    // Деструктор
    ~shared_ptr(){
        if(!counter) return;
        --*counter;
        if(*counter == 0){
            delete _ptr;
            delete counter;
        }
    }

    // Оператор стрелочка ->
    T* operator->() const noexcept { return _ptr; }

    // Оператор разыменования *
    T& operator*() const noexcept { return *_ptr; }

    // Метод, который возвращает количество ссылок на объект
    unsigned use_counter() const noexcept { return (counter) ? *counter : 0; }

    // Оператор присваивания
    shared_ptr& operator=(const shared_ptr& other) noexcept {
        if(this == &other) return *this;
        if(counter != nullptr){
            --*counter;
            if(*counter == 0){
                delete _ptr;
                delete counter;
            }
        }
        _ptr = other._ptr;
        counter = other.counter;
        if(counter != nullptr){
            ++*counter;
        }
        return *this;
    }
};

#endif // POINTERS_H
