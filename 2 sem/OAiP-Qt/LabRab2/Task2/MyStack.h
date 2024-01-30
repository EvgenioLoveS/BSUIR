#ifndef MYSTACK_H
#define MYSTACK_H

#include <QMessageBox>
#include <QString>
#include <QTextStream>

template <typename T>

class MyStack
{

private:
    struct Node{
        T data;
        Node* next;
    };
    Node* root;

public:
    MyStack():root(nullptr){};

    ~MyStack()
    {
        while(!empty()){
            pop();
        }
    }

    void push(T x){
        Node* newnode = new Node;
        newnode->data=x;
        newnode->next=root;
        root=newnode;
    }

    T pop(){
        if(empty()){
            return 0;
        }
        Node* delnode = root;
        T x = delnode->data;
        root = delnode->next;
        delete delnode;
        return x;
    }

    bool empty() const{
        return root==nullptr;
    }

    const T& top(){
        if(empty()){
            return 0;
        }
        return root->data;
    }


};
#endif // MYSTACK_H
