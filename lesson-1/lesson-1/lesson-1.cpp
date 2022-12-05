// lesson-1.cpp
#include <Windows.h>
#include <utility>
#include "lesson-1.h"
#include "gtest/gtest-test.h"
#include "src/gtest.h"
#include "myTest.h"

template <typename T, typename U>
void AssertEq(const T& t, const U& u)
{
    if (t != u)
    {
        ostringstream os;
        os << "Assertion failed: " << t << "!=" << u;
        throw runtime_error(os.str());
    }
}

template <typename TestFunc>
void RunTest(TestFunc func, const string& test_name)
{
    try
    {
        func();
        cerr << test_name << " OK" << endl;
    }
    catch (runtime_error& e) 
    {
        cerr << test_name << " FAIL: " << e.what() << endl;
    }
}

int main()
{
    ifstream file("PhoneBook.txt"); // путь к файлу PhoneBook.txt 
    PhoneBook book(file);
    cout << book;
    cout << "------SortByPhone-------" << endl;
    book.SotrByPhone();
    assert(SBPisSorted());

    cout << book;
    cout << "------SortByName--------" << endl;
    book.SortByName();
    assert(SBNisSorted());

    cout << book;
    cout << "-----GetPhoneNumber-----" << endl;
    // лямбда функция, которая принимает фамилию и выводит номер телефона человека, либо строку с ошибкой
    auto print_phone_number = [&book](const string& surname) {
        cout << surname << "\t";
        auto answer = book.GetPhoneNumber(surname);
        if (get<0>(answer).empty())
            cout << get<1>(answer);
        else
            cout << get<0>(answer);
        cout << endl;
    };
    // вызовы лямбды
    print_phone_number("Ivanov");
    RunTest(print_phone_number("Ivanov"), "print_phone_number()");
    print_phone_number("Petrov");
    RunTest(print_phone_number("Petrov"), "print_phone_number()");
    cout << "----ChangePhoneNumber----" << endl;
    book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" },
        PhoneNumber{ 7, 123, "15344458", nullopt });
    book.ChangePhoneNumber(Person{ "Ivanov", "Margarita", "Vladimirovna" },
        PhoneNumber{ 16, 465, "9155448", 13 });
    cout << book;
    return 0;
};
