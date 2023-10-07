#pragma once
#include "Map.h"
#include "Ship.h"
#include <string>
#include <stdlib.h>
using namespace std;
struct Player {
	Player(char status_) : status{ status_ } {

	}
public:
	void createShip(Map* m, int sizeShip) {
		vector<pair<char, int>> data;
		string coord;
		cout << "Добавьте корабль:" << endl;
		for (int i = 0; i < sizeShip; i++) {
			cin >> coord;
			data.push_back({ coord[0], coord.length() < 3 ?  (int)coord[1] - 48 : 10});
		}		
		
		Ship ship = Ship(status, data);
		if (m->add_ship(ship)) {
			system("cls");
			m->show();
			ships.push_back(ship);
			cout << "Корабль успешно добавлен!" << endl;
		}
		else {
			system("cls");
			m->show();
			cout << "Координаты коробля некорректны!" << endl;
			createShip(m, sizeShip);
		}
			
	}
	vector<Ship> ships;		
	char status;
};