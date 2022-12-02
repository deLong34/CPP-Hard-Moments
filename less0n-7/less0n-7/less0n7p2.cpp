// less0n7p2.cpp 

#include <iostream>
#include <fstream>
#include"myProps.pb.h"
using namespace std;



int main()
{
    StudentGroup SGroup;
    Student St1;
    St1.fname();
    St1.add_ratings(4);
    St1.add_ratings(5);
    St1.add_ratings(5);
    St1.add_ratings(4);
    St1.averagescore();
    Student St2;
    St2.fname();
    St2.add_ratings(3);
    St2.add_ratings(5);
    St2.add_ratings(3);
    St2.add_ratings(4);
    St2.averagescore();

    SGroup.add_students();

    ofstream out("C:\gb\CPP\CPP-Hard-Moments\less0n-7\StudentGroup1.bin", ios_base::binary);
    SGroup.SerialiseToOstream(&out);

    ifstream in("C:\gb\CPP\CPP-Hard-Moments\less0n-7\StudentGroup1.bin", ios_base::binary);
    SGroup.GetAllInfo();

    std::cout << "Hello World!\n";
    return 0;
}
