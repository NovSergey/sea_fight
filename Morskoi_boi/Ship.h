#pragma once
#include <vector>
#include <map>
using namespace std;

struct Ship {
	Ship() {}
	Ship(char view_, vector<pair<char, int>> coords) : view{view_} {
		for (auto coord : coords) {
			position[coord] = view;
		}
	}
public:
	map<pair<char, int>, char> position;
private:
	char view;
};