#include <iostream> 
#include <fstream>

#ifdef _WIN32
#include <windows.h>
#endif


int main()
{
#ifdef _WIN32
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif

    std::ifstream in;
    in.open("ReverseThisFile.cpp");
    if (!in.is_open())
    {
        std::cout << "error";
    }

    char test = '0';
    int count = 0;
    
    while (!in.eof())
    {
        in.get(test);
        count++;
    }
    in.close();
    in.open("ReverseThisFile.cpp");
    if (!in.is_open())
    {
        std::cout << "error";
    }///uyfuy
    for (int i = count + 42; i >= 3; i --)
    {
        in.seekg(i, std::ios::beg);
        in.get(test);
        std::cout << test;
    }                       
    in.close();
    return 0;
}
