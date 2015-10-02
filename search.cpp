#include <cstdlib>
#include <stdlib.h>
#include <math.h>
#include <cstdio>
#include <iostream>

using namespace std;

int *createArray(int length, int valueRange)
{
	int *arr = new int[length];
	for (int i = 0; i < length; ++i)
		arr[i] = (int)rand() % valueRange;
	return arr;
}

//#TEST print
void printArray(int *arr, int length)
{
	for (int i = 0; i < length; ++i)
		cout << " " << arr[i];
	cout << endl;
}

// hmmm...
void disposeArray(int *arr)
{
	delete [] arr;
}


///#SORTING

void swapElements(int *element1, int *element2)
{
	*element1 ^= *element2;
	*element2 ^= *element1;
	*element1 ^= *element2;
}

void bubbleSort(int *arr, int size)
{
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size - i - 1; ++j)
			if (arr[j] > arr[j+1])
				swapElements(&arr[j], &arr[j+1]);
}

void selectionSort(int *arr, int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		int minIndex = i;
		
		for (int j = i + 1; j < size; ++j)
			if (arr[j] < arr[minIndex])
				minIndex = j;
		
		if (minIndex != i)
			swapElements(&arr[minIndex], &arr[i]);
	}
}

void insertionSort(int *arr, int size)
{
	for (int i = 1; i < size; ++i)
		for (int j = i; j > 0 && arr[j] < arr[j-1]; --j)
			swapElements(&arr[j], &arr[j-1]);
}

void shakerSort(int *arr, int size)
{
	int left = 0;
	int right = size - 1;
	
	do 
	{
		for (int i = left; i < right; ++i)
			if (arr[i] > arr[i+1])
				swapElements(&arr[i], &arr[i+1]);
		--right;
		
		for (int i = right; i > left; --i)
			if (arr[i] < arr[i-1])
				swapElements(&arr[i], &arr[i-1]);
		++left;
	}
	while (left <= right);
}

void shellSort(int *arr, int size)
{	
	int i, j, k;
	int temp;
	
	for (k = size/2; k > 0; k /= 2)
	{
		for (i = k; i < size; ++i)
		{
			temp = arr[i];
			for (j = i; j >= k; j -= k)
			{
				if (temp < arr[j-k])
					arr[j] = arr[j-k];
				else
					break;
			}
			arr[j] = temp;
		}
	}
}

///#SORTING_END


///#LINEAR_SEARCH

// Сложность O(n) т.к. присутствует один цикл
void linearSearch(int *arr, int length, int key)
{
	int i = 0;
	for(; i < length; ++i)
		if (arr[i] == key)
			break;
	
	if(i < length)
		cout << "key : " << key << " found on the index : " << i << endl;
	else
		cout << "no match found" << endl;
}

// сложность та же, но операций меньше на одну итерацию
void linearSearchOptimize(int *arr, int length, int key)
{
	int i = 0;
	arr[length] = key;
	
	while(arr[i] != key)
		++i;
		
	if(i < length)
		cout << "key : " << key << " found on the index : " << i << endl;
	else
		cout << "no match found" << endl;
}

///#LINEAR_SEARCH_END

///#BINARY_SEARCH

//not optimized
bool binarySearch(int *arr, int key, int size)
{
	int left = 0;
	int right = size -1;
	
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (arr[middle] == key)
		{
			cout << "item found on the index : " << middle << endl;
			return true;
		}
		
		if (arr[middle] < key)
			left = middle + 1;
		else
			right = middle - 1;
	}
	
	cout << "no match found" << endl;
	return false;
}

//optimized
bool binarySearchOptimized(int *arr, int key, int size)
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
	{
		cout << "item found on the index : " << right << endl;
		return true;
	}
	
	cout << "no match found" << endl;
	return false;
}

//recursive
/*
bool binarySearch(int* arr, int key, int low, int hight)
{
	if (low > hight)
	{
		cout << "Error";
		return false;
	}
	int mid = (low + hight) / 2;
	
	if (arr[mid] == key)
		return true;
	if (arr[mid] < key)
		return BinarySearch(arr, key, mid + 1, hight);
	if (arr[mid] > key)
		return BinarySearch(arr, key, low, mid - 1);
		
	return false;
}
*/

///#BINARY_SEARCH_END


int main()
{
	// можешь заменить константы на ввод из консоли или еще чего
	// это неважно
	const int LENGHT = 100;
	const int VALUE_RANGE = 200;
	
	int key = 0;
	cout << "input key : ";
	cin >> key;
	
	cout << endl;
	
	// создаем массив
	int *arr = createArray(LENGHT, VALUE_RANGE);
	
	//#TEST print
	printArray(arr, LENGHT);
	
	cout << endl;
	
	cout << "linear search" << endl;
	linearSearch(arr, LENGHT, key);
	
	cout << "\n" << endl;
	
	cout << "linear search optimized" << endl;
	linearSearch(arr, LENGHT, key);
	
	cout << "\n" << endl;
	
	cout << "sorting..." << endl;
	selectionSort(arr, LENGHT);
	printArray(arr, LENGHT);
	
	cout << "\n" << endl;
	
	cout << "binary search" << endl;
	cout << binarySearch(arr, key, LENGHT);
	
	cout << "\n" << endl;
	
	cout << "linear search optimized" << endl;
	cout << binarySearchOptimized(arr, key, LENGHT);
	
	delete [] arr;
	
	return 1;
}