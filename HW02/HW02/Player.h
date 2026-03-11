#pragma once
#include <string>
#include <iostream>
#include "Monster.h"

using namespace std;

class Player {
public:

    Player(string name)
        : nickname(name)
        , job_name("Player")
        , level(1)
        , HP(100)
        , MP(100)
        , power(10)
        , defence(10)
        , accuracy(5)
        , speed(10)
    {}

    virtual void attack() = 0;
    virtual int attack(Monster* mon) = 0;

    void printPlayerStatus();

    // getter 
    string getJobName();
    string getNickname();
    int getLevel();
    int getHP();
    int getMP();
    int getPower();
    int getDefence();
    int getAccuracy();
    int getSpeed();

    // setter 
    void setNickname(string user_name);
    void setHP(int HP);
    void setMP(int MP);
    void setPower(int power);
    void setDefence(int defence);
    void setAccuracy(int accuracy);
    void setSpeed(int speed);

    virtual ~Player() {
        cout << "Player Deleted" << endl;
    }

protected:
    string job_name;
    string nickname;
    int level;
    int HP;
    int MP;
    int power;
    int defence;
    int accuracy;
    int speed;
};