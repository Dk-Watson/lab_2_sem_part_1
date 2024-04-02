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
        cout << "5 - Сортировка" << endl;
        cout << "6 - Тестирование" << endl;
        cout << "7 - выход" << endl;
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
            cout << "Введите адрес" << endl;
            cin >> address;
            cout << "Введите айди студента" << endl;
            cin >> studentID;
            cout << "Введите адрес почты" << endl;
            cin >> email;
            students.push_back(ExtendedStudent(name, age, major, semester, tuitionPaid, address, studentID, email));
        }

        if (menu == 2) {
            cout << "Введите имя какого студента удалить" << endl;
            cin >> nameToDelete;
            auto it = find_if(students.begin(), students.end(), [nameToDelete](const ExtendedStudent& student) {
                return student.name == nameToDelete;
                });

            // Если студент найден - удаляем
            if (it != students.end()) {
                students.erase(it);
                cout << "Студент успешно удален" << endl;
            }
            else {
                cout << "Студент с таким именем не найден" << endl;
            }
        }

        if (menu == 3) {
            cout << "Введите какого студента отредактировать" << endl;
            cin >> nameToEdit;

            cout << "Что изменить" << endl;
            cout << "1 - Имя" << endl;
            cout << "2 - Возраст" << endl;
            cout << "3 - Специальность" << endl;
            cout << "4 - Семестр" << endl;
            cout << "5 - Тип обучения" << endl;
            cout << "6 - Адрес" << endl;
            cout << "7 - ID" << endl;
            cout << "8 - Почту" << endl;
            cin >> rename;

            auto it = find_if(students.begin(), students.end(), [nameToEdit](const ExtendedStudent& student) {
                return student.name == nameToEdit;
                });

            if (rename == 1) {
                string newName;
                cout << "Введите новое имя" << endl;
                cin >> newName;
                it->name = newName;
            }

            if (rename == 2) {
                int newAge;
                cout << "Введите новый возраст" << endl;
                cin >> newAge;
                it->age = newAge;
            }

            if (rename == 3) {
                string newMajor;
                cout << "Введите новую специальность" << endl;
                cin >> newMajor;
                it->major = newMajor;
            }

            if (rename == 4) {
                int newSemester;
                cout << "Введите новый семестр" << endl;
                cin >> newSemester;
                it->semester = newSemester;
            }

            if (rename == 5) {
                bool newTuitionPaid;
                cout << "Обновите тип обучения" << endl;
                cin >> newTuitionPaid;
                it->tuitionPaid = newTuitionPaid;
            }

            if (rename == 6) {
                string newAddress;
                cout << "Введите новый адрес" << endl;
                cin >> newAddress;
                it->address = newAddress;
            }

            if (rename == 7) {
                int newStudentID;
                cout << "Введите новый StudentID" << endl;
                cin >> newStudentID;
                it->studentID = newStudentID;
            }

            if (rename == 8) {
                string newEmail;
                cout << "Введите новую почту" << endl;
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
            Student student1("Иванов", 20, "Математика", 3, true);

            // Тестирование метода display класса Student

            if (student1.name == "Иванов" and student1.age == 20 and student1.major == "Математика" and student1.semester == 3 and student1.tuitionPaid == true) {
                cout << "Метод display класса Student работает верно " << endl;
            }

            else {
                cout << "Метод display класса Student работает не верно" << endl;
            }

            // Тестирование класса ExtendedStudent
            ExtendedStudent student2("Петров", 22, "Физика", 4, false, "Адрес1", 12345, "petrov@example.com");

            // Тестирование метода displayExtendedInfo класса ExtendedStudent
            if (student2.name == "Петров" and student2.age == 22 and student2.major == "Физика" and student2.semester == 4 and student2.tuitionPaid == false
                and student2.address == "Адрес1" and student2.studentID == 12345 and student2.email == "petrov@example.com") {
                cout << "Метод display класса ExtendedStudent работает верно " << endl;
            }

            else {
                cout << "Метод display класса ExtendedStudent работает не верно" << endl;
            }

            // Тестирование метода editAddress класса ExtendedStudent
            student2.editAddress("Новый Адрес");
            if (student2.address == "Новый Адрес") {
                cout << "Метод editAddress класса ExtendedStudent работает верно " << endl;
            }
            else {
                cout << "Метод editAddress класса ExtendedStudent работает не верно " << endl;
            }
        }
    } while (menu != 7);

    return 0;
}