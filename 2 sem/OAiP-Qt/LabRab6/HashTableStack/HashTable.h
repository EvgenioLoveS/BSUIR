#ifndef HASHTABLE_H
#define HASHTABLE_H

#pragma once
#include <iostream>
#include <vector>
#include <QString>

const int TABLE_SIZE = 10;

class HashTable {

public:

    HashTable() : table(TABLE_SIZE, nullptr) {}

    ~HashTable() { clear(); }

    void put(int key, int value) {
        int index = hash(key);
        Node *current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node *newNode = new Node(key, value);
        newNode->next = table[index];
        table[index] = newNode;
    }

    int get(int key) {
        int index = hash(key);
        Node *current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    void remove(int key) {
        int index = hash(key);
        Node *current = table[index];
        Node *previous = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (previous == nullptr) {
                    table[index] = current->next;
                } else {
                    previous->next = current->next;
                }
                delete current;
                return;
            }
            previous = current;
            current = current->next;
        }
    }

    int size() {
        int count = 0;
        for (int i = 0; i < TABLE_SIZE; i++) {
            Node *current = table[i];
            while (current != nullptr) {
                count++;
                current = current->next;
            }
        }
        return count;
    }

    void print(std::string &str) {
        for (int i = 0; i < TABLE_SIZE; i++) {
            str += "[" + std::to_string(i) + "]: ";
            Node *current = table[i];
            while (current != nullptr) {
                str += "(" + std::to_string(current->key) + ", " + std::to_string(current->value) + ")";
                current = current->next;
                if (current != nullptr) {
                    str += " -> ";
                }
            }
            str += "\n";
        }
    }

    int hash(int key) { return key % TABLE_SIZE; }

    void clear() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            Node *current = table[i];
            while (current != nullptr) {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
            table[i] = nullptr;
        }
    }

    struct Node {
            int key;
            int value;
            Node *next;

            Node(int k, int v) : key(k), value(v), next(nullptr) {}
        };

protected:

    std::vector<Node*> table;
};

#endif // HASHTABLE_H
