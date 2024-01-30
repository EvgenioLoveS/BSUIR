#ifndef VECTOR_H
#define VECTOR_H
#include <algorithm>
#include <cmath>
#include <memory>
#include <limits>
#include <QtDebug>
//#include <QMessageBox>

/*class Vector
{
public:
    Vector(){};
};*/


template <class T>
class vector{

private:
    size_t _size = 0;
    size_t _capacity = 1;
    T* v{};

public:

    vector(){ // констуктор
        v = new T[1];
    }

    ~vector(){ // деструктор
        delete[] v;
    }

    vector(size_t size, const T& value = T{}) : _size(size), _capacity(size == 0 ? 1 : size) { // создание вектора
        v = new T[_capacity];
        for (size_t i = 0; i < _size; ++i) {
            v[i] = value;
        }
    }

    vector(const vector& other) : _size(other._size), _capacity(other._capacity), v(new T[_capacity]) { // констуктор копирования
        std::copy(other.v, other.v + _size, v);
    }

    vector(std::initializer_list<T> list) : v(new T[list.size()]), _size(list.size()), _capacity(list.size()){
      std::copy(list.begin(), list.end(), v);
    }

    class iterator{

    private:
        T* _ptr;

    public:

        iterator(T* vec): _ptr(vec){};
        ~iterator(){};

        bool operator==(const iterator& tmp) const
        {
            return _ptr == tmp._ptr;
        };

        bool operator!=(const iterator& tmp) const
        {
            return !(* this == tmp);
        };

        iterator& operator=(const iterator &tmp)
        {
            _ptr=tmp._ptr;
        };

        iterator& operator++()
        {
            _ptr++;
            return *this;
        }

        iterator& operator--()
        {
            _ptr--;
            return *this;
        }

        T& operator*() const
        {
            return *_ptr;
        };

        T* operator->()
        {
            return _ptr;
        };

        T* operator&()
        {
            return _ptr;
        };
    };

    class reverse_iterator{

    private:
        T* _ptr;

    public:

        reverse_iterator(T* vec): _ptr(vec){};
        ~reverse_iterator(){};

        bool operator==(const iterator& tmp) const
        {
            return _ptr == tmp._ptr;
        };

        bool operator!=(const iterator& tmp) const
        {
            return !(* this == tmp);
        };

        iterator& operator=(const iterator &tmp)
        {
            _ptr=tmp._ptr;
        };

        iterator& operator++()
        {
            _ptr--;
            return *this;
        }

        iterator& operator--()
        {
            _ptr++;
            return *this;
        }

        T& operator*() const
        {
            return *_ptr;
        };

        T* operator->()
        {
            return _ptr;
        };

        T* operator&()
        {
            return _ptr;
        };
    };


    T& operator[](size_t index)  {
        return v[index];
    }

    const T& operator[](size_t index) const {
        return v[index];
    }

    vector operator=(const vector& other) {
        if (this != &other) {
            delete[] v;
            v = new T[other._capacity];
            for(size_t i = 0; i < other._size; ++i) v[i] = other.v[i];
            _size = other._size;
            _capacity = other._size;
        }
        return *this;
    }

    size_t size() const { //Возвращает количество элементов в векторе
        return _size;
    }

    unsigned long long max_size(){ //Возвращает максимальную длину вектора.
         return std::numeric_limits<size_t>::max() / sizeof(T);//количество элементов, которое можно хранить в векторе
    }

    size_t capacity() const { //Возвращает число элементов, которое вектор может содержать
        return _capacity;
    }

    T* data() { // Возвращает указатель на первый элемент в векторе
        return v;
    }

    void clear(){ //Очищает элементы вектора
        delete[] v;
        v = new T[1];
        _capacity = 1;
        _size = 0;
    }

    bool empty(){ //Проверяет, пуст ли контейнер вектора
        return _size == 0;
    }

    T& at(size_t i){ //Возвращает ссылку на элемент в заданном положении в векторе
        if(i > _size - 1){
            return *v;
        }
        return v[i];
    }

    T& back() { //Возвращает ссылку на последний элемент вектора
        if(!_size){
            return *v;
        }
        return v[_size-1];
    }

    T& front() { //Возвращает ссылку на первый элемент в векторе
        return v[0];
    }

    void reserve(const size_t& n){ // Резервирует минимальную длину хранилища для объекта вектора
        _capacity = n;
        T* tmp = v;
        v = new T[_capacity];

        if(_size > _capacity){
            _size = _capacity - 1;
        }

        for(int i = 0; i < _size; ++i){
            v[i] = tmp[i];
        }
    }

    void resize(const size_t& n){ //Определяет новый размер вектора
        if(!_capacity){
            _capacity = 1;
            while (_capacity < n) {
                _capacity *= 2;
            }
            v = new T[_capacity];
            for (size_t i = 0; i < n; ++i) v[i] = {};
            _size = n;
        }
        else{
            while(_capacity < n){
                _capacity *= 2;
            }
            T* tmp = v;
            v = new T[_capacity];
            for (size_t i = 0; i < _size; ++i) v[i] = tmp[i];
            for(size_t i = _size; i < n; ++i) v[i] = 0;
            _size = n;
            delete[] tmp;
        }
    }

    void push_back(const T& value){ //Добавляет элемент в конец вектора
        if(!_capacity){
            _capacity = _size + 1;
            v = new T[_capacity];
         }
        else if (_size == _capacity){
            _capacity *= 2;
            T* tmp = v;
            v = new T[_capacity];
            for (size_t i = 0; i < _size; ++i) v[i] = tmp[i];
            delete[] tmp;
        }
        ++_size;
        v[_size-1] = value;
    }

    void pop_back(){ // Удаляет элемент в конце вектора.
        if(!_size){
            return;
        }
        --_size;
        if(_capacity / 2 >= _size){
            _capacity /= 2;
            T* tmp = v;
            v = new T[_capacity];
            for(int i = 0; i < _size;i++) v[i] = tmp[i];
            delete[] tmp;
        }
    }

    void insert(const iterator& it, const T& value){ //Вставляет элемент или множество элементов в заданную позиции в вектор
        ++_size;
        size_t ind = it.base() - v;
        if(_size > _capacity){
            _capacity *= 2;
            T* tmp = v;
            v = new T[_capacity];
            for (size_t i = 0; i < ind; ++i) v[i] = tmp[i];
            v[ind] = value;
            for(size_t i = ind + 1; i < _size; ++i) v[i] = tmp[i-1];
            delete[] tmp;
        }
        else{
            for(size_t i = _size; i > ind; --i){
                v[i] = v[i-1];
            }
            v[ind] = value;
        }
    }

    void insert_from_4(const int &pos, const T &elem) {   //Вставляет элемент или множество элементов в заданную позиции в вектор
            if (pos < 0 || pos > _size) {
                throw std::out_of_range("Invalid position specified");
            }

            if (_size >= _capacity) {
                _capacity = (_capacity == 0 ? 1 : _capacity * 2);
                T *tmp = new T[_capacity];
                for (int i = 0; i < _size; i++) {
                    tmp[i] = std::move(v[i]);
                }
                delete[] v;
                v = tmp;
            }

            for (int i = _size; i > pos; i--) {
                v[i] = std::move(v[i - 1]);
            }

            v[pos] = std::move(elem);
            _size++;
        }

    void erase(const iterator& it){ //Метод удаления элемента
        int ind = it.base() - v;
        --_size;
        for(size_t i = ind; i < _size; ++i){
            v[i] = v[i+1];
        }
    }
    void erase_from_4(int index1, int index2) { //Метод удаления элемента
        for (int i = index2; i < _size; i++) {
        v[index1 + i - index2] = v[i];
        }
        _size -= index2 - index1;
    }

    void assign(iterator start, iterator end){ //Удаляет вектор и копирует указанные элементы в пустой вектор
        delete[] v;
        v = nullptr;
        _size = 0;
        _capacity = 1;
        iterator tmp = start;
        while(tmp != end){
            tmp++;
            ++_size;
            if(_size > _capacity){
                _capacity *= 2;
            }
        }
        v = new T[_capacity];
        for(int i = 0; start <= end; ++start, ++i){
            v[i] = *start.base();
        }
    }

    void assign_from_4(int size, T element) {
        _size = size;
        _capacity = (int)((double)(_size) * 1.5);
        delete[] v;
        v = new T[_capacity];
        for (int i = 0; i < _size; ++i) {
            v[i] = element;
        }
    }

    void emplace_from_4(const int& pos, T&& elem) {

            if (pos < 0 || pos > _size) {
                throw std::out_of_range("Invalid position specified");
            }

            if (_size >= _capacity) {
                _capacity = (_capacity == 0 ? 1 : _capacity * 2);
                T* tmp = new T[_capacity];
                for (int i = 0; i < _size; i++) {
                    tmp[i] = std::move(v[i]);
                }
                delete[] v;
                v = tmp;
            }

            for (int i = _size; i > pos; i--) {
                v[i] = std::move(v[i-1]);
            }

            v[pos] = std::move(elem);
            _size++;
        }

    void swap(vector& other){
        if(this != &other){
            vector<T> tmp(other);
            other = *this;
            *this = tmp;
        }
    }

    iterator begin(){
        return iterator(v);
    }

    iterator end(){
        if(!_size){
            return nullptr;
        }
        return iterator(&v[_size]);
    }

    const iterator cbegin() const{
        return iterator(v);
    }


    const iterator cend() const{
        if(!_size){
            return nullptr;
        }
        return iterator(&v[_size]);
    }

    reverse_iterator rend(){
        return reverse_iterator(v-1);
    }

    reverse_iterator rbegin(){
        if(!_size){
            return nullptr;
        }
        return reverse_iterator(v + _size - 1);
    }

    const reverse_iterator crend() const {
        return iterator(v);
    }

    const reverse_iterator crbegin() const {
        if(!_size){
            return nullptr;
        }
        return iterator(&v[_size]);
    }

    template<class... Args>
    _COMPLEX_DEFINED void emplace_back(Args&&... args) noexcept {
        using expander = T[];
        (void)expander{NULL,
        (void(push_back(args)), NULL)...};
    }

    template<class... Args>
    void emplace(const iterator& it, Args&&... args) noexcept {
        size_t pos = it.base() - v;
        size_t oldSize = _size;
        T* newV = new T[_size - pos];
        for(size_t i = pos - 1, j = 0; i < _size; ++i, ++j){
            newV[j] = v[i];
        }
        _size -= pos;
        emplace_back(args...);
        for(size_t i = 0; i < oldSize - pos + 1; ++i){
            push_back(newV[i]);
        }
        delete[] newV;
    }

};

#endif // VECTOR_H
