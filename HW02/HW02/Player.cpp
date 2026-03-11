#include "Player.h"
#include <iostream>
using namespace std;

void Player::printPlayerStatus()
{

    cout << "=============================" << endl;
    cout << "* Now : " << job_name << " - Ability *" << endl;
    cout << "- Nic name : " << nickname << endl;
    cout << "- Lv. " << level << endl;
    cout << "- HP: " << HP << endl;
    cout << "- MP: " << MP << endl;
    cout << "- Attack : " << power << endl;
    cout << "- Defence : " << defence << endl;
    cout << "- Accurancy : " << accuracy << endl;
    cout << "- Speed : " << speed << endl;
    cout << "=============================" << endl;
}


void Player::setNickname(string user_name)
{
    nickname = user_name;
}

void Player::setHP(int hp)
{
    HP = hp;
}

void Player::setMP(int mp)
{
    MP = mp;
}

void Player::setPower(int pwr)
{
    power = pwr;
}

void Player::setDefence(int def)
{
    defence = def;
}

void Player::setAccuracy(int acc)
{
    accuracy = acc;
}

void Player::setSpeed(int spd)
{
    speed = spd;
}

string Player::getJobName()
{
    return job_name;
}

string Player::getNickname()
{
    return nickname;
}

int Player::getLevel()
{
    return level;
}

int Player::getHP()
{
    return HP;
}

int Player::getMP()
{
    return MP;
}

int Player::getPower()
{
    return power;
}

int Player::getDefence()
{
    return defence;
}

int Player::getAccuracy()
{
    return accuracy;
}

int Player::getSpeed()
{
    return speed;
}