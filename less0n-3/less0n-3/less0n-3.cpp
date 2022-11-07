// less0n-3.cpp 
#include"less0n-3.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    //---1---//
    cout << "Добавляем в список среднее арифметическое: " << endl;
    list<double> List{ 0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 1100.99 };
    PushBackList(List);
    for (const auto& i : List)
    {
        cout << i << ", ";
    }
    cout << endl;

    //---2---//
    cout << "Класс Матрица: " << endl;
    Matrix matrix(cin);
    matrix.PrintMatrix();
    matrix.PrintDet();

    //---3---//
    cout << "Пробуем Range: " << endl;
    for (const auto& i : Range<int> (5, 15))
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Пробуем Range еще раз с дабл: " << endl;
    for (const auto& i : Range<double>(5.1, 15.5, 0.1))
    {
        cout << i << " ";
    }
    cout << endl;


    cout << "Hello World!\n";
}
