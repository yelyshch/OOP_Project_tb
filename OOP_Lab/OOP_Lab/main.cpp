#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <windows.h>
#include "Manager.h"

using std::string;
using std::cout;
using std::endl;

void Test(Manager MainM){
    cout<<"Current level="<<MainM.CurrentLevel<<endl;
}

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Manager MainManager;
    Test(MainManager);
    return 0;
}
