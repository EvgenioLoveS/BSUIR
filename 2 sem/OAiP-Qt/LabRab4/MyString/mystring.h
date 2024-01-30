#ifndef MYSTRING_H
#define MYSTRING_H

#include "MyString_global.h"
#include <cmath>
#include <utility>
#include <stdexcept>
#include <memory>

class MyUniquePtr
{
private:
    char* _ptr; // Указатель на объект типа T
public:
    // Конструкторы
    MyUniquePtr() : _ptr(nullptr) {}
    explicit MyUniquePtr(char* unObj) : _ptr(unObj) {}
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
    char& operator*() const noexcept {
        return *_ptr;
    }
    char* operator->() const noexcept {
        return _ptr;
    }

    // Методы
    char* get() const {
        return _ptr;
    }
    void reset() {
        delete _ptr;
        _ptr = nullptr;
    }
    void reset(char* ptr) {
        if (_ptr != ptr) {
            reset();
            _ptr = ptr;
        }
    }
    char* release() {
        char* ptr = _ptr;
        _ptr = nullptr;
        return ptr;
    }

    // Оператор приведения к bool
    operator bool() const noexcept { return static_cast<bool>(_ptr); }

    // Реализация make_unique для типа char
    MyUniquePtr make_unique(char value) {
        return MyUniquePtr(new char(value));
    }
};

class MyIteratorString {
private:
    char* _ptr;
public:

    MyIteratorString(){};
    MyIteratorString(char* ptr) : _ptr(ptr) {}
    ~MyIteratorString(){}

    MyIteratorString& operator++() {
        ++_ptr;
        return *this;
    }

    MyIteratorString operator++(int) {
        MyIteratorString tmp = *this;
        ++_ptr;
        return tmp;
    }

    MyIteratorString& operator--() {
        --_ptr;
        return *this;
    }

    MyIteratorString operator--(int) {
        MyIteratorString tmp = *this;
        --_ptr;
        return tmp;
    }

    char& operator*() const {
        return *_ptr;
    }

    char* operator->() const {
        return _ptr;
    }

    bool operator==(const MyIteratorString& other) const {
        return _ptr == other._ptr;
    }

    bool operator!=(const MyIteratorString& other) const {
        return _ptr != other._ptr;
    }

    MyIteratorString& operator=(const MyIteratorString& tmp) {
            if (this != &tmp) {
                _ptr = tmp._ptr;
            }
            return *this;
        }

    operator char*() const {
        return _ptr;
    }

    MyIteratorString& begin();
    MyIteratorString& end();
};

class MYSTRING_EXPORT MyString : public MyIteratorString
{

private:
    MyUniquePtr _data;
    size_t _size;

public:

    //конструктор по умолчанию
    MyString() : _size(0) {
        _data = MyUniquePtr(new char[1]);
        _data.get()[0] = '\0';
    }

    //конструктор класса MyString с параметром const char*
    MyString(const char* str) : _size(mystrlen(str)) {
        _data = MyUniquePtr(new char[_size + 1]);
        mystrcpy(_data.get(), str);
    }

    // Конструктор с использованием умных указателей и итераторов
    MyString(const char* str, size_t count) :
            _size(count), // Устанавливаем размер строки
            _data(MyUniquePtr(new char[_size + 1])) // Создаем умный указатель на массив символов
    {
        mystrncpy(_data.get(), str, _size); // Копируем count символов из переданного указателя
        _data.get()[_size] = '\0'; // Устанавливаем завершающий нулевой символ
    }

    //конструктор копирования
    MyString(const MyString& other) : MyIteratorString(other), _size(other._size) {
        _data = MyUniquePtr(new char[_size + 1]);
        mystrcpy(_data.get(), other._data.get());
        _data.get()[_size] = '\0'; // добавляем нулевой символ в конец строки
    }


    // Деструктор
    ~MyString() = default;

    const char* getData() const {
        return _data.get();
    }

    // Доступ к данным
    const char* c_str() const {
        return _data.get();
    }


    // Доступ к символам
    char& operator[](int ind){
        return _data.get()[ind];
    }

    // Доступ к символам (const-версия)
    const char& operator[](int ind) const {
        return _data.get()[ind];
    }

    // Операторы присваивания
    MyString& operator=(const MyString& other) {
        if (this != &other) {
            _size = other._size;
            _data = MyUniquePtr(new char[_size + 1]);
            mystrcpy(_data.get(), other._data.get());
        }
        return *this;
    }

    MyString& operator=(MyString&& other) {
        if (this != &other) {
            _size = other._size;
            _data = std::move(other._data); // Используем std::move для перемещения указателя на данные
            other._size = 0; // Обнуляем размер исходного объекта
        }
        return *this;
    }

    MyString& operator=(const char* str) {
        size_t len = mystrlen(str);
        _size = len;
        _data = MyUniquePtr(new char[_size + 1]);
        mystrcpy(_data.get(), str);
        return *this;
    }

    // Операторы сравнения
    bool operator==(const MyString& other) const { // Оператор равенства
        return mystrcmp(_data.get(), other._data.get()) == 0;
    }
    bool operator!=(const MyString& other) const { // Оператор неравенства
        return !(*this == other);
    }
    bool operator<(const MyString& other) const { // Оператор меньше
        return mystrcmp(_data.get(), other._data.get()) < 0;
    }
    bool operator>(const MyString& other) const { // Оператор больше
        return mystrcmp(_data.get(), other._data.get()) > 0;
    }
    bool operator<=(const MyString& other) const { // Оператор меньше или равно
        return mystrcmp(_data.get(), other._data.get()) <= 0;
    }
    bool operator>=(const MyString& other) const { // Оператор больше или равно
        return mystrcmp(_data.get(), other._data.get()) >= 0;
    }

    // Оператор конкатенации (+=)
    MyString& operator+=(const MyString& other) {
        int new_size = _size + other._size;
        char* new_data = new char[new_size + 1];
        mystrcpy(new_data, _data.get());
        mystrcat(new_data, other._data.get());
        _data = MyUniquePtr(new_data);
        _size = new_size;
        return *this;
    }

    // Оператор присваивания с конкатенацией (+)
    MyString operator+(const MyString& other) const {
        MyString result(*this);
        result += other;
        return result;
    }

    MyIteratorString begin() {
    return MyIteratorString(_data.get());
    }

    MyIteratorString end() {
    return MyIteratorString(_data.get() + _size);
    }

    static const size_t npos = static_cast<size_t>(-1);

    //-------------------------------------------------------------------------------
    //Функции С++
    //-------------------------------------------------------------------------------

    // Размер строки
    int size() const {
        return _size;
    }

    // Метод для проверки, является ли строка пустой
    bool empty() const {
        return _size == 0;
    }

    // Очистка строки
    void clear() {
        _data = MyUniquePtr(new char[1]);
        _data.get()[0] = '\0';
        _size = 0;
    }

    // Изменение размера строки
    void resize(size_t newSize) {
        if (newSize == _size) {
            // Если новый размер равен текущему, ничего не делаем
            return;
        } else if (newSize < _size) {
            // Если новый размер меньше текущего,
            // обрезаем строку до нового размера
            _data.get()[newSize] = '\0';
        } else {
            // Если новый размер больше текущего,
            // выделяем новый буфер и копируем в него содержимое старого буфера
            MyUniquePtr newData(new char[newSize + 1]);
            mymemcpy(newData.get(), _data.get(), _size);
            newData.get()[_size] = '\0';
            _data = std::move(newData);
        }
        _size = newSize;
    }

    // Функция push_back для добавления символа в конец строки
    void push_back(char c) {
        // Создаем новый буфер размером на единицу больше текущего
        MyUniquePtr newData(new char[_size + 2]);

        // Копируем данные из текущего буфера в новый буфер
        mystrcpy(newData.get(), _data.get());

        // Добавляем новый символ в конец нового буфера
        newData.get()[_size] = c;
        newData.get()[_size + 1] = '\0';

        // Заменяем текущий буфер на новый буфер
        _data = std::move(newData);

        // Увеличиваем размер строки на единицу
        _size += 1;
    }

    // Функция для вставки строки s в текущую строку начиная с позиции start
    MyString& insert(size_t start, const MyString& s)
    {
        if (start > _size) // Если указанная позиция вставки превышает размер текущей строки
            throw std::out_of_range("Index out of range");

        int newSize = _size + s._size; // Вычисляем новый размер строки
        MyUniquePtr newData(new char[newSize + 1]); // Создаем новый блок памяти под строку

        // Копируем символы из текущей строки до позиции start в новый блок памяти
        mystrncpy(newData.get(), _data.get(), start);
        // Копируем символы из строки s в новый блок памяти, начиная с позиции start
        mystrncpy(newData.get() + start, s._data.get(), s._size);
        // Копируем символы из текущей строки, начиная с позиции start, в новый блок памяти
        mystrncpy(newData.get() + start + s._size, _data.get() + start, _size - start);

        newData.get()[newSize] = '\0'; // Устанавливаем завершающий нулевой символ

        _data = std::move(newData); // Перемещаем владение новым блоком памяти в _data
        _size = newSize; // Обновляем размер текущей строки

        return *this;
    }

    //функция позволяет вставить часть (параметры insStart, num) строки s в заданную позицию start вызывающей строки:
    MyString& insert(size_t start, const MyString& s, size_t insStart, size_t num) {
        if (start > _size) // Если указанная позиция start превышает размер текущей строки
            throw std::out_of_range("Index out of range");

        if (insStart >= s._size) // Если указанная позиция начала вставки insStart превышает размер подстроки s
            throw std::out_of_range("Index out of range");

        // Вычисляем новый размер строки после вставки
        size_t newSize = _size + num;

        // Выделяем новый блок памяти для строки с учетом нового размера
        MyUniquePtr newData(new char[newSize + 1]);

        // Копируем символы из текущей строки до позиции start в новый блок памяти
        mystrncpy(newData.get(), _data.get(), start);
        // Копируем символы из подстроки s, начиная с позиции insStart и содержащей num символов, в новый блок памяти, начиная с позиции start
        mystrncpy(newData.get() + start, s._data.get() + insStart, num);
        // Копируем символы из текущей строки, начиная с позиции start + num, в новый блок памяти
        mystrncpy(newData.get() + start + num, _data.get() + start, _size - start);

        newData.get()[newSize] = '\0'; // Устанавливаем завершающий нулевой символ

        _data = std::move(newData); // Перемещаем владение новым блоком памяти в _data
        _size = newSize; // Обновляем размер текущей строки

        return *this;
    }

    //s – строка, которая вставляется в вызывающую строку;
    //start – позиция в вызывающей строке, из которой осуществляется вставка строки s;
    //insStart – позиция в строке s, из которой происходит вставка;
    //num – количество символов в строке s, которые вставляются с позиции insStart.

    // Функция для замены подстроки num символов, начиная с позиции start, на подстроку s
    MyString& replace(size_t start, size_t num, const MyString& s) {
        if (start > _size) // Если указанная позиция start превышает размер текущей строки
            throw std::out_of_range("Index out of range");

        // Вычисляем новый размер строки после замены
        size_t newSize = _size - num + s._size;

        // Выделяем новый блок памяти для строки с учетом нового размера
        MyUniquePtr newData(new char[newSize + 1]);

        // Копируем символы из текущей строки до позиции start в новый блок памяти
        mystrncpy(newData.get(), _data.get(), start);
        // Копируем символы из строки s в новый блок памяти, начиная с позиции start
        mystrncpy(newData.get() + start, s._data.get(), s._size);
        // Копируем символы из текущей строки, начиная с позиции start + num, в новый блок памяти
        mystrncpy(newData.get() + start + s._size, _data.get() + start + num, _size - start - num);

        newData.get()[newSize] = '\0'; // Устанавливаем завершающий нулевой символ

        _data = std::move(newData); // Перемещаем владение новым блоком памяти в _data
        _size = newSize; // Обновляем размер текущей строки

        return *this;
    }

    // Функция для замены подстроки num символов, начиная с позиции start, на подстроку s, начиная с позиции replStart и содержащую replNum символов
    MyString& replace(size_t start, size_t num, const MyString& s, size_t replStart, size_t replNum) {
        if (start > _size) // Если указанная позиция start превышает размер текущей строки
            throw std::out_of_range("Index out of range");

        if (replStart >= s._size) // Если указанная позиция начала подстроки replStart превышает размер подстроки s
            throw std::out_of_range("Index out of range");

        // Вычисляем новый размер строки после замены
        size_t newSize = _size - num + replNum;

        // Выделяем новый блок памяти для строки с учетом нового размера
        MyUniquePtr newData(new char[newSize + 1]);

        // Копируем символы из текущей строки до позиции start в новый блок памяти
        mystrncpy(newData.get(), _data.get(), start);
        // Копируем символы из строки s, начиная с позиции replStart и содержащие replNum символов, в новый блок памяти, начиная с позиции start
        mystrncpy(newData.get() + start, s._data.get() + replStart, replNum);
        // Копируем символы из текущей строки, начиная с позиции start + num, в новый блок памяти
        mystrncpy(newData.get() + start + replNum, _data.get() + start + num, _size - start - num);

        newData.get()[newSize] = '\0'; // Устанавливаем завершающий нулевой символ

        _data = std::move(newData); // Перемещаем владение новым блоком памяти в _data
        _size = newSize; // Обновляем размер текущей строки

        return *this;
    }

    // Функция для удаления символов из строки, начиная с позиции index и удаляющая num символов (по умолчанию удаляет все символы после указанной позиции)
    MyString& erase(size_t index, size_t num) {
        if (index >= _size) // Если указанная позиция index превышает размер текущей строки
            throw std::out_of_range("Index out of range");

        // Если num равен npos (максимальному значению size_type), то удаляем все символы после указанной позиции
        if (num == npos) {
            _size = index; // Обновляем размер текущей строки до позиции index
            _data.get()[_size] = '\0'; // Устанавливаем завершающий нулевой символ
        } else if (num > 0) {
            // Вычисляем новый размер строки после удаления
            size_t newSize = _size - num;

            // Копируем символы из текущей строки, начиная с позиции index + num, в новый блок памяти
            mystrncpy(_data.get() + index, _data.get() + index + num, _size - index - num);

            _data.get()[newSize] = '\0'; // Устанавливаем завершающий нулевой символ
            _size = newSize; // Обновляем размер текущей строки
        }

        return *this;
    }

    // Функция для добавления подстроки s в текущую строку, начиная с позиции start
    MyString &append(const MyString &s, size_t start) {
        size_t sLen = s.size(); // Длина подстроки s
        size_t len = size(); // Длина текущей строки
        if (start > len) { // Если начальная позиция больше длины текущей строки, возвращаем текущую строку без изменений
            return *this;
        }
        if (sLen == 0) { // Если подстрока пустая, ничего не добавляем
            return *this;
        }
        // Создаем уникальный указатель на новый буфер памяти, в котором будет объединена текущая строка и подстрока s
        MyUniquePtr newBuffer(new char[len + sLen]);
        char* newData = newBuffer.get(); // Получаем указатель на новый буфер памяти
        const char* data = _data.get(); // Получаем указатель на данные текущей строки
        const char* sData = s._data.get(); // Получаем указатель на данные подстроки s

        // Копируем данные текущей строки в новый буфер памяти
        for (size_t i = 0; i < len; ++i) {
            newData[i] = data[i];
        }

        // Копируем подстроку s в новый буфер памяти, начиная с позиции start
        mymemcpy(newData + len, sData + start, sLen);

        // Обновляем указатель на данные и длину текущей строки
        _data = std::move(newBuffer);
        _size = len + sLen;

        return *this;
    }

    // Функция для добавления C-строки s в текущую строку, добавляя num символов
    MyString &append(const char *s, size_t num) {
        size_t len = size(); // Длина текущей строки
        if (num == 0) { // Если num = 0, ничего не добавляем
            return *this;
        }
        // Создаем уникальный указатель на новый буфер памяти, в котором будет объединена текущая строка и C-строка s
        MyUniquePtr newBuffer(new char[len + num]);
        char* newData = newBuffer.get(); // Получаем указатель на новый буфер памяти
        const char* data = _data.get(); // Получаем указатель на данные текущей строки

        // Копируем данные текущей строки в новый буфер памяти
        for (size_t i = 0; i < len; ++i) {
            newData[i] = data[i];
        }

        // Копируем C-строку s в новый буфер памяти, добавляя num символов
        for (size_t i = 0; i < num; ++i) {
            newData[len + i] = s[i];
        }

        // Обновляем указатель на данные и длину текущей строки
        _data = std::move(newBuffer);
        _size = len + num;

        return *this;
    }

    // Функция для присвоения пустой строки
    MyString &assign(void) {
        // Создаем уникальный указатель на новый буфер памяти с одним нулевым символом
        MyUniquePtr newBuffer(new char[1]{'\0'});
        // Обновляем указатель на данные и длину текущей строки
        _data = std::move(newBuffer);
        _size = 0;
        return *this;
    }

    // Функция для присваивания подстроки s, начиная с позиции st, длиной num символов, текущей строке
    MyString &assign(const MyString &s, size_t st, size_t num) {
        size_t sLen = s.size(); // Длина строки s
        if (st >= sLen) { // Если начальная позиция st больше или равна длине строки s, возвращаем текущую строку без изменений
            return *this;
        }
        // Ограничиваем длину подстроки num, чтобы не выйти за пределы строки s
        num = (num < sLen - st) ? num : (sLen - st);
        // Создаем уникальный указатель на новый буфер памяти, в котором будет содержаться подстрока s
        MyUniquePtr newBuffer(new char[num]);
        char* newData = newBuffer.get(); // Получаем указатель на новый буфер памяти
        const char* sData = s._data.get(); // Получаем указатель на данные строки s

        // Копируем подстроку s в новый буфер памяти, начиная с позиции st
        mymemcpy(newData, sData + st, num);

        // Обновляем указатель на данные и длину текущей строки
        _data = std::move(newBuffer);
        _size = num;

        return *this;
    }

    // Функция для поиска подстроки s в текущей строке, начиная с позиции start (по умолчанию start = 0)
    size_t find(const MyString& s, size_t start) const {
        size_t sLen = s.size();// Длина подстроки s
        size_t len = size(); // Длина текущей строки
        if (start > len) { // Если начальная позиция больше длины текущей строки, возвращаем npos
            return npos;
        }
        if (sLen == 0) { // Если подстрока пустая, возвращаем текущую позицию start
            return start;
        }
        const char* data = _data.get(); // Получаем указатель на данные текущей строки
        const char* sData = s._data.get(); // Получаем указатель на данные подстроки s
        for (size_t i = start; i <= len - sLen; ++i) { // Перебираем символы текущей строки
            bool found = true;
            for (size_t j = 0; j < sLen; ++j) { // Перебираем символы подстроки s
                if (*(data + i + j) != *(sData + j)) { // Если символы не совпадают, выходим из цикла
                    found = false;
                    break;
                }
            }
            if (found) { // Если найдена подстрока s, возвращаем текущую позицию i
                return i;
            }
        }
        return npos; // Если подстрока s не найдена, возвращаем npos
    }

    // Функция для сравнения подстроки s с указанной подстрокой в текущей строке,
    // начиная с позиции start, и ограниченной num символами
    int compare(size_t start, size_t num, const MyString& s) const {
        size_t len = size(); // Длина текущей строки
        size_t sLen = s.size(); // Длина подстроки s
        if (start > len) { // Если начальная позиция больше длины текущей строки, возвращаем ошибку
            throw std::out_of_range("Start position is out of range.");
        }
        // Ограничение длины подстроки s на основе переданного значения num
        size_t cmpLen = std::min(num, sLen);
        const char* data = _data.get(); // Получаем указатель на данные текущей строки
        const char* sData = s._data.get(); // Получаем указатель на данные подстроки s
        for (size_t i = 0; i < cmpLen; ++i) { // Перебираем символы ограниченной подстроки s
            if (*(data + start + i) < *(sData + i)) { // Если символ в текущей строке меньше символа в подстроке s, возвращаем -1
                return -1;
            }
            else if (*(data + start + i) > *(sData + i)) { // Если символ в текущей строке больше символа в подстроке s, возвращаем 1
                return 1;
            }
        }
        // Если ограниченная подстрока s совпадает со строкой на указанной позиции, или достигнута максимальная длина,
        // то возвращаем результат сравнения длин текущей строки и подстроки s
        if (cmpLen == sLen) {
            return 0;
        }
        else if (cmpLen == num) {
            return (sLen < num) ? 1 : -1;
        }
        else {
            return 0;
        }
    }

    //-------------------------------------------------------------------------------
    //Функции Си
    //-------------------------------------------------------------------------------

    //Копирует символы из одного массива в другой
    void* mymemcpy(void* s1, const void* s2, size_t n)
    {
        // Проверяем, что указатель s1 не равен nullptr
        if(s1 == nullptr) return nullptr;

        char* p = static_cast<char*>(s1); // Приводим указатель s1 к типу char*
        const char* q = static_cast<const char*>(s2); // Приводим указатель s2 к типу const char*

        std::unique_ptr<char[]> buffer(new char[n]); // Создаем умный указатель на массив char для буфера

        // Копируем данные из s2 в буфер
        mymemcpy(buffer.get(), q, n);

        // Копируем данные из буфера в s1
        mymemcpy(p, buffer.get(), n);

        return s1; // Возвращаем указатель на начало скопированной памяти
    }

    //Копирует символы из одного массива в другой с учётом перекрытия массивов
    void* mymemmove(void* s1, const void* s2, size_t n)
    {
        char* d = static_cast<char*>(s1); // Приводим указатель s1 к типу char*
        const char* s = static_cast<const char*>(s2); // Приводим указатель s2 к типу const char*

        if (d == s) {
            return s1; // Если исходный и целевой буферы совпадают, нет необходимости в перемещении данных
        }

        if (d < s) {
            // Если целевой буфер находится перед исходным, можно использовать прямое копирование
            std::unique_ptr<char[]> buffer(new char[n]); // Создаем умный указатель на массив char для буфера

            // Копируем данные из s2 в буфер
            mymemcpy(buffer.get(), s, n);

            // Копируем данные из буфера в s1
            mymemcpy(d, buffer.get(), n);
        } else {
            // Если целевой буфер находится после исходного, можно использовать обратное копирование
            std::unique_ptr<char[]> buffer(new char[n]); // Создаем умный указатель на массив char для буфера

            // Копируем данные из s2 в буфер в обратном порядке
            for (size_t i = n; i > 0; --i) {
                buffer[i - 1] = s[i - 1];
            }

            // Копируем данные из буфера в s1
            for (size_t i = 0; i < n; ++i) {
                d[i] = buffer[i];
            }
        }

        return s1;
    }

    size_t mystrlen(const char* s)
    {
        size_t len = 0;
        std::unique_ptr<const char[]> ptr{ s };

        while (*s != '\0') {
            len++;
            s++;
        }

        return len;
    }

    //Заполняет определённое количество символов массива заданным
    void* mymemset(void* s, int c, size_t n)
    {
        auto p = static_cast<char*>(s); // Приводим указатель s к типу char*

        // Создаем уникальный указатель unique_ptr для временного массива, чтобы не утратить исходный указатель s
        std::unique_ptr<char[]> s_copy(new char[n]);

        // Заполняем временный массив значением c
        for (size_t i = 0; i < n; i++) {
            s_copy[i] = static_cast<char>(c);
        }

        // Копируем содержимое временного массива обратно в исходный адрес памяти s
        mymemcpy(s, s_copy.get(), n);

        return s; // Возвращаем указатель на начало заполненной памяти
    }

    //Лексикографически сравнивает две строки
    int mystrncmp(const char* s1, const char* s2, size_t n)
    {
        std::unique_ptr< char[]> ps1(new char[n]);
        for (size_t i = n; i > 0; --i) {
            ps1[i - 1] = s1[i - 1];
        }

        std::unique_ptr<char[]> ps2(new char[n]);
        for (size_t i = n; i > 0; --i) {
            ps2[i - 1] = s2[i - 1];
        }

        int i = 0;
        while ((ps1[i] != '\0' || ps2[i] != '\0') && n > 0) {
            if (ps1[i] < ps2[i]) {
                return -1;
            }
            else if (ps1[i] > ps2[i]) {
                return 1;
            }
            ps1[i + 1];
            ps2[i + 1];
            n--;
        }
        // Если строки равны или достигнут конец строки s1 или s2, возвращаем 0
        return 0;
    }

    //Сравнивает в лексикографическом порядке две строки
    int mystrcmp(const char* s1, const char* s2)
    {
        int n = 1000;

        std::unique_ptr< char[]> ps11(new char[n]);
        for (size_t i = n; i > 0; --i) {
            ps11[i - 1] = s1[i - 1];
        }

        std::unique_ptr<char[]> ps22(new char[n]);
        for (size_t i = n; i > 0; --i) {
            ps22[i - 1] = s2[i - 1];
        }

        int i = 0;
        while (ps11[i] != '\0' || ps22[i] != '\0') {
            if (ps11[i] < ps22[i]) {
                return -1;
            }
            else if (ps11[i] > ps22[i]) {
                return 1;
            }
            ps11[i + 1];
            ps22[i + 1];
        }

        // Если строки равны или достигнут конец строки s1 или s2, возвращаем 0
        return 0;
    }

    //Присоединяет копию одной строки к заданной
    char* mystrcat(char* s1, const char* s2)
    {
        size_t s1Length = mystrlen(s1);
        size_t s2Length = mystrlen(s2);

        // Создаем новый умный указатель на массив символов достаточного размера
        std::unique_ptr<char[]> result(new char[s1Length + s2Length + 1]);

        // Копируем символы из s1 в result
        memcpy(result.get(), s1, s1Length);

        // Копируем символы из s2 в result, начиная с позиции после s1
        memcpy(result.get() + s1Length, s2, s2Length + 1);

        return result.release(); // Возвращаем указатель на массив символов
    }

    //Присоединяет определённое количество символов одной строки к другой
    char* mystrncat(char* s1, const char* s2, size_t n)
    {
        // Определяем длину строки s1
        size_t s1Length = mystrlen(s1);

        // Создаем новый умный указатель на массив символов достаточного размера
        std::unique_ptr<char[]> result(new char[s1Length + n + 1]);

        // Копируем символы из s1 в result
        mymemcpy(result.get(), s1, s1Length);

        // Копируем не более n символов из s2 в result, начиная с позиции после s1
        mystrncpy(result.get() + s1Length, s2, n);
        result.get()[s1Length + n] = '\0'; // Добавляем завершающий нулевой символ в конец строки result

        return result.release(); // Возвращаем указатель на массив символов
    }

    //Сравнивает определённое количество символов в двух массивах
    int mymemcmp(const void* s1, const void* s2, size_t n)
    {
       // MyUniquePtr p1(reinterpret_cast<const unsigned char*>(s1));
        //MyUniquePtr p2(reinterpret_cast<const unsigned char*>(s2));

        const char* d = static_cast<const char*>(s1); // Приводим указатель s1 к типу char*
        const char* s = static_cast<const char*>(s2); // Приводим указатель s1 к типу char*

        std::unique_ptr< char[]> ps1(new char[n]);
        for (size_t i = n; i > 0; --i) {
            ps1[i - 1] = d[i - 1];
        }

        std::unique_ptr<char[]> ps2(new char[n]);
        for (size_t i = n; i > 0; --i) {
            ps2[i - 1] = s[i - 1];
        }

        int i = 0;

        for (size_t i = 0; i < n; i++) {
            if (ps1[i] < ps2[i]) {
                return -1; // Возвращаем -1, если s1 < s2
            }
            else if (ps1[i] > ps2[i]) {
                return 1; // Возвращаем 1, если s1 > s2
            }
            ps1[i++];
            ps2[i++];
        }

        return 0; // Возвращаем 0, если s1 == s2
    }

    //Копирует содержимое одной строки в другую
    char* mystrcpy(char* s1, const char* s2)
    {
        char* dest = s1; // Указатель на начало целевой строки

        // Определяем длину строки s2
        size_t s2Length = mystrlen(s2);

        // Создаем новый умный указатель на массив символов достаточного размера
        std::unique_ptr<char[]> result(new char[s2Length + 1]);

        // Копируем символы из s2 в result
        mymemcpy(result.get(), s2, s2Length);

        result[s2Length] = '\0'; // Добавляем завершающий нулевой символ в конец строки result

        // Копируем символы из result в s1
        mymemcpy(s1, result.get(), s2Length + 1);

        return dest; // Возвращение указателя на целевую строку
    }

    //Копирует определённое количество символов в символьный массив
    char* mystrncpy(char* s1, const char* s2, size_t n)
    {
        char* dest = s1; // Указатель на начало строки назначения (s1)

        // Создаем умный указатель на массив символов достаточного размера
        std::unique_ptr<char[]> result(new char[n + 1]);

        // Копируем символы из s2 в result
        for (size_t i = 0; i < n && s2[i] != '\0'; i++) {
            result[i] = s2[i];
        }

        // Если строка s2 короче, чем n символов, заполняем оставшуюся часть result нулевыми символами
        for (size_t i = n; i > 0; i--) {
            if (s2[i - 1] == '\0') {
                result[i - 1] = '\0';
            }
        }

        // Копируем символы из result в s1
        for (size_t i = 0; i < n; i++) {
            s1[i] = result[i];
        }

        return dest;
    }


    //Возвращает указатель на первое вхождение младшего байта заданного параметра
    char* mystrchr(const char* str, int ch)
    {
        while (*str != '\0') {
            if (*str == ch) {
                return const_cast<char*>(str); // Приведение const char* к char* с использованием const_cast
            }
            ++str; // Переход к следующему символу
        }
        return nullptr; // Если символ не найден, возвращаем nullptr
    }

    //разбиение строки на части по указанному разделителю.
    char* mystrtok(char* s1, const char* s2)
    {
        static std::unique_ptr<char, void(*)(char*)> lastToken(nullptr, [](char* p){}); // Умный указатель с пользовательским удалителем для сохранения состояния между вызовами
        if (s1 != nullptr) {
            lastToken.reset(s1); // Инициализация lastToken при первом вызове функции
        } else {
            s1 = lastToken.get(); // Восстановление состояния разбора между вызовами
        }

        // Пропуск начальных разделителей
        while (*s1 != '\0' && mystrchr(s2, *s1) != nullptr) {
            *s1++ = '\0'; // Замена разделителей нулевыми символами
        }

        if (*s1 == '\0') {
            return nullptr; // Если достигнут конец строки, возвращаем nullptr
        }

        char* token = s1; // Указатель на начало текущего токена

        // Поиск конца текущего токена
        while (*s1 != '\0' && mystrchr(s2, *s1) == nullptr) {
            s1++; // Переход к следующему символу
        }

        if (*s1 != '\0') {
            *s1++ = '\0'; // Замена разделителя нулевым символом
        }

        lastToken.reset(s1); // Сохранение состояния разбора между вызовами
        return token; // Возвращение указателя на текущий токен
    }
};

#endif // MYSTRING_H
