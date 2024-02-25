#include "LaboratoryH.h"

void ReadingFile(Student** student, string LastName)
{
	*student = new Student();
	bool check = false;
	string newOnTrip;
	string patronymic;
	string group;
	string age;
	string course;
	ifstream ifFile;
	string str;
	bool checkStudentInFile = false;
	ifFile.open("Laboratory4.txt");
	if (ifFile.is_open())
	{
		getline(ifFile, str);
		if (str == "")
		{
			cout << "файл пустой" << endl;
			return;
		}
		do
		{
			if (str.find(LastName) != -1)
			{
				checkStudentInFile = true;
				(*student)->Set_LastName(LastName);
				getline(ifFile, str);
				(*student)->Set_FirstName(newOnTrip);
				getline(ifFile, str);
				(*student)->Set_Patronymic(patronymic);
				getline(ifFile, str);
				(*student)->Set_Group(group);
				getline(ifFile, str);
				(*student)->Set_Age(ConvertStringToInt(str));
				getline(ifFile, str);
				(*student)->Set_Course(ConvertStringToInt(str));
				getline(ifFile, str);


				break;
			}
			getline(ifFile, str);
		} while (!ifFile.eof());
	}
}

bool CheckChoice(string str)
{
	int i;
	bool check = true;
	for (i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			check = false;
		}
	}
	return check;
}

void ClearFile()
{
	ofstream file;
	file.open("laboratory4.txt");
	if (file.is_open())
	{
		cout << "файл отчищен" << endl << endl;
	}
	file.close();
}


void NewStudent(Student** student)
{
	string L;
	string F;
	string P;
	string G;
	int A;
	int C;


	cout << "введите имя: ";
	cin >> L;
	cout << "введите фамилию: ";
	cin >> F;
	cout << "введите отчество: ";
	cin >> P;
	cout << "введите группу: ";
	cin >> G;
	cout << "введите возраст: ";
	cin >> A;
	cout << "введите курс: ";
	cin >> C;


	*student = new Student(L, F, P, G, A, C);
}

void OutputObject(Student* student)
{
	cout << "имя: " << student->Get_LastName() << endl;
	cout << "фамилия: " << student->Get_FirstName() << endl;
	cout << "отчество: " << student->Get_Patronymic() << endl;
	cout << "группа: " << student->Get_Group() << endl;
	cout << "возраст: " << student->Get_Age() << endl;
	cout << "курс: " << student->Get_Course() << endl;
	cout << endl;
}

void СhangeObject(Student* student)
{
	int element = -1;

	cout << "выберите элемент которому хотели бы поменять значение " << endl;
	cout << "имя - нажмите 1" << endl;
	cout << "фамилия - нажмите 2" << endl;
	cout << "отчество - нажмите 3" << endl;
	cout << "группа - нажмите 4" << endl;
	cout << "возраст - нажмите 5" << endl;
	cout << "курс - нажмите 6" << endl;
	cout << "для отмены нажмите на клавишу с любым другим числом" << endl;
	cin >> element;

	switch (element)
	{
	case 1:
		student->ChangeLastName();
		cout << "имя изменено" << endl;
		break;
	case 2:
		student->ChangeFirstName();
		cout << "фамилия изменена" << endl;
		break;

	case 3:
		student->ChangePatronymic();
		cout << "отчество изменено" << endl;
		break;

	case 4:
		student->ChangeGruop();
		cout << "группа изменена" << endl;
		break;

	case 5:
		student->ChangeAge();
		cout << "возраст изменён" << endl;
		break;

	case 6:
		student->ChangeCourse();
		cout << "курс изменён" << endl;
		break;

	default:
		cout << "изменений нет" << endl;
		break;
	}
	cout << endl;
}

void WriteFile(Student** student)
{
	ifstream fileIf;
	string counterStr;
	int quantitystr = 0;
	int i;
	int counter = 0;
	fileIf.open("laboratory4.txt");
	if (fileIf.is_open())
	{
		while (!fileIf.eof())
		{
			getline(fileIf, counterStr);
			quantitystr++;
		}
		quantitystr -= 7;
		fileIf.close();
		fileIf.open("laboratory4.txt");
		if (fileIf.is_open())
		{
			for (i = 0; i < quantitystr; i++)
			{
				getline(fileIf, counterStr);
			}
			if (counterStr == "")
			{
				counter = 1;
			}
			else
			{
				counter = stoi(counterStr);
				counter++;
			}
		}
	}
	fileIf.close();

	ofstream fileOf;
	fileOf.open("laboratory4.txt", ios::app);
	if (fileOf.is_open())
	{
		fileOf << counter << ") ";
		fileOf << "имя: " << (*student)->Get_LastName() << endl;
		fileOf << "фамилия: " << (*student)->Get_FirstName() << endl;
		fileOf << "отчество: " << (*student)->Get_Patronymic() << endl;
		fileOf << "группа: " << (*student)->Get_Group() << endl;
		fileOf << "возраст: " << (*student)->Get_Age() << endl;
		fileOf << "курс: " << (*student)->Get_Course() << endl;
		fileOf << endl;
	}
	fileOf.close();
}

int ConvertStringToInt(string str)
{
	int numberInt;
	string numberStr;
	int i;
	for (i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]))
		{
			numberStr += str[i];
		}
	}

	numberInt = stoi(numberStr);

	return numberInt;
}
