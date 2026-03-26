#pragma once
class Item{
private:
	char* name;
	bool availability;
	double price;
	void free();
	void copyFrom(const Item& other);

public:
	Item();
	Item(const char* name, double price, bool availability);
	Item(const Item& other);
	Item& operator=(const Item& other);
	~Item();

	const char* getName() const;
	void setName(const char* name);
	const bool getAvailability() const;
	void setAvailability(bool availability);
	const double getPrice() const;
	void setPrice(double price);

};