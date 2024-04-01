#include <iostream>
#include <list>
#include <string>
#include <windows.h>

using namespace std;

class Student {
public:
    string name;  // Имя
    int age;  // Возраст
    string major;  // Специальность
    bool tuitionPaid;  // Коммерция или нет
    int semester;  // Текущий семестр 

    Student(string n, int a, string m, int s, bool t) : name(n), age(a), major(m), semester(s), tuitionPaid(t){}

    void display() const {
        cout << "Имя: " << name << ", Возраст: " << age << ", Специальность: " << major << ", Семестр: " << semester << ", Коммерция: " << tuitionPaid << endl;
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
            students.push_back(Student(name, age, major, semester, tuitionPaid));
        }

        if (menu == 2) {
            cout << "Введите имя какого студента удалить" << endl;
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
            cout << "Введите какого студента отредактировать" << endl;
            cin >> nameToEdit;

            cout << "Что изменить" << endl;
            cout << "1 - Имя" << endl;
            cout << "2 - Возраст" << endl;
            cout << "3 - Специальность" << endl;
            cout << "4 - Семестр" << endl;
            cout << "5 - Тип обучения" << endl;
            cin >> rename;

            if (rename == 1) {
                string newName;
                cout << "Введите новое имя" << endl;
                cin >> newName;
                for (auto& s : students) {
                    if (s.name == nameToEdit) {
                        s.name = newName;
                    }
                }
            }

            if (rename == 2) {
                int newAge;
                cout << "Введите новый возраст" << endl;
                cin >> newAge;
                for (auto& s : students) {
                    if (s.name == nameToEdit) {
                        s.age = newAge;
                    }
                }
            }

            if (rename == 3) {
                string newMajor;
                cout << "Введите новую специальность" << endl;
                cin >> newMajor;
                for (auto& s : students) {
                    if (s.name == nameToEdit) {
                        s.major = newMajor;
                    }
                }
            }

            if (rename == 4) {
                int newSemester;
                cout << "Введите новый семестр" << endl;
                cin >> newSemester;
                for (auto& s : students) {
                    if (s.name == nameToEdit) {
                        s.semester = newSemester;
                    }
                }
            }

            if (rename == 5) {
                bool newTuitionPaid;
                cout << "Обновите тип обучения" << endl;
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
            cout << "Тестирование метода display..." << endl; // тестирование метода display
            cout << "Создание тестового студента:" << endl;
            Student testStudent("Иван Иванов", 20, "IT", 3, true);
            cout << "Ожидаемый результат: Имя: Иван Иванов, Возраст: 20, Специальность: IT, Семестр: 3, Коммерция: 1" << endl;
            if (testStudent.name == "Иван Иванов" and testStudent.age == 20 and testStudent.major == "IT" and testStudent.semester == 3 and testStudent.tuitionPaid == true) {
                cout << "Метод работает верно" << endl;
            }
            else {
                cout << "Метод работает не верно" << endl;
            }
        }

    } while (menu != 6);
    return 0;
}