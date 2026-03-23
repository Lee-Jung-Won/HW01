#include <iostream>
#include <vector>
#include <string>
#include <crtdbg.h>
#include "PotionRecipe.h"
// "AlchemyWorkshop.h"
#include "searchfunc.h"
#include "printfunc.h"

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    AlchemyWorkshop myWorkshop;
    searchfunc search(&myWorkshop);
    printfunc print(&myWorkshop);

    while (true) {
        std::cout << "⚗️ 연금술 공방 관리 시스템" << std::endl;
        std::cout << "1. 레시피 추가" << std::endl;
        std::cout << "2. 모든 레시피 출력" << std::endl;
        std::cout << "3. 탐색" << std::endl;
        std::cout << "4. 종료" << std::endl;
        std::cout << "5. 사용" << std::endl;
        std::cout << "6. 반납" << std::endl;

        std::cout << "선택: ";

        int choice;
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "잘못된 입력입니다. 숫자를 입력해주세요." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 1) {
            std::string name;
            std::cout << "물약 이름: ";
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, name);

            // 여러 재료를 입력받기 위한 로직
            std::vector<std::string> ingredients_input;
            std::string ingredient;
            std::cout << "필요한 재료들을 입력하세요. (입력 완료 시 '끝' 입력)" << std::endl;

            while (true) {
                std::cout << "재료 입력: ";
                std::getline(std::cin, ingredient);

                // 사용자가 '끝'을 입력하면 재료 입력 종료
                if (ingredient == "끝") {
                    break;
                }
                ingredients_input.push_back(ingredient);
            }

            // 입력받은 재료가 하나 이상 있을 때만 레시피 추가
            if (!ingredients_input.empty()) {
                myWorkshop.addRecipe(name, ingredients_input);
            }
            else {
                std::cout << ">> 재료가 입력되지 않아 레시피 추가를 취소합니다." << std::endl;
            }

        }
        else if (choice == 2) {
            //myWorkshop.displayAllRecipes();
            if ((myWorkshop.getreicpes())->empty())
            {
                std::cout << "Nothing..." << std::endl;
                continue;
            }

            print.print_byingred(myWorkshop.getreicpes());
        }

        else if (choice == 3) {
            std::string name1;
            std::cout << "Input Name : ";
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, name1);

            //PotionRecipe* a = search.search_byname(name1);
            print.print_byname(search.search_byname(name1));

            std::string name2;
            std::cout << "Input Ingred : ";
            //std::cin.ignore(10000, '\n');
            std::getline(std::cin, name2);

            std::vector<PotionRecipe>* b = search.search_byingred(name2);
            print.print_byingred(b);

            delete b;
            b = nullptr;
        }

        else if (choice == 4) {
            std::cout << "공방 문을 닫습니다..." << std::endl;
            break;

        }

        else if (choice == 5) {
            std::string name3;
            std::cout << "Write Name to USE : ";
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, name3);

            std::vector<PotionRecipe>* c = search.search_byall(name3);

            if (c == nullptr) //vector<potion> 자료형
            {
                std::cout << "Nothing find..." << std::endl;
                continue;
            }

            std::cout << "\nFind your INPUT in [name,ingreds]... : " << c->size() << std::endl;
            for (auto i : *c)
            {
                print.print_byname(&i);
                std::cout << std::endl << "This is what you want to USE? : Y/N ";
                std::string opt;
                std::getline(std::cin, opt);
                if (opt == "Y")
                {
                    if (myWorkshop.getbag()->dispensePotion(i.potionName))
                    {
                        std::cout << "[ " << i.potionName << " ] Potion...Use" << std::endl;
                        std::cout << "You Have : " << myWorkshop.getbag()->getStock(i.potionName) << std::endl << std::endl;
                        continue;
                    }
                        std::cout << "Nothing left... You can't use" << std::endl;
                        std::cout << "You Have : " << myWorkshop.getbag()->getStock(i.potionName) << std::endl << std::endl;

                }
            }
            delete c;
            c = nullptr;
        }
        else if (choice == 6)
        {
            std::string name4;
            std::cout << "Write Name to RETURN : ";
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, name4);

            std::vector<PotionRecipe>* d = search.search_byall(name4);
            if (d == nullptr)
            {
                std::cout << "Nothing find..." << std::endl;
                continue;
            }
            
            std::cout << "\nFind your INPUT in [name,ingreds]... : " << d->size() << std::endl;
            for (auto k : *d)
            {
                print.print_byname(&k);
                std::cout << "This is what you want to RETURN? : Y/N ";
                std::string opt1;
                std::getline(std::cin, opt1);
                if (opt1 == "Y")
                {
                    if (myWorkshop.getbag()->getStock(k.potionName) < 3)
                    {
                        std::cout << "[ " << k.potionName << " ] RETURN COMPLETED..." << std::endl;
                        std::cout << "\t>> " << myWorkshop.getbag()->getStock(k.potionName) << " --> ";
                        myWorkshop.getbag()->returnPotion(k.potionName);
                        std::cout << myWorkshop.getbag()->getStock(k.potionName) << std::endl;
                        continue;
                    }
                    std::cout << "Already Full Now... : " << myWorkshop.getbag()->getStock(k.potionName) << std::endl;
                }
            }
            delete d;
            d = nullptr;
        }
        else {
            std::cout << "잘못된 선택입니다. 다시 시도하세요." << std::endl;
        }


    }

    return 0;
}