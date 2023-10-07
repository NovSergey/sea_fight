#include "Map.h"
#include "Player.h"
#include <iostream>
#include "Computer.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    Map map_player = Map();
    Map map_computer = Map();
    auto computer = Computer('0');
    char v;
    cout << "Как будут отображаться ваши корабли: ";
    cin >> v;
    auto player = Player(v);
    int count_ship;
    cout << "Сколько кораблей вы хотите поставить?" << endl;
    cin >> count_ship;
    for (int i = 0; i < count_ship; i++) {

        int size = 0;
        do {
            cout << "Введите размер корабля: ";
            cin >> size;
            if (size < 5 and size > 0) {
                break;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Размер не правильный" << endl;
        } while (true);
        player.createShip(&map_player, size);
    }
    system("cls");    
    map_player.show();
    for (int i = 0; i < 5; i++) {
        int size=3;
        computer.createShip(&map_computer, size);
    }
    map_computer.show();
}


