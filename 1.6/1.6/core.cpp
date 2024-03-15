#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;
class Student {
public:
    string name;
    int age;
    // Конструктор по умолчанию
    Student() {}
    // Параметризованный конструктор
    Student(string n, int a) : name(n), age(a) {}
    // Метод для сохранения данных в файл
    void saveToFile(string filename) const {
        ofstream file(filename);
        // Проверка успешного открытия файла
        if (file.is_open()) {
            // Запись данных в файл
            file << name << " " << age << endl;
            file.close();
        }
    }

    // Метод для загрузки данных из файла
    void loadFromFile(string filename) {
        ifstream file(filename);
        // Проверка успешного открытия файла
        if (file.is_open()) {
            // Чтение данных из файла
            file >> name >> age;
            file.close();
        }
    }
    // Метод для отображения данных
    void display() const {
        cout << "Имя: " << name << ", Возраст: " << age << endl;// Вывод данных на экран
    }
};
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Создание объекта Student1 и сохранение его в файл
    Student Student1;

    string name;
    int age;
    cout << "Имя: ";
    cin >> name;
    cout << "Возраст: ";
    cin >> age;

    Student1 = Student(name, age);
    Student1.saveToFile("Student1.txt");

    cout << "Проверка записанных данных:" << endl;
    
    // Создание объекта Student2 и загрузка данных из файла
    Student Student2;
    Student2.loadFromFile("Student1.txt");

    if (Student1.name == Student2.name) {
        if (Student1.age == Student2.age) {
            cout << ("В файл все записалось верно");
        }

    }

    return 0;
}