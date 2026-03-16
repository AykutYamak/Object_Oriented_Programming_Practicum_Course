#include <iostream>
#include <fstream>
#include <cmath>
//1
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

//2
void writeProdAndSumToFile(int a, int b, int c) {
	std::ofstream ofile("result.txt", std::ios::out | std::ios::beg);
	if (!ofile.is_open())
	{
		std::cerr << "Error! The file didn't open!";
		return; 
	}
	ofile << (a + b + c);
	ofile << '\n';
	ofile << (a * b * c);
	ofile.close();
}
void returnDifference(std::ifstream& file) {
	if (!file.is_open())
	{
		return;
	}
	int sum = 0;
	int product = 0;
	file >> sum;
	file >> product;
	std::cout << std::abs(product - sum) << std::endl;
}
//3
void saveArr(char *array) {
	std::ofstream ofile("arrays.txt", std::ios::app);
	int i = 0;
	while (array[i] != '|' && array[i]!='\0')
	{
		ofile << array[i];
		i++;
	}
	ofile << '\n';
	ofile.close();
	std::cout << "Done!";
}
char* loadArr(int lineNum) {
	std::ifstream ifile("arrays.txt", std::ios::in);
	if (!ifile.is_open())
	{
		throw "Error! File didn't open!";
	}
	const int MAX_BUFFER = 1024;
	char buffer[MAX_BUFFER];
	int currentLineNumber = 1;
	while (ifile.getline(buffer,MAX_BUFFER))
	{
		if (currentLineNumber == lineNum)
		{
			int len = 0;
			while (buffer[len] != '\0')
			{
				len++;
			}
			char* result = new char[len + 1];
			for (int i = 0; i <= len; i++)
			{
				result[i] = buffer[i];
			}
			ifile.close();
			return result;
		}
		currentLineNumber++;
	}
	ifile.close();
	return nullptr;
} 

//4
void readFromFileWriteToMatrix(std::ifstream& file, int matrix[3][3]) {
	char separator;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			file >> matrix[i][j];
			if (j < 2)
			{
				file >> separator;
			}
		}
		if (i < 2)
		{
			file >> separator;
		}
	}
}

void prodOfTwoMatrices(std::ifstream& fileOne, std::ifstream& fileTwo) {
	if (!fileOne.is_open() || !fileTwo.is_open())
	{
		throw "Error with the files' opening";
	}
	int matrix1[3][3];
	int matrix2[3][3];
	int matrixResult[3][3] = { 0 };
	readFromFileWriteToMatrix(fileOne, matrix1);
	readFromFileWriteToMatrix(fileTwo, matrix2);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				matrixResult[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
	std::ofstream ofile("resultMatrix.txt");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			ofile << matrixResult[i][j];
		}
		if (i < 2) {
			ofile << '|';
		}
	}
	ofile.close();
}

//5
enum HairColor {
	Brown,
	Black,
	Blonde,
	Red,
	White
};
struct Student {
	char firstName[16];
	char lastName[16];
	int facultyNum;
	double averageGrade;
	HairColor hairColor;
};
int countStudentsInFile(const char* fileName) {
	std::ifstream ifile(fileName, std::ios::in);
	if (!ifile.is_open())
	{
		std::cerr << "Error! The file didn't open!" << '\n';
		return 0;
	}
	int count = 0;
	char buffer[1025];
	while (ifile.getline(buffer,1025))
	{
		count++;
	}
	ifile.close();
	return count;
}

void saveStudentToFile(Student& student, const char* fileName) {
	
	
	if (countStudentsInFile(fileName) >= 1024)
	{
		std::cout << "The file is full (1024 students reached)!" << '\n';
		return;
	}
	
	std::ofstream ofile(fileName, std::ios::out | std::ios::app);
	if (!ofile.is_open()) {
		std::cout << "Error opening file for writing!\n";
		return;
	}
	ofile << student.firstName << "," << student.lastName << "," << student.facultyNum << "," << student.averageGrade << "," << student.hairColor << '\n';
	std::cout << "SAVED SUCCESSFULLY!" << '\n';
	ofile.close();
}
void readStudentsFromFile(const char* fileName) {
	std::ifstream ifile(fileName, std::ios::in | std::ios::beg);
	if (!ifile.is_open())
	{
		std::cout << "Error! The file didn't open!";
		return;
	}
	ifile.seekg(0, std::ios::beg);
	char buffer[1025];
	while (ifile.getline(buffer,1025))
	{
		std::cout << buffer << '\n';
	}
	ifile.close();
}
//6
enum Genre {
	Fantasy,
	Mystery,
	Science,
	Hirostical
};
struct Book {
	char ISBN[10];
	Genre genre;
	char title[128];
	char author[128];
};
bool checkIfFileContainsBook(char* ISBN, const char* filename) {
	std::ifstream ifile(filename, std::ios::beg | std::ios::in | std::ios::binary);
	char buffer[1025];
	while (ifile.getline(buffer,1025))
	{

	}
}
void saveBookToFile(const char* filename) {
	std::ofstream ofile(filename, std::ios::out | std::ios::app | std::ios::binary);
	if (!ofile.is_open())
	{
		std::cout << "Error! File didn't open!" << '\n';
		return;
	}
	
}


int main()
{	//2
	/*int a, b, c;
	std::cout << "Въведете три числа едно след друго: ";
	std::cin >> a >> b >> c;
	writeProdAndSumToFile(a, b, c);
	std::ifstream ifile("result.txt", std::ios::in | std::ios::beg);
	if (!ifile.is_open())
	{
		throw "error";
	}
	returnDifference(ifile);
	ifile.close();*/

	//4
	/*std::ofstream tempFile1("matrix1.txt");
	if (tempFile1.is_open()) {
		tempFile1 << "1,2,3|4,5,6|7,8,9";
		tempFile1.close();
	}

	std::ofstream tempFile2("matrix2.txt");
	if (tempFile2.is_open()) {
		tempFile2 << "9,8,7|6,5,4|3,2,1";
		tempFile2.close();
	}

	std::ifstream fileOne("matrix1.txt", std::ios::in);
	std::ifstream fileTwo("matrix2.txt", std::ios::in);

	try {
		std::cout << "Започва умножение на матриците...\n";

		prodOfTwoMatrices(fileOne, fileTwo);

		std::cout << "Готово! Резултатът е успешно записан в 'resultMatrix.txt'.\n";
	}
	catch (const char* errorMessage) {
		std::cerr << "Възникна грешка: " << errorMessage << '\n';
	}

	if (fileOne.is_open()) fileOne.close();
	if (fileTwo.is_open()) fileTwo.close();*/

	char fileName[] = "template.csv";
	Student student1 = { "Ivan","Ivanov",12345,4.50, HairColor::Black };
	saveStudentToFile(student1, fileName);
	readStudentsFromFile(fileName);
	Student student2 = { "Misho", "Mishev", 53456, 2.56, HairColor::Red };
	saveStudentToFile(student2, fileName);
	readStudentsFromFile(fileName);
}