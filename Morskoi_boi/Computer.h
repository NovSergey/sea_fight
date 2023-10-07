#pragma once
#include "Map.h"
#include "Ship.h"
#include <string>
#include <stdlib.h>
#include "time.h"
using namespace std;
struct Computer {
	Computer(char status_) : status{ status_ } {

	}
private:
	bool check_distance(Ship new_ship) {
		for (auto s : ships) {
			for (auto p : s.position) {
				auto key = p.first;
				if (new_ship.position.count({ key.first + 1, key.second }) > 0)
					return false;
				else if(new_ship.position.count({ key.first - 1, key.second}) > 0)
					return false;
				else if (new_ship.position.count({ key.first, key.second + 1}) > 0)
					return false;
				else if (new_ship.position.count({ key.first, key.second - 1}) > 0)
					return false;
			}
		}
		return true;
	}
public:
	void createShip(Map* m, int sizeShip) {
		srand(time(NULL));
		Ship ship;
		while (m->add_ship(ship) == false or check_distance(ship) == false) {
			vector<pair<char, int>> data;
			pair<char, int> random_point = { rand() % 10 + 65,rand() % 10 + 1 };
			data.push_back(random_point);
			auto random_path = rand() % 2;
			switch (random_path)
			{
			case 0:
				for (int i = 1; i < sizeShip; i++) {
					data.push_back({ random_point.first, random_point.second+i});
				}
				break;
			case 1:
				for (int i = 1; i < sizeShip; i++) {
					data.push_back({ random_point.first+i, random_point.second});
				}
				break;
			default:
				break;
			}
			
			ship = Ship(status, data);

				
		}
		ships.push_back(ship);
	}
	vector<Ship> ships;
	char status;
};