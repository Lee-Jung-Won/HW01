#pragma once
#include <vector>
#include <string>
#include "AlchemyWorkshop.h"

class PotionRecipe;

class searchfunc
{
private:
    AlchemyWorkshop* con;
public:
    searchfunc(AlchemyWorkshop* it) : con(it) {}

    PotionRecipe* search_byname(std::string name);

    std::vector<PotionRecipe>* search_byingred(std::string name);
    std::vector<PotionRecipe>* search_byall(std::string name);

};
