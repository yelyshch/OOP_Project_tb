#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <windows.h>
#include <iomanip>
#include "Manager.h"

using std::string;
using std::cout;
using std::endl;
using std::setw;

const int N = 5;

void PrintField(Field *MainF, int x, int y){

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if (i == x && j == y) cout << setw(3) << 'p';
            else if(MainF->cells[i][j].hasObstacle()) cout<<setw(3)<<'x';
            else if(MainF->cells[i][j].hasUnitPresent()) cout<<setw(3)<<'m';
            else cout<<setw(3)<<0;
        }
        cout<<endl;
    }
}

void GetHeroData(Hero MainH) {
    cout << "speed=" << MainH.getSpeed()<<endl;
    cout << "damage=" << MainH.getDamage() << endl;
    cout << "protection=" << MainH.getProtection() << endl;
}

void TestLab1(Manager MainM){
    cout<<"Current level="<<MainM.CurrentLevel<<endl;
    MainM.createField(N, N, 2, 1);
    PrintField(MainM.gameField, MainM.Player.getX(), MainM.Player.getY());
    GetHeroData(MainM.Player);
    MainM.Player.move(1, 1, *MainM.gameField);
    cout << "PLayer move(1,1):\n";
    GetHeroData(MainM.Player);
    MainM.Player.diceResults(MainM.DiceRoll(), MainM.DiceRoll(), MainM.DiceRoll());
    PrintField(MainM.gameField, MainM.Player.getX(), MainM.Player.getY());
    GetHeroData(MainM.Player);

}

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Manager MainManager;
    TestLab1(MainManager);
    return 0;
}
