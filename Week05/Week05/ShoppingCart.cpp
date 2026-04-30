#include <iostream>
#include <fstream>
#include "ShoppingCart.hpp"
#pragma warning(disable:4996)
void ShoppingCart::free() {
	this->countItems = 0;
	if (this->items)
	{
		delete[] this->items;
		this->items = nullptr;
	}
}
void ShoppingCart::copyFrom(const ShoppingCart& other) {
	this->countItems = other.countItems;
	this->capacity = other.capacity;
	if (other.items!=nullptr)
	{
		this->items = new Item[this->capacity];
		for (size_t i = 0; i < this->countItems; i++)
		{
			this->items[i] = other.items[i];
		}
	}
	else
	{
		this->items = nullptr;
	}
}
void ShoppingCart::resize() {
	int newCapacity = (this->capacity == 0) ? 2 : this->capacity * 2;
	Item* newItems = new Item[newCapacity];

	for (size_t i = 0; i < this->countItems; i++)
	{
		newItems[i] = this->items[i];
	}
	delete[] this->items;
	this->items = newItems;
	this->capacity = newCapacity;
}
int ShoppingCart::find(const char* name) const{
	if (!name) return -1;
	for (size_t i = 0; i < this->countItems; i++)
	{
		if (strcmp(this->items[i].getName(),name) == 0)
		{
			return i;
		}
	}
	return -1;
}
ShoppingCart::ShoppingCart() {
	this->countItems = 0;
	this->capacity = 0;
	this->items = nullptr;
}
ShoppingCart::ShoppingCart(int countItems, int capacity, Item* items) {
	this->countItems = countItems;
	if (capacity < countItems)
	{
		resize();
	}
	this->capacity = capacity;
	this->items = nullptr;
	this->items = new Item[this->countItems];
	this->items = items;
}
ShoppingCart::ShoppingCart(const ShoppingCart& other) {
	copyFrom(other);
}
ShoppingCart& ShoppingCart::operator=(const ShoppingCart& other) {
	if (this!=&other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
ShoppingCart::~ShoppingCart() {
	free();
}
bool ShoppingCart::addItem(const Item& item) {
	if (find(item.getName()) != -1)
	{
		std::cout << "Item already added!\n";
		return false;
	}
	if (this->countItems == this->capacity)
	{
		resize();
	}

	for (size_t i = 0; i < this->countItems; i++)
	{
		if (this->items[i].getName() == item.getName())
		{
			std::cout << "Item already added!\n";
			return false;
		}
	}
	this->items[countItems] = item;
	this->countItems++;
	return true;
}
bool ShoppingCart::removeItem(const char* name) {
	if (!name) {
		return false;
	}
	for (size_t i = 0; i < this->countItems; i++)
	{
		if (strcmp(this->items[i].getName(),name) == 0)
		{
			for (int j = i; j < countItems-1; j++)
			{
				items[j] = items[j + 1];
			}
			countItems--;
			return true;
		}
	}
	return false;
}
int ShoppingCart::itemsCount() const{
	return this->countItems;
}
const bool ShoppingCart::exists(const char* name) const {
	int resultIndex = find(name);
	if(this->items[resultIndex].getName() != nullptr) return true;
	return false;
}
const bool ShoppingCart::isEmpty() const{
	if (countItems == 0) return true;
	return false;
}
const double ShoppingCart::getPriceOf(const char* name) const{
	if (!name)
	{
		return 0.0;
	}
	int resultIndex = find(name);
	if (this->items[resultIndex].getName() == nullptr)
	{
		return 0.0;
	}
	return this->items[resultIndex].getPrice();
}
const double ShoppingCart::totalPrice() const{
	double result = 0;
	for (size_t i = 0; i < countItems; i++)
	{
		result += this->items[i].getPrice();
	}
	return result;
}
void ShoppingCart::sortByName(){
	for (size_t i = 0; i < countItems-1; i++)
	{
		for (size_t j = 0; j < countItems-i-1; j++)
		{
			if (strcmp(this->items[j].getName(), this->items[j+1].getName())>0)
			{
				std::swap(this->items[j], this->items[j + 1]);
			}
		}
	}
}
bool ShoppingCart::save(std::ofstream& ofile) const{
	if (!ofile.is_open())
	{
		std::cout << "File didn't open!\n";
		return false;
	}
	ofile << "Items' count: " << countItems << "\n";
	for (size_t i = 0; i < countItems; i++)
	{
		ofile << "Name: " << this->items[i].getName() << " Price: " << this->items[i].getPrice() << " Availability: " << this->items[i].getAvailability() << "\n";
	}
	return true;
}

