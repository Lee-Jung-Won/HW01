#pragma once
#include <string>

class Item
{
private:
	std::string name_;
	int price_;
public:
	Item(const std::string& name = "", int price = 0);
	const std::string& GetName() const;
	int GetPrice() const;
	void Clear();
};
