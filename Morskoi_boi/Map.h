#pragma once
#include <map>
#include <iostream>
#include "Ship.h"
using namespace std;


struct Map
{
	Map()
	{		
			for (auto s: rows)
			{
				for (size_t i = 1; i < 11; i++)
				{
					field[{s, i}] = '*';
				}
			}
		
	}
private:
	string rows = "ABCDEFGHIJ";

	bool is_exist_ship(Ship ship) {
		auto position = ship.position;
		for (auto p : position)
			if (field[p.first] != '*') return false;
		return true;
	}

	bool check_pos_ship(Ship ship) {
		auto position = ship.position;
		auto first_pair = ship.position.begin();
		auto check_row = first_pair->first.first;
		auto check_column = first_pair->first.second;
		if (position.size() == 1)
			return true;
		for (auto p : position) {
			if(check_column != p.first.second){
				check_column = 0;
			}
			if (check_row != p.first.first) {
				check_row = '0';
			}
		}		
		if (check_column == 0 and check_row != '0') {

			auto n_column = first_pair->first.second;
			for (auto p : position) {
				if (p == *first_pair)continue;
				if (abs(n_column - p.first.second) != 1) {
					return false;
				}
				n_column = p.first.second;
			}
			return true;
		}
		else if (check_column != 0 and check_row == '0') {
			auto n_row = first_pair->first.first;
			for (auto p : position) {
				if (p == *first_pair)continue;
				if (abs(n_row - p.first.first) != 1) {
					return false;
				}
				n_row = p.first.first;
			}
			return true;
		}
		return false;
	} 
	bool check_correct(Ship ship) {
		int result = check_pos_ship(ship) + is_exist_ship(ship);
		return result == 2 ? true : false;
	}

public:
	void show()
	{
		cout << "  ";
		for (int i = 1; i < 11; i++)
			cout << i << " ";
		cout << endl;
		for (auto s : rows)
		{
			cout << s << " ";
			for (size_t i = 1; i < 11; i++)
			{
				cout << field[{s, i}] << " ";
			}
			cout << endl;
		}
	}

	bool add_ship(Ship ship) {
		if (ship.position.size() == 0) {
			return false;
		}
		else if (check_correct(ship))
		{
			for (auto p : ship.position)
				field[p.first] = p.second;
			return true;
		}			
		return false;
	}
	map<pair<char, int>, char> field;
};
