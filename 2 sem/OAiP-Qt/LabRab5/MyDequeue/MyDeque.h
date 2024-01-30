#ifndef MYDEQUEUE_H
#define MYDEQUEUE_H
#include <iostream>

template<class T>
class Node {   //это узел очереди

public:

    Node(){};

    ~Node(){
        delete prev;
        delete next;
        delete []data;
    }

    int count = 0;  //счетчик количества элементов в массиве

    Node<T> *prev = nullptr;  //указатель на предыд узел

    Node<T> *next = nullptr;  //указатель на след узел

    T *data = new T[4]; //массив из 4 элементов типа T
};

template<class T>
class DequeIterator {

private:
    Node <T> *_node;  // указатель на узел

    int _index;   //индекс текущего элемента

public:
    DequeIterator() {};

    DequeIterator(Node <T> *node) : _node(node) {};

    DequeIterator(Node <T> *node, size_t index) : _node(node), _index(index) {};

    ~DequeIterator() {};

    DequeIterator<T> begin();

    DequeIterator<T> end();

    T &operator*() const {
        return _node->data[_index];
    }

    T *operator->() const {
        return &_node->data[_index];
    }

    DequeIterator<T> begin() const {  //пока нода может указывать на предыдущую перемещаем и оставляем первой
        Node <T> *firstNode = _node;
        while (firstNode->prev) {
            firstNode = firstNode->prev;
        }
        return DequeIterator<T>(firstNode, 0);
    }

    DequeIterator<T> end() const {
        Node <T> *lastNode = _node;
        while (lastNode->next) {
            lastNode = lastNode->next;
        }
        return DequeIterator<T>(lastNode, lastNode->count);
    }

    DequeIterator &operator++() {
        if (_index + 1 < _node->count) {
            _index++;
        } else {
            _node = _node->next;
            _index = 0;
        }
        return *this;
    }

    DequeIterator operator++(int) {
        DequeIterator tmp = *this;
        ++(*this);
        return tmp;
    }

    DequeIterator &operator--() {
        if (_index > 0) {
            _index--;
        } else {
            _node = _node->prev;
            _index = _node->count - 1;
        }
        return *this;
    }

    DequeIterator operator--(int) {
        DequeIterator tmp = *this;
        --(*this);
        return tmp;
    }


    bool operator==(const DequeIterator &other) const {
        return (_node == other._node) && (_index == other._index);
    }

    bool operator!=(const DequeIterator &other) const {
        return !(*this == other);
    }
};

template<class T>
class Deque : public DequeIterator<T> {

private:
    Node<T> *m_head;  // указатель на первый элемент

    Node<T> *m_tail;  // указатель на последний элемент

    size_t m_capacity = 0;  // обозначает текущее количество узлов в деке

    size_t m_size = 0;   // количество элементов в деке

public:
    DequeIterator<T> begin()  {
        Node<T>* firstNode = m_head;
        return DequeIterator<T>(firstNode, 0);
    }

    DequeIterator<T> end()  {
        Node<T>* lastNode = m_tail;
        return DequeIterator<T>(lastNode, lastNode->count);
    }

    //конструктор по умолчанию
    Deque(){};

    //деструктор по умолчанию
    ~Deque(){};

    //добавляет x в конец очереди.
    void push_back(const T &addItem);
    //добавляет x в начало очереди.
    void push_front(const T &addItem);
    //удаляет последний элемент из очереди.
    void pop_back();
    //удаляет первый элемент из очереди
    void pop_front();
    //задаем новый размер
    void resize(size_t new_size);

    bool isEmpty() {
        return m_size == 0;
    };

    int getSize() {
        return m_size;
    };

    void clear() {
        m_capacity = 0;
        m_size = 0;
        m_head = nullptr;
        m_tail = nullptr;
    }

    T& back() {
        return m_tail->data[m_tail->count - 1];
    }

    T& front() {
        return m_head->data[0];
    }

    T& operator[](size_t index)
    {
        // Если индекс находится вне диапазона элементов, выбрасываем исключение
        if (index < 0 || index >= m_size) {
            throw std::out_of_range("Index out of range");
        }

        // Ищем узел, содержащий элемент с индексом index
        Node<T>* node = m_head;
        size_t count = 0;

        while (node != nullptr && count + node->count <= index) {
            count += node->count;
            node = node->prev;
        }

        // Возвращаем элемент из найденного узла по соответствующему индексу в его массиве
        return node->data[index - count];
    }
};

template<class T>
void Deque<T>::push_back(const T &addItem) {

   if(m_capacity == 0) {   //Если дек пустой
       m_head = new Node<T>;  //то создается новый узел
       m_tail = m_head;
       m_tail->data[0] = addItem;  //элемент помещается в его массив
       m_tail->count++;
       m_capacity++;
   }

   else {  //В противном случае, если текущий узел еще не заполнен

       if(m_tail->count < 4){
           m_tail->data[m_tail->count] = addItem;  //то элемент добавляется в его массив
           m_tail->count++;
       }

       else {  //Если текущий узел уже заполнен
            m_tail->prev = new Node<T>;  //то создается новый узел
            m_tail->prev->next = m_tail;
            m_tail = m_tail->prev;
            m_tail->data[m_tail->count] = addItem;  //элемент помещается в его массив
            m_tail->count++;
            m_capacity++;
       }
   }

   m_size++;
}

template<class T>
void Deque<T>::push_front(const T & addItem) {

    if(m_capacity == 0){  //проверка, что в очереди пока нет элементов
        m_tail=m_head = new Node<T>;  //создание нового узла (экземпляра класса Node)
        m_head->data[0] = addItem;  //добавление элемента в первый узел очереди
        m_head->count++;   //увеличение счетчика элементов в первом узле
        m_head->prev = m_tail; //указание на следующий узел (заднюю часть) для первого узла
        m_capacity++;  //увеличение счетчика вместимости очереди
    }

    else {

        if(m_head->count < 4) {  //проверка, что первый узел еще не заполнен
            for(auto i = 0; i < m_head->count; i++){  //цикл, который сдвигает элементы в первом узле вправо на одну позицию
                auto tmp = m_head->data[i + 1];   //сохранение значения следующего элемента
                m_head->data[i + 1] = m_head->data[i];  //перемещение текущего элемента на одну позицию вправо
            }
            m_head->data[0] = addItem;   //добавление нового элемента в первую позицию
            m_head->count++;   // увеличение счетчика элементов в первом узле

        }

        else {    //если первый узел заполнен
             m_head->next = new Node<T>;  //создание нового узла и указание на него в текущем первом узле
             m_head->next->prev = m_head;  //установка связи между новым узлом и текущим первым узлом
             m_head = m_head->next;  //перемещение указателя _front на новый узел
             m_head->data[0] = addItem;   //добавление элемента в новый первый узел
             m_head->count++;   //увеличение счетчика элементов в новом первом узле
             m_capacity++;
        }
    }

    m_size++;  //увеличение счетчика элементов в очереди
}

template<class T>
void Deque<T>::pop_back() {

    if (m_tail->count > 1) {  // если в последнем узле больше одного элемента
        m_tail->data[--m_tail->count] = T();  //то последний элемент удаляется путем уменьшения счетчика и присвоения ему значения по умолчанию для типа T
    }

    else {  //если у последнего узла есть только один элемент

        Node<T> *tmp = m_tail;  //создание временного указателя на последний узел
        m_tail = m_tail->prev;  //перемещение указателя на предыдущий узел

        if (m_tail) {  //если предыдущий узел существует
            delete tmp;  //удаление временного указателя
            m_tail->next = nullptr;  //обнуление указателя на следующий узел предыдущего узла
        }

        else {
            // Если у нас только один узел в очереди, удаляем все его элементы.
            delete[] tmp->data;  // удаление массива элементов в последнем узле
            delete tmp;
            m_tail = m_head = nullptr;
            m_capacity = m_size = 0;
        }
    }
    m_size--;
}

template<class T>
void Deque<T>::pop_front() {

    if (m_head->count <= 1) {  // если количество элементов в первом узле _front меньше или равно 1
        Node <T> *tmp = m_head; //Поэтому метод удаляет узел _front
        m_head = m_head->prev;  //перемещает указатель на _front на предыдущий узел в очереди
        delete tmp;
        m_capacity--;

    } else {  //Если количество элементов в узле больше 1
        m_head->data[0] = rand();  //то метод сначала устанавливает первый элемент в массиве данных случайным числом
        for (auto i = 1; i < m_head->count; i++) {  // затем с помощью цикла сдвигает все остальные элементы влево
            m_head->data[i - 1] = m_head->data[i];   //чтобы заменить удаленный элемент
        }
    }
}
#endif // MYDEQUEUE_H
