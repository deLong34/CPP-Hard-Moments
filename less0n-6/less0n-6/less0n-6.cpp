// less0n-6.cpp
#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>
#include "less0n-6.h"

int main()
{
	setlocale(LC_ALL, "RUS");

	//-----1-----//
	cout << "Работаем с cout:" << endl;
	const size_t countThreads = 8;
	vector<thread> threads;
	threads.reserve(countThreads);
	for (size_t i = 0; i < countThreads; i++)
	{
		threads.emplace_back([=]() {
			cout << "запуск потока " << i << ", его id: " << this_thread::get_id() << endl;
			});
	}
	for (auto& i : threads) i.join();

	cout << endl;
	cout << "Работаем с потокобезопасным pcout:" << endl;
	threads.clear();
	for (size_t i = 0; i < countThreads; i++)
	{
		threads.emplace_back([=]() {
			pcout{} << "запускаем безопасный поток " << i << ", его id: " << this_thread::get_id() << endl;
			});
	}
	for (auto& i : threads) i.join();
    cout << endl;

	//-----2-----//
	long pos;
	cout << "Введите, какое по счету простое число Вы хотели бы увидеть? ";
	cin >> pos;
	thread t1(findMySimple, pos);
	t1.join();

	//-----3-----//
	thread t11(ownerPutValuables);
	thread t22(thiefStealsValuables);
	t11.join();
	t22.join();

	return 0;
}
