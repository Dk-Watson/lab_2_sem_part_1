#include "class.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); //����������� ��������� ������ � �����

    int size;
    cout << "������� ���������� ��������� ������: ";
    cin >> size;

    int choice_1, choice_2, choice_3;
    cout << "������� 1 ��� ������� ��������, 2 ��� ������� ����������: ";
    cin >> choice_1;

    if (choice_1 == 1) {
        Student* StudArr = new Student[size]; //�������� ������� �������

        cout << "��� ��������� ������ ��������? 1 - �� ����� 2 - ������ ����: ";
        cin >> choice_2;

        if (choice_2 == 1) {
            loadFromFile(StudArr, size); // ���������� � �����
        }

        else {
            loadKeyboard(StudArr, size); // ���������� � ����������
        }

        cout << "������ ��������:" << endl;
        printArray(StudArr, size); // ����� 

        cout << "�������� ��� ������� ������� �������? 1 - ������� 2 - ��������: ";
        cin >> choice_3;

        if (choice_3 == 1) {
            int index;
            cout << "������� ������ ���������� ��������: " << endl;
            cout << "����� �������� - " << size << endl;
            cin >> index;

            removeElement(StudArr, size, index); // �������� ��������

            cout << "������ �������� ����� ��������: " << endl;
            printArray(StudArr, size); // ����� 

            saveToFile(StudArr, size); // ���������� � ����
        }

        else {
            Student* Studvrem = new Student[size];
            loadKeyboard(Studvrem, 1);
            Student NewElementStudArrRedux = Studvrem[0]; // ����� �������
            int NewSize = size + 1;

            Student* StudArrRedux = new Student[NewSize]; // �������� ������ ������� �������
            for (int i = 0; i < size; i++) {
                StudArrRedux[i] = StudArr[i]; // ���������� �������� ������ �������
            }

            StudArrRedux[size] = NewElementStudArrRedux; // ���������� ������ �������� ���������� �������� 

            cout << "������ �������� ����� ����������: " << endl;
            printArray(StudArrRedux, NewSize); // ����� 

            saveToFile(StudArrRedux, NewSize); // ���������� � ����
        }
    }

    if (choice_1 == 2) {
        Student* StudArr = new Student[size];
        cout << "��� ��������� ������ ����������? 1 - �� ����� 2 - ������ ����: ";
        cin >> choice_2;

        if (choice_2 == 1) {
            loadFromFile(StudArr, size); // ���������� � �����
        }

        else {
            loadKeyboard(StudArr, size); // ���������� � ����������

        }

        Student** StudArrPtr = new Student * [size]; // �������� ������� ���������� �������
        for (int i = 0; i < size; i++) {
            StudArrPtr[i] = &StudArr[i];
        }

        cout << "������ ��������:" << endl;
        printArray(*StudArrPtr, size);// ����� 

        cout << "�������� ��� ������� ������� �������? 1 - ������� 2 - ��������: ";
        cin >> choice_3;

        if (choice_3 == 1) {
            int index;
            cout << "������� ������ ���������� ��������: " << endl;
            cout << "����� �������� - " << size << endl;
            cin >> index;
            removeElement(*StudArrPtr, size, index); // �������� ��������

            cout << "������ �������� ����� ��������: " << endl;

            printArray(*StudArrPtr, size); // �����
            saveToFile(*StudArrPtr, size); // ���������� � ����
        }

        else {
            Student* Studvrem = new Student[size];
            loadKeyboard (Studvrem, 1);
            Student NewElementStudArrRedux = Studvrem[0]; // ����� �������
            int NewSize = size + 1;

            Student* StudArrRedux = new Student[NewSize];// �������� ������ ������� 
            for (int i = 0; i < size; i++) {
                StudArrRedux[i] = StudArr[i];
            }

            StudArrRedux[size] = NewElementStudArrRedux; // ���������� ������ �������� ���������� �������� 

            cout << "������ �������� ����� ����������: " << endl;

            printArray(StudArrRedux, NewSize);// �����
            saveToFile(StudArrRedux, NewSize);// ���������� � ����
        }
    }
    return 0;
}
