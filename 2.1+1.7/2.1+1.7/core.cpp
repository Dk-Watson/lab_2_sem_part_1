#include "DynamicList.h"

class Student{
public:
    string name;  // Имя
    int age;  // Возраст
    string major;  // Специальность
    bool tuitionPaid;  // Коммерция или нет
    int semester;  // Текущий семестр 

    friend ostream& operator<<(ostream& os, const Student& student){
        os << "Имя: " << student.name << ", Возраст: " << student.age << ", Специальность: " << student.major << ", Коммерция: " << student.tuitionPaid << ", Семестр: " << student.semester;
        return os;
    }

    friend istream& operator>>(istream& is, Student& student){
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

int main(){
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    DynamicList<Student> studentsList;

    cout << "Количество студентов: ";
    int numStudents;
    cin >> numStudents;

    for (int i = 0; i < numStudents; ++i){
        cout << "Ввод информации о студенте " << i + 1 << ":" << endl;
        Student newStudent;
        cin >> newStudent;
        studentsList.insert(newStudent);
    }

    studentsList.saveToFile("students.txt");

    string searchName;
    cout << "Введите имя студента для поиска: ";
    cin >> searchName;

    if (studentsList.search(searchName)){
        cout << searchName << " Есть в списке" << endl;
    }
    else{
        cout << searchName << " Нет в списке" << endl;
    }

    cout << "Удаление первого ученика из списка" << endl;
    //studentsList.remove(studentsList.head->data);

    return 0;
}