#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <cmath>
//1
struct point {
    int cord[3];
};

union vec3 {
    point Point;
    struct {
        int x;
        int y;
        int z;
    };
};

void print(const vec3 vector) {
    //std::cout << "x = " << vector.x << " y = " << vector.y << " z = " << vector.z << '\n';
    std::cout << "x = " << vector.Point.cord[0] << " y = " << vector.Point.cord[1] << " z = " << vector.Point.cord[2];
}
vec3 sum(const vec3 vector1, const vec3 vector2) {
    vec3 result = { vector1.x + vector2.x, vector1.y + vector2.y, vector1.z + vector2.z };
    return result;
}
vec3 sub(const vec3 vector1, const vec3 vector2) {
    vec3 result = { abs(vector1.Point.cord[0] - vector2.Point.cord[0]), abs(vector1.Point.cord[1] - vector2.Point.cord[1]), abs(vector1.Point.cord[2]-vector2.Point.cord[2])};
    return result;
}
int dot(const vec3 vector1, const vec3 vector2) {
    vec3 result = { (vector1.x * vector2.x), (vector1.y * vector2.y),(vector1.z * vector2.z) };
    int actualResult = result.x + result.y + result.z;
    return actualResult;
}

//2
enum ContainmentStatus {
    FullyContained,
    PartiallyContained,
    NotContained
};
struct Point {
    int x;
    int y;
};

struct Rectangle {
    Point lowerLeft;
    Point upperRight;
};

int getDist(const int p1, const int p2) {
    return abs(p1 - p2);
}

int Perimeter(const Rectangle rectangle) {
    int result = (getDist(rectangle.lowerLeft.x, rectangle.upperRight.x) * 2) + (getDist(rectangle.lowerLeft.y,rectangle.upperRight.y) * 2);
    return result;
}
int Lice(const Rectangle rectangle) {
    int result = getDist(rectangle.lowerLeft.x, rectangle.upperRight.x) * getDist(rectangle.lowerLeft.y, rectangle.upperRight.y);
    return result;
}
ContainmentStatus checkContainment(const Rectangle& r1, const Rectangle& r2) {
    bool isFullyInside = (r1.lowerLeft.x >= r2.lowerLeft.x &&
        r1.lowerLeft.y >= r2.lowerLeft.y &&
        r1.upperRight.x <= r2.upperRight.x &&
        r1.upperRight.y <= r2.upperRight.y);

    if (isFullyInside) {
        return FullyContained;
    }

    bool isCompletelyOutside = (r1.upperRight.x < r2.lowerLeft.x ||   
        r1.lowerLeft.x > r2.upperRight.x ||   
        r1.upperRight.y < r2.lowerLeft.y ||   
        r1.lowerLeft.y > r2.upperRight.y);   

    if (isCompletelyOutside) {
        return NotContained;
    }

    return PartiallyContained;
}


//3
struct Name {
    char firstName[16];
    char lastName[16];
};
enum Specialty {
    CompSci,
    Informatics,
    SE,
    IS
};
struct Student {
    Name name;
    int fNumber;
    float averageGrade;
    Specialty specialty;
};
void printStudent(Student& student) {
    std::cout << student.name.firstName << " " << student.name.lastName << " " << student.fNumber << " " << student.averageGrade << " ";
    switch (student.specialty)
    {
    case Specialty::CompSci: std::cout << "CompSci"; break;
    case Specialty::Informatics: std::cout << "Informatics"; break;
    case Specialty::SE: std::cout << "SE"; break;
    case Specialty::IS: std::cout << "IS"; break;
    default: std::cout << "unknown"; break;
    }
}
Student initStudent(char firstName[], char lastName[], int fNumber, float averageGrade, Specialty specialtyNum) {
    Student student;
    strcpy(student.name.firstName, firstName);
    strcpy(student.name.lastName, lastName);
    student.fNumber = fNumber;
    student.averageGrade = averageGrade;
    student.specialty = specialtyNum;
    return student;
}
Student createStudent() {
    Student student;
    std::cout << "Enter first name: ";
    std::cin >> student.name.firstName;
    std::cout << "\nEnter last name: ";
    std::cin >> student.name.lastName;
    std::cout << "\nEnter faculty number: ";
    std::cin >> student.fNumber;
    std::cout << "\nEnter average grade: ";
    std::cin >> student.averageGrade;
    std::cout << "\nEnter specialty(CompSci, Informatics, SE, IS): ";
    char *input = new char[32];
    std::cin >> input;
    if (strcmp("CompSci", input) == 0)
    {
        student.specialty = Specialty::CompSci;
    }
    else if (strcmp("Informatics",input) == 0)
    {
        student.specialty = Specialty::Informatics;
    }
    else if (strcmp("SE",input) == 0)
    {
        student.specialty = Specialty::SE;
    }
    else if (strcmp("IS",input) == 0)
    {
        student.specialty = Specialty::IS;
    }
    else
    {
        std::cout << "Invalid specialty!";
        std::cout << "Defaulting to CompSci!\n";
        student.specialty = Specialty::CompSci;
    }
    delete[] input;
    return student;
}

//4
struct Term {
    double coef;
    int exp;
};
int const MAX_TERMS = 100;

struct Polynomial {
    Term terms[MAX_TERMS];
    int currentCount = 0;
    void printPolynomial() {
        for (int i = 0; i < currentCount; i++)
        {
            double c = terms[i].coef;
            int e = terms[i].exp;
            if (i>0)
            {
                if (c>0) 
                {
                    std::cout << " + ";
                }
                else
                {
                    std::cout << " - ";
                }
            }
            else
            {
                if (c < 0)
                {
                    std::cout << "-";
                }
            }
            double abs_c = std::abs(c);
            if (abs_c != 1 || e == 0)
            {
                std::cout << abs_c;
            }
            if (e>0)
            {
                std::cout << "x";
                if (e>1)
                {
                    std::cout << "^" << e;
                }
            }
        }
        std::cout << "\n";

    }
};
void addTerm(Polynomial& polynomial, const Term newTerm) {
    if (newTerm.coef==0)
    {
        return;
    }
    int i = 0;
    while (i < polynomial.currentCount && polynomial.terms[i].exp > newTerm.exp)
    {
        i++;
    }

    if (i < polynomial.currentCount && polynomial.terms[i].exp == newTerm.exp)
    {
        polynomial.terms[i].coef += newTerm.coef;
        if (polynomial.terms[i].coef == 0)
        {
            for (int j = 0; j < polynomial.currentCount-1; j++)
            {
                polynomial.terms[j] = polynomial.terms[j + 1];
            }
            polynomial.currentCount--;
        }
    }
    else
    {
        if (polynomial.currentCount >= MAX_TERMS)
        {
            std::cout << "The polynomial is full!\n";
            return;
        }
        for (int j = polynomial.currentCount; j > i; j--)
        {
            polynomial.terms[j] = polynomial.terms[j - 1];
        }
        polynomial.terms[i] = newTerm;
        polynomial.currentCount++;
    }
}Polynomial add(const Polynomial& poly1, const Polynomial& poly2) {
    Polynomial result = poly1;
    for (int i = 0; i < poly2.currentCount; i++)
    {
        addTerm(result, poly2.terms[i]);
    }
    return result;
}
Polynomial mult(const Polynomial& poly1, const Polynomial& poly2) {
    Polynomial result;
    for (int i = 0; i < poly1.currentCount; i++)
    {
        for (int j = 0; j < poly2.currentCount; j++)
        {
            Term newTerm;
            newTerm.coef = poly1.terms[i].coef * poly2.terms[i].coef;
            newTerm.exp = poly1.terms[i].exp + poly2.terms[i].exp;
            addTerm(result, newTerm);
        }
    }
    return result;
}
double eval(const Polynomial& poly, double number) {
    double result = 0;
    for (int i = 0; i < poly.currentCount; i++)
    {
        result += (poly.terms[i].coef * (pow(number,poly.terms[i].exp)));
    }
    return result;
}

//5 
enum Genre {
    Novel,
    Historical,
    Poetry,
    Other
};
struct Book {
    char title[50];
    char author[50];
    Genre genre;
    bool available;
};
const int COUNT = 5;
struct Library {
    Book books[COUNT];
    int currentCount = 0;
    void printAllBooks() {
        if (currentCount == 0) {
            std::cout << "The library is empty!\n";
            return;
        }

        for (int i = 0; i < currentCount; i++) {
            std::cout << "- Title: " << books[i].title
                << " | Author: " << books[i].author
                << " | Genre: ";

            switch (books[i].genre) {
            case Novel: std::cout << "Novel"; break;
            case Historical: std::cout << "Historical"; break;
            case Poetry: std::cout << "Poetry"; break;
            case Other: std::cout << "Other"; break;
            }

            std::cout << " | Available: " << (books[i].available ? "Yes" : "No") << "\n";
        }
    }
};
Book InitBook(const char* title, const char* author, const Genre genre, const bool available) {
    Book book;
    strcpy(book.title, title);
    strcpy(book.author, author);
    book.genre = genre;
    book.available = available;
    return book;
}
void addBookToLib(const Book& book, Library &lib) {
    if (lib.currentCount < COUNT)
    {
        lib.books[lib.currentCount] = book;
        lib.currentCount++;
        std::cout << "Added book!";
        if (lib.currentCount == COUNT)
        {
            std::cout << "The library is full!";
        }
        return;
    }
    else
    {
        std::cout << "The library is full!";
    }
}
void getBookByTitle(Library &lib, const char* title) {
    for (int i = 0; i < lib.currentCount; i++)
    {
        if (strcmp(lib.books[i].title,title) == 0)
        {
            lib.books[i].available = false;
            return;
        }
    }
}
void returnBookByTitle(Library& lib, const char* title) {
    for (int i = 0; i < lib.currentCount; i++)
    {
        if (strcmp(lib.books[i].title, title) == 0)
        {
            if (!lib.books[i].available)
            {
                lib.books[i].available = true;
                std::cout << "Returned " << title;
            }
            else
            {
                std::cout << "The book " << title << " was not borrowed.";
            }
            return;
        }
    }
    std::cout << "Book " << title << " does not belong to this library.\n";
}
int main()
{
  //1
  /*  vec3 vector1 = { 1,2,3 };
    vec3 vector2 = { 4,5,6 };
    print(vector1);
    vec3 result = sum(vector1, vector2);
    std::cout << std::endl;
    std::cout << std::endl;
    print(result);
    result = sub(vector1, vector2);
    std::cout << std::endl;
    std::cout << std::endl;
    print(result);
    int dotResult = dot(vector1, vector2);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << dotResult;*/
    
    //2
    /*Rectangle rectangle;
    rectangle.lowerLeft.x = 2;
    rectangle.lowerLeft.y = 5;
    rectangle.upperRight.x = 5;
    rectangle.upperRight.y = 8;
    std::cout << Lice(rectangle);*/

    //3
    /*std::cout << "=== Testing initStudent ===\n";

    char fName[] = "Ivan";
    char lName[] = "Ivanov";

    Student s1 = initStudent(fName, lName, 81234, 5.50, Specialty::SE);
    printStudent(s1);
    std::cout << "\n\n";

    std::cout << "=== Testing createStudent ===\n";
    Student s2 = createStudent();

    std::cout << "\n--- Newly Created Student ---\n";
    printStudent(s2);
    std::cout << "\n";*/

    //4
   /* Term newTerm{ 2,3 };
    Term newTerm2{ 4,3 };
    Polynomial poly;
    Polynomial poly2;
    addTerm(poly, newTerm);
    addTerm(poly, newTerm2);
    addTerm(poly2, newTerm2);
    Polynomial result = add(poly, poly2);
    result.printPolynomial();
    result = mult(poly, poly2);
    result.printPolynomial();
    std::cout << eval(poly, 1);*/

    return 0;
    
}