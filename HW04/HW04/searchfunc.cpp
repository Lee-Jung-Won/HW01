#include "searchfunc.h"

PotionRecipe* searchfunc::search_byname(std::string name)
{
    auto i = std::find(con->getreicpes()->begin(), con->getreicpes()->end(), name);
    if (i != con->getreicpes()->end())
    {
        return &(*i);
    }
    return nullptr;
}

std::vector<PotionRecipe>* searchfunc::search_byingred(std::string name)
{
    std::vector<PotionRecipe>* stor = new std::vector<PotionRecipe>();
    for (auto i : *(con->getreicpes()))
    {
        auto k = std::find(i.ingredients.begin(), i.ingredients.end(), name);
        if (k != i.ingredients.end())
        {
            stor->emplace_back(i);
        }
    }
    if (stor->empty())
    {
        return nullptr;
    }
    return stor;
}

std::vector<PotionRecipe>* searchfunc::search_byall(std::string name)
{
    std::vector<PotionRecipe>* stor1 = new std::vector<PotionRecipe>();
    for (auto j : *(con->getreicpes()))
    {
        if (j.potionName == name)
        {
            stor1->emplace_back(j);
            continue;
        }
        auto k = std::find(j.ingredients.begin(), j.ingredients.end(), name);
        if (k != j.ingredients.end())
        {
            stor1->emplace_back(j);
            continue;
        }
    }
    if (stor1->empty())
    {
        return nullptr;
    }
    return stor1;
}
