#include <iostream>
#include <list>
#include <string>
#include <windows.h>

using namespace std;

class Student {
public:
    string name;
    int age;
    string major;
    bool tuitionPaid;
    int semester;

    Student(string n, int a, string m, int s, bool t) : name(n), age(a), major(m), semester(s), tuitionPaid(t) {}

    void display() const {
        cout << "���: " << name << ", �������: " << age << ", �������������: " << major << ", �������: " << semester << ", ���������: " << tuitionPaid;
    }
};

class ExtendedStudent : public Student {
public:
    string address;
    int studentID;
    string email;

    ExtendedStudent(string n, int a, string m, int s, bool t, string addr, int id, string e) : Student(n, a, m, s, t), address(addr), studentID(id), email(e) {}

    void displayExtendedInfo() const {
        cout << " �����: " << address << ", ID ��������: " << studentID << ", Email: " << email << endl;
    }

    void editAddress(string newAddress) {
        address = newAddress;
    }

    void editEmail(string newEmail) {
        email = newEmail;
    }

    void editStudentID(int newID) {
        studentID = newID;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    list<ExtendedStudent> students;
    // ����������, ��������, �������������� � ����� �������� ����� ����������� �����, ��� � ���������� �������, ��������� ������ STL.
    // ������:
    int menu, age, semester, rename, studentID;
    string nameToDelete, nameToEdit, name, major, email, address;
    bool tuitionPaid;

    do {
        cout << "1 - �������� ��������" << endl;
        cout << "2 - ������� ��������" << endl;
        cout << "3 - ������������� ��������" << endl;
        cout << "4 - ����� ���������� � ���� ���������" << endl;
        cout << "5 - ������������" << endl;
        cout << "6 - �����" << endl;
        cout << "-------------" << endl;
        cin >> menu;

        if (menu == 1) {
            cout << "������� ��� ��������" << endl;
            cin >> name;
            cout << "������� ������� ��������" << endl;
            cin >> age;
            cout << "������� �������� �������������" << endl;
            cin >> major;
            cout << "������� ������� �������" << endl;
            cin >> semester;
            cout << "�������� �� ���������?" << endl;
            cin >> tuitionPaid;
            cout << "�������� �����" << endl;
            cin >> address;
            cout << "������� ���� ��������" << endl;
            cin >> studentID;
            cout << "������� ����� �����" << endl;
            cin >> email;
            students.push_back(ExtendedStudent(name, age, major, semester, tuitionPaid, address, studentID, email));
        }

        if (menu == 2) {

        }

        if (menu == 3) {

        }

        if (menu == 4) {
            for (const auto& student : students) {
                student.display();
                student.displayExtendedInfo();
            }
        }

        if (menu == 5) {

        }
    } while (menu != 6);

   

    // ���������� ��������
    students.sort([](const ExtendedStudent& a, const ExtendedStudent& b) {
        return a.name < b.name;
        });

    return 0;
}