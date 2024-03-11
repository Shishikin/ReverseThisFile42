#include <iostream>
#include <fstream>
#ifdef _WIN32
#include <windows.h>
#endif
int main()
{
#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::ifstream in;
    in.open(__FILE__);    
    if (!in.is_open() && in.fail())
    {
        std::cout << "error";
    } 

    char ch;    
    in.seekg(0, std::ios::end);
    int flag = 0;
    int position = in.tellg();
    for (int i = position - 1; i >= 3; i--)
    {
        in.seekg(i, std::ios::beg);
        in.get(ch);
        if (ch != '\n')
        {
            std::cout << ch;
        }  
        else
        {
            if (flag % 2 == 0)
            {
                std::cout << ch;
            }
            flag++;
        }
    }
    in.close();
#else
    std::ifstream in;
    in.open(__FILE__);
    if (!in.is_open() && in.fail())
    {
        std::cout << "error";
    }
    char ch;
    in.seekg(0, std::ios::end);
    int position = in.tellg();
    for (int i = position - 1; i >= 3; i--)
    {
        in.seekg(i, std::ios::beg);
        in.get(ch);
        std::cout << ch;
    }
    in.close();
#endif    
    return 0;
}