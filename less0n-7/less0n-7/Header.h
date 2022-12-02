#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <optional>
#include <array>
#include <vector>
using namespace std;

class FullName
{
private:
    char* name;
    char* surname;
    optional<char*> patronomic;
public:
    FullName()
    {
        name = nullptr;
        surname = nullptr;
        if (patronomic)
        {
            patronomic = nullptr;
        }
    };
    FullName(char* _name, char* _surname, char* _patronomic)
    {
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
        surname = new char[strlen(_surname) + 1];
        strcpy(surname, _surname);
        if (patronomic)
        {
            patronomic = new char[strlen(_patronomic) + 1];
            strcpy(patronomic, _patronomic);
        } 
    };
    ~FullName()
    {
        if (name != NULL)
            delete[] name;
        if (surname != NULL)
            delete surname;
        if (patronomic != NULL)
            delete patronomic;
    };
    void SetName(char* _name)
    {
        name = _name;
    };
};


class Student
{
private:
    FullName FName;
    int ratings[20];
    double averageScore;
public:
    Student()
    {
        FName = FullName();
        for (size_t i = 0; i < 20; i++)
        {
            ratings[i] = NULL;
        }
        averageScore = 0;
    }


    Student(char* _name, char* _surname, optional<char*> _petronomic)
    {
        FullName(_name, _surname, _patronomic);
    };

    ~Student();
    void set_info()
    {
        char* _name;
        char* _surname;
        char* _patr;
        cout << endl << "Enter name : ";
        cin >> _name;
        cout << "Enter surname : ";
        cin >> _surname;
        cout << "Enter patronomic : ";
        cin >> _patr;
        Student(_name, _surname, _patr);
        cout << endl;
    }
    void print_info()
    {
        cout << endl << "Name : " << FullMame.name << endl;
        cout << "Surname : " << FullName.surname << endl;
        cout << "Patronomic : " << FullName.patronomic << endl;
        cout << "AverageScore : " << averageScore << endl;
    }
};

class StudentGroup
{
private:
    Student* students;
    int count;
    int num;
public:
    StudentGroup()
    {
        int count = 0;
        Student* students = nullptr;
    };
    ~StudentGroup()
    {
        if (students != nullptr)
            delete[] students;
    }
    void print_menu();
    int menu_choice();
    void add_student();
    void change_student();
    void del_student();
    void del_student_by_no();
    void save_info();
    void load_info();
    void print_info();
    void Exit();
};

void StudentGroup::print_menu()
{
    cout <<
        "================================================== \n"
        "1 - Add new student\n"
        "2 - Delete information about some student by index \n"
        "3 - Delete information about all students\n"
        "4 - Change information about student by index\n"
        "5 - See information about all students\n"
        "6 - Save current list in file\n"
        "7 - Load current list from file\n"
        "8 - Exit\n"
        "================================================== \n";
}

int StudentGroup::menu_choice()
{
    cout << "Your choose: " << flush;

    char key;
    do
    {
        key = _getch();
    } while (key < '0' || key > '9');

    cout << key << endl << endl;

    return key - '0';
}

void StudentGroup::add_student()
{
    cout << "=================================== \n";
    cout << "Enter information about new student \n";
    cout << "=================================== \n";
    Student* tmp = new Student[count + 1];
    for (int i = 0; i < count; i++)
    {
        tmp[i] = students[i];
    }
    delete[] students;
    students = tmp;
    students[count].Student::set_info();
    count++;
}

void StudentGroup::change_student()
{
    cout << "========================================== \n";
    cout << " Change information about student by index \n";
    cout << "========================================== \n";
    cout << "Enter student's index in list: ";
    cin >> num;

    if (num > 0 && num <= count)
    {
        students[num - 1].set_info();
    }
    else
        cout << "List is empty!!!" << endl;
}

void StudentGroup::del_student()
{
    cout << "===================================== \n";
    cout << "Delete information about all students \n";
    cout << "===================================== \n";

    delete[] students;
    students = nullptr;
    count = 0;

    cout << " All information deleted.\n\n";
}

void StudentGroup::del_student_by_no()
{
    cout << "============================================== \n";
    cout << "Delete information about some student by index \n";
    cout << "============================================== \n";
    cout << "Enter student's index in list: ";
    cin >> num;

    if (num > 0 && num <= count)
    {
        num--;

        if (count == 1)
        {
            delete[] students;
            students = nullptr;
        }
        else
        {
            Student* tmp = new Student[count - 1];
            for (int i = 0; i < num; i++)
                tmp[i] = students[i];

            for (int i = num + 1; i < count; i++)
                tmp[i - 1] = students[i];

            delete[] students;
            students = tmp;
        }
        count--;

        cout << "Information deleted.\n\n";
    }
    else
        cout << "List is empty!!!" << endl;
}

void StudentGroup::save_info()
{
    FILE* stream;

    if ((stream = fopen("StudentsList.dat", "wb")) == NULL)
    {
        cout << "Cannot open file!\n";
        return;
    }

    fwrite(&count, sizeof(count), 1, stream);
    fwrite(students, sizeof(students[0]), count, stream);

    if (ferror(stream))
        cout << "Cannot save array to file!\n";
    else
        cout << "Array was successfully saved to file!\n";

    fclose(stream);
}

void StudentGroup::load_info()
{
    FILE* stream;

    if ((stream = fopen("StudentsList.bin", "rb")) == NULL)
    {
        cout << "Cannot open file!\n";
        return;
    }
    int newArraySize;
    fread(&newArraySize, sizeof(newArraySize), 1, stream);

    if (count != newArraySize)
    {
        delete[] students;
        students = new Student[newArraySize];
        count = newArraySize;
    }

    fread(students, sizeof(students[0]), count, stream);

    if (ferror(stream))
        cout << "Cannot correctly load array from file!\n";
    else
        cout << "Array was successfully loaded from file!\n";

    fclose(stream);
}

void StudentGroup::print_info()
{
    cout << "=================================== \n";
    cout << " See information about students \n";
    cout << "=================================== \n";

    if (count > 0)
    {
        for (int i = 0; i < count; i++)
        {
            cout << "\t\tStudent #" << i + 1;
            students[i].print_info();
        }
    }
    else
    {
        cout << "List is empty!!!" << endl;
    }
}

void StudentGroup::Exit()
{
    if (count > 0)
        delete[] students;
    exit(0);
    return;
}