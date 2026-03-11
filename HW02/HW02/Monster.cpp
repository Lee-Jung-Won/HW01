#include "Monster.h"
#include "Player.h"

int Monster::attack(Player* user)
{
	cout << "!!! Mon'" << name << " Attack !!!" << endl;

	if ((user->getHP() - power) <= 0)
	{
		user->setHP(0);
		cout << "Mon'hp : " << user->getHP() << "\t"<< user->getJobName() << " : (User) is DEAD" << std::endl;
		cout << "!!! " << name << " : MONS VICTORY !!!" << endl;
		return 0;
	}
	else
	{
		std::cout << "User'hp : " << user->getHP() << " -> ";
		user->setHP(user->getHP() - power);
		std::cout << user->getHP() << std::endl;
		return 1;
	}
	
}

string Monster::M_getname() {
	return name;
}
int Monster::M_gethp()
{
	return hp;
}
int Monster::M_getpower()
{
	return power;
}
int Monster::M_getdefence()
{
	return defence;
}
int Monster::M_getspeed()
{
	return speed;
}


void Monster::M_setname(string m_name)
{
	name = m_name;
}
void Monster::M_sethp(int m_hp)
{
	hp = m_hp;
}
void Monster::M_setpower(int m_pwr)
{
	power = m_pwr;
}
void Monster::M_setdefence(int m_def)
{
	defence = m_def;
}
void Monster::M_setspeed(int m_spd)
{
	speed = m_spd;
}







//#include <iostream>\
//
//void Monster::M_setname(string m_name)
//{
//	name = m_name;
//}
//
//void Monster::M_sethp(int m_hp)
//{
//	hp = m_hp;
//}
//
//int Monster::M_gethp()
//{
//	return hp;
//}
//
//int Monster::M_getdefence()
//{
//	return defence;
//}