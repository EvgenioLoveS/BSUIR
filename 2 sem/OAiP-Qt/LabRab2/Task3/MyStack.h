#ifndef MYSTACK_H
#define MYSTACK_H
#include <pointer.h>

template <class T>
class Stack
{
private:
    int size;
    struct node {
        T value;
        unique_ptr<node> prev;
    };
    unique_ptr<node> last;
public:
    Stack()
    {
        last = unique_ptr<node>();
        size = 0;
    }

    T Top()
    {
        if (last)
            return last->value;
        else
            return 0;
    }

    void Pop()
    {
        if (last)
            last = std::move(last->prev);
        --size;
    }

    void Push(T value)
    {
        unique_ptr<node> tmp(new node);
        tmp->value = value;
        tmp->prev = std::move(last);
        last = std::move(tmp);
        ++size;
    }
    int getSize() const
    {
        return size;
    }
};
#endif // MYSTACK_H
