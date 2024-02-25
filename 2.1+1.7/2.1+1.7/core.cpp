#include "DynamicList.h"

class Student{
public:
    string name;
    int age;

    friend ostream& operator<<(ostream& os, const Student& student){
        os << "Name: " << student.name << ", Age: " << student.age;
        return os;
    }

    friend istream& operator>>(istream& is, Student& student){
        cout << "Enter name: ";
        is >> student.name;
        cout << "Enter age: ";
        is >> student.age;
        return is;
    }
};

int main(){
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    DynamicList<Student> studentsList;

    cout << "Enter the number of students: ";
    int numStudents;
    cin >> numStudents;

    for (int i = 0; i < numStudents; ++i)
    {
        cout << "Enter data for student " << i + 1 << ":" << endl;
        Student newStudent;
        cin >> newStudent;
        studentsList.insert(newStudent);
    }

    studentsList.saveToFile("students.txt");

    string searchName;
    cout << "Enter the name of the student to search for: ";
    cin >> searchName;

    if (studentsList.search(searchName))
    {
        cout << searchName << " is in the list" << endl;
    }
    else
    {
        cout << searchName << " is not in the list" << endl;
    }

    cout << "Removing the first student from the list" << endl;
    studentsList.remove(studentsList.head->data);

    return 0;
}