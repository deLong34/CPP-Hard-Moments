#pragma once
#include <optional>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
//-----1-----//////
class Person
{
private:
	string  surname, name;
	optional<string> patronymic;

public:
	Person(const string& s, const string& n, const optional<string>& p) : surname(s), name(n), patronymic(p) {};
	string getSurname() const { return surname; };

	friend bool operator< (const Person& p1, const Person& p2);
	friend bool operator== (const Person& p1, const Person& p2);
	friend ostream& operator<< (ostream& out, const Person& person);
};

//-----2-----/////
class PhoneNumber
{
private:
	uint16_t country, city;
	string number;
	optional<uint16_t> dopNumber;

public:
	PhoneNumber() = default;
	PhoneNumber(uint16_t co, uint16_t ci, const string& n, const optional<uint16_t>& d) : country(co), city(ci), number(n), dopNumber(d)
	{};

	friend ostream& operator<< (ostream& out, const PhoneNumber& phN);
	friend bool operator< (const PhoneNumber& phN1, const PhoneNumber& phN2);
	friend bool operator== (const PhoneNumber& phN1, const PhoneNumber& phN2);
};
//-----3-----/////
class PhoneBook
{
public:
	PhoneBook(ifstream& fStr);
	void SortByName();
	void SotrByPhone();
	tuple<string, PhoneNumber> GetPhoneNumber(const string& surname);
	void ChangePhoneNumber(const Person& person, const PhoneNumber& phN);
	friend ostream& operator<< (ostream& out, PhoneBook phB);
private:
	vector<pair<Person, PhoneNumber>> record;
};

class Less
{
private:
	bool sortByPhone;
public:
	Less(bool flag = false) : sortByPhone(flag)
	{};
	
	bool operator() (const pair<Person, PhoneNumber>& left, const pair<Person, PhoneNumber>& right)
	{
		if (left.first == right.first || sortByPhone)
			return left.second < right.second;
		else return left.first < right.first;
	}
};

