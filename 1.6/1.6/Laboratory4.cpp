#include "LaboratoryH.h"


int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bool check;
	string strReplay;
	string strMenu;
	Student* student = NULL;
	string LastName;

	cout << "��� ������ ������ ������� - 1" << endl << "��� ������ ������� ����� ������" << endl;
	cin >> strReplay;
	check = CheckChoice(strReplay);

	if (check == false)
	{
		return 0;
	}

	while (stoi(strReplay) == 1)
	{
		cout << "��� �������� ������� ������� - 1" << endl;
		cout << "��� ��������� ��� ���������� ������� ������� - 2" << endl;
		cout << "��� ���������� ������� � ���� ������� - 3" << endl;
		cout << "��� �������� ������� �� ����� ������� - 4" << endl;
		cout << "��� ������� ����� ������� - 5" << endl;
		cout << "��� ������������ ������� - 6" << endl;
		cout << "��� �������� ��������� ������� ����� ������ �������" << endl;
		cin >> strMenu;
		cout << endl;
		check = CheckChoice(strMenu);

		if (check == false)
		{
			return 0;
		}

		switch (stoi(strMenu))
		{
		case 1:
			if (student != nullptr)
			{
				delete student;
				student = nullptr;
			}
			NewStudent(&student);
			OutputObject(student);
			break;
		case 2:
			if (student == nullptr)
			{
				cout << "������� ���" << endl;
				cout << endl;
				continue;
			}
			�hangeObject(student);
			OutputObject(student);
			break;
		case 3:
			if (student == nullptr)
			{
				cout << "������ �� ����������" << endl;
				cout << endl;
				continue;
			}
			WriteFile(&student);
			break;
		case 4:
			if (student != nullptr)
			{
				delete student;
				student = nullptr;
			}
			LastName = "�������";
			ReadingFile(&student, LastName);
			break;
		case 5:
			ClearFile();
			break;
		case 6:
			if (student != nullptr)
			{
				delete student;
				student = nullptr;
			}
			LastName = " �������";
			ReadingFile(&student, LastName);
			OutputObject(student);
			break;
		default:

			return 0;
			break;
		}
	}
}
