#include "StockManager.h"
#include <algorithm>

void StockManager::initializeStock(std::string potionName)
{
	potionStock.emplace(potionName, MAX_STOCK);
}

bool StockManager::dispensePotion(std::string potionName)
{
	auto i = potionStock.find(potionName);
	if (i->second > 0)
	{
		(i->second)--;
		return 1;
	}
	return 0;
}

void StockManager::returnPotion(std::string potionName)
{
	auto i = potionStock.find(potionName);
	if ((i->second) - MAX_STOCK > -1)
	{
		return;
	}
	(i->second)++;

}

int StockManager::getStock(std::string potionName)
{//name이 중복이면 find가 제구실을 못한다...
	auto i = potionStock.find(potionName);
	return i->second;
}
