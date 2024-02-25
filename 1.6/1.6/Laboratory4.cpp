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

	cout << "Для начала работы нажмите - 1" << endl << "для выхода нажмите любую кнопку" << endl;
	cin >> strReplay;
	check = CheckChoice(strReplay);

	if (check == false)
	{
		return 0;
	}

	while (stoi(strReplay) == 1)
	{
		cout << "для создания объекта нажмите - 1" << endl;
		cout << "для изменения уже созданного объекта нажмите - 2" << endl;
		cout << "для сохранения объекта в файл нажмите - 3" << endl;
		cout << "для загрузки объекта из файла нажмите - 4" << endl;
		cout << "для очистки файла нажмите - 5" << endl;
		cout << "для тестирования нажмите - 6" << endl;
		cout << "для закрытия программы нажмите любую другую клавишу" << endl;
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
				cout << "объекта нет" << endl;
				cout << endl;
				continue;
			}
			СhangeObject(student);
			OutputObject(student);
			break;
		case 3:
			if (student == nullptr)
			{
				cout << "объект не существует" << endl;
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
			LastName = "Николай";
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
			LastName = " Николай";
			ReadingFile(&student, LastName);
			OutputObject(student);
			break;
		default:

			return 0;
			break;
		}
	}
}
