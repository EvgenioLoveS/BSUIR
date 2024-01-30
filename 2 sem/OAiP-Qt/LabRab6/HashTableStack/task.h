#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <HashTable.h>
#include <cstdlib>
#include <ctime>

using namespace std;

class task : public HashTable
{
public:
    task(int table_size) : HashTable()
    {
        srand(time(nullptr));
        for (int i = 0; i < table_size; i++)
        {
            int key = rand() % 100 + 1;
            int value = rand() % 1000 + 1;
            put(key, value);
        }
    }

    void deleteNodesWithEvenKeys()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            Node* current_node = table[i];
            Node* previous_node = nullptr;
            while (current_node) {
                if (current_node->key % 2 == 0)
                {
                    if (previous_node)
                    {
                        previous_node->next = current_node->next;
                    }
                    else
                    {
                        table[i] = current_node->next;
                    }
                    Node* temp = current_node;
                    current_node = current_node->next;
                    delete temp;
                }
                else
                {
                    previous_node = current_node;
                    current_node = current_node->next;
                }
            }
        }
    }
};

#endif // TASK_H
