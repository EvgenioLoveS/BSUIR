#ifndef MYQUEUE_H
#define MYQUEUE_H
#include "MyUniquePtr.h"

template <class T>
class MyQueue
{

private:

    struct Node
    {
        Node(const T& value) : data(value), next(nullptr) {}
        T data;                 // Данные узла
        MyUniquePtr<Node> next; // Указатель на следующий узел
    };

    MyUniquePtr<Node> m_head;  // Указатель на первый узел
    Node* m_tail;              // Указатель на последний узел
    size_t m_size;             // Количество элементов в очереди

public:

    // Конструктор по умолчанию
    MyQueue() : m_head(nullptr), m_tail(nullptr), m_size(0) {}

    // Деструктор
    virtual ~MyQueue();

    // Добавить элемент в конец очереди
    void push(const T& item);

    // Удалить первый элемент очереди
    void pop();

    // Проверка, является ли очередь пустой
    bool isEmpty() const {
        return m_size == 0;
    }

    // Получение размера очереди
    int getSize() const {
        return m_size;
    }

    // Получить первый элемент очереди
    const T& front() const {
        return m_head->data;
    }

    // Получить последний элемент очереди
    const T& back() const {
        return m_tail->data;
    }

    // Очистка очереди от всех элементов
    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }
};


template<class T>
MyQueue<T>::~MyQueue(){
    while(!isEmpty()){
        pop();
    }
}

// Добавление элемента в конец очереди
template<class T>
void MyQueue<T>::push(const T& item){
    MyUniquePtr<Node> newNode(new Node(item));
    if (isEmpty()) {
        m_head = std::move(newNode);
        m_tail = m_head.get();
    } else {
        m_tail->next = std::move(newNode);
        m_tail = m_tail->next.get();
    }
    m_size++;
}

// Удаление элемента из начала очереди
template<class T>
void MyQueue<T>::pop() {
    if (!isEmpty()) {
        m_head = std::move(m_head->next);
        m_size--;
        if (isEmpty()) {
            m_tail = nullptr;
        }
    }
}


template <class T>
class MyDoubleQueue : public MyQueue<T>
{
private:
    typename MyQueue<T>::Node* m_back;  // Указатель на последний узел
public:
    // Конструктор по умолчанию
    MyDoubleQueue() : MyQueue<T>(), m_back(nullptr) {}

    // Добавить элемент в начало очереди
    void push_front(const T& item);

    // Удалить последний элемент очереди
    void pop_back();

    // Преобразовать очередь в кольцо
    void makeCircle();

    // Очистить очередь от всех элементов и обнулить указатели
    void clear() {
        MyQueue<T>::clear();
        m_back = nullptr;
    }
};

// Добавление элемента в начало очереди
template<class T>
void MyDoubleQueue<T>::push_front(const T& item){
    MyUniquePtr<typename MyQueue<T>::Node> newNode(new typename MyQueue<T>::Node(item));
    if (MyQueue<T>::isEmpty()) {
        MyQueue<T>::m_head = std::move(newNode);
        m_back = MyQueue<T>::m_head.get();
    } else {
        newNode->next = std::move(MyQueue<T>::m_head);
        MyQueue<T>::m_head = std::move(newNode);
    }
    MyQueue<T>::m_size++;
}

// Удаление элемента из конца очереди
template<class T>
void MyDoubleQueue<T>::pop_back() {
    if (!MyQueue<T>::isEmpty()) {
        if (MyQueue<T>::m_head.get() == m_back) {
            MyQueue<T>::pop();
            m_back = nullptr;
        } else {
            typename MyQueue<T>::Node* curNode = MyQueue<T>::m_head.get();
            while (curNode->next.get() != m_back) {
                curNode = curNode->next.get();
            }
            curNode->next.reset();
            m_back = curNode;
            MyQueue<T>::m_size--;
        }
    }
}

// Преобразование очереди в кольцо
template<class T>
void MyDoubleQueue<T>::makeCircle() {
    if (!MyQueue<T>::isEmpty() && m_back == nullptr) {
        m_back = MyQueue<T>::m_head.get();
        typename MyQueue<T>::Node* curNode = MyQueue<T>::m_head.get();
        while (curNode->next) {
            curNode = curNode->next.get();
        }
        curNode->next = std::move(MyQueue<T>::m_head);
    }
}

#endif // MYQUEUE_H
