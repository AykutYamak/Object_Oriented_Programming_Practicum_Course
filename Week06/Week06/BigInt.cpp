#include <iostream>
#include "BigInt.hpp"
#pragma warning (disable : 4996)

void BigInt::copy(const BigInt& other) {
	this->number = new char[strlen(other.number) + 1];
	strcpy(this->number, other.number);
	this->isNegative = other.isNegative;
}
void BigInt::free() {
	delete[] this->number;
	this->isNegative = false;
}
bool BigInt::validNumber(const char* num) {
	if (!num || strlen(num) < 1) return false;
	if (num[0] == '-') num++;
	size_t length = strlen(num);
	for (size_t i = 0; i < length; i++)
	{
		if (num[i] < '0' || num[i] > '9') return false;
	}
	return true;
}
void BigInt::trim(char*& str) {
	size_t len = strlen(str);
	size_t count = 0;
	while (str[count] == '0' && count < len-1)
	{
		count++;
	}
	char* result = new char[len - count + 1];
	strcpy(result, str + count);
	delete[] str;
	str = result;
}
void BigInt::resize(size_t capacity) {
	char* newNum = new char[capacity] {0};
	strcpy(newNum, number);
	delete[] number;
	number = newNum;
}
BigInt::BigInt():number(new char[2]{'0',0}),isNegative(false){}
BigInt::BigInt(const char* number) : number(new char[2]{'0',0}),isNegative(false) 
{
	if (number[0] == '-')
	{
		isNegative = true;
		number++;
	}
	if (validNumber(number))
	{
		this->number = new char[strlen(number) + 1];
		strcpy(this->number, number);
		trim(this->number);
		if (strcmp(this->number, "0") == 0) isNegative = false;
	}
}
BigInt::BigInt(const BigInt& other) {
	copy(other);
}
BigInt& BigInt::operator=(const BigInt& other) {
	if (*this!=other)
	{
		free();
		copy(other);
	}
	return *this;
}
BigInt::~BigInt() {
	free();
}
BigInt BigInt::operator-(const BigInt& other) const {
	return *this + (-other);
}
BigInt BigInt::operator-() const {
	BigInt result = *this;
	if (result != "0")
	{
		result.isNegative = !isNegative;
	}
	return result;
}
BigInt BigInt::operator+(const BigInt& other) const {
	if (isNegative < other.isNegative && *this < -other || isNegative && other.isNegative)
	{
		return -(-(*this) + (-other));
	}

	size_t biggerLength;
	size_t smallerLength;
	int biggerSign;
	int smallerSign;
	const char* biggerNum;
	const char* smallerNum;
	if (strlen(number) >= strlen(other.number))
	{
		biggerLength = strlen(number);
		smallerLength = strlen(other.number);
		biggerSign = isNegative ? -1 : 1;
		smallerSign = other.isNegative ? -1 : 1;
		biggerNum = number;
		smallerNum = other.number;
	}
	else
	{
		biggerLength = strlen(other.number);
		smallerLength = strlen(number);
		biggerSign = other.isNegative ? -1 : 1;
		smallerSign = isNegative ? -1 : 1;
		biggerNum = other.number;
		smallerNum = number;
	}

	BigInt result;
	result.resize(biggerLength + 2);

	bool carry = false;
	int carrySign = 0;
	for (size_t i = 1; i <= smallerLength; i++)
	{
		char sum =
			biggerSign * (biggerNum[biggerLength - i] - '0') +
			smallerSign * (smallerNum[smallerLength - i] - '0') +
			carrySign * carry + '0';
	}
}

