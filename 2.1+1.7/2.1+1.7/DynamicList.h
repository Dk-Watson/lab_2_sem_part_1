#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H

#include <iostream>
#include <fstream>
#include <windows.h>
#include <cassert>

using namespace std;

class Student { 
public:
    string name;  // ���
    int age;  // �������
    string major;  // �������������
    bool tuitionPaid;  // ��������� ��� ���
    int semester;  // ������� ������� 

    friend ostream& operator<<(ostream& os, const Student& student) {
        os << "���: " << student.name << ", �������: " << student.age << ", �������������: " << student.major << ", ���������: " << student.tuitionPaid << ", �������: " << student.semester;
        return os;
    }

    friend istream& operator>>(istream& is, Student& student) {
        cout << "����� ���: ";
        is >> student.name;
        cout << "����� �������: ";
        is >> student.age;
        cout << "����� �������������: ";
        is >> student.major;
        cout << "��������� ��� ���: ";
        is >> student.tuitionPaid;
        cout << "����� ������� �������: ";
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

    void insert(const T& data) // ����� ����� � ����
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

    void remove(const T& data) // ����� ��������
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
            cout << "������� �� ������" << endl;
        }
        else
        {
            Node<T>* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    bool search(const string& name) // ����� ������ 
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

    void saveToFile(const string& filename){ // ����� ���������� � ����
        ofstream file(filename);
        Node<T>* current = head;
        while (current != nullptr)
        {
            file << current->data << endl;
            current = current->next;
        }
        file.close();
    }

    Node<T>* getHead() const{ // ����������� "������"
        return head;
    }

    bool removeFirst(){ // �������� �������
        if (head != nullptr){
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool testInsert() { // ���� ������ ������
        DynamicList<Student> studentsList;
        Student s1 = { "�������", 20, "�������", 1, 2 };
        studentsList.insert(s1);
        return assert(studentsList.search("�������") == true);
    }

private:
    Node<T>* head;
};

#endif // DYNAMICLIST_H