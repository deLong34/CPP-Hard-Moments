#include "lesson-1.h"
#include <tuple>
#include <iomanip>
#include <algorithm>
#include <string>

//-----1-----///////////////////////// 
//--Перегружаем оператор вывода <<
ostream& operator<< (ostream& out, const Person& person)
{
	if (person.patronymic.has_value())
	{
		out << setw(12) << person.surname << " " << setw(12) << person.name << setw(15) << person.patronymic.value();
	}
	else
		out << setw(12) << person.surname << " " << setw(12) << person.name;
	return out;
}
//--перегружаем оператор <
bool operator< (const Person& p1, const Person& p2)
{
	return (tie(p1.surname, p1.name, p1.patronymic) < tie(p2.surname, p2.name, p2.patronymic));
}
//--перегружаем оператор ==
bool operator== (const Person& p1, const Person& p2)
{
	return (tie(p1.surname, p1.name, p1.patronymic) == tie(p2.surname, p2.name, p2.patronymic));
}

//-----2-----/////////////////////////
ostream& operator<< (ostream& out, const PhoneNumber& phN)
{
	if (phN.dopNumber.has_value())
	{
		out << "+" << phN.country << "(" << phN.city << ")" << phN.number << "_" << phN.dopNumber.value();
	}
	return out;
};
bool operator< (const PhoneNumber& phN1, const PhoneNumber& phN2)
{
	return (tie(phN1.country, phN1.city, phN1.number, phN1.dopNumber) < tie(phN2.country, phN2.city, phN2.number, phN2.dopNumber));
};


bool operator== (const PhoneNumber& phN1, const PhoneNumber& phN2)
{
	return (tie(phN1.country, phN1.city, phN1.number, phN1.dopNumber) == tie(phN2.country, phN2.city, phN2.number, phN2.dopNumber));
};
//-----3-----/////
//конструктор PhoneBook
PhoneBook::PhoneBook(ifstream& fstr)
{
	string surname, name;
	optional<string> patronymic;
	uint16_t country, city;
	string number;
	optional<string> ext;
	optional<int> extension;
	if (fstr.is_open())
	{
		while (fstr >> surname >> name >> patronymic.emplace() >> country >> city >> number >> ext.emplace())
		{
			if (patronymic.has_value())
				if (patronymic.value() == "-")
					patronymic = nullopt;
			Person person(surname, name, patronymic);
			if (ext.has_value())
				if (ext.value() == "-")
					extension = nullopt;
				else
					extension.emplace() = stoi(ext.value());
			PhoneNumber phN(country, city, number, extension);
			record.push_back(make_pair(person, phN));
		}
	    
	}
	fstr.close();
}

void PhoneBook::SortByName()
{
	Less less;
	sort(record.begin(), record.end(), less);
}

void PhoneBook::SotrByPhone()
{
	Less less(true);
	sort(record.begin(), record.end(), less);
}

tuple<string, PhoneNumber> PhoneBook::GetPhoneNumber(const string& surname)
{
	PhoneNumber number;
	string res = "";
	int count = 0;
	for_each(record.begin(), record.end(), [&](const auto& rec)
		{
			if (rec.first.getSurname() == surname)
			{
				number = rec.second; 
				count++; 
			}
		}
	);
	if (count == 0) res = "Not found";
	else if (count > 1) res = "Found more then 1";
	return make_tuple(res, number);
}

void PhoneBook::ChangePhoneNumber(const Person& person,  const PhoneNumber& phN)
{
	int count = 0;
	for_each(record.begin(), record.end(), [&](auto& rec)
		{
			if (rec.first == person)
			{
				rec.second = phN;
			}
		}
	);
}

ostream& operator<< (ostream& out, PhoneBook phB)
{
	for (auto& rec : phB.record)
	{
		for (auto& [person, number] : phB.record)
		{
			out << rec.first << " " << rec.second << endl;
			out << person << setw(5) << number << endl;
		}
	}
	return out;
}