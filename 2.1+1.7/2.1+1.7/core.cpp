#include "DynamicList.h"

class Student{
public:
    string name;  // ���
    int age;  // �������
    string major;  // �������������
    bool tuitionPaid;  // ��������� ��� ���
    int semester;  // ������� ������� 

    friend ostream& operator<<(ostream& os, const Student& student){
        os << "���: " << student.name << ", �������: " << student.age << ", �������������: " << student.major << ", ���������: " << student.tuitionPaid << ", �������: " << student.semester;
        return os;
    }

    friend istream& operator>>(istream& is, Student& student){
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

int main(){
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    DynamicList<Student> studentsList;

    cout << "���������� ���������: ";
    int numStudents;
    cin >> numStudents;

    for (int i = 0; i < numStudents; ++i){
        cout << "���� ���������� � �������� " << i + 1 << ":" << endl;
        Student newStudent;
        cin >> newStudent;
        studentsList.insert(newStudent);
    }

    studentsList.saveToFile("students.txt");

    string searchName;
    cout << "������� ��� �������� ��� ������: ";
    cin >> searchName;

    if (studentsList.search(searchName)){
        cout << searchName << " ���� � ������" << endl;
    }
    else{
        cout << searchName << " ��� � ������" << endl;
    }

    cout << "�������� ������� ������� �� ������" << endl;
    //studentsList.remove(studentsList.head->data);

    return 0;
}