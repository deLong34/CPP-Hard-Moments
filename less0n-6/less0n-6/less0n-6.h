#pragma once
#include <sstream>
#include <iostream>
#include <mutex>
#include <vector>
#include <chrono>
#include <algorithm>
using namespace std;


//-----1-----//
mutex coutLock;

class pcout
{
public:
	pcout()
	{
		coutLock.lock();
	}
	~pcout()
	{
		coutLock.unlock();
	}
	template <typename T>
	pcout& operator<< (const T& t)
	{
		cout << t;
		return *this;
	}
	pcout& operator<< (ostream& (*fp)(ostream&))
	{
		cout << fp;
		return *this;
	}
};

//-----2------//
boolean isSimple(long nom)
{
	for (int i = 2; i <= nom / 2; i++) if ((nom % i) == 0) return false;
	return true;
};

void findMySimple(long n)
{
	//long n = 100;
	vector<long> simpls;
	simpls.reserve(n);
	long counter = 2;
	long simpleCounter = 0;
	while (simpleCounter < n)
	{
		counter++;
		if (isSimple(counter))
		{
			simpleCounter++;
			pcout{} << "Нашли " << simpleCounter << "-е простое число --> " << counter << endl;
		}
	}
	cout << n << "-ое простое число равно " << counter << endl;
};

//-----3-----//
vector<int> valuables;
mutex mut;
condition_variable cond_val;
int cnt = 0;
//int data;

void ownerPutValuables()
{
	while (cnt < 10)
	{
		int const data = rand() * 100;
		unique_lock<mutex> lk(mut);
		this_thread::sleep_for(500ms);
		valuables.push_back(data);
		cond_val.notify_one();
		cnt++;
		cout << "Положили вещь за " << data << "р." << endl;
		lk.unlock();
	}
}

void thiefStealsValuables()
{
	while (true)
	{
		unique_lock<mutex> lk(mut);
		cond_val.wait(lk, [] {return !valuables.empty(); });
		sort(valuables.begin(), valuables.end());
		int& data = *(valuables.end() - 1);
		valuables.pop_back();
		this_thread::sleep_for(1000ms);
		lk.unlock();
		cout << "Украли вешь, которая стоит " << data << "р. " << endl;
		cnt--;
	}
}
