#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H

#include <iostream>
#include <fstream>
#include <windows.h>
#include <cassert>

using namespace std;

class Student { 
public:
    string name;  // Имя
    int age;  // Возраст
    string major;  // Специальность
    bool tuitionPaid;  // Коммерция или нет
    int semester;  // Текущий семестр 

    friend ostream& operator<<(ostream& os, const Student& student) {
        os << "Имя: " << student.name << ", Возраст: " << student.age << ", Специальность: " << student.major << ", Коммерция: " << student.tuitionPaid << ", Семестр: " << student.semester;
        return os;
    }

    friend istream& operator>>(istream& is, Student& student) {
        cout << "Введи имя: ";
        is >> student.name;
        cout << "Введи возраст: ";
        is >> student.age;
        cout << "Введи специальность: ";
        is >> student.major;
        cout << "Коммерция или нет: ";
        is >> student.tuitionPaid;
        cout << "Введи текущий семестр: ";
        is >> student.semester;
        return is;
    }
};

template <class T>
struct Node{
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

    void insert(const T& data) // метод вноса в лист
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

    void remove(const T& data) // метод удаления
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
            cout << "Элемент не найден" << endl;
        }
        else
        {
            Node<T>* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    bool search(const string& name) // метод поиска 
    {
        Node<T>* current = head;
        while (current != nullptr)
        {
            if (current->data.name == name) 
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void saveToFile(const string& filename){ // метод сохранения в файл
        ofstream file(filename);
        Node<T>* current = head;
        while (current != nullptr)
        {
            file << current->data << endl;
            current = current->next;
        }
        file.close();
    }

    Node<T>* getHead() const{ // возвращение "головы"
        return head;
    }

    bool removeFirst(){ // удаление первого
        if (head != nullptr){
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool testInsert() { // тест метода поиска
        DynamicList<Student> studentsList;
        Student s1 = { "Дмитрий", 20, "Инженер", 1, 2 };
        studentsList.insert(s1);
        return assert(studentsList.search("Дмитрий") == true);
    }

private:
    Node<T>* head;
};

#endif // DYNAMICLIST_H