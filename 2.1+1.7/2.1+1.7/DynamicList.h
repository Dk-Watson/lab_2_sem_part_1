#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H

#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

template <class T>
struct Node
{
    T data;
    Node* next;
};

template <class T>
class DynamicList
{
public:
    DynamicList() : head(nullptr) {}
    ~DynamicList()
    {
        Node<T>* current = head;
        while (current != nullptr)
        {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }

    void insert(const T& data)
    {
        Node<T>* newNode = new Node<T>{ data, nullptr };
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node<T>* current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void remove(const T& data)
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (head->data == data)
        {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node<T>* current = head;
        while (current->next != nullptr && current->next->data != data)
        {
            current = current->next;
        }

        if (current->next == nullptr)
        {
            cout << "Ёлемент не найден" << endl;
        }
        else
        {
            Node<T>* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    bool search(const T& data)
    {
        Node<T>* current = head;
        while (current != nullptr)
        {
            if (current->data == data)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void saveToFile(const string& filename)
    {
        ofstream file(filename);
        Node<T>* current = head;
        while (current != nullptr)
        {
            file << current->data << endl;
            current = current->next;
        }
        file.close();
    }

private:
    Node<T>* head;
};

#endif // DYNAMICLIST_H