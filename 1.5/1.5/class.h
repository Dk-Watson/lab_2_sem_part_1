#include <iostream>  
#include <fstream>  // ����-����� ��/� ����
#include <string>  
#include <windows.h>  // ��� ������ � ��������� Windows API

using namespace std;  

class Student {  // ����������� ������
public:
    string name;  // ��� ��������
    int age;  // ������� ��������
    string major;  // ������������� ��������
    bool tuitionPaid;  // ������ �������� (��������� ��� ���)
    int semester;  // ������� ������� ��������

    Student() {  // ����������� ������ �� ���������
        name = "Undefined";
        age = -1;
        major = "Undefined";
        tuitionPaid = false;
        semester = 1;
    }

    // ������������������� ����������� ������
    Student(string input_name, int input_age, string input_major, bool input_tuitionPaid, int input_semester)
        : name(input_name), age(input_age), major(input_major), tuitionPaid(input_tuitionPaid), semester(input_semester) {}

    void display() {  // ����� ������ � ��������
        cout << "���: " << name << endl << " �������: " << age << endl << " �������������: " << major << endl << " ������ ��������: " << tuitionPaid << endl << " �������: " << semester << endl;
    }

    void payTuition() {  // ����� ������ ��������
        tuitionPaid = true;
    }

    void advanceSemester() {  // ����� �������� �� ��������� �������
        semester++;
    }

    void changeMajor(string newMajor) {  // ����� ����� �������������
        major = newMajor;
    }
};

void loadFromFile(Student arr[], int size) {  // �������� ������ �� ����� � ������
    ifstream file("students.txt");
    for (int i = 0; i < size; i++) {
        string name, major;
        int age, semester;
        bool tuitionPaid;
        file >> arr[i].name >> arr[i].age >> arr[i].major >> arr[i].tuitionPaid >> arr[i].semester;
    }
    file.close();
}

void loadKeyboard(Student arr[], int size) {  // ���� ������ � ������ ����� ����������
    for (int i = 0; i < size; i++) {
        string name, major;
        int age, semester;
        bool tuitionPaid;
        cout << "���: ";
        cin >> name;
        cout << "�������: ";
        cin >> age;
        cout << "�������������: ";
        cin >> major;
        cout << "���������� ��������? (1 ��� ��, 0 ��� ���): ";
        cin >> tuitionPaid;
        cout << "�������: ";
        cin >> semester;
        cout << "--------- " << endl;
        arr[i] = Student(name, age, major, tuitionPaid, semester);
    }
}

void printArray(Student arr[], int size) {  // ����� ������� ���������
    for (int i = 0; i < size; i++) {
        arr[i].display();
    }
}

void removeElement(Student arr[], int& size, int index) {  // �������� �������� �� �������
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

void saveToFile(Student arr[], int size) {  // ���������� ������ ������� ��������� � ����
    ofstream file("file_students.txt");
    for (int i = 0; i < size; i++) {
        file << arr[i].name << " " << arr[i].age << " " << arr[i].major << " " << arr[i].tuitionPaid << " " << arr[i].semester << endl;
    }
    file.close();
}