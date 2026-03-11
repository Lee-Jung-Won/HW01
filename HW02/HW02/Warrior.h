#pragma once
#include "Player.h"

class Warrior : public Player
{
public:

	Warrior(string nickname) : Player(nickname) {
		job_name = "Warrior";
		cout << "Now you are Warrior !" << endl;
	}

	void attack();
	int attack(Monster* mon);

	~Warrior() {
		cout << "Warrior Deleted" << endl;
	}

};