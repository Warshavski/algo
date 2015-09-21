#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cctype>


using namespace std;

const int BUFF_SIZE = 255;

void printAllText(char **arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << i << " "  << arr[i];	
		cout << endl;		
	}
}

void printAllText(char **arr, int size, char path[])
{
	ofstream outfile;
	outfile.open(path);
	
	for (int i = 0; i < size; ++i)
		outfile << arr[i] << '\n';
		
	outfile.close();
}

char **readFromFile(char path[], int size)
{
	ifstream sentencesFile;
	sentencesFile.open(path);
	
	char **sentencesArr = new char*[size];
	
	int i = 0;
	while(!sentencesFile.eof())
	{
		sentencesArr[i] = new char[BUFF_SIZE];
		sentencesFile.getline(sentencesArr[i], BUFF_SIZE);
	
		++i;
	}
	sentencesFile.close();

	return sentencesArr;
}


//#WTF how to delete temp array?
char *selectFirstWord(char *row)
{
	char *buff = new char[BUFF_SIZE];
	strcpy(buff, row);
	
	char *pch = strtok(buff, " ");
	while (pch != NULL)
	{
		delete [] buff;
		return pch;
	}
	return NULL;
}

void swapElements(char *element1, char *element2)
{
	char *buff = new char[BUFF_SIZE];
	strcpy(buff, element1);
	strcpy(element1, element2);
	strcpy(element2, buff);
	
	delete [] buff;
}

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
	const int TEXT_LENGTH = 30;
	char **text = readFromFile("test.txt", TEXT_LENGTH);
	
	printAllText(text, TEXT_LENGTH);
	
	sortSentences(text, TEXT_LENGTH);
	
	printAllText(text, TEXT_LENGTH);
	printAllText(text, TEXT_LENGTH, "outputText.txt")
	
	for (int i = 0; i < TEXT_LENGTH; ++i)
		delete [] text[i];
	
	return 0;
}