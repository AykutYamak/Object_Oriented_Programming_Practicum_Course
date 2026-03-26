#include "Item.hpp"
#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

void Item::free() {
	if (this->name)
	{
		delete[] name;
		this->name = nullptr;
	}
	this->price = 0;
	this->availability = false;
}
void Item::copyFrom(const Item& other) {
	this->price = other.price;
	this->availability = other.availability;
	if (other.name!=nullptr)
	{
		this->name = new char[strlen(other.name) + 1];
		strcpy(this->name, other.name);
	}
	else
	{
		this->name = nullptr;
	}
	
}
Item::Item() {
	this->name = nullptr;
	this->price = 0;
	this->availability = false;
}
Item::Item(const char* name, double price, bool availability) {
	this->name = nullptr;
	Item::setName(name);
	Item::setPrice(price);
	Item::setAvailability(availability);
}
Item::Item(const Item& other) {
	copyFrom(other);
}
Item& Item::operator=(const Item& other) {
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
Item::~Item() {
	free();
}

const char* Item::getName() const {
	return this->name;
}
void Item::setName(const char* name) {
	if (!name)	
	{
		return;
	}
	if (this->name != nullptr)
	{
		delete[] this->name;
	}
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
const bool Item::getAvailability() const 
{
	return this->availability;
}
void Item::setAvailability(bool availability) {
	this->availability = availability;
}
const double Item::getPrice() const{
	return this->price;
}
void Item::setPrice(double price) {
	if (price<0)
	{
		return;
	}
	this->price = price;
}


