#include <iostream>
#include <fstream>

int sizeFileLinear(std::ifstream& file) {
	if (!file.is_open())
	{
		return -1;
	}
	char c;
	size_t result = 0;
	while (file.get(c))
	{
		result++;
	}
	return result;
}
int sizeFileConst(std::ifstream& file) {
	if (!file.is_open())
	{
		return -1;
	}
	file.seekg(0, std::ios::end);
	return file.tellg();
}
int returnDifference(std::ifstream& file) {
	if (!file.is_open())
	{
		return -1;
	}
	int sum = 0;
	int product = 0;
	file >> sum;
	file >> product;
	return product - sum;
}
void saveArr(char *array) {
	std::ofstream ofile("arrays.txt", std::ios::app);
	int i = 0;
	while (array[i] != '|')
	{
		ofile << array[i];
		i++;
	}
	ofile << '|';
	ofile.close();
	std::cout << "Done!";
}
//void loadArr(char* array) {
//	std::ifstream ifile("arrays.txt", std::ios::in);
//	char c;
//	for (int i = 0; ; i++)
//	{
//		ifile.g
//		for (int j = 0; [j]!='|'; j++)
//		{
//
//		}
//	}
//}

int main()
{
	/*std::ofstream ofile("filename.txt");
	ofile << "asdadsas";
	ofile.close();
	std::ifstream file("filename.txt");

	if (!file)
	{
		std::cout << "Error";
		return 1;
	}
	std::cout << "size (linear time): " << sizeFileLinear(file);
	std::cout << "size (const time): " << sizeFileConst(file);*/

	/*int a, b, c;
	std::cin >> a >> b >> c;
	std::ofstream ofile("result.txt");
	ofile << a + b + c;
	ofile << "\n";
	ofile << a * b * c;
	ofile.close();
	std::ifstream in("result.txt");
	std::cout << returnDifference(in);
	in.close();*/
	
	char array[5]{ '1','2','3','4','|'};
	saveArr(array);
}