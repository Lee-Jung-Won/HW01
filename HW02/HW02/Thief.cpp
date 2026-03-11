#include "Thief.h"
#include <iostream>

void Thief::attack()
{
    std::cout << "! Throw a knife !" << std::endl;
}

int Thief::attack(Monster* mon)
{
    std::cout << "Knife Attack" << endl;

    if ((mon->M_gethp() - power) <= 0)
    {
        cout << "Mon'hp : " << mon->M_gethp() << " -> ";
        mon->M_sethp(0);
        cout << mon->M_gethp() << endl;
        cout << "Mon is DEAD" << std::endl;
        cout << "!!! " << nickname << " VICTORY !!!" << endl;
        return 0;
    }
    else
    {
        std::cout << "Mon'hp : " << mon->M_gethp() << " -> ";
        mon->M_sethp(mon->M_gethp() - power);
        std::cout << mon->M_gethp() << std::endl;
        return 1;
    }
}