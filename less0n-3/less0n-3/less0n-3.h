#pragma once
#include<list>
#include<iostream>
#include<vector>
#include<iomanip>
#include<optional>
#include<string>

using namespace std;

//-----1-----//
void PushBackList(list<double>& lis)
{
	double sum = 0;
	for (const auto& pos : lis)
	{
		sum += pos;
	}
	lis.push_back(sum / lis.size());
}

//-----2-----//
class Matrix
{
public:
	Matrix(istream& strem);
	void PrintMatrix();
	void PrintDet();

protected:
	Matrix(const Matrix& pMatrix, const size_t& stringIndex);
	void Calculate();

private:
	vector<vector<int>> matrix;
	size_t size;
	optional<int> determinant;
	vector<Matrix> minors;

};

//-----3-----//
template<typename T>
class RangeIterator
{
public:
	typedef T RangeType;
	typedef RangeIterator<RangeType> SelfType;
	typedef typename RangeType::ValueType ValueType;

	RangeIterator(RangeType* range, ValueType startValue) : myRange(range), myValue(startValue) {};
	operator ValueType() { return myValue; }
	ValueType operator*() { return myValue; }
	SelfType& operator++()
	{
		myValue += myRange->step();
		return *this;
	}
	SelfType operator++(int)
	{
		SelfType tempIterator(*this);
		++(*this);
		return tempIterator;
	}
	bool operator!=(SelfType& r)
	{
		return !(*this == r);
	}
private:
	RangeType* myRange;
	ValueType myValue;
};

template<typename T> class Range
{
public:
	typedef size_t SizeType;
	typedef T ValueType;
	typedef T RangeType;
	Range(T min, T max, T step = T(1)) : myMin(min), myMax(max), myStep(step) {};
	ValueType operator[](RangeType& i) { return (myMin + (i * myStep));	}
	SizeType size() { return static_cast<SizeType>((myMax - myMin) / myStep); }
	ValueType step() { return myStep;  }
	RangeIterator<Range<T>> begin() { return RangeIterator<Range<T>>(this, myMin); }
	RangeIterator<Range<T>> end() { return RangeIterator<Range<T>>(this, myMin + size() * myStep); }

private:
	T myMin;
	T myMax;
	T myStep;
};
