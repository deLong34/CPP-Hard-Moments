#pragma once
#include <unordered_set>
#include <map>
#include <string>
#include <set>

using namespace std;

//-----1-----//
template <typename Type, typename Iterator>
void printUniqueElements(const Iterator& begin, const Iterator& end)
{
	unordered_set<Type> elements;
	copy(begin, end, inserter(elements, elements.end()));
	copy(elements.begin(), elements.end(), ostream_iterator<Type>(cout, ", "));
}


//-----2-----//
string ignoreSpecSimbols(const string& str)
{
	string ignore("\n\t\r");
	const auto begin = str.find_first_not_of(ignore);
	const auto end = str.find_last_not_of(ignore);
	return (begin != string::npos) ? str.substr(begin, end - begin + 1) : string{};
}

multimap<string, int> countText(string& txt)
{
	multimap<string, int> result;
	auto endItTxt = end(txt);
	auto beginItTxt = begin(txt);
	auto intItTxt = find(beginItTxt, endItTxt, '.');
	while (beginItTxt != endItTxt && distance(beginItTxt, intItTxt))
	{
		string str = ignoreSpecSimbols({ beginItTxt, intItTxt });
		int qte = count(str.begin(), str.end(), ' ') + 1;
		result.insert(make_pair(move(str), qte));
		beginItTxt = next(intItTxt, 1);
		intItTxt = find(beginItTxt, endItTxt, '.');
		if (intItTxt == endItTxt) break;
	}
	return result;
}

//компаратор для сравнения строк
//const auto cmp = [](const string& _left, const string& _right) {
//	return _left.size() < _right.size();
//};
