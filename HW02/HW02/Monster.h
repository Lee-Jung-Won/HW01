#pragma once
#include <string>
#include <iostream>

class Player;

using namespace std;

class Monster
{
protected:
	string name;
	int hp;
	int power;
	int defence;
	int speed;
public:
	Monster(string a)
		: name(a)
		, hp(10)
		, power(30)
		, defence(10)
		, speed(10)
	{
	}

	~Monster() {
		cout << "Monster Destroyed" << endl;
	}

	int attack(Player* user);

	void M_setname(string m_name);
	void M_sethp(int m_hp);
	void M_setpower(int m_pwr);
	void M_setdefence(int m_def);
	void M_setspeed(int m_spd);

	string M_getname();
	int M_gethp();
	int M_getpower();
	int M_getdefence();
	int M_getspeed();

};