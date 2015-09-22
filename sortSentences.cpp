#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <string.h>

using namespace std;

/* TODO : 
 *		1. Add realization on list.
 *      2. Check memory use
 */

const int BUFF_SIZE = 255;

void printAllText(char **text, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << i << " "  << text[i];	
		cout << endl;		
	}
	cout << endl;
}

void printAllText(char **text, int size, char path[])
{
	ofstream outfile;
	outfile.open(path);
	
	for (int i = 0; i < size; ++i)
		outfile << i << " " << text[i] << '\n';
		
	outfile.close();
}

// yeap not good (better use list)
char **compressArray(char **array, int compressedSize, int currentSize)
{
	char **compressedArray = new char*[compressedSize];
	
	for (int i = 0; i < compressedSize; ++i)
	{
		compressedArray[i] = new char[BUFF_SIZE];
		strcpy(compressedArray[i], array[i]);
	}
	
	for (int i = 0; i < currentSize; ++i)
		delete [] array[i];	
		
	return compressedArray;
}

char **readFromFile(char path[], int &sentencesCount)
{
	ifstream textFile;
	textFile.open(path);
	
	char **sentences = new char*[BUFF_SIZE];
	
	sentencesCount = 0;
	while (!textFile.eof())
	{
		sentences[sentencesCount] = new char[BUFF_SIZE];
		textFile.getline(sentences[sentencesCount], BUFF_SIZE);
		
		++sentencesCount;
	}
	
	char **copressedSentences = compressArray(sentences, sentencesCount, BUFF_SIZE);
	sentences = NULL;
	
	textFile.close();

	return copressedSentences;
}


/* select first word from sentence
 * TODO : add array of the separators
 */
char *selectFirstWord(char *sentence)
{
	char *word = new char[BUFF_SIZE];
	
	for (int i = 0; i < BUFF_SIZE; ++i)
	{
		if (sentence[i] == ' ')
			break;
		word[i] = sentence[i];
	}
	
	return word;
	/*
	char *buff = new char[BUFF_SIZE];
	strcpy(buff, row);
	
	char *pch = strtok(buff, " ");
	delete [] buff;
	return pch;
	*/
}

void swapElements(char *element1, char *element2)
{
	char *buff = new char[BUFF_SIZE];
	strcpy(buff, element1);
	strcpy(element1, element2);
	strcpy(element2, buff);
	
	delete [] buff;
}

// not goods sorting (too slow)
void sortSentences(char **arr, int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		int min = i;
		for (int j = i + 1; j < size; ++j)
			if (strcmp(selectFirstWord(arr[j]), selectFirstWord(arr[min])) < 0)
				min = j;
		if (min != i)
			swapElements(arr[i], arr[min]);
	}
}

int main()
{
	int sentencesCount = 0;
	char **text = readFromFile("test.txt", sentencesCount);
	
	cout << "Unsorted text : " << endl;
	printAllText(text, sentencesCount);
	
	sortSentences(text, sentencesCount);
	
	cout << "Sorted text : " << endl;
	printAllText(text, sentencesCount);
	printAllText(text, sentencesCount, "outputText.txt");
	
	for (int i = 0; i < sentencesCount; ++i)
		delete [] text[i];
	
	return 0;
}