#pragma once
#include <map>
#include <string>

class StockManager
{
private:
	std::map<std::string, int> potionStock;
	const int MAX_STOCK = 3;
public:
	void initializeStock(std::string potionName);
	bool dispensePotion(std::string potionName);
	void returnPotion(std::string potionName);
	int getStock(std::string potionName);
};

