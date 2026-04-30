//#include <iostream>
//#include <cstring>
//#pragma warning (disable:4996)
//
//const int NAME_LENGTH = 9;
//const int PHONE_NUMBER_LENGTH = 11;
//
//
//class Book {
//private:
//	static int _idCounter;
//	int id;
//	char* title;
//	bool status;
//	char takenBy[NAME_LENGTH];
//	void free() {
//		delete[] title;
//		title = nullptr;
//		status = false;
//		takenBy[0] = '\0';
//	}
//	void copyFrom(const Book& other) {
//		this->id = other.id;
//		this->setTitle(other.getTitle());
//		this->setUser(other.getUser());
//		this->setStatus(other.getStatus());
//	}
//public:
//
//	Book() {
//		_idCounter++;
//		id = _idCounter;
//		title = nullptr;
//		status = false;
//		takenBy[0] = '\0';
//	}
//	Book(const char* title, bool status) {
//		_idCounter++;
//		id = _idCounter;
//		if (title == nullptr)
//		{
//			this->title = nullptr;
//		}
//		else
//		{
//			this->title = new char[strlen(title) + 1];
//			strcpy(this->title, title);
//		}
//		this->takenBy[0] = '\0';
//		this->status = status;
//
//	}
//	Book(const Book& other) {
//		this->title = nullptr;
//		copyFrom(other);
//	}
//	Book& operator=(const Book& other) {
//		if (this!=&other)
//		{
//			free();
//			copyFrom(other);
//		}
//		return *this;
//	}
//	~Book() {
//		free();
//	}
//	const int getId() const{
//		return this->id;
//	}
//	const char* getTitle() const{
//		if (this->title != nullptr)
//		{
//			return this->title;
//		}
//		return "";
//	}
//	void setTitle(const char* title) {
//		if (title!=nullptr)
//		{
//			int length = strlen(title) + 1;
//			this->title = new char[length];
//			strcpy(this->title, title);
//		}
//		else
//		{
//			this->title = nullptr;
//		}
//	}
//	const bool getStatus()const {
//		return this->status;
//	}
//	void setStatus(bool status) {
//		this->status = status;
//	}
//	const char* getUser()const {
//		return this->takenBy;
//	}
//	void setUser(const char* userName) {
//		if (userName == nullptr || strlen(userName) > 8)
//		{
//			this->takenBy[0] = '\0';
//		}
//		else
//		{
//			int len = strlen(userName);
//			for (size_t i = 0; i < len; i++)
//			{
//				this->takenBy[i] = userName[i];
//			}
//			this->takenBy[len] = '\0';
//		}
//	}
//	void print() {
//		std::cout << "Id: " << this->id << '\n';
//		std::cout << "Title: " << (this->title == nullptr ? "No title" : this->title) << '\n';
//		std::cout << "Status: " << (this->status == true ? "Available" : "Not available") << '\n';
//	}
//	friend std::ostream& operator<<(std::ostream& os, const Book& book);
//};
//int Book::_idCounter = 0;
//std::ostream& operator<<(std::ostream& os, const Book& book) {
//	os << "Id: " << book.id << '\n';
//	os << "Title: " << (book.title==nullptr ? "No title" : book.title) << '\n';
//	os << "Status: " << (book.status == true ? "Available" : "Not available") << '\n';
//	return os;
//}
//
//class User {
//private:
//	char name[NAME_LENGTH];
//	char phoneNumber[PHONE_NUMBER_LENGTH];
//	void copyFrom(const User& other) {
//		/*if (other.name!= nullptr && strlen(other.name)+1 <= 9)
//		{
//			int sizeName = strlen(other.name) + 1;
//			for (size_t i = 0; i < sizeName-1; i++)
//			{
//				this->name[i] = other.name[i];
//			}
//			this->name[sizeName-1] = '\0';
//		}
//		else
//		{
//			this->name[0] = '\0';
//		}
//		if (strlen(other.phoneNumber)+1 > 11)
//		{
//			this->phoneNumber[0] = '\0';
//		}
//		else
//		{
//			int length = strlen(other.phoneNumber) + 1;
//			for (int i = 0; i < length; i++)
//			{
//				this->phoneNumber[i] = other.phoneNumber[i];
//			}
//			this->phoneNumber[length] = '\0';
//		}*/
//		this->setName(other.getName());
//		this->setPhoneNumber(other.getPhoneNumber());
//	}
//public:
//	User() {
//		this->name[0] = '\0';
//		this->phoneNumber[0] = '\0';
//	}
//	User(const char* name, const char* phonenumber) {
//		setName(name);
//		setPhoneNumber(phonenumber);
//	}
//	User(const User& other) {
//		copyFrom(other);
//	}
//	User& operator=(const User& other) {
//		if (this!=&other)
//		{
//			this->setName(nullptr);
//			this->setPhoneNumber(nullptr);
//			copyFrom(other);
//		}
//		return *this;
//	}
//	const char* getName() const {
//		return this->name;
//	}
//	void setName(const char* name) {
//		if (name==nullptr)
//		{
//			this->name[0] = '\0';
//		}
//		else
//		{
//			int size = strlen(name) + 1;
//
//			if (size<=9)
//			{
//				for (size_t i = 0; i < size-1; i++)
//				{
//					this->name[i] = name[i];
//				}
//				this->name[size-1] = '\0';
//			}
//			else
//			{
//				this->name[0] = '\0';
//			}
//		}
//	}
//	const char* getPhoneNumber() const{
//		return this->phoneNumber;
//	}
//	void setPhoneNumber(const char* phoneNumber) {
//
//		if (phoneNumber == nullptr || strlen(phoneNumber)+1 > 11)
//		{
//			this->phoneNumber[0] = '\0';
//		}
//		else
//		{
//			int len = strlen(phoneNumber);
//			for (int i = 0; i < len; i++)
//			{
//				this->phoneNumber[i] = phoneNumber[i];
//			}
//			this->phoneNumber[len] = '\0';
//		}
//	}
//};
//
//class Library {
//private:
//	Book* books;
//	int capacityBooks;
//	int countBooks;
//	User* users;
//	int capacityUsers;
//	int countUsers;
//	void free() {
//		delete[] books;
//		books = nullptr;
//		delete[] users;
//		users = nullptr;
//		capacityBooks = 0;
//		countBooks = 0;
//		capacityUsers = 0;
//		countUsers = 0;
//	}
//	void copyFrom(const Library& other) {
//		this->capacityBooks = other.capacityBooks;
//		this->countBooks = other.countBooks;
//		this->capacityUsers = other.capacityUsers;
//		this->countUsers = other.countUsers;
//		this->books = new Book[this->capacityBooks];
//		for (int i = 0; i < countBooks; i++)
//		{
//			this->books[i] = other.books[i];
//		}
//		this->users = new User[this->capacityUsers];
//		for (int i = 0; i < this->countUsers; i++)
//		{
//			this->users[i] = other.users[i];
//		}
//	}
//	void resizeBooks() {
//		int newCapacity = (this->capacityBooks == 0) ? 2 : capacityBooks * 2;
//		Book* newBooks = new Book[newCapacity];
//		for (int i = 0; i < this->countBooks; i++)
//		{
//			newBooks[i] = this->books[i];
//		}
//		delete[] books;
//		books = newBooks;
//		capacityBooks = newCapacity;
//	}
//	void resizeUsers() {
//		int newCapacity = (this->capacityUsers == 0) ? 2 : capacityUsers * 2;
//		User* newUsers = new User[newCapacity];
//		for (int i = 0; i < this->countUsers; i++)
//		{
//			newUsers[i] = this->users[i];
//		}
//		delete[] users;
//		users = newUsers;
//		capacityUsers = newCapacity;
//	}
//
//public:
//	Library() {
//		capacityBooks = 2;
//		countBooks = 0;
//		books = new Book[capacityBooks];
//		capacityUsers = 2;
//		countUsers = 0;
//		users = new User[capacityUsers];
//	}
//	Library(int capacityBooks, int countBooks, int capacityUsers, int countUsers) {
//		this->capacityBooks = capacityBooks;
//		this->countBooks = countBooks;
//		this->capacityUsers = capacityUsers;
//		this->countUsers = countUsers;
//		books = new Book[capacityBooks];
//		users = new User[capacityUsers];
//	}
//	Library(const Library& other) {
//		copyFrom(other);
//	}
//	Library& operator=(const Library& other) {
//		if (this!=&other)
//		{
//			free();
//			copyFrom(other);
//		}
//		return *this;
//	}
//	~Library() {
//		free();
//	}
//	void addBook(const Book& book) {
//		bool exists = false;
//		for (int i = 0; i < this->countBooks; i++)
//		{
//			if (this->books[i].getTitle() == book.getTitle())
//			{
//				exists = true;
//				break;
//			}
//		}
//		if (exists)
//		{
//			std::cout << "This book already exists!" << std::endl;
//			return;
//		}
//		
//		if (this->countBooks >= this->capacityBooks)
//		{
//			resizeBooks();
//		}
//		this->books[countBooks] = book;
//		countBooks++;
//	}
//	void addUser(const User& user) {
//		bool exists = false;
//		for (int i = 0; i < this->countUsers; i++)
//		{
//			if (strcmp(user.getName(), this->users[i].getName()) == 0)
//			{
//				exists = true;
//				break;
//			}
//		}
//		if (exists)
//		{
//			std::cout << "This user already exists!" << std::endl;
//			return;
//		}
//		if (this->countUsers >= this->capacityUsers)
//		{
//			resizeUsers();
//		}
//		this->users[countUsers] = user;
//		this->countUsers++;
//	}
//	void takeBookBy(const int id, const char* userName) {
//		bool userExists = false;
//		for (int i = 0; i < this->countUsers; i++)
//		{
//			if (strcmp(this->users[i].getName(),userName) == 0)
//			{
//				userExists = true;
//				break;
//			}
//		}
//		if (!userExists)
//		{
//			std::cout << "Error: User '" << userName << "' is not registered!" << std::endl;
//			return;
//		}
//		for (int i = 0; i < this->countBooks; i++)
//		{
//			if (this->books[i].getId() == id)
//			{
//				if (this->books[i].getStatus() == true)
//				{
//					this->books[i].setStatus(false);
//					this->books[i].setUser(userName);
//					std::cout << "Book successfully taken by " << userName << "!" << std::endl;
//				}
//				else
//				{
//					std::cout << "This book is already taken by " << this->books[i].getUser() << "!" << std::endl;
//				}
//				return;
//			}
//		}
//		std::cout << "Book with ID " << id << " does not exist!" << std::endl;
//		return;
//	}
//	void returnBookBy(const int id) {
//		for (int i = 0; i < this->countBooks; i++)
//		{
//			if (this->books[i].getId() == id)
//			{
//				if (this->books[i].getStatus() == true)
//				{
//					std::cout << "This book is already available!" << std::endl;
//				}
//				else
//				{
//					this->books[i].setStatus(true);
//					this->books[i].setUser(nullptr);
//					std::cout << "The book is returned successfully!" << std::endl;
//
//				}
//				return;
//			}
//		}
//		std::cout << "Book with ID " << id << " does not exist!" << std::endl;
//	}
//	friend std::ostream& operator<<(std::ostream& os, const Library& lib);
//};
//std::ostream& operator<<(std::ostream& os, const Library& lib) {
//	
//	for (int i = 0; i < lib.countBooks; i++)
//	{
//		os << lib.books[i].getId() << " | " 
//		   << lib.books[i].getTitle() << " | " 
//		   << lib.books[i].getUser() << " | " 
//		   << (lib.books[i].getStatus() == true ? "Available" : "Not available") 
//		   << std::endl;
//	}
//	return os;
//}
//int main() {
//		Library myLibrary;
//
//		std::cout << ">>> ADDING USERS <<<\n";
//		User u1("Ivan", "0888123456");
//		User u2("Maria", "0899999999");
//
//		myLibrary.addUser(u1);
//		myLibrary.addUser(u2);
//		std::cout << "-----------------------\n\n";
//
//		std::cout << ">>> ADDING BOOKS <<<\n";
//		Book b1("Pod Igoto", true);
//		Book b2("Tiutiun", true);
//		Book b3("1984", true);
//
//		myLibrary.addBook(b1);
//		myLibrary.addBook(b2);
//		myLibrary.addBook(b3);
//		std::cout << "-----------------------\n\n";
//
//		std::cout << ">>> INITIAL CATALOG <<<\n";
//		std::cout << myLibrary;
//		std::cout << "\n";
//
//		std::cout << ">>> TAKING BOOKS <<<\n";
//		// Използваме директно b1.getId(), вместо да гадаем числото!
//		myLibrary.takeBookBy(b1.getId(), "Ivan");
//		myLibrary.takeBookBy(b2.getId(), "Maria");
//
//		myLibrary.takeBookBy(b1.getId(), "Maria"); // ГРЕШКА: Вече е заета
//		myLibrary.takeBookBy(b3.getId(), "Gosho"); // ГРЕШКА: Непознат потребител
//		myLibrary.takeBookBy(99, "Ivan");          // ГРЕШКА: Грешно ID
//		std::cout << "-----------------------\n\n";
//
//		std::cout << ">>> CATALOG AFTER TAKING <<<\n";
//		std::cout << myLibrary;
//		std::cout << "\n";
//
//		std::cout << ">>> RETURNING BOOKS <<<\n";
//		myLibrary.returnBookBy(b1.getId());  // УСПЕХ: Връщаме "Под игото"
//		myLibrary.returnBookBy(b3.getId());  // ГРЕШКА: "1984" не е била заета
//		std::cout << "-----------------------\n\n";
//
//		std::cout << ">>> FINAL CATALOG <<<\n";
//		std::cout << myLibrary;
//
//		return 0;
//}