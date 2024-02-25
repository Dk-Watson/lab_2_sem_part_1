#include "class.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); //локализация командной строки и ввода

    int size;
    cout << "Введите количество элементов класса: ";
    cin >> size;

    int choice_1, choice_2, choice_3;
    cout << "Введите 1 для массива объектов, 2 для массива указателей: ";
    cin >> choice_1;

    if (choice_1 == 1) {
        Student* StudArr = new Student[size]; //создание массива классов

        cout << "Как заполнить массив объектов? 1 - из файла 2 - ручной ввод: ";
        cin >> choice_2;

        if (choice_2 == 1) {
            loadFromFile(StudArr, size); // заполнение с файла
        }

        else {
            loadKeyboard(StudArr, size); // заполнение с клавиатуры
        }

        cout << "Массив объектов:" << endl;
        printArray(StudArr, size); // вывод 

        cout << "Добавить или удалить элемент массива? 1 - удалить 2 - добавить: ";
        cin >> choice_3;

        if (choice_3 == 1) {
            int index;
            cout << "Введите индекс удаляемого элемента: " << endl;
            cout << "Всего индексов - " << size << endl;
            cin >> index;

            removeElement(StudArr, size, index); // удаление элемента

            cout << "Массив объектов после удаления: " << endl;
            printArray(StudArr, size); // вывод 

            saveToFile(StudArr, size); // сохранение в файл
        }

        else {
            Student* Studvrem = new Student[size];
            loadKeyboard(Studvrem, 1);
            Student NewElementStudArrRedux = Studvrem[0]; // новый элемент
            int NewSize = size + 1;

            Student* StudArrRedux = new Student[NewSize]; // создание нового массива классов
            for (int i = 0; i < size; i++) {
                StudArrRedux[i] = StudArr[i]; // присвоение значений новому массиву
            }

            StudArrRedux[size] = NewElementStudArrRedux; // присвоение нового значения последнему элементу 

            cout << "Массив объектов после добавления: " << endl;
            printArray(StudArrRedux, NewSize); // вывод 

            saveToFile(StudArrRedux, NewSize); // сохранение в файл
        }
    }

    if (choice_1 == 2) {
        Student* StudArr = new Student[size];
        cout << "Как заполнить массив указателей? 1 - из файла 2 - ручной ввод: ";
        cin >> choice_2;

        if (choice_2 == 1) {
            loadFromFile(StudArr, size); // заполнение с файла
        }

        else {
            loadKeyboard(StudArr, size); // заполнение с клавиатуры

        }

        Student** StudArrPtr = new Student * [size]; // создание массива указателей классов
        for (int i = 0; i < size; i++) {
            StudArrPtr[i] = &StudArr[i];
        }

        cout << "Массив объектов:" << endl;
        printArray(*StudArrPtr, size);// вывод 

        cout << "Добавить или удалить элемент массива? 1 - удалить 2 - добавить: ";
        cin >> choice_3;

        if (choice_3 == 1) {
            int index;
            cout << "Введите индекс удаляемого элемента: " << endl;
            cout << "Всего индексов - " << size << endl;
            cin >> index;
            removeElement(*StudArrPtr, size, index); // удаление элемента

            cout << "Массив объектов после удаления: " << endl;

            printArray(*StudArrPtr, size); // вывод
            saveToFile(*StudArrPtr, size); // сохранение в файл
        }

        else {
            Student* Studvrem = new Student[size];
            loadKeyboard (Studvrem, 1);
            Student NewElementStudArrRedux = Studvrem[0]; // новый элемент
            int NewSize = size + 1;

            Student* StudArrRedux = new Student[NewSize];// создание нового массива 
            for (int i = 0; i < size; i++) {
                StudArrRedux[i] = StudArr[i];
            }

            StudArrRedux[size] = NewElementStudArrRedux; // присвоение нового значения последнему элементу 

            cout << "Массив объектов после добавления: " << endl;

            printArray(StudArrRedux, NewSize);// вывод
            saveToFile(StudArrRedux, NewSize);// сохранение в файл
        }
    }
    return 0;
}
