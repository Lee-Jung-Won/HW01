#include "printfunc.h"

void printfunc::print_byname(PotionRecipe* pl)
{
    if (pl == nullptr)
    {
        std::cout << "Nothing to print by [Name]" << std::endl;
        return;
    }

    std::cout << "===== [ " << pl->potionName << " ] Info =====" << std::endl;
    std::cout << "Now Left Potions : " << con->getbag()->getStock(pl->potionName) << std::endl;
    std::cout << "\tIngredients >> ";
    for (auto i : pl->ingredients)
    {
        std::cout << i << ",\t";
    }
    std::cout << std::endl << "=============================" << std::endl;
}

void printfunc::print_byingred(std::vector<PotionRecipe>* al)
{
    if (al == nullptr)
    {
        std::cout << "\nNothing to print...\n" << std::endl;
        return;
    }
    std::cout << "\n===== Searching ALL Info =====" << std::endl;
    for (auto j : *al)
    {
        print_byname(&j); // << ? why not &(*j) = auto=value notadress find=adress
    }
}