#include <iostream>
#include <list>
#include <string>
#include <windows.h>

using namespace std;

class Student {
public:
    string name;  // ���
    int age;  // �������
    string major;  // �������������
    bool tuitionPaid;  // ��������� ��� ���
    int semester;  // ������� ������� 

    Student(string n, int a, string m, int s, bool t) : name(n), age(a), major(m), semester(s), tuitionPaid(t){}

    void display() const {
        cout << "���: " << name << ", �������: " << age << ", �������������: " << major << ", �������: " << semester << ", ���������: " << tuitionPaid << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    list<Student> students;
    int menu, age, semester, rename;
    string nameToDelete, nameToEdit, name, major;
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
            students.push_back(Student(name, age, major, semester, tuitionPaid));
        }

        if (menu == 2) {
            cout << "������� ��� ������ �������� �������" << endl;
            cin >> nameToDelete;

            for (auto it = students.begin(); it != students.end(); ) {
                if (it->name == nameToDelete) {
                    it = students.erase(it);
                }
                else {
                    ++it;
                }
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
            cin >> rename;

            if (rename == 1) {
                string newName;
                cout << "������� ����� ���" << endl;
                cin >> newName;
                for (auto& s : students) {
                    if (s.name == nameToEdit) {
                        s.name = newName;
                    }
                }
            }

            if (rename == 2) {
                int newAge;
                cout << "������� ����� �������������" << endl;
                cin >> newAge;
                for (auto& s : students) {
                    if (s.name == nameToEdit) {
                        s.age = newAge;
                    }
                }
            }

            if (rename == 3) {
                string newMajor;
                cout << "������� ����� �������������" << endl;
                cin >> newMajor;
                for (auto& s : students) {
                    if (s.name == nameToEdit) {
                        s.major = newMajor;
                    }
                }
            }

            if (rename == 4) {
                int newSemester;
                cout << "������� ����� �������������" << endl;
                cin >> newSemester;
                for (auto& s : students) {
                    if (s.name == nameToEdit) {
                        s.semester = newSemester;
                    }
                }
            }

            if (rename == 5) {
                bool newTuitionPaid;
                cout << "������� ����� �������������" << endl;
                cin >> newTuitionPaid;
                for (auto& s : students) {
                    if (s.name == nameToEdit) {
                        s.tuitionPaid = newTuitionPaid;
                    }
                }
            }
            
        }

        if (menu == 4) {
            for (const auto& s : students) {
                s.display();
            }
        }

        if (menu == 5) {
            
        }

    } while (menu != 6);
    return 0;
}