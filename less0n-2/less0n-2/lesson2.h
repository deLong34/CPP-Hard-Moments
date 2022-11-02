#pragma once
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

//-----1-----//
template<typename T>
void Swap(T* ptr1, T* ptr2)
{
	T p = move(*ptr1);
	*ptr1 = move(*ptr2);
	*ptr2 = move(p);
}

//-----2-----//
template<typename V>
void SortPointers(vector<V*>& vptr)
{
	sort(vptr.begin(), vptr.end(), [](V* left, V* right) { return *left < *right; });
}

//-----3-----//
int CountIfFind(const string& searchLine, const string& searchElements)
{
	return count_if(searchLine.begin(), searchLine.end(), [&searchElements](const char& s)
		{
			return searchElements.find(s) != string::npos;
		}
	);
}

int CountIfFor(const string& searchLine, const string& searchElements)
{
	return count_if(searchLine.begin(), searchLine.end(), [&searchElements](const char& s)
		{
			for (const auto& SE : searchElements)
			{
				if (s == SE) return true;
			}
			return false;
		}
	);
}

int ForFind(const string& searchLine, const string& searchElements)
{
	int count(0);
	for (const auto& s : searchLine)
	{
		if (searchElements.find(s) != string::npos) count++;
	}
	return count;
}

int ForFor(const string& searchLine, const string& searchElements)
{
	int count(0);
	for (const auto& s : searchLine)
	{
		for (const auto& SE : searchElements)
		{
			if (s == SE)
			{
				count++;
				break;
			}
		}
	}
	return count;
}
