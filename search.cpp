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
	
	delete [] arr;
	
	return 1;
}