#pragma once
#include <iostream>
#include <vector>
#include "AlchemyWorkshop.h"

class printfunc
{
private:
    AlchemyWorkshop* con;
public:
    printfunc(AlchemyWorkshop* it) : con(it) {}

    void print_byname(PotionRecipe* pl);

    void print_byingred(std::vector<PotionRecipe>* al);

};
