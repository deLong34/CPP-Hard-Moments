#pragma once
#include<algorithm>
#include<vector>
#include <iostream>
#include <string>
#include <optional>

using namespace std;


template <typename Container, typename Value>
void insert_sorted(Container& cont, const Value& val)
{
	auto it = upper_bound(cont.begin(), cont.end(), val);
	cont.insert(it, val);
}

template<typename T>
void printVect(const vector<T>& vec)
{
	cout << "Количество элементов : " << vec.size() << endl;
	for (auto i : vec)
	{
		cout << i << ' ';
	}
	cout << endl;
}

template<typename T>
void printContainer(const T& cont)
{
	const size_t size = cont.size();
	for_each(cont.begin(), cont.end(), [count = 0, &size](const auto& i) mutable
	{
		count++;
		cout << i;
		if (count != size) cout << ", ";
	});
	cout << endl;
}