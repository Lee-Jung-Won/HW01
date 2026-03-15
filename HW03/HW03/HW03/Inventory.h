#pragma once
#include <iostream>
#include <algorithm>
#include "Item.h"

inline bool compareItemsByPrice(const Item& a, const Item& b);

template <typename Tp>
class Inventory
{
private:
	int capacity_;
	int size_;
	Tp* item_;
public:
	Inventory();
	Inventory(int cap);
	Inventory(Inventory<Tp>& copyone);
	~Inventory();

	int const GetSize();
	int const GetCapacity();
	void SortItems();
	void const PrintAllItems();
	
	void RemoveLastItem();
	void Resize(const int newcapacity);

	void Additem(const Tp& in_item);
	void Assign(const Inventory<Tp>& other);

};

template <typename Tp>
Inventory<Tp>::Inventory()
	: capacity_(10)
	, size_(0)
	, item_(new Tp[capacity_])
{
}

template <typename Tp>
Inventory<Tp>::Inventory(int cap)
	: capacity_(cap)
	, size_(0)
	, item_(new Tp[capacity_])
{
}

template <typename Tp>
Inventory<Tp>::Inventory(Inventory<Tp>& copyone)
	: capacity_(copyone.capacity_)
	, size_(copyone.size_)
	, item_(new Tp[copyone.capacity_])
{
	for (int i = 0; i < size_; i++)
	{
		item_[i] = copyone.item_[i];
	}
	//Tp* tempitem = new Tp[copyone.capacity_];
	//for (int i = 0; i < size_; i++)
	//{
	//	tempitem[i] = copyone.item_[i];
	//}
	//delete[] item_;
	//item_ = tempitem;
}

template  <typename Tp>
Inventory<Tp>::~Inventory()
{
	if (item_ != nullptr)
	{
		delete[] item_;
		item_ = nullptr;
	}
}

template <typename Tp>
int const Inventory<Tp>::GetSize()
{
	return size_;
}

template <typename Tp>
int const Inventory<Tp>::GetCapacity()
{
	return capacity_;
}

template <typename Tp>
void Inventory<Tp>::Additem(const Tp& in_item)
{
	if (size_ < capacity_)
	{
		item_[size_] = in_item;
		size_++;
	}
	else
	{
		std::cout << "Can't be loaded... It's Full now" << std::endl;
		std::cout << "storage is upgrading X2..." << std::endl;
		Resize((capacity_ * 2));
	}
}

template <typename Tp>
void Inventory<Tp>::RemoveLastItem()
{
	if (size_ <= 0)
	{
		std::cout << "Your Inven is already empty." << std::endl;
	}
	else
	{

		item_[size_ - 1].Clear();
		size_--;
	}
}

template <typename Tp>
void Inventory<Tp>::Resize(const int newcapacity)
{
	if (newcapacity < size_)
	{
		std::cout << (size_ - newcapacity) << ": Data gonna be lost..." << std::endl;
		size_ = newcapacity;
	}
		capacity_ = newcapacity;

		Tp* tempitem = new Tp[capacity_];
		for (int i = 0; i < size_; i++)
		{
			tempitem[i] = item_[i];
		}
		delete[] item_;
		item_ = tempitem;

		std::cout << "Cap has Changed to... > " << capacity_ << std::endl << std::endl;
}

template <typename Tp>
void Inventory<Tp>::Assign(const Inventory<Tp>& other)
{
	if (other.size_ > capacity_)
	{
		Tp* tempitem = new Tp[capacity_];
		for (int i = 0; i < capacity_; i++)
		{
			tempitem[i] = other.item_[i];
		}
		delete[] item_;
		item_ = tempitem;

		std::cout << "Assign Completed... Lost data detected : " << other.size_ - capacity_ << std::endl;
		size_ = capacity_;
		std::cout << "Size : " << capacity_ << "\tCap : " << capacity_ << "\t >> FULL NOW " << std::endl << std::endl;
	}
	else
	{
		for (int i = 0; i < size_; i++)
		{
			item_[i].Clear();
		} // 어차피 size가 조절되서 입력만 하는거라 clear할필요없긴함

		for (int i = 0; i < other.size_; i++)
		{
			item_[i] = other.item_[i];
		}
		std::cout << "Assign Completed..." << std::endl;
		size_ = other.size_;

	}
}

template <typename Tp>
void Inventory<Tp>::SortItems()
{
	if (capacity_ <= 1)
	{
		std::cout << "Nothing to sort..." << std::endl;
	}
	else
	{
		std::sort(item_, item_ + size_, compareItemsByPrice);
		std::cout << "Sort Completed..." << std::endl;
	}
}

template <typename Tp>
void const Inventory<Tp>::PrintAllItems()
{
	if (size_ <= 0)
	{
		std::cout << "Nothing to print..." << std::endl;
	}
	else
	{
		for (int i = 0; i < size_; i++)
		{
			std::cout << item_[i].GetName() << " " << item_[i].GetPrice() << std::endl;

		}
		std::cout << "Print Completed..." << std::endl;
		std::cout << "Size : " << size_ << "\tCapacity : " << capacity_ << std::endl << std::endl;
	}
}

inline bool compareItemsByPrice(const Item& a, const Item& b) {
	return a.GetPrice() < b.GetPrice();
}