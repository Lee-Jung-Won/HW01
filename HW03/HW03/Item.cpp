#include "Item.h"

Item::Item(const std::string& name, int price)
	:name_(name)
	, price_(price)
{
}

const std::string& Item::GetName() const
{
	return name_;
}

int Item::GetPrice() const
{
	return price_;
}

void Item::Clear()
{
	name_ = "";
	price_ = 0;
}

std::ostream& operator<<(std::ostream& InOStream, const Item& ItemRef)
{
	InOStream << "( " << ItemRef.GetName() << " , " << ItemRef.GetPrice() << " )";
	return InOStream;
}