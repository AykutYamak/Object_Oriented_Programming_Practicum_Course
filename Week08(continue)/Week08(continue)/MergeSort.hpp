#include <iostream>
#include <functional>
template<typename T>
T* merge(const T* left, const T* right, unsigned lSize, unsigned rSize, const std::function<bool(T, T)>& compare) {
	T* result = new T[lSize + rSize];
	unsigned posLeft = 0, posRight = 0;
	while (posLeft < lSize && posRight < rSize)
	{
		if (compare(left[posLeft], right[posRight]))
			result[posLeft + posRight] = left[posLeft++];
		else
			result[posLeft + posRight] = right[posRight++];
	}
	while (posRight < rSize)
	{
		result[posLeft + posRight] = right[posRight++];
	}
	while (posLeft < lSize)
	{
		result[posLeft + posRight] = left[posLeft++];
	}
	delete[] left;
	delete[] right;
	return result;
}
template<typename T>
T* mergeSort(T* array, unsigned size, const std::function<bool(T,T)>& compare) {
	if (size == 0)
	{
		return nullptr;
	}
	else if (size == 1)
	{
		return array;
	}
	unsigned leftSize = size / 2;
	unsigned rightSize = size - leftSize;
	T* left = new T[leftSize];
	T* right = new T[rightSize];

	for (int i = 0; i < leftSize; i++)
	{
		left[i] = array[i];
	}
	for (int i = 0; i < rightSize; i++)
	{
		right[i] = array[leftSize + i];
	}
	T* leftNew = mergeSort(left, leftSize, compare);
	T* rightNew = mergeSort(right, rightSize, compare);
	if (leftSize > 1) delete[] left;
	if (rightSize > 1) delete[] right;
	T* res = merge(leftNew, rightNew,leftSize, rightSize,compare);

	return res;

}