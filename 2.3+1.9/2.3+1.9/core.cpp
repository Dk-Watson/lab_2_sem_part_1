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
        cout << "5 - ����������" << endl;
        cout << "6 - ������������" << endl;
        cout << "7 - �����" << endl;
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
            cout << "������� �����" << endl;
            cin >> address;
            cout << "������� ���� ��������" << endl;
            cin >> studentID;
            cout << "������� ����� �����" << endl;
            cin >> email;
            students.push_back(ExtendedStudent(name, age, major, semester, tuitionPaid, address, studentID, email));
        }

        if (menu == 2) {
            cout << "������� ��� ������ �������� �������" << endl;
            cin >> nameToDelete;
            auto it = find_if(students.begin(), students.end(), [nameToDelete](const ExtendedStudent& student) {
                return student.name == nameToDelete;
                });

            // ���� ������� ������ - �������
            if (it != students.end()) {
                students.erase(it);
                cout << "������� ������� ������" << endl;
            }
            else {
                cout << "������� � ����� ������ �� ������" << endl;
            }
        }

        if (menu == 3) {
            cout << "������� ������ �������� ���������������" << endl;
            cin >> nameToEdit;

            cout << "��� ��������" << endl;
            cout << "1 - ���" << endl;
            cout << "2 - �������" << endl;
            cout << "3 - �������������" << endl;
            cout << "4 - �������" << endl;
            cout << "5 - ��� ��������" << endl;
            cout << "6 - �����" << endl;
            cout << "7 - ID" << endl;
            cout << "8 - �����" << endl;
            cin >> rename;

            auto it = find_if(students.begin(), students.end(), [nameToEdit](const ExtendedStudent& student) {
                return student.name == nameToEdit;
                });

            if (rename == 1) {
                string newName;
                cout << "������� ����� ���" << endl;
                cin >> newName;
                it->name = newName;
            }

            if (rename == 2) {
                int newAge;
                cout << "������� ����� �������" << endl;
                cin >> newAge;
                it->age = newAge;
            }

            if (rename == 3) {
                string newMajor;
                cout << "������� ����� �������������" << endl;
                cin >> newMajor;
                it->major = newMajor;
            }

            if (rename == 4) {
                int newSemester;
                cout << "������� ����� �������" << endl;
                cin >> newSemester;
                it->semester = newSemester;
            }

            if (rename == 5) {
                bool newTuitionPaid;
                cout << "�������� ��� ��������" << endl;
                cin >> newTuitionPaid;
                it->tuitionPaid = newTuitionPaid;
            }

            if (rename == 6) {
                string newAddress;
                cout << "������� ����� �����" << endl;
                cin >> newAddress;
                it->address = newAddress;
            }

            if (rename == 7) {
                int newStudentID;
                cout << "������� ����� StudentID" << endl;
                cin >> newStudentID;
                it->studentID = newStudentID;
            }

            if (rename == 8) {
                string newEmail;
                cout << "������� ����� �����" << endl;
                cin >> newEmail;
                it->email = newEmail;
            }
        }

        if (menu == 4) {
            for (const auto& student : students) {
                student.display();
                student.displayExtendedInfo();
            }
        }

        if (menu == 5) {
            students.sort([](const ExtendedStudent& a, const ExtendedStudent& b) {
                return a.studentID < b.studentID;
                });
            for (const auto& student : students) {
                student.display();
                student.displayExtendedInfo();
            }
        }

        if (menu == 6) {
            Student student1("������", 20, "����������", 3, true);

            // ������������ ������ display ������ Student

            if (student1.name == "������" and student1.age == 20 and student1.major == "����������" and student1.semester == 3 and student1.tuitionPaid == true) {
                cout << "����� display ������ Student �������� ����� " << endl;
            }

            else {
                cout << "����� display ������ Student �������� �� �����" << endl;
            }

            // ������������ ������ ExtendedStudent
            ExtendedStudent student2("������", 22, "������", 4, false, "�����1", 12345, "petrov@example.com");

            // ������������ ������ displayExtendedInfo ������ ExtendedStudent
            if (student2.name == "������" and student2.age == 22 and student2.major == "������" and student2.semester == 4 and student2.tuitionPaid == false
                and student2.address == "�����1" and student2.studentID == 12345 and student2.email == "petrov@example.com") {
                cout << "����� display ������ ExtendedStudent �������� ����� " << endl;
            }

            else {
                cout << "����� display ������ ExtendedStudent �������� �� �����" << endl;
            }

            // ������������ ������ editAddress ������ ExtendedStudent
            student2.editAddress("����� �����");
            if (student2.address == "����� �����") {
                cout << "����� editAddress ������ ExtendedStudent �������� ����� " << endl;
            }
            else {
                cout << "����� editAddress ������ ExtendedStudent �������� �� ����� " << endl;
            }
        }
    } while (menu != 7);

    return 0;
}