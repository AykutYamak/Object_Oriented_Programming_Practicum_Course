//#include <iostream>
//#include <cstring>
//#include <functional>
//#pragma warning (disable:4996)
//template<typename T>
//class Pipeline {
//private:
//	std::function<T(T)>* funcs;
//
//	size_t capacity;
//	size_t count;
//	void free() {
//		delete[] funcs;
//		funcs = nullptr;
//		capacity = 0;
//		count = 0;
//	}
//	void copyFrom(const Pipeline& other){
//		this->capacity = other.capacity;
//		this->count = other.count;
//		this->funcs = new std::function<T(T)>[this->capacity];
//		for (int i = 0; i < this->count; i++)
//		{
//			this->funcs[i] = other.funcs[i];
//		}
//	}
//	void resizeFuncs() {
//		size_t newCapacity = (this->capacity == 0) ? 2 : this->capacity * 2;
//		std::function<T(T)>* newFuncs = new std::function<T(T)>[newCapacity];
//		for (size_t i = 0; i < this->count; i++)
//		{
//			newFuncs[i] = this->funcs[i];
//		}
//		delete[] funcs;
//		funcs = newFuncs;
//		capacity = newCapacity;
//	}
//public:
//	Pipeline() {
//		this->capacity = 2;
//		this->count = 0;
//		this->funcs = new std::function<T(T)>[capacity];
//	}
//	Pipeline(const Pipeline& other) {
//		copyFrom(other);
//	}
//	Pipeline<T>& operator=(const Pipeline& other) {
//		if (this!=&other)
//		{
//			free();
//			copyFrom(other);
//		}
//		return *this;
//	}
//	~Pipeline() {
//		free();
//	}
//	
//	Pipeline<T>& pipe(std::function<T(T)> f) {
//		if (this->count >= this->capacity)
//		{
//			resizeFuncs();
//		}
//		this->funcs[this->count] = f;
//		this->count++;
//		return *this;
//	}
//	size_t size() const{
//		return this->count;
//	}
//	void clear() {
//		delete[] this->funcs;
//		this->funcs = nullptr;
//		this->count = 0;
//		this->capacity = 0;
//	}
//	Pipeline<T>& operator()(T val) const{
//		for (size_t i = 0; i < this->count; i++)
//		{
//			val = this->funcs[i](val);
//		}
//		return val;
//	}
//	Pipeline<T>& operator+(const Pipeline<T> other) {
//	Pipeline<T> result;
//		for (size_t i = 0; i < this->count; i++)
//		{
//			result.pipe(this->funcs[i]);
//		}
//		for (size_t i = 0; i < other.count; i++)
//		{
//			result.pipe(other.funcs[i]);
//		}
//		return result;
//	}
//	Pipeline<T>& operator+=(const Pipeline<T> other) {
//		for (size_t i = 0; i < other.count; i++)
//		{
//			this->pipe(other.funcs[i]);
//		}
//		return *this;
//	}
//	T reduce(std::function<T(T, T)> f, T init) const{
//		T accumulator = init;
//		T current_val = init;
//		for (size_t i = 0; i < this->count; i++)
//		{
//			current_val = this->funcs[i](current_val);
//			accumulator = f(accumulator, current_val);
//		}
//	}
//	return accumulator;
//
//};
//
//
//int main() {
//	return 0;
//}