// less0n-4.cpp

#include <iostream>
#include<list>
#include"less0n-4.h"
#include"Source.cpp"


int main()
{
  //-----1-----//
	cout << "Работа с Функцией insert_sorted:" << endl;
	vector<int> vec{ -5, -3, -2, -1, 0, 2, 3, 6, 7, 9 };
	list<int> list{ -9, -5, -3, -1, 2, 4, 6, 8, 9 };
	printContainer(vec);
	insert_sorted(vec, 1);
	printContainer(vec);
	cout << endl;
	printContainer(list);
	insert_sorted(list, 0);
	printContainer(list);
    cout << endl;

	//-----2-----//
	cout << "Ошибка преобразования сигнала из аналогово в цифровой: " << endl;
	const size_t count = 100;
	vector<double_t> analogSignal(count);
	vector<int64_t> digitalSignal(count);
	generateAnalogSignal(analogSignal);
	copy(analogSignal.begin(), analogSignal.end(), digitalSignal.begin());
	cout << "Аналоговый сигнал: " << endl;
	printContainer(analogSignal);
	cout << endl;
	cout << "Цифровой сигнал: " << endl;
	printContainer(digitalSignal);
	cout << endl;
	cout << "Ошибка преобразования сигнала сотавляет: " << calculateSignalConversionError(analogSignal, digitalSignal) << endl;
    //-----//

	return 0;
}

