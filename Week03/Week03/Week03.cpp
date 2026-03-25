#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
//1
bool isPrime(int n) {
	if (n <= 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 3; i <= std::sqrt(n); i++)
	{
		if (n%i == 0)
		{
			return false;
		}
	}
	return true;
}
void writePrimeNumsToFile(const char* filename) {
	std::ifstream ifile(filename, std::ios::in | std::ios::binary);
	if (!ifile.is_open())
	{
		std::cerr << "Error! File "  << filename << " didn't open!" << '\n';
		return;
	}
	std::ofstream ofile("primes.bin", std::ios::out | std::ios::binary);
	if (!ofile.is_open())
	{
		std::cerr << "Error! The primes.bin file didn't open!" << '\n';
		ifile.close();
		return;
	}
	int currentNumber = 0;
	int primesCount = 0;

	while (ifile.read(reinterpret_cast<char*>(&currentNumber),sizeof(int)))
	{
		if (isPrime(currentNumber))
		{
			ofile.write(reinterpret_cast<char*>(&currentNumber), sizeof(int));
			primesCount++;
		}
	}
	std::cout << "Successfully extracted " << primesCount << " prime numbers!" << '\n';
	ofile.close();
	ifile.close();
}

//2
enum Type {
	Margarita,
	Kalcone,
	Burata
};
enum Size {
	S,
	M,
	L
};
struct Pizza {
	Type typePizza;
	Size sizePizza;
	double price;
};
struct Order
{
	char clientName[50];
	char phoneNumber[20];
	char address[100];
	double price;
	int countPizzas;
	Pizza pizzas[10];
};


void writeOrdersToBinary(const char* filename, Order* orders, int count) {
	std::ofstream ofile(filename, std::ios::out | std::ios::binary);
	if (!ofile.is_open())
	{
		std::cout << "Erorr! File didn't open!" << '\n';
		return;
	}
	for (int i = 0; i < count; i++)
	{
		if (orders[i].clientName == '\0')
		{
			break;
		}
		ofile.write(reinterpret_cast<const char*>(&orders[i]), sizeof(Order));
 	}
	std::cout << "Successfully written " << count << " orders in the file!" << '\n';
	ofile.close();
}
int loadOrdersFromBinary(const char* filename, Order orders[], int maxCapacity) {
	std::ifstream ifile(filename, std::ios::binary | std::ios::in);
	if (!ifile.is_open())
	{
		std::cout << "Erorr! File didn't open!" << '\n';
		return 0;
	}
	int count = 0;
	
	while (count < maxCapacity && ifile.read(reinterpret_cast<char*>(&orders[count]),sizeof(Order)))
	{
		count++;
	}

	ifile.close();
	return count;

}
void sortOrdersByAddress(Order orders[], int count) {
	for (int i = 0; i < count-1; i++)
	{
		for (int j = 0; j < count-i-1; j++)
		{
			if (std::strcmp(orders[i].address, orders[j].address) > 0)
			{
				Order temp = orders[j];
				orders[j] = orders[j+1];
				orders[j+1] = temp;
			}
		}
	}
	std::cout << "Orders are sorted!" << '\n';
	return;
}


//3
struct jobAd {
	char companyName[26];
	int countDevsInTheCompany;
	int countPaidDaysOff;
	long long salary;
};
int main()
{
    std::cout << "Hello World!\n";
}