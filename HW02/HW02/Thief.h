#pragma once
#include "Player.h"

class Thief : public Player
{
public:

	Thief(string nickname) : Player(nickname) {
		job_name = "Thief";
		cout << "Now you are Theif !" << endl;
	}

    void attack();
	int attack(Monster* mon);

	~Thief() {
		cout << "Thief Deleted" << endl;
	}
};