#pragma once
#include "Player.h"

class Magician : public Player
{
public:

	Magician(string nickname) : Player(nickname) {
		job_name = "Magician";
		cout << "Now you are Magician !" << endl;
	}

    void attack();
	int attack(Monster* mon);

	~Magician() {
		cout << "Magician Deleted" << endl;
	}

};