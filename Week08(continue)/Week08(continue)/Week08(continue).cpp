#include <iostream>
#include "MergeSort.hpp"

bool less(int l, int r) {
	return l < r;
}
int main()
{
	int arr1[6] = { 1,4,5,6,3,2 };
	while (true)
	{
		int* result = mergeSort<int>(arr1, 6, less);
		for (int i = 0; i < 6; i++)
		{
			std::cout << result[i] << " ";
		}
		delete[] result;
	}
	
}
