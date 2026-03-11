#pragma once
#include "Player.h"

class Archer : public Player
{
public:

	Archer(string nickname) : Player(nickname) {
		job_name = "Archer";
		cout << "Now you are Archer !" << endl;
	}

    void attack();
	int attack(Monster* mon);

	~Archer() {
		cout << "Archer Deleted" << endl;
	}
};