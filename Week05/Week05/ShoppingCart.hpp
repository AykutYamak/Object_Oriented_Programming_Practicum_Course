#pragma once
#include "Item.hpp"
#include <fstream>
class ShoppingCart {
private:
	int countItems;
	int capacity;
	Item* items;
	void free();
	void copyFrom(const ShoppingCart& other);
	void resize();
	int find(const char* name) const;
public:
	ShoppingCart();
	ShoppingCart(int countItems, int capacity, Item* items);
	ShoppingCart(const ShoppingCart& other);
	ShoppingCart& operator=(const ShoppingCart& other);
	~ShoppingCart();

	bool addItem(const Item& item);
	bool removeItem(const char* name);
	int itemsCount() const;
	const bool exists(const char* name) const;
	const bool isEmpty() const;
	const double getPriceOf(const char* name) const;
	const double totalPrice() const;
	void sortByName();
	bool save(std::ofstream& ofile) const;
};
