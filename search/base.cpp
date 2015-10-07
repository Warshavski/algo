#include <cstdlib>
#include <stdlib.h>
#include <math.h>
#include <cstdio>
#include <iostream>

using namespace std;


///#SEARCH_START



//#COMMON_START

int *createArray(const int size, const int valueRange)
{
	int *arr = new int[size];
	
	for (int i = 0; i < size; ++i)
		arr[i] = (int)rand() % valueRange;
		
	return arr;
}

int *createArray(const int size)
{
	int *arr = new int[size];
	
	for (int i = 0; i < size; ++i)
		arr[i] = i;
		
	return arr;
}

void printArray(int *arr, const int size)
{
	for (int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

void resetArray(int *arr, const int size, const int valueRange)
{
	for (int i = 0; i < size; ++i)
		arr[i] = (int)rand() % valueRange;
}

//#COMMON_END





//#LINEAR_SEARCH
bool linearSearch(int *arr, const int size, const int key)
{
	int i = 0;
	for (; i < size; ++i)
		if (arr[i] == key)
			break;
	
	if (i < length)
		return true;
	return false;
}

//#LINEAR_SEARCH_OPTIMIZE
bool linearSearchOptimize(int *arr, const int size, const int key)
{
	arr[size] = key;
	int i = 0;
	
	while (arr[i] != key)
		++i;
		
	if (i < size)
		return true;
	return false;
}

//#BINARY_SEARCH
bool binarySearch(int *arr, const int size, const int key)
{
	int left = 0;
	int right = size - 1;
	
	while (left <= right)
	{
		int middle = (left + right) / 2;
		
		if (arr[middle] == key)
			return true;
		
		if (arr[middle] < key)
			left = middle + 1;
		else
			right = middle - 1;
	}
	
	return false;
}

//#BINARY_SEARCH_OPTIMAIZE
bool binarySearchOptimaize(int *arr, const int size, const int key)
{
	int left = 0;
	int right = size - 1;
	
	while (left < right)
	{
		int middle = (left + right) / 2;
		
		if (arr[middle] < key)
			left = middle + 1;
		else
			right = middle;
	}
	
	if (arr[right] == key)
		return true;
		
	return false;
}

//#BINARY_SEARCH_RECUR
bool binarySearch(int *arr, const int left, const int right, const int key)
{
	if (left > right)
		return false;
		
	int middle = (left + right) / 2;
	
	if (arr[middle] == key)
		return true;
	
	if (arr[middle] > key)
		binarySearch(arr, left, middle - 1, key);
		
	if (arr[middle < key)
		binarySearch(arr, middle + 1, right, key);
	
	return false;
}



///#SEARCH_END


int main()
{
	/* #TEST_SEARCH
	  * linearSearch(testArray, ARRAY_SIZE, KEY);
	  * linearSearchOptimize(testArray, ARRAY_SIZE, KEY);
	  * binarySearch(testArray, ARRAY_SIZE, KEY);
	  * binarySearchOptimize(testArray, ARRAY_SIZE, KEY);
	  * binarySearch(testArray, 0, ARRAY_SIZE - 1, KEY);
	  */
}
