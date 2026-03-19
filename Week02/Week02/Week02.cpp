#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
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
	char ISBN[11];
	Genre genre;
	char title[128];
	char author[128];
};

bool checkIfFileContainsBook(char* ISBN, const char* filename) {
	std::ifstream ifile(filename, std::ios::beg | std::ios::in);
	if (!ifile.is_open())
	{
		std::cout << "Error! File didn't open!" << std::endl;
		return false;
	}
	char buffer[1025];
	while (ifile.getline(buffer,1025))
	{
		if (std::strncmp(buffer, ISBN, 10) == 0) {
			return true;
		}
	}
	return false;
}
void saveBookToFile(const char* filename, Book& book) {
	if (checkIfFileContainsBook(book.ISBN, filename))
	{
		std::cout << "This book is already saved in the file!" << '\n';
		return;
	}

	std::ofstream ofile(filename, std::ios::out | std::ios::app);
		
	if (!ofile.is_open())
	{
		std::cout << "Error! File didn't open!" << '\n';
		return;
	}
	ofile << book.ISBN << " | " << book.title << " | " << book.author << " | " << book.genre << " | " << '\n';
	std::cout << "Done!" << '\n';
}
int getAllBooksFromFile(const char* filename, Book books[], int maxCapacity) {
	std::ifstream ifile(filename, std::ios::in);
	if (!ifile.is_open())
	{
		std::cout << "Error! File didn't open!" << std::endl;
		return -1;
	}

	int count = 0;
	char buffer[1025];
	while (count < maxCapacity && ifile.getline(buffer, 1025))
	{
		char* ptr = buffer;
		char* sep1 = std::strstr(ptr, " | ");
		if (!sep1)
		{
			continue;
		}
		*sep1 = '\0';
		std::strncpy(books[count].ISBN, ptr, 11);
		ptr = sep1 + 3;
		char* sep2 = std::strstr(ptr, " | ");
		if (!sep2)
		{
			continue;
		}
		*sep2 = '\0';
		std::strncpy(books[count].title, ptr, 128);
		ptr = sep2 + 3;
		char* sep3 = std::strstr(ptr, " | ");
		if (!sep3)
		{
			continue;
		}
		*sep3 = '\0';
		std::strncpy(books[count].author, ptr, 128);

		ptr = sep3 + 3;
		books[count].genre = static_cast<Genre>(std::atoi(ptr));
		count++;
	}
	return count;
}

void printBook(const Book& book) {
	std::cout << "ISBN: " << book.ISBN << "\nTitle: " << book.title << "\nAuthor: " << book.author << "\nGenre ID: " << book.genre << "\n-------------------\n";
}
Book* getBookByISBN(const char* filename, char* ISBN) {
	std::ifstream ifile(filename, std::ios::in);
	if (!ifile.is_open())
	{
		std::cout << "Error! The file didn't open!";
		return nullptr;
	}
	char buffer[1025];
	int count = 0;
	if (checkIfFileContainsBook(ISBN, filename))
	{
		while (ifile.getline(buffer,1025))
		{
			count++;
		}
	}
	else
	{
		std::cout << "No book with this ISBN found!" << std::endl;
		ifile.close();
		return nullptr;
	}
	ifile.close();
	Book* books = new Book[count];
	int loadedBooks = getAllBooksFromFile(filename, books, count);
	for (int i = 0; i < loadedBooks; i++)
	{
		if (std::strcmp(books[i].ISBN, ISBN))
		{
			Book* foundbook = new Book;
			*foundbook = books[i];
			std::cout << "Done!" << '\n';
			delete[] books;
			return foundbook;
		}
	}
	std::cout << "No book with this ISBN found!" << std::endl;
	delete[] books;
	return nullptr;
}
void updateBookInFile(const char* filename, const char* ISBN, const Book& updatedBook) {
	int maxCapacity = 100;
	Book* books = new Book[maxCapacity];
	int loadedCount = getAllBooksFromFile(filename, books, maxCapacity);
	bool isFound = false;
	for (int i = 0; i < loadedCount; i++)
	{
		if (std::strcmp(books[i].ISBN,ISBN))
		{
			books[i] = updatedBook;
			isFound = true;
			break;
		}
	}
	if (!isFound)
	{
		std::cout << "Book with this ISBN isn't found!" << std::endl;
		delete[] books;
		return;
	}
	std::ofstream ofile(filename, std::ios::out);
	if (!ofile.is_open())
	{
		std::cout << "Error! Could not open file to save updates!" << std::endl;
		delete[] books;
		return;
	}
	for (int i = 0; i < loadedCount; i++)
	{
		ofile << books[i].ISBN << " | " << books[i].title << " | " << books[i].author << " | " << books[i].genre << '\n';
	}
	std::cout << "Book updated successfully!" << std::endl;
	delete[] books;
}
void deleteBookFromFile(const char* filename, const char* ISBN, int maxCapacity) {
	Book* books = new Book[maxCapacity];
	int loadedCount = getAllBooksFromFile(filename, books, maxCapacity);
	std::ofstream ofile(filename, std::ios::out);
	if (!ofile.is_open())
	{
		std::cout << "Error! Could not open file to save updates!" << std::endl;
		delete[] books;
		return;
	}
	bool isDeleted = false;
	for (int i = 0; i < loadedCount; i++)
	{
		if (std::strcmp(books[i].ISBN, ISBN))
		{
			isDeleted = true;
			continue;
		}
		ofile << books[i].ISBN << " | " << books[i].title << " | " << books[i].author << " | " << books[i].genre << '\n';
	}
	if (isDeleted)
	{
		std::cout << "Book deleted successfully!" << std::endl;
	}
	else
	{
		std::cout << "Book with this ISBN is not found!" << std::endl;
	}
	delete[] books;
}

//7

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

	//5
	/*char fileName[] = "template.csv";
	Student student1 = { "Ivan","Ivanov",12345,4.50, HairColor::Black };
	saveStudentToFile(student1, fileName);
	readStudentsFromFile(fileName);
	Student student2 = { "Misho", "Mishev", 53456, 2.56, HairColor::Red };
	saveStudentToFile(student2, fileName);
	readStudentsFromFile(fileName);*/
	
	//6
	const char* dbFile = "library.txt";
    
    Book library[100];

	int loadedCount = getAllBooksFromFile(dbFile, library, 100);

	std::cout << "Успешно заредени " << loadedCount << " книги от файла.\n\n";
	return 0;
}