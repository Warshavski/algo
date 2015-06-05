#include <vector>
#include <bitset>
#include <cstring>
#include <cassert>
#include <list>
#include <string>

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime> 

using namespace std;

/* Fill matrix from *.txt file
void FillMatrix()
{
	const int size = 10;
	int[] array = new int[size];
	fstream myfile("123.txt",ios::in);
	
	while (!myfile.eof())
	{
		// текущий столбец
		int currCol = 0;
		// строковый поток в него будем записывать 
		// прочитанную строку из файла, 
		// чтобы посимвольно считать в массив
		std::stringstream strst;
		// массив куда считывается строки из файла
		char buff[1024];
		// само чтение строки из файла в массив
		myfile.getline(buff,1024); 
		// заполнение строкового потока
		strst << buff; 
		// чтение строкового потока до конца 
		// аналогично fstream
		while(!strst.eof()) 
		{
			// переменная в которую считывается символ из строкового потока
			// + неявное преобразование в тип int из char
			int value;
			// считывание символа
			strst >> value ;
			// запись значения в матрицу
			matrix[currRow][currCol] = value;
			// переход к следующему значению матрицы (колонка)
			++currCol;
		}
		// переход на следующую строку матрицы
		++currRow;
	}
	// закрытие файлового потока
	myfile.close();
	break;
}

void matrix()
{
	int rowsQnt = 0;
	int colsQnt = 0;
	
	cout << "Input rows quantity : ";
	cin >> rowsQnt;
	cout << "Input cols quantity : ";
	cin >> colsQnt;
	
	cout << endl;
	
	// объявление матрицы
	int **matrix;
	
	int fillMethod = 0;
	cout << "Input method :\n1. Custom method\n2. Read from file" << endl;
	cin >> fillMethod;
	
	switch (fillMethod)
	{
		case 1:
			// создание матрицы 
			// создание массива указателей на массив указателей
			// (динамический двумерный массив)
			*(&matrix) = new int* [rowsQnt];
			for (int i = 0; i < rowsQnt; ++i)
				matrix[i] = new int [colsQnt];
		
			// заполнение матрицы вручную
			for (int i = 0; i < rowsQnt; ++i)
			{
				cout << "Line " << i << " : " << endl;
				for (int j = 0; j < colsQnt; ++j)
				{
					int value = 0;
					cout << "\tInput value " << j << " : ";
					cin >> value;
					matrix[i][j] = value;
				}
			}
			break;
		case 2:
			// создание матрицы
			*(&matrix) = new int* [rowsQnt];
			for (int i = 0; i < rowsQnt; ++i)
				matrix[i] = new int [colsQnt];
			// функция чтения из файла (открытие файла по заданному пити)
			// fstream [имя фунции]("путь к файлу", [параметры])
			fstream myfile("123.txt",ios::in);
			// текущая строка
			int currRow = 0;
			// чтение до конца файла eof(end of file)
			// т.е. будет выполняться тело цикла пока 
			// не дойдем до символа конца файла
			while (!myfile.eof())
			{
				// текущий столбец
				int currCol = 0;
				// строковый поток в него будем записывать 
				// прочитанную строку из файла, 
				// чтобы посимвольно считать в массив
				std::stringstream strst;
				// массив куда считывается строки из файла
				char buff[1024];
				// само чтение строки из файла в массив
				myfile.getline(buff,1024); 
				// заполнение строкового потока
				strst << buff; 
				// чтение строкового потока до конца 
				// аналогично fstream
				while(!strst.eof()) 
				{
					// переменная в которую считывается символ из строкового потока
					// + неявное преобразование в тип int из char
					int value;
					// считывание символа
					strst >> value ;
					// запись значения в матрицу
					matrix[currRow][currCol] = value;
					// переход к следующему значению матрицы (колонка)
					++currCol;
				}
				// переход на следующую строку матрицы
				++currRow;
			}
			// закрытие файлового потока
			myfile.close();
			break;
	}
	
	// выполнение операции
	int minSum = 0;
	int rowNum = -1;
	for (int i = 0; i < rowsQnt; ++i)
	{
		int rowSum = 0;
		for (int j = 0; j < colsQnt; ++j)
		{
			int value = matrix[i][j];	
			if (value < 0 && value > -2)
				rowSum += value;
		}
		if (rowSum < minSum)
		{
			minSum = rowSum;
			rowNum = i;
		}
	}
	
	if (rowNum == -1)
		cout << "No result" << endl;
	else
		cout << "Min sum : " << minSum << " at row #" << rowNum << endl;
	
	// удаление матрицы
	for (int i = 0; i < rowsQnt; ++i) 
        delete []matrix[i];
}
*/

/* Shrunk Array
void ShrunkArray(int value, int* arr, int &size)
{
    for(int i = 0; i < size; ++i)
    {
        if(arr[i] == value) 
        {
            for(int j = i; j < size - 1; ++j)
				arr[j] = arr[j + 1];
            --size;
            --i;
        }
    }
}

int ShrunkArray2(int value, int* arr, int size) 
{
	for(int i = 0; i < size; i++) 
	{
		if(arr[i] == value) 
		{
			for(int j = i; j < size - 1; arr[j] = arr[j + 1], ++j);
			--size;
			i--;
		}
	}
	return size;
}
*/

/* for struct Student
struct student
{
    int number;
    char fio[20];
    char facult[6];
    char shifr[8];
};

void Input(student *arr, int N) //1
{
    for(int i = 0; i < N; ++i)
    {
        cout << "Student #" << i+1 << endl;
        arr[i].number = i+1;
        cout << "Input Fio: ";
        cin >> arr[i].fio;
        cout << "Input FAQ: ";
        cin >> arr[i].facult;
        cout << "Input group code: ";
        cin >> arr[i].shifr;
        cout << endl;
    }
}

void PrintEntry(student entry)
{
	cout << "Student #" << entry.number << endl;
	cout << "   Fio : " << entry.fio << endl;
	cout << "   Faculty : " << entry.facult << endl;
	cout << "   Group code : " << entry.shifr << endl;
	cout << endl;
}

void PrintArray(student *arr, int size)
{
	for (int i = 0; i < size; ++i)
		PrintEntry(arr[i]);
	cout << endl;
}

void SaveToFile(student *arr, int size, char *path)
{
	ofstream stduFile;
	stduFile.open(path);
	
	for (int i = 0; i < size; ++i)
	{
		stduFile << arr[i].number << ',';
		stduFile << arr[i].fio << ',';
		stduFile << arr[i].facult << ',';
		stduFile << arr[i].shifr;
		stduFile << '\n';
	}
	
	stduFile.close();
}
*/



int *CreateArray(int size, int valueRange)
{
	int *arr = new int[size];
	for (int i = 0; i < size; ++i)
		arr[i] = (int)rand() % valueRange;
	return arr;
}

int *CreateArray(int &size, char *path)
{
	int *arr = NULL;
	ifstream file(path);
	
	if (file.is_open())
	{
		file >> size;
		
		arr = new int[size];
		for (int i = 0; !file.eof(); ++i)
			file >> arr[i];
		file.close();
	}
	return arr;
}

void DeleteArray(int *arr)
{
	delete [] arr;
	arr = 0;
}

void ResetArray(int *arr, int size, int valueRange)
{
	for (int i = 0; i < size; ++i)
		arr[i] = (int)rand() % valueRange;
}

void PrintArray(int *arr, int size)
{
	for (int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

void PrintArray(int *arr, int size, char *path)
{
	const int inRow = 20;
	ofstream outFile;
	outFile.open(path);
	
	outFile << size << '\n';
	for (int i = 0, j = 0; i < size; ++i, ++j)
	{
		if (j == inRow)
		{
			outFile << '\n';
			j = 0;
		}
		outFile << arr[i] << " ";
	}
	
	outFile.close();
}

void Print(int *arr, int size)
{
	int key = -1;
	
	cout << "Print method :\n"
			"#1 - Console\n"
			"#2 - File\n"
			"#0 - Break\n" << endl;
	
	while (key != 0)
	{
		cout << "Print menu : ";
		cin >> key;
		
		switch (key)
		{
			case 1 :
				PrintArray(arr, size);
				key = 0;
				break;
			case 2 :
				char path[255];
				cout << "Input file path : ";
				cin >> path;
				PrintArray(arr, size, path);
				key = 0;
			default :
				cout << "wrong key!" << endl;
		}
	}
}

void SwapElements(int* elem1 , int* elem2)
{
	*elem1 ^= *elem2;
	*elem2 ^= *elem1;
	*elem1 ^= *elem2;
}

int *DistinctArray(int *arr, int &size)
{
	/*
	for (int i = 0; i < size; ++i)
		for (int j = i + 1; j < size; ++j)
			if (arr[i] == arr[j])
			{
				for (int k = j; k < size - 1; ++k)
					SwapElements(&arr[k], &arr[k+1]);
				--size;
				--j;
			}
	
	int *resultArr = new int[size];
	for (int i = 0; i < size; ++i)
		resultArr[i] = arr[i];
		
	delete [] arr;
	return resultArr;
	*/
	int temp = arr[0];
	int count = 0;
	for (int i = 1; i < size; ++i)
	{
		if (arr[i] != temp)
		{
			for (int j = i + 1; j < size; ++j)
				if (arr[i] == arr[j])
					arr[j] = temp;
		}
		else
			++count;
	}
	
	cout << count << endl;
	int *result = new int[size - count];
	result[0] = arr[0];
	for (int i = 1, j = 0; i < size; ++i)
		if (arr[i] != arr[0])
			result[++j] = arr[i];
	size -= count;
	delete [] arr;
	arr = NULL;
	return result;
}
	
bool BinarySearch(int* arr, int value, int low, int hight)
{
	if (low > hight)
	{
		cout << "Error ";
		return false;
	}
	int mid = (low + hight) / 2;
	
	if (arr[mid] == value)
		return true;
	if (arr[mid] < value)
		return BinarySearch(arr, value, mid + 1, hight);
	if (arr[mid] > value)
		return BinarySearch(arr, value, low, mid - 1);
	return false;
		
	/*
	int mid = (low + hight) / 2;
	if (mid == 1)
	{
		if (arr[0] == value)
			return true;
		else 
			return false;
	}
	
	if (value < arr[mid])
		return BinarySearch(arr, value, low, mid - 1);
	else if (value > arr[mid])
		return BinarySearch(arr, value, mid + 1, hight);
	else
		return true;
	*/
}
	
void BubbleSort(int *arr, int size)
{
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size - 1 - i; ++j)
			if (arr[j] > arr[j+1])
				SwapElements(&arr[j], &arr[j+1]);
}

void InsertionSort(int *arr, int size)
{	
	for (int i = 1; i < size; ++i)
		for (int j = i; j > 0 && arr[j] < arr[j-1]; --j)
			SwapElements(&arr[j], &arr[j-1]);
	/*
	for (int i = 1; i < size; ++i)
		for (int j = i; j > 0 && arr[j] < arr[j-1]; --j)
			SwapElements(&arr[j], &arr[j-1]); */
}

void InsertionSort(int *arr, int bottom, int top)
{
	int i, j;	
	for (int i = bottom + 1; i <= top; ++i)
	{
		int j = 0;
		int temp = arr[i];
		for (j = i - 1; j >= bottom && arr[j] > temp; --j)
			arr[j+1] = arr[j];
		arr[j+1] = temp;
	}
	
	/*
	int i;
	int j;
	for (i = low + 1; i <= hight; ++i)
	{
		int temp = arr[i];
		for (j = i - 1; j >= low && arr[j] > temp; --j)
			arr[j+1] = arr[j];
		arr[j+1] = temp;
	}
	*/
}

void SelectionSort(int *arr, int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		int min = i;
		for (int j = i + 1; j < size; ++j)
			if (arr[j] < arr[min])
				min = j;
		if (min != i)
			SwapElements(&arr[i], &arr[min]);
	}
}

void ShakerSort(int *arr, int size)
{
	int start = 0;
	int end = size - 1;
	
	do
	{
		for (int i = end; i > start; --i)
			if (arr[i] < arr[i-1])
				SwapElements(&arr[i], &arr[i-1]);
		++start;
		
		for (int i = start; i < end; ++i)
			if (arr[i] > arr[i+1])
				SwapElements(&arr[i], &arr[i+1]);
		--end;
	}
	while (start <= end);
}

void GnomeSort(int *arr, int size)
{
	/*
	int i = 1;
	while (i < size)
	{
		if (i == 0 || arr[i] > arr[i - 1])
			++i;
		else
		{
			SwapElements(&arr[i], &arr[i-1]);
			--i;
		}
	}
	*/
	cout << "###FAIL###" << endl;
}

void ShellSort(int *arr, int size)
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
	/*
	unsigned long i, j, inc; 
	float temp; 
	inc = 1;                         // начальный инкремент 
	
	do 
	{
		inc *= 3; 
		++inc; 
	} 
	while (inc <= size); 
	
	do // Цикл частичных сортировок
	{                           
		inc /= 3; 
		// Внутренний цикл простых вставок
		for (i = inc + 1; i <= size; i++) 
		{
			temp = arr[i]; 
			j = i; 
			while (arr[j-inc] > temp) 
			{
				arr[j] = arr[j-inc]; 
				j -= inc; 
				if ( j <= inc ) 
					break; 
			}
			arr[j] = temp; 
		}
	} 
	while (inc > 1); 
	*/
}

///*---- Start Merge Sort ----
/* Проверка массива на пустоту (не верное)
	- *arr - указатель на массив
	- size - размер массива
*/
bool IsEmpty(int *arr, int size)
{
	for (int i = 0; i < size; ++i)
		if (arr[i] != 0)
			return false;
	return true;
}

/* Слияние двух массивов
	- *A - указатель на первый массив
	- alen - длина первого массива
	- *B - указатель на второй массив
	- blen - длина второго массива
*/
// приоритетная функция слияния
int *Merge (int *A, int alen, int *B, int blen)
{
	/*
	if (IsEmpty(A, alen) == true)
		return B;
	if (IsEmpty(B, blen))
		return A;
	*/
	int* result = new int[alen + blen];
	
	int index = 0;
	while (alen && blen)
	{
		if (*A < *B)
		{
			result[index] = *A;
			++A;
			--alen;
		}
		else
		{
			result[index] = *B;
			++B;
			--blen;
		}
		++index;
	}
	
	if (alen == 0)
		for (; blen != 0; --blen, ++index, ++B)
			result[index] = *B;	
	else if (blen == 0)
		for (; alen != 0; --alen, ++index, ++A)
			result[index] = *A;
	return result;
}

void Merge(int *arr, int lBoundary, int rBoundary, int mid)
{
	int lInc = 0, rInc = 0;
	int *tempArr = new int[rBoundary - lBoundary];
	
	while ((lBoundary + lInc < mid) && (mid + rInc < rBoundary))
	{
		if (arr[lBoundary + lInc] < arr[mid + rInc])
		{
			tempArr[lInc + rInc] = arr[lBoundary + lInc];
			++lInc;
		}
		else 
		{
			tempArr[lInc + rInc] = arr[mid + rInc];
			++rInc;
		}
	}
	
	while (lBoundary + lInc < mid)
	{
		tempArr[lInc + rInc] = arr[lBoundary + lInc];
		++lInc;
	}
	
	while (mid + rInc < rBoundary)
	{
		tempArr[lInc + rInc] = arr[mid + rInc];
		++rInc;
	}
	
	for (int i = 0; i < lInc + rInc; ++i)
		arr[lBoundary + i] = tempArr[i];
		
	delete [] tempArr;
	tempArr = NULL;
	
	/* Test example
	int lInc = 0, rInc = 0;
	int *tempArr = new int[rBoundary - lBoundary];
	
	while ((lBoundary + lInc < mid) && (mid + rInc < rBoundary))
	{
		if (arr[lBoundary + lInc] < arr[mid + rInc])
		{
			tempArr[lInc + rInc] = arr[lBoundary + lInc];
			++lInc;
		}
		else
		{
			tempArr[lInc + rInc] = arr[mid + rInc];
			++rInc;
		}	
	}
	
	while (lBoundary + lInc < mid)
	{
		tempArr[lInc + rInc] = arr[lBoundary + lInc];
		++lInc;
	}
	
	while (mid + rInc < rBoundary)
	{
		tempArr[lInc + rInc] = arr[mid + rInc];
		++rInc;
	}
	
	for (int i = 0; i < rInc + lInc; ++i)
		arr[lBoundary + i] = tempArr[i];
		
	delete [] tempArr;
	tempArr = NULL;
	*/
}

/* слияние для рекурсивной фунции
void merge(int *arr, int left, int mid, int right)
{
	int it1 = 0;
	int it2 = 0;
	int *temp = new int[right - left];
	
	while ((left + it1 < mid) && (mid + it2 < right))
	{
		if (arr[left + it1] < arr[mid + it2])
		{	
			temp[it1 + it2] = arr[left + it1];
			it1 += 1;
		}
		else
		{
			temp[it1 + it2] = arr[mid + it2];
			it2 += 1;
		}	
	}
	
	while (left + it1 < mid)
	{
		temp[it1 + it2] = arr[left + it1];
		it1 += 1;
	}
	
	while (mid + it2 < right)
	{
		temp[it1 + it2] = arr[mid + it2];
		it2 += 1;
	}
	
	for (int i = 0; i < it1 + it2; ++i)
		arr[left + i] = temp[i];
	delete [] temp;
}
*/

///* Итеративная версия сортировки слиянием («Восходящая сортировка слиянием»).
void MergeSort(int* arr, int size)
{
	int n = 1, l, ost;
	int *tempArr;
	while (n < size)
	{
		l = 0;
		while (l < size)
		{
			if (l + n >= size) 
				break;
				
			ost = (l + n * 2 > size) ? (size - (l + n)) : n;
			tempArr = Merge(arr + l, n, arr + l + n, ost);
			
			for (int i = 0; i < n + ost; i++) 
				arr[l+i] = tempArr[i];
			delete [] tempArr;
			l += n * 2;
		}
		n *= 2;
	}
}

///* Рекурсивная соритровка слиянием
void RecurMergesort(int *arr, int left, int right)
{
	if (left + 1 >= right)
		return;
	int mid = (left + right) / 2;
	RecurMergesort(arr, left, mid);
	RecurMergesort(arr, mid , right);
	Merge(arr, left, right, mid);
}

void RecurMergesortInter(int *arr, int size)
{
	int left = 0;
	int right = size;
	RecurMergesort(arr, left, right);
}
///* ---- End Merge Sort ----

///* ---- Start Quick Sort ----
int Partition(int low, int hight, int *arr)
{
	int i = low + 1, j = hight;
	int p = low + ((hight - low) >> 1);
	int pivot = arr[p];
	arr[p] = arr[low];
	
	while (1)
	{
		while (i < j && pivot > arr[i]) ++i;
		while (j >= i && arr[j] > pivot) --j;
		if (i >= j)
			break;
		
		SwapElements(&arr[i], &arr[j]);
		++i;
		--j;
	}
	arr[low] = arr[j];
	arr[j] = pivot;
	
	return j;
}

void QuickSort(int *arr, int low, int hight)
{
	int pivot;
	if (hight - low < 12)
	{
		InsertionSort(arr, low, hight);
		return;
	}	
	
	while (low < hight)
	{
		pivot = Partition(low, hight, arr);
		if (pivot - low <= hight - pivot)
		{
			QuickSort(arr, low, pivot - 1);
			low = pivot + 1;
		}
		else
		{
			QuickSort(arr, pivot, hight);
			hight = pivot - 1;
		}
	}
}

void QuickSortIter(int *arr, int size)
{
	int low = 0;
	int hight = size - 1;
	QuickSort(arr, low, hight);
}
///* ---- End Quick Sort ----

///* ---- Start Heap Sort ----
void DownHeap (int *arr, int rootIndex, int size)
{
	int childIndex;
	int newRoot = arr[rootIndex];
	
	while (rootIndex <= size/2)
	{
		childIndex = rootIndex * 2;
		if (childIndex < size && arr[childIndex] < arr[childIndex+1])
			++childIndex;
		
		if (newRoot >= arr[childIndex])
			break;
		
		arr[rootIndex] = arr[childIndex];
		rootIndex = childIndex;
	}
	arr[rootIndex] = newRoot;
}

void HeapSort(int *arr, int size)
{
	int i;
	for (i = size/2; i >= 1; --i)
		DownHeap(arr, i, size);
		
	for (i = size; i > 1; --i)
	{
		SwapElements(&arr[i], &arr[1]);
		DownHeap(arr, 1 , i - 1);
	}
}
///* End Head Sort

void ShowTooltip()
{
	cout << "#1 - Show tip\n" 
		"#2 - Create array\n" 
		"#3 - Print array\n" 
		"#4 - Reset array\n"
		"#5 - Delete array\n"
		"#6 - Distinct array\n"
		"#7 - Sort array\n"
		"#8 - Search\n"
		"#0 - Exit" << endl;
}

void ShowSortTip()
{
	cout << "Choose sorting method :\n"
			"#1 - Bubble sort\n"
			"#2 - Insertion sort\n"
			"#3 - Selection sort\n"
			"#4 - Shaker sort\n"
			"#5 - Gnome sort\n"
			"#6 - Shell sort\n"
			"#7 - Merge sort\n"
			"#8 - Recursive Merge sort\n"
			"#9 - Quick Sort\n"
			"#10 - Heap Sort\n"
			"#0 - Exit\n" << endl;
}

int SetSearchValue()
{
	int searchValue;
	cout << "Input search value : ";
	cin >> searchValue;
	return searchValue;
}

typedef bool searchFunc(int*, int, int, int);
void Search(int *arr, int size)
{
	clock_t time = clock(); // начальное время
			
	const int varQnt = 1;
	searchFunc *search[varQnt] = {BinarySearch};
	int key = -1;
	
	cout << "Choose searching method :\n"
			"#1 - Binary search\n"
			"#0 - Break\n" << endl;
	while (key != 0)
	{
		cout << "Search menu : ";
		cin >> key;
		if (key == 1)
		{
			cout << "Result : " << search[key-1](arr, SetSearchValue(), 0, size) << endl;
			time = clock() - time; // конечное время
			cout << (double)time/CLOCKS_PER_SEC << endl;
			key = 0;
		}
		else
			cout << "wrong key!" << endl;
	}
}

typedef void sortFunc(int*, int);
void Sort(int *arr, int size)
{
	clock_t time;
	const int varQnt = 10;
	int reservedKey[varQnt] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	sortFunc *sort[varQnt] = {BubbleSort, InsertionSort, SelectionSort, 
				ShakerSort, GnomeSort, ShellSort, MergeSort,
				RecurMergesortInter, QuickSortIter, HeapSort};
				
	ShowSortTip();
	
	int key = -1;
	while (key != 0)
	{
		cout << "Sort menu : ";
		cin >> key;
		if (BinarySearch(reservedKey, key, 0, varQnt))
		{
			time = clock(); // начальное время
			sort[key-1](arr, size);
			time = clock() - time; // конечное время 
			cout << (double)time/CLOCKS_PER_SEC << endl;
			
			key = 0;
		}
		else
			cout << "wrong key!" << endl;
	}
}

int main()
{
	//unsigned long long int a = 0;
	int *arr = NULL;
	int size = 0, valueRange = 400;
	int key = -1;
	
	
	clock_t time;
	ShowTooltip();
	while (key != 0)
	{
		cout << endl;
		cout << "Main menu : ";
		cin >> key;
		switch (key)
		{
			case 1 :
				ShowTooltip();
				break;
			case 2 :
				if (arr != NULL)
				{
					delete [] arr;
					arr = NULL;
				}
				cout << "Input array size : ";
				cin >> size;
				cout << "Input value range : ";
				cin >> valueRange;
				
				time = clock(); // начальное время
				arr = CreateArray(size, valueRange);
				time = clock() - time; // конечное время
				cout << (double)time/CLOCKS_PER_SEC << endl;
				break;
			case 3 : 
				Print(arr, size);
				break;
			case 4 : 
				cout << "Input value range : ";
				cin >> valueRange;
				ResetArray(arr, size, valueRange);
				break;
			case 5 :
				//DeleteArray(arr);
				delete [] arr;
				arr = NULL;
				break;
			case 6 :
				time = clock(); // начальное время
				arr = DistinctArray(arr, size);
				time = clock() - time; // конечное время
				cout << (double)time/CLOCKS_PER_SEC << endl;
				break;
			case 7 :
				Sort(arr, size);
				break;
			case 8 :
				Search(arr, size);
				break;
			default :
				cout << "Main menu : ";
				break;
			
		}
		if (key != 0)
			cout << "done!" << endl;
	}

	/*
	int size = 5;
	student *stdu = new student[size];
	Input(stdu, size);
	//PrintArray(stdu, size);
	char path[255] = "test.txt";
	Print(stdu, size, path);
	*/
	/* 
	int size = 5;
	int arr[5] = {0, 1, 2, 0, 3};
	PrintArray(arr, size);
	//size = ShrunkArray2(0, arr, size);
	ShrunkArray(0, arr, size);
	PrintArray(arr, size);
	*/
	/*
	const int count = 5;
	vector<vector<int>> vvec;
	
	fstream myfile("123.txt", ios::in);
	while (!myfile.eof())
	{
		stringstream strst;
		char buff[1024];
		
		myfile.getline(buff, 1024);
		strst << buff;
		
		vector<int> rowValues;
		while (!strst.eof())
		{
			int value;
			strst >> value;
			rowValues.push_back(value);
		}
		vvec.push_back(rowValues);
	}
	myfile.close();
	
	for(vector<vector<int>>::size_type i = 0; 
		i != vvec.size(); ++i)
	{
		for(vector<int>::size_type j = 0; 
			j != vvec[i].size(); ++j)
		{
			cout << vvec[i][j] << '\t';
		}
		cout << endl;
	}
	*/
}

void CountElems()
{
	/*
	fstream myfile("123.txt",ios::in);
	while (!myfile.eof())
	{
		std::stringstream strst;
		char buff[1024];
		
		myfile.getline(buff,1024); 
		strst << buff; 
		
		while( !strst.eof() ) 
			++cols;
		++rows;
	}
	myfile.close();
	cout << rows << '\t' << cols;
	*/
}

void ReadFile()
{
	fstream myfile("123.txt",ios::in);
	
	int rows = 0;
	int cols = 0;
	
	while (!myfile.eof())
	{
		std::stringstream strst;
		char buff[1024];
		
		myfile.getline(buff,1024); 
		strst << buff; 
		
		while( !strst.eof() ) 
		{ 
			++cols;
			int x; 
			strst >> x; 
			cout << x << '\t';
		} 
		cout << endl;
		++rows;
	}
	myfile.close();
	cout << rows << '\t' << cols;
}
