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

/*
void printAllText(char **text, int size, char path[])
{
	ofstream outfile;
	outfile.open(path);
	
	for (int i = 0; i < size; ++i)
		outfile << i << " " << text[i] << '\n';
		
	outfile.close();
}
*/

/* yeap, pretty shitty (better use list)
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
*/

/*char **readFromFile(char path[], int &sentencesCount)
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
}*/

/*
/// * select first word from sentence
// * TODO : add array of the separators
// * /
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
	///*
	char *buff = new char[BUFF_SIZE];
	strcpy(buff, row);
	
	char *pch = strtok(buff, " ");
	delete [] buff;
	return pch;
	//* /
}

void swapElements(char *element1, char *element2)
{
	char *buff = new char[BUFF_SIZE];
	strcpy(buff, element1);
	strcpy(element1, element2);
	strcpy(element2, buff);
	
	delete [] buff;
}
*/

/*
// not so good sorting (too slow)
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
*/
/*
void printAllText(char **text, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << i << " "  << text[i];	
		cout << endl;		
	}
	cout << endl;
}
*/

const int BUFF_SIZE = 255;
const char END_OF_TEXT = '\0';

struct sentence
{
	int startPosition;
	int lenght;
	
	/* use constructors or not ?
	sentence()
	{
		startPosition = 0;
		lenght = 0;
	}
	
	sentence (int sPos, int len)
	{
		startPosition = sPos;
		lenght = len;
	}
	*/
};

void printAllText(char *text)
{
	for (int i = 0; text[i] != END_OF_TEXT; ++i)
		cout << text[i];
	cout << endl;
}



void printAllText(char *text, sentence order[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << i << " : ";
		for (int j = order[i].startPosition, k = 0; k < order[i].lenght; ++j, ++k)
			cout << text[j];
		cout << endl;
	}
}

void printAllText(char *text, char path[])
{
	ofstream outfile;
	outfile.open(path);
	
	for (int i = 0; text[i] != END_OF_TEXT; ++i)
		outfile << text[i];
		
	outfile.close();
}

void printAllText(char *text, sentence order[], int size, char path[])
{
	ofstream outfile;
	outfile.open(path);
	
	for (int i = 0; i < size; ++i)
	{
		for (int j = order[i].startPosition, k = 0; k < order[i].lenght; ++j, ++k)
			outfile << text[j];
		outfile << '\n';
	}
		
	outfile.close();
}

char *readFromFile(char path[])
{
	char *text;
	long textLength;
   
    ifstream textFile;
	textFile.open(path);
	
	bool bRead = false;
	
    if(!textFile)
        cout<< "Error! Can't open <<" << path << "\n";
    else
    {
		/* Sets the position of the next character to be extracted from the input stream.
		 * position : end of file */
        textFile.seekg(0, ios::end);
		
		/* Returns the position of the current character in the output stream.
		 * sets textLength */
        textLength = textFile.tellg();
		
		// position : begin of file
        textFile.seekg(0, ios::beg);
        
		/* try to create array for our text
		 * just allocate memory	*/
		if(!(text = new char[textLength + 1]))
            cout<<"Error! Can't allocate memory \n";
        else
        {
            textFile.read(text, textLength);
			/* sets the null termination character
			 * It marks the end of the string */
            text[textLength] = '\0';
        }
		
        bRead = !textFile.bad();
        textFile.close();
	}
	return text;
}

bool endOfSentence(char currentChar)
{
	const int SIZE = 3;
	char dividers[SIZE] = {'.', '!', '?'};
	
	for (int i = 0; i < SIZE; ++i)
		if (currentChar == dividers[i])
			return true;
	
	return false;
}

sentence *compressArray(sentence array[], int currentSize, int compressedSize)
{
	sentence *compressedArray = new sentence[compressedSize];
	
	for (int i = 0 ; i < compressedSize; ++i)
		compressedArray[i] = array[i];
	
	return compressedArray;
}

/* TODO : 
 *		1. optimize memory allocation.
 * 		2. optimize code (check end of text and ignore of ' ' and '\n')
 *      3. manipulate with pointers instead of objects
 */ 
sentence *createSentencesArray(char *text, int &out_sentencesCount)
{
	sentence *tempArray = new sentence[BUFF_SIZE];
	
	out_sentencesCount = 0;
	int position = 0;
	for (int i = 0; text[i] != END_OF_TEXT; ++i)
	{
		if (endOfSentence(text[i]))
		{
			tempArray[out_sentencesCount].startPosition = position;
			tempArray[out_sentencesCount].lenght = i - position + 1;
			++out_sentencesCount;	
	
			do 
				++i;
			while (text[i] != END_OF_TEXT && (text[i] == '\n' || text[i] == ' '));
			
			
			position = i;
		}
	}
	
	sentence *array = compressArray(tempArray, BUFF_SIZE, out_sentencesCount);
	
	delete [] tempArray;
	
	return array;
}


// on swap better use pointers
void sortSentences(char *text, sentence order[], int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		int minIndex = i;
		
		for (int j = i + 1; j < size; ++j)
			if ((text[order[j].startPosition] < text[order[minIndex].startPosition]))
				minIndex = j;
		
		if (minIndex != i)
		{
			sentence buff = order[i];
			order[i] = order[minIndex];
			order[minIndex] = buff;
		}
			
	}
}

//#TEST
void printSentenceArray(sentence arr[], int size)
{	
	for (int i = 0; i < size; ++i)
		cout << arr[i].startPosition << " | " << arr[i].lenght << endl;
	cout << endl;
}

int main()
{
	int sentencesCount = 0;
	
	char *text = readFromFile("test2.txt");
	
	//cout << "Unsorted text : " << endl;
	//printAllText(text);
	
	cout << '\n' << endl;
	sentence *arr = createSentencesArray(text, sentencesCount);
	
	cout << "unsorted text : " << endl;
	printAllText(text, arr, sentencesCount);
	
	sortSentences(text, arr, sentencesCount);
	
	cout << endl;
	cout << "sorted text : " << endl;
	printAllText(text, arr, sentencesCount);
	printAllText(text, arr, sentencesCount, "outFile.txt");
	
	delete [] text;
	
	return 0;
}