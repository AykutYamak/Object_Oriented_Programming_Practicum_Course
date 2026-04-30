//#include <iostream>
//#include <cstring>
//
//#pragma warning (disable:4996)
//class Coordinates {
//private:
//	int W;
//	int N;
//	void copyFrom(const Coordinates& other) {
//		W = other.W;
//		N = other.N;
//	}
//public:
//	const int getW() const {
//		return this->W;
//	}
//	void setW(int W) {
//		this->W = W;
//	}
//	const int getN() const{
//		return this->N;
//	}
//	void setN(int N) {
//		this->N = N;
//	}
//
//};
//class Location {
//private:
//	char* name;
//	Coordinates coords;
//	char* description;
//	void free() {
//		delete[] name;
//		name = nullptr;
//		coords.setW(0);
//		coords.setN(0);
//		delete[] description;
//		description = nullptr;
//	}
//	void copyFrom(const Location& other) {
//		if (other.name != nullptr)
//		{
//			int size = strlen(other.name);
//			name = new char[size + 1];
//			strcpy(name, other.name);
//		}
//		else
//		{
//			name = nullptr;
//		}
//		if (other.description != nullptr)
//		{
//			int size = strlen(other.description);
//			description= new char[size + 1];
//			strcpy(description, other.description);
//		}
//		else
//		{
//			description = nullptr;
//		}
//		this->coords = other.coords;
//	}
//public:
//	//Location() {
//	//	this->name = nullptr;
//	//	this->description = description;
//	//	coords.setN(0);
//	//	coords.setW(0);
//	//}
//	Location(const char* name, const Coordinates& coords, const char* description) {
//		setName(name);
//		setDescription(description);
//		int W = coords.getW();
//		int N = coords.getN();
//		setCoordinates(W, N);
//	}
//	Location(const Location& other) {
//		copyFrom(other);
//	}
//	Location operator=(const Location& other) {
//		if (this!=&other)
//		{
//			free();
//			copyFrom(other);
//		}
//		return *this;
//	}
//	~Location() {
//		free();
//	}
//	const char* getName() const{
//		return this->name;
//	}
//	void setName(const char* name)
//	{
//		if (name!= nullptr)
//		{
//			this->name = new char[strlen(name) + 1];
//			strcpy(this->name, name);
//		}
//		else
//		{
//			this->name = nullptr;
//		}
//	}
//	const char* getDescription() const {
//		return this->description;
//	}
//	void setDescription(const char* description) {
//		if (this->description!=nullptr)
//		{
//			this->description = new char[strlen(description) + 1];
//			strcpy(this->description, description);
//		}
//		else
//		{
//			this->description = nullptr;
//		}
//	}
//	const Coordinates getCoordinates() const {
//		return this->coords;
//	}
//	void setCoordinates(const int W, const int N) {
//		this->coords.setN(N);
//		this->coords.setW(W);
//	}
//
//	friend bool operator==(const Location& first, const Location& second);
//	friend bool operator!=(const Location& first, const Location& second);
//	friend std::ostream& operator<<(std::ostream& os, const Location& loc);
//};
//std::ostream& operator<<(std::ostream& os, const Location& loc) {
//	os << loc.name << " ";
//	os << "[" << loc.coords.getN() << ',' << loc.coords.getW() << "]" << " : ";
//	os << loc.description;
//	return os;
//}
//bool operator==(const Location& first, const Location& second) {
//	if (first.name == nullptr && second.name == nullptr)
//	{
//		int firstW = first.coords.getW();
//		int firstN = first.coords.getN();
//		int secondW = second.coords.getW();
//		int secondN = second.coords.getN();
//		return firstW == secondW && firstN == secondN;
//		
//	}
//	else if (first.name == nullptr || second.name == nullptr)
//	{
//		return false;
//	}
//	if (!strcmp(first.name, second.name))
//	{
//		int firstW = first.coords.getW();
//		int firstN = first.coords.getN();
//		int secondW = second.coords.getW();
//		int secondN = second.coords.getN();
//		return firstW == secondW && firstN == secondN;
//	}
//	return false;
//}
//bool operator!=(const Location& first, const Location& second) {
//	/*if (first.name == nullptr && second.name == nullptr)
//	{
//		int firstW = first.coords.getW();
//		int firstN = first.coords.getN();
//		int secondW = second.coords.getW();
//		int secondN = second.coords.getN();
//		return firstW == secondW && firstN == secondN;
//	}
//	else if (first.name == nullptr || second.name == nullptr)
//	{
//		return false;
//	}
//	if (strcmp(first.name,second.name))
//	{
//		return true;
//	}
//	else
//	{
//		int firstW = first.coords.getW();
//		int firstN = first.coords.getN();
//		int secondW = second.coords.getW();
//		int secondN = second.coords.getN();
//		return firstW != secondW && firstN != secondN;
//	}
//	return false;*/
//	return !(first == second);
//}
//class Region {
//	Location* locs;
//
//};
//int main()
//{
//	 
//}
