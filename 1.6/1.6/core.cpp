#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;
class Student {
public:
    string name;
    int age;
    // ����������� �� ���������
    Student() {}
    // ����������������� �����������
    Student(string n, int a) : name(n), age(a) {}
    // ����� ��� ���������� ������ � ����
    void saveToFile(string filename) const {
        ofstream file(filename);
        // �������� ��������� �������� �����
        if (file.is_open()) {
            // ������ ������ � ����
            file << name << " " << age << endl;
            file.close();
            cout << "��������� � ����: " << filename << endl;
        }
    }
    // ����� ��� �������� ������ �� �����
    void loadFromFile(string filename) {
        ifstream file(filename);
        // �������� ��������� �������� �����
        if (file.is_open()) {
            // ������ ������ �� �����
            file >> name >> age;
            file.close();
            cout << "��������� �� �����: " << filename << endl;
        }
    }
    // ����� ��� ����������� ������
    void display() const {
        cout << "���: " << name << ", �������: " << age << endl;// ����� ������ �� �����
    }
};
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // �������� ������� Student1 � ���������� ��� � ����
    Student Student1;

    string name;
    int age;
    cout << "���: ";
    cin >> name;
    cout << "�������: ";
    cin >> age;

    Student1 = Student(name, age);
    Student1.saveToFile("Student1.txt");
    // �������� ������� Student2 � �������� ������ �� �����
    Student Student2;
    Student2.loadFromFile("Student1.txt");
    // ����������� ������ ������� Student2
    Student2.display();
    return 0;
}