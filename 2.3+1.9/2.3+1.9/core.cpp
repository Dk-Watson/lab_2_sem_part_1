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
        cout << "Имя: " << name << ", Возраст: " << age << ", Специальность: " << major << ", Семестр: " << semester << ", Коммерция: " << tuitionPaid;
    }
};

class ExtendedStudent : public Student {
public:
    string address;
    int studentID;
    string email;

    ExtendedStudent(string n, int a, string m, int s, bool t, string addr, int id, string e) : Student(n, a, m, s, t), address(addr), studentID(id), email(e) {}

    void displayExtendedInfo() const {
        cout << " Адрес: " << address << ", ID студента: " << studentID << ", Email: " << email << endl;
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
    // Добавление, удаление, редактирование и вывод объектов можно осуществить также, как в предыдущем примере, используя методы STL.
    // Пример:
    int menu, age, semester, rename, studentID;
    string nameToDelete, nameToEdit, name, major, email, address;
    bool tuitionPaid;

    do {
        cout << "1 - добавить студента" << endl;
        cout << "2 - удалить студента" << endl;
        cout << "3 - редактировать студента" << endl;
        cout << "4 - вывод информации о всех студентах" << endl;
        cout << "5 - тестирование" << endl;
        cout << "6 - выход" << endl;
        cout << "-------------" << endl;
        cin >> menu;

        if (menu == 1) {
            cout << "Введите Имя студента" << endl;
            cin >> name;
            cout << "Введите возраст студента" << endl;
            cin >> age;
            cout << "Введите название специальности" << endl;
            cin >> major;
            cout << "Введите текущий семестр" << endl;
            cin >> semester;
            cout << "Обучение на коммерции?" << endl;
            cin >> tuitionPaid;
            cout << "Введимте адрес" << endl;
            cin >> address;
            cout << "Введите айди студента" << endl;
            cin >> studentID;
            cout << "Введите адрес почты" << endl;
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

   

    // сортировка допилить
    students.sort([](const ExtendedStudent& a, const ExtendedStudent& b) {
        return a.name < b.name;
        });

    return 0;
}