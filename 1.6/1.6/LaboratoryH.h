#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;

class Student
{
	string LastName;
	string FirstName;
	string Patronymic;
	string Group;
	int Age;
	int Course;

public:
	void Set_LastName(string L)
	{
		LastName = L;
	}
	string Get_LastName() const
	{
		return LastName;
	}

	void Set_FirstName(string F)
	{
		FirstName = F;
	}
	string Get_FirstName() const
	{
		return FirstName;
	}

	void Set_Patronymic(string P)
	{
		Patronymic = P;
	}
	string Get_Patronymic() const
	{
		return Patronymic;
	}

	void Set_Group(string G)
	{
		Group = G;
	}
	string Get_Group() const
	{
		return Group;
	}

	void Set_Age(int A)
	{
		Age = A;
	}
	int Get_Age() const
	{
		return Age;
	}
	void Set_Course(int C)
	{
		Course = C;
	}
	int Get_Course() const
	{
		return Course;
	}


public:

	Student()
	{
		LastName = "";
		FirstName = "";
		Patronymic = "";
		Group = "";
		Age = 0;
		Course = 0;
	}

	Student(string L, string F, string P, string G, int A, int C)
	{
		LastName = L;
		FirstName = F;
		Patronymic = P;
		Group = G;
		Age = A;
		Course = C;
	}

	Student(Student* student)
	{
		LastName = student->LastName;
		FirstName = student->FirstName;
		Patronymic = student->Patronymic;
		Group = student->Group;
		Age = student->Age;
		Course = student->Course;
	}

	~Student()
	{

	}

	void ChangeLastName()
	{
		string LastName_1;
		cout << "введите изменёное имя " << endl;
		cin >> LastName_1;
		LastName = LastName_1;
	}
	void ChangeFirstName()
	{
		string FirstName_1;
		cout << "введите изменёную фамилию " << endl;
		cin >> FirstName_1;
		FirstName = FirstName_1;
	}
	void ChangePatronymic()
	{
		string Patronymic_1;
		cout << "введите изменённое очество " << endl;
		cin >> Patronymic_1;
		Patronymic = Patronymic_1;
	}
	void ChangeGruop()
	{
		string Gruop_1;
		cout << "введите изменёную группу " << endl;
		cin >> Gruop_1;
		Group = Gruop_1;
	}
	void ChangeAge()
	{
		int Age_1;
		cout << "введите изменёный возраст " << endl;
		cin >> Age_1;
		Age = Age_1;
	}
	void ChangeCourse()
	{
		int Course_1;
		cout << "введите изменёный курс " << endl;
		cin >> Course_1;
		Course = Course_1;
	}
};


void NewStudent(Student** student);
bool CheckChoice(string str);
void OutputObject(Student* student);
void СhangeObject(Student* student);
int ConvertStringToInt(string str);
void ReadingFile(Student** student, string LastName);
void ClearFile();
void WriteFile(Student** student);
