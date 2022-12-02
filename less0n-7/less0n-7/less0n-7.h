#pragma once
#include <string>
#include <iostream>
#include <optional>
#include <vector>
#include <fstream>

using namespace std;

class FullName
{
public:
	FullName() 
	{
		name = nullptr;
		surname = nullptr;
		if (patronomic)
		{
			patronomic = nullptr;
		}
	};
	~FullName();
	string getSurname() const { return surname; };

	friend bool operator< (const FullName& p1, const FullName& p2);
	friend bool operator== (const FullName& p1, const FullName& p2);
	friend ostream& operator<< (ostream& out, const FullName& person);

private:
	char* name;
	char* surname;
	optional<char*> patronomic;
};

ostream& operator<< (ostream& out, const FullName& person)
{
	if (person.)
	{

	}
}






class Student {
public:

private:
	FullName fName;
	vector<int> ratings;
	float averageScore;
};

class StudentGroup {
public:
	//---------------------------//
	class IRepository
	{
	public:
		//IRepository();
		//~IRepository();
		virtual void Open() = 0; //десериализация из файла
		virtual void Save() = 0; //сериализация в файл
	private:
	};
	//---------------------------//
	class IMethods
	{
	public:
		//IMethods();
		//~IMethods();
		virtual double GetAverageScore(const FullName& name) = 0;
		virtual string GetAllInfo(const FullName& name) = 0;
		virtual string GetAllInfo() = 0;

	private:

	};
	//------------------------------//

private:
	//Student* studentsArray = Student[10];
};

