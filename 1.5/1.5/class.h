#include <iostream>  
#include <fstream>  
#include <string>  
#include <windows.h>  

using namespace std;

class Student {  // Класс
public:
    string name;  // Имя
    int age;  // Возраст
    string major;  // Специальность
    bool tuitionPaid;  // Коммерция или нет
    int semester;  // Текущий семестр 

    Student() {  // Конструктор
        name = "Undefined";
        age = -1;
        major = "Undefined";
        tuitionPaid = false;
        semester = 1;
    }

    // Параметризированный конструктор 
    Student(string input_name, int input_age, string input_major, bool input_tuitionPaid, int input_semester)
        : name(input_name), age(input_age), major(input_major), tuitionPaid(input_tuitionPaid), semester(input_semester) {}

    void display() {  // Вывод
        cout << "Имя: " << name << endl << " Возраст: " << age << endl << " Специальность: " << major << endl << " Коммерция: " << tuitionPaid << endl << " Семестр: " << semester << endl;
    }

    void payTuition() {  // Метод оплаты
        tuitionPaid = true;
    }

    void advanceSemester() {  // Перевод на новый семестр
        semester++;
    }

    void changeMajor(string newMajor) {  // Смена специальности
        major = newMajor;
    }
};

void loadFromFile(Student arr[], int size) {  // Загрузка с файла
    ifstream file("students.txt");
    for (int i = 0; i < size; i++) {
        string name, major;
        int age, semester;
        bool tuitionPaid;
        file >> arr[i].name >> arr[i].age >> arr[i].major >> arr[i].tuitionPaid >> arr[i].semester;
    }
    file.close();
}

void loadKeyboard(Student arr[], int size) {  // Ввод с клавиатуры
    for (int i = 0; i < size; i++) {
        string name, major;
        int age, semester;
        bool tuitionPaid;
        cout << "Имя: ";
        cin >> name;
        cout << "Возраст: ";
        cin >> age;
        cout << "Специальности: ";
        cin >> major;
        cout << "Коммерция или нет? : ";
        cin >> tuitionPaid;
        cout << "Семестр: ";
        cin >> semester;
        cout << "--------- " << endl;
        arr[i] = Student(name, age, major, tuitionPaid, semester);
    }
}

void printArray(Student arr[], int size) {  // Вывод
    for (int i = 0; i < size; i++) {
        arr[i].display();
    }
}

void removeElement(Student arr[], int& size, int index) {  // Удаление элемента
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

void saveToFile(Student arr[], int size) {  // Сохранение в файл
    ofstream file("file_students.txt");
    for (int i = 0; i < size; i++) {
        file << arr[i].name << " " << arr[i].age << " " << arr[i].major << " " << arr[i].tuitionPaid << " " << arr[i].semester << endl;
    }
    file.close();
}

void saveArrayToFile(Student* arr[], int size, string filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < size; i++) {
            file << arr[i]->name << " " << arr[i]->age << arr[i]->major << arr[i]->tuitionPaid << arr[i]->semester << endl;
        }
        file.close();
        cout << "Сохранено в файл: " << filename << endl;
    }
    else {
        cout << "Ошибка при открытии файла для записи" << endl;
    }
}

void loadArrayFromFile(Student* arr[], int size, string filename) {
    ifstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < size; i++) {
            file >> arr[i]->name >> arr[i]->age >> arr[i]->major >> arr[i]->tuitionPaid >> arr[i]->semester;
        }
        file.close();
        cout << "Загружено из файла: " << filename << endl;
    }
    else {
        cout << "Ошибка при открытии файла для загрузки" << endl;
    }
}

void displayArray(Student* arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i]->display();
    }
}