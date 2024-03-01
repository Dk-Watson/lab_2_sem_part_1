#include "DynamicList.h"

int main(){
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    DynamicList<Student> studentsList;

    int vibor;
    cout << "Для запуска программы введите 1 ";
    cout << "Для теста введите 2 ";
    cin >> vibor;

    if (vibor == 1) {
        cout << "Количество студентов: ";
        int numStudents;
        cin >> numStudents;

        for (int i = 0; i < numStudents; ++i) { //ввод информации в лист
            cout << "Ввод информации о студенте " << i + 1 << ":" << endl;
            Student newStudent;
            cin >> newStudent;
            studentsList.insert(newStudent);
        }

        string searchName; // поиск по листу
        cout << "Введите имя студента для поиска: ";
        cin >> searchName;

        if (studentsList.search(searchName)) {
            cout << searchName << " Есть в списке" << endl;
        }
        else {
            cout << searchName << " Нет в списке" << endl;
        }

        cout << "Удаление первого ученика из списка" << endl;
        studentsList.removeFirst();

        studentsList.saveToFile("students.txt");
    }

    else { // тестирование метода поиска 
        DynamicList<Student> test;
        if (test.testInsert()) {
            cout << "Тестирование поиска завершено успешно" << endl;
        }
        else {
            cout << "Ошибка тестирования" << endl;
        }
    }
    return 0;
}