#include <iostream>
#include <functional>
template<typename T>
T max_element(T x, T y) {
	return (x > y) ? x : y;
}
template<typename T>
void printArray(const T* array, size_t size, std::ostream& os = std::cout) {
	for (size_t i = 0; i < size; i++)
	{
		std::cout << array[i] << " ";
	}

}
template<typename T>
T* createAndFillArray(size_t size, T value) {
	T* newArray = new T[size];
	for (int i = 0; i < size; i++)
	{
		newArray[i] = value;
	}
	return newArray;
}
template<typename T>
void map(std::function<T(T)> f, T* arr, size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = f(arr[i]);
	}
}
template<typename T>
T* filter(std::function<bool(T)> f, const T* arr, size_t size, size_t& newSize) {
	newSize = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (f(arr[i]))
		{
			newSize++;
		}
	}
	if (newSize == 0)
	{
		return nullptr;
	}
	int resultIndex = 0;
	T* result = new T[newSize];
	for (size_t i = 0; i < size; i++)
	{
		if (f(arr[i]))
		{
			result[resultIndex++] = arr[i];
		}
	}

	return result;
}
template<typename T, typename R>
R reduce(std::function<R(R, T)> f, R initial, const T* arr, size_t size) {
	R accumulator = initial;
	for (size_t i = 0; i < size; i++)
	{
		accumulator = f(accumulator, arr[i]);
	}
	return accumulator;
}
template<typename T,typename V, typename R>
std::function<R(V)> compose(std::function<R(T)> f, std::function<T(V)> g) {
	return [f, g](V x) {
		return g(f(x));
		};
}
template<typename T>
struct Result {
	T value;
	int index;
};
template<typename T>
Result<T> findBy(std::function<bool(T)> f, T* arr, size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		if (f(arr[i]))
		{
			
			return { arr[i], (int)i };
		}
	}
	return { T(),-1};
}
bool even(int x) { return x % 2 == 0; }
template<typename R, typename T, typename U>
std::function<R(U, T)> flip_func(std::function<R(T, U)> f) {
	return[f](U y, T x) {
		return f(x, y);
		}
}


int main() {
	int arr[4] = { 1, 2, 3, 4 };

	Result<int> res = findBy<int>(even, arr, 4);

	if (res.index != -1) {
		std::cout << "value: " << res.value << ", index: " << res.index << std::endl;
	}
	else {
		std::cout << "not found" << std::endl;
	}
	return 0;
}