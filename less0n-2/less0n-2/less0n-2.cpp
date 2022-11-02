//Less0n-2
#include <iostream>
#include<chrono>
#include<fstream>
#include<Windows.h>
#include "lesson2.h"
//#include"Timer.h"

int main()
{
    setlocale(LC_ALL, "RU");

    //-----1-----//
    cout << "---Swap---" << endl;
    int a = 111, b = 222;
    int* aPtr = &a;
    int* bPtr = &b;
    cout << "a = " << *aPtr << ", b = " << *bPtr << endl;
    Swap<int>(aPtr, bPtr);
    cout << "a = " << *aPtr << ", b = " << *bPtr << endl;

    //-----2-----//
    const size_t size = 10;
    vector<int*> myVector;
    myVector.reserve(size);
    for (size_t i = 0; i < size; i++)
    {
        int* element = new int(rand() % 100);
        myVector.push_back(element);
    }
    auto printV = [&myVector]()
    {
        for (const auto n : myVector)
        {
            cout << *n << " ";
        }
        cout << endl;
    };
    //
    printV();
    SortPointers<int>(myVector);
    printV();

    for (auto n : myVector) { delete n; }

    //-----3-----//
    ifstream file("WWv1.txt");
    file.seekg(0, ios::end);
    int sizef = file.tellg();
    file.seekg(0);
    string str(sizef, ' ');
    file.read(&str[0], sizef);
    string vowels = "АЕЁИОУЫЭЮЯаеёиоуэюя";
    int count = 0;

    //---3.1---//
    auto start = chrono::steady_clock::now();
    count = CountIfFind(str, vowels);
    auto end = chrono::steady_clock::now();
    cout << "Найдено " << count << " гласных" << endl;
    chrono::duration<double> time = end - start;
    cout << "CountIfFind time = " << time.count() << " seconds" << endl;

    //---3.2---//
    start = chrono::steady_clock::now();
    count = CountIfFor(str, vowels);
    end = chrono::steady_clock::now();
    cout << "Найдено " << count << " гласных" << endl;
   time = end - start;
    cout << "CountIfFor time = " << time.count() << " seconds" << endl;

    //---3.3---//
    start = chrono::steady_clock::now();
    count = ForFind(str, vowels);
    end = chrono::steady_clock::now();
    cout << "Найдено " << count << " гласных" << endl;
    time = end - start;
    cout << "ForFind time = " << time.count() << " seconds" << endl;

    //---3.4---//
    start = chrono::steady_clock::now();
    count = ForFor(str, vowels);
    end = chrono::steady_clock::now();
    cout << "Найдено " << count << " гласных" << endl;
    time = end - start;
    cout << "ForFor time = " << time.count() << " seconds" << endl;

    return 0;
}
