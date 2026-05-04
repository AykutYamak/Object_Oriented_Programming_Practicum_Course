#pragma once
#include <iostream>

class BigInt {
private:
	char* number;
	bool isNegative;

	void copy(const BigInt&);
	void free();
	bool validNumber(const char*);
	static void trim(char*&);
	void resize(size_t capacity);
public:
	BigInt();
	BigInt(const char*);
	BigInt(const BigInt&);
	BigInt& operator=(const BigInt&);
	~BigInt();
	
	BigInt operator-(const BigInt&) const;
	BigInt operator-() const;
	BigInt operator+(const BigInt&) const;
	BigInt operator*(const BigInt&) const;
	BigInt operator/(const BigInt&) const;
	BigInt operator%(const BigInt&) const;
	BigInt& operator+=(const BigInt&);
	BigInt& operator-=(const BigInt&);
	BigInt& operator++();
	BigInt operator++(int);
	BigInt& operator--();
	BigInt operator--(int);
	bool operator==(const BigInt&) const;
	bool operator!=(const BigInt&) const;
	bool operator<(const BigInt&) const;
	bool operator>(const BigInt&) const;
	bool operator>=(const BigInt&) const;
	bool operator<=(const BigInt&) const;

	friend std::ostream& operator<<(std::ostream&, const BigInt&);
	friend std::istream& operator>>(std::istream&, BigInt&);
};