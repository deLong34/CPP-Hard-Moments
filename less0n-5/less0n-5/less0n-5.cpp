// less0n-5.cpp 

#include<iostream>
#include<vector>
#include<windows.h>
#include"less0n-5.h"



int main()
{
	setlocale(LC_ALL, "RU");
	//---1---//////////////////////////////////
	cout << "Работа с Функцией printUniqueElements:" << endl;
	vector<string> stringsStr{ "str1", "str2", "str1", "str3", "str4", "str1", "str4", "str5", "str2", "str12" };
	cout << endl;
	cout << "Исходные контейнер типа STRING:" << endl;
	copy(stringsStr.begin(), stringsStr.end(), ostream_iterator<string>(cout, ", "));
	cout << endl;
	cout << "Результат:" << endl;
	printUniqueElements<string>(stringsStr.begin(), stringsStr.end());
	cout << endl;
	list<string> stringsList{ "str1", "str2", "str1", "str3", "str4", "str1", "str4", "str5", "str2", "str12", " ", "str1" };
	cout << endl;
	cout << "Исходный контейнер типа LIST:" << endl;
	copy(stringsList.begin(), stringsList.end(), ostream_iterator<string>(cout, ", "));
	cout << endl;
	cout << "Результат:" << endl;
	printUniqueElements<string>(stringsList.begin(), stringsList.end());
	//---2---//////////////////////////////////////////
	cout << endl;
	cout << "Сортировка предложений по длинне: " << endl;
	cout << "Вставьте свой текст: " << endl;
    cin.unsetf(ios::skipws);
	string txt{ istream_iterator<char>{cin}, {} };
	for (const auto& text : countText(txt))
	{
		int qte = count(text.first.begin(), text.first.end(), ' ') + 1;
		cout << qte << " слов/а: " << text.first << endl;
	}
	
	return 0;
}
