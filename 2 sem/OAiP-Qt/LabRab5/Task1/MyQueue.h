#ifndef MYQUEUE_H
#define MYQUEUE_H
#include "MyUniquePtr.h"
#include <QString>
#include <memory>

template <class T>
class MyQueue
{

    protected:

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

#endif // MYQUEUE_H
