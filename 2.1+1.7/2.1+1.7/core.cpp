#include "DynamicList.h"

int main(){
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    DynamicList<Student> studentsList;

    int vibor;
    cout << "��� ������� ��������� ������� 1 ";
    cout << "��� ����� ������� 2 ";
    cin >> vibor;

    if (vibor == 1) {
        cout << "���������� ���������: ";
        int numStudents;
        cin >> numStudents;

        for (int i = 0; i < numStudents; ++i) { //���� ���������� � ����
            cout << "���� ���������� � �������� " << i + 1 << ":" << endl;
            Student newStudent;
            cin >> newStudent;
            studentsList.insert(newStudent);
        }

        string searchName; // ����� �� �����
        cout << "������� ��� �������� ��� ������: ";
        cin >> searchName;

        if (studentsList.search(searchName)) {
            cout << searchName << " ���� � ������" << endl;
        }
        else {
            cout << searchName << " ��� � ������" << endl;
        }

        cout << "�������� ������� ������� �� ������" << endl;
        studentsList.removeFirst();

        studentsList.saveToFile("students.txt");
    }

    else { // ������������ ������ ������ 
        DynamicList<Student> test;
        if (test.testInsert()) {
            cout << "������������ ������ ��������� �������" << endl;
        }
        else {
            cout << "������ ������������" << endl;
        }
    }
    return 0;
}