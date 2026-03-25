#include <iostream>
#include <functional>
#include <fstream>

//1
template<typename T>
void swap(T &x, T &y) {
    T temp = x;
    x = y;
    y = temp;
}

//2
void countingSortChar(char* arr, int size) {
    int count[256] = { 0 };
    for (int i = 0; i < size; i++)
    {
        count[(unsigned char)arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i < 256; i++)
    {
        while (count[i] > 0)
        {
            arr[index] = (char)i;
            index++;
            count[i]--;
        }
    }
}
template<typename T>
void insertionSort(T* arr, int size) {
    for (int i = 1; i < size; i++)
    {
        T key = arr[i];
        int j = i - 1;

        while (j>=0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
template<typename T>
void sortArray(T* array, int size) {
    insertionSort(array, size);
}
template<>
void sortArray<char>(char* array, int size) {
    countingSortChar(array, size);
}

//3
template<typename A, typename B, typename R>
std::function<R(B)> curry(R(*f)(A, B), A a) {
    return [f, a](B b) {
        return f(a, b);
    };
}
int sum(int a, int b) {
    return a + b;
}

//4
template<typename R, typename A, typename B>
std::function<R(B, A)> flip(R(*f)(A, B)) {
    return [f](B b, A a) {
        return f(a, b);
    };
}

//5
template<typename T>
void sortBy(T* arr, size_t size, std::function<bool(const T&)> f) {
    for (size_t i = 1; i < size; i++)
    {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && f(arr[j]) > f(key))
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
//6
template<typename T, typename U>
T accumulate(std::function<T(const U&, const T&)> op,
            const T& nv, 
            std::function<U(int)> term, 
            int a, int b)
{
    T result = nv;
    while (a <= b) {
        result = op(term(b), result);
        b--;
    }
    return result;
}
//Bonus
template<class T>
T* createArrFromRange(int a, int b, std::function<T(int)> term) {
    size_t size = b - a + 1;
    T* arr = new T[size];
    return accumulate<T*, T>([&size](const T& x, T* arr) {arr[(size--) - 1] = x; return arr;}, arr, term, a, b);
}
int* createArrFromRange(int a, int b) {
    return createArrFromRange<int>(a, b, [](int x) {return x;});
}

//7
template<class V, class K>
struct Record {
    K key;
    V value;
};

template<class T, size_t N>
struct Collection {
    T* records[N];
};

template<typename T, size_t N>
void readCollection(Collection<T, N>& c, const char* filename) {
    std::ifstream in(filename, std::ios::in);
    if (!in.is_open())
    {
        throw "error, file didn't open!";
    }
    for (size_t i = 0; i < N && in; i++)
    {
        in >> c.records[i].key;
        in >> c.records[i].value;
    }
    in.close();
}
template<typename T, size_t N>
void writeCollection(const Collection<T, N>& c, const char* filename) {
    std::ofstream ofs(filename, std::ios::out);
    if (!ofs.is_open())
    {
        throw "error, file didn't open!";
    }
    for (size_t i = 0; i < N; i++)
    {
        ofs << c.records[i].key << " " << c.records[i].value << '\n';
    }
    ofs.close();
}

template<typename T, size_t N>
T maxRecord(const Collection<T, N>& c)
{
    size_t maxInd = 0;
    for (size_t i = 0; i < N; i++)
    {
        if (c.records[maxInd].value < c.records[i].value)
        {
            maxInd = i;
        }
    }
    return c.records[maxInd];
}

template<typename T, size_t N>
void sortByValue(Collection<T, N>& c) {
    sortBy(c.records, N, [](const T& record) {return record.value; });
} 

template<typename T, size_t N>
int filter(const Collection<T, N>& c, std::function<bool(const T&)> pred) {
    int count = 0;
    for (size_t i = 0; i < N; i++)
    {
        if (pred(c.records[i]))
        {
            count++;
        }
    }
    return count;
}

//8
template<class T, size_t N>
struct Vector {
    T arr[N];
    size_t size;
};

template<typename T, typename U, size_t N>
Vector<U, N> map(std::function<U(const T&)> f, const Vector<T, N>& vec) {
    Vector<U, N> result;
    result.size = vec.size;
    for (size_t i = 0; i < vec.size; i++)
    {
        result.arr[i] = f(vec.arr[i]);
    }
    return result;
}

template<typename T, size_t N>
Vector<T, N> filter(std::function<bool(const T&)> f, const Vector<T, N>& vec) {
    Vector<T, N> result;
    for (size_t i = 0; i < vec.size; i++)
    {
        if (f(vec.arr[i]))
        {
            result.arr[result.size] = vec.arr[i];
            result.size++;
        }
    }
    return result;
}
template<typename T, size_t N>
bool all(std::function<bool(const T&)> f, const Vector<T, N> &vec) {
    for (size_t i = 0; i < vec.size; i++)
    {
        if (!f(vec.arr[i])) return false;
    }
    return true;
}

template<typename T,size_t N>
bool any(std::function<bool(const T&)> f, const Vector<T, N>& vec) {
    return !all([f](const T& x) {return !f(x);}, vec);
}

template<typename T, typename U, typename V, size_t N>
Vector<V, N> zipWith(std::function<V(const T&, const V&)> op, const Vector<T, N>& vec1, const Vector<U, N>& vec2) {
    Vector<V, N> result;
    result.size = std::min({ vec1.size, vec2.size });
    for (size_t i = 0; i < result.size; i++)
    {
        result.arr[i] = op(vec1.arr[i], vec2.arr[i]);
    }
    return result;
}

int main()
{
   /* int result = flip<int,int,int>([](int x, int y) { return x - y; })(2, 1);
    int arr[5] = { 1,2,3,4,5 };
    size_t size = 5;

    sortBy<int>(arr, size, [](int x) 
        {return x % 2;}
    );

    std::cout << "arr = {";
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << (i < size - 1 ? ", " : "");
    }
    std::cout << "}\n";*/
  /*  std::cout << accumulate<int, int>([](int x, int y) {return x + y;}, 0, [](int x) {return x;}, 0, 10) << std::endl;
    int* arr = createArrFromRange<int>(1, 10, [](int x) {return x;});
    for (int i = 0; i < 10; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;*/

    //8
    Vector<int, 10> v1 = { {1,2,3,4,5}, 5 };
    Vector<int, 10> v2 = { {5,4,3,2}, 4 };
    Vector<int, 10> v3 = zipWith<int, int, int>([](int x, int y) {return x * y; }, v1, v2);
    for (int i = 0; i < v3.size; i++) {
        std::cout << v3.arr[i] << " "; // 5 8 9 8
    }
    return 0;
}

