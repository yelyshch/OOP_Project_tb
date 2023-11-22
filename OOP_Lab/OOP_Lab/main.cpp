#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <windows.h>
#include "Manager.h"

using std::string;

int DiceRoll(int type_of_roll)
{
    return rand() % 6 + 1;
}

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    return 0;
}