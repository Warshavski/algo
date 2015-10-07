#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;



///#SORTINGS_START



//#COMMON_START

void swapElements(int *element1, int *element2)
{
	*element1 ^= *element2;
	*element2 ^= *element1;
	*element1 ^= *element2;
}

int *createArray(const int size, const int valueRange)
{
	int *arr = new int[size];
	
	for (int i = 0; i < size; ++i)
		arr[i] = (int)rand() % valueRange;
		
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





//#SIMPLE_SORTINGS_START


//#BUBBLE_SORT
void bubbleSort(int *arr, const int size)
{
	cout << "bubble sort\n" << endl;
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size - i - 1; ++j)
			if (arr[j] > arr[j+1])
				swapElements(&arr[j], &arr[j+1]);
}

//#SELECTION_SORT
void selectionSort(int *arr, const int size)
{
	cout << "selection sort\n" << endl;
	for (int i = 0; i < size - 1; ++i)
	{
		int minIndex = i;
		
		for (int j = i + 1; j < size; ++j)
			if (arr[j] < arr[minIndex])
				minIndex = j;
				
		if (minIndex != i)
			swapElements(&arr[i], &arr[minIndex]);
	}
}

//#INSERTION_SORT
void insertionSort(int *arr, const int size)
{
	cout << "insertion sort\n" << endl;
	for (int i = 1; i < size; ++i)
		for (int j = i; j > 0 && arr[j] < arr[j-1]; --j)
			swapElements(&arr[j], &arr[j-1]);
}

//#SHAKER_SORT (enchanted bubble sort)
void shakerSort(int *arr, const int size)
{
	cout << "shaker sort\n" << endl;
	int left = 0;
	int right = size - 1;
	do
	{
		for (int i = 0; i < size; ++i)
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

//#SHELL_SORT
void shellSort(int *arr, const int size)
{
	cout << "shell sort\n" << endl;
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


//#SIMPLE_SORTINGS_END



///#SORTINGS_END



int main()
{
	const int ARRAY_SIZE = 100;
	const int VALUE_RANGE = 100;
	const int KEY = 100;
	
	int *testArray = createArray(ARRAY_SIZE, VALUE_RANGE);
	
	printArray(testArray, ARRAY_SIZE);
	cout << '\n' << endl;
	
	/* #TEST_SORTINGS
	 * bubbleSort(testArray, ARRAY_SIZE);
	 * selectionSort(testArray, ARRAY_SIZE);
	 * insertionSort(testArray, ARRAY_SIZE);
	 * shakerSort(testArray, ARRAY_SIZE);
	 */
	 
	 
	 
	
	printArray(testArray, ARRAY_SIZE);
	cout << '\n' << endl;
	
	return 0;
}





















































