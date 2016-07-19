#include "stdafx.h"
//#include "sorting.h"

using namespace std;

const char END_OF_STRING = '\0';

///#COMMON_START

//calculating string length
int u_strlen(char str[])
{
	int index = 0;
	while (str[index] != END_OF_STRING)
		++index;
	return index;
}

//coping one string into another
void u_strcpy(char firstStr[], char secondStr[])
{
	for (int i = 0; (firstStr[i] = secondStr[i]) != END_OF_STRING; ++i);
}

//compares one string to another
int u_strcmp(char firstStr[], char secondStr[])
{
	int i;
	for (i = 0; firstStr[i] == secondStr[i] != END_OF_STRING; ++i)
		if (firstStr[i] == END_OF_STRING)
			return 0;
	return firstStr[i] - secondStr[i];
}

//compares one string with another(first 'n' symbols)
int u_strncmp(char firstStr[], char secondStr[], int n)
{
	for (int i = 0; i < n && firstStr[i] != END_OF_STRING; ++i)
		if (firstStr[i] != secondStr[i])
			return firstStr[i] - secondStr[i];
	return 0;
}

//concatenates one string with another
void u_strcat(char firstStr[], char secondStr[])
{
	u_strcpy(firstStr + u_strlen(firstStr), secondStr);
}

///#COMMON_END





//prints quantity of each symbol in the string 
void symbolCount(char str[])
{
	int strLen = u_strlen(str);
	
	//separate array initialization
	//#start_function
	bool *list = new bool[strLen];
	for (int i = 0; i < strLen; ++i)
		list[i] = false;
	//#end_function
	
	
	for (int i = 0; str[i] != END_OF_STRING; ++i)
	{
		if (list[i] == false)
		{
			list[i] = true;
			cout << "symbol : " << str[i] << " count : ";
			
			int count = 1;
			for (int j = i + 1; str[j] != '\0'; ++j)
			{
				if (str[i] == str[j] && list[j] == false)
				{
					list[j] = true;
					++count ;
				}
			}	
			cout << count << endl;
		}
	}
}

/*prints quantity of each symbol in the string, but destroys inputted string
void symbolCount(char str[])
{
	int len = u_strlen(str);
	
	for (int i = 0; str[i] != END_OF_STRING; ++i)
	{
		if (str[i] != '\n')
		{
			cout << str[i] << " : ";
			int count = 1;
			for (int j = i + 1; str[j] != END_OF_STRING; ++j)
			{
				if (str[i] == str[j])
				{
					++count;
					str[j] = '\n';
				}
			}
			cout << count << endl;
		}
	}
}
*/

/*check if string is palindrome(start->end == end->start);
bool isPalindrome(char str[])
{
	//char str[] = {'i','f',' ','i',' ','h','a','d',' ','a',' ','h','i','f','i','\0'};

	int strLength = u_strlen(str);
	int middle = strLength % 2 == 0 ? 
		(strLength - 2) / 2 + 1 : (strLength - 2) / 2;
	
	for (int i = 0, j = len - 2; i <= len2 || j >= len2; ++i, --j)
	{
		for (; i <= len2 && str[i] == ' '; ++i);
		for (; j >= len2 && str[j] == ' '; --j);
		
		if (str[i] != str[j])
			return false; //cout << str[i] << str[j] << endl;
	}
	return true;
}
*/

//check if string is palindrome(start->end == end->start);
bool isPalindrome(char str[])
{
	int strLength = u_strlen(str);
	int middle = strLength % 2 == 0 ?
		strLength / 2 + 1 : strLength / 2;
	
	for (int i = 0, j = strLength - 1; i < middle; ++i, --j)
	{
		for (; i < middle && str[i] == ' '; ++i);
		for (; j > middle && str[j] == ' '; --j);
		
		if (str[i] != str[j])
			return false;
	}
	return true;
}

//removes spaces from a string
void trimString(char str[])
{
	const char SPACE = ' ';
	int j = 0;
	for (int i = 0; str[i] != END_OF_STRING; ++i)
	{
		if (str[i] != SPACE)
		{
			str[j] = str[i];
			++j;
		}
	}
	str[j] = END_OF_STRING;
}





///#REVERSE_STRING_START

//reverses string (pointers version)
void reverseString(char *strStart)
{
	char *strEnd = strStart;
	
	while( strEnd && *strEnd)
		++strEnd;
	
	for (--strEnd; strStart < strEnd; ++strStart, --strEnd)
	{
		*strStart ^= *strEnd;
		*strEnd ^= *strStart;
		*strStart ^= *strEnd;
	}
}

//reverses string (array version)
void reverseString(char str[], const int lenght)
{
	for (int i = 0, j = lenght - 1; i < lenght / 2 ; ++i, --j)
	{
		int bufferValue = str[i];
		str[i] = str[j];
		str[j] = bufferValue;
	}
}

///#REVERSE_STRING_END





///#SEARCH_START

void substringSearch(char str[], const int strSize,
	char sub[], const int subSize)
{
	bool isFound = false;
	
	for (int i = 0; i < strSize - subSize; ++i)
	{
		int j = 0;
		while (j < subSize && str[i+j] == sub[j])
			++j;
		
		if (j == subSize)
		{
			isFound = true;
			cout << "Sub found on index : " << i << endl;
		}
	}
	
	if (!isFound)
		cout << "Sub not found" << endl;
	
}

//searches string in a one-dimensional array of strings
void searchString(char strSequence[], char strKey[])
{
	int sequenceLenght = u_strlen(strSequence);
	int keyLenght = u_strlen(strKey);
	
	bool isFound = false;
	for (int i = 0, j = 0; i < sequenceLenght; ++i, ++j)
	{
		if (strSequence[i] != strKey[j])
		{
			j = -1;
			while (strSequence[i] != ' ' && strSequence[i] != '\0')
				++i;
		}
		
		if (j == keyLenght - 1)
		{
			isFound = true;
			cout << "string found on index : "  << i << endl;	
		}
	}
	
	if (!isFound)
		cout << "string not found" << endl;
}

///#SEARCH_END





int main()
{
	char strPalindrome[] = "if i had a hifi";
	char strPalindrome2[] = "iffi";
	char strCount[] = "word or not a word, just some very long sentence";
	
	cout << strPalindrome << endl;
	trimString(strPalindrome);
	cout << strPalindrome << endl;
	
	return 0;
}









/*#WAAAAT?

void AllTrim(char *dest, const char *src)
{
    if (src == 0)
        src = dest;

    char *beg = dest;
    bool  wrSpace = *src != ' ';

    for (; *src; src++)
    {
        if (*src != ' ')
        {
            *dest++ = *src;
            wrSpace = true;
        }
        else if (wrSpace)
        {
            *dest++ = *src;
            wrSpace = false; 
        }
    }

    if (beg == dest || wrSpace) 
		*dest = '\0';
    else
		*--dest = '\0';
	
}


void Substring()
{
	int i, char t;
	char a[N], *p = argv[1];
	
	for (i = 0; i < N-1; a[i] = t, ++i)
		if (!cin.get(t))
			break;
	a[i] = 0;
	
	for (i = 0; a[i] != 0; ++j)
	{
		int j;
		for (j = 0; p[j] != 0; ++j)
			if (a[i+j] != p[j])
				break;
		if (p[j] == 0)
			cout << i << " ";
	}
	cout << endl;
}


vector<int> prefix_function(string s)
{
	int n = (int)s.length();
	vector<int> pi(n);
	
	for (int i = 1; i < n; ++i)
	{
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])
			++j;
		pi[i] = j;
	}
	return pi;
}

void prefix(char str[])
{
	int size = u_strlen(str);
	int *pref = new int[size];
	
	for (int i = 0; i < size; ++i)
		pref[i] = 0;	
	
	for (int i = 1; i < size; ++i)
	{
		int j = pref[i-1];
		while (j > 0 && str[i] != str[j])
			j = pref[j-1];
		if (str[i] == str[j])
			++j;
		pref[i] = j;
	}
	
	for (int i = 0; i < size; ++i)
		cout << pref[i] << " ";
	cout << endl;
	
	delete [] pref;
}

void kmp()
{
	int index = -1;
	string haystack = "abcdabfdsfewrwescabcdabiaolelabcdabscabcdabiaoelelelalewdwdsae"; //"some string for substring or sub string"; //"abcdabscabcdabia";
	string needle = "abcdabscabcdabiao";//"sub";
	vector<int> pref = prefix_function(needle); //haystack
	
	int slen = (int)haystack.length();
	int plen = (int)needle.length();
	
	//vector<int> pref(plen);
	
	
	/*
	pref[0] = 0;
	for (int k = 0, i = 1; i < plen; i++)
	{
		while ( k > 0 && needle[k] != needle[i] )
				k = pref[k-1];

		if ( needle[k] == needle[i] )
				k++;

		pref[i] = k;
	}
	* /
	/*
	for ( int k = 0, i = 0; i <= slen; i++ )
	{
		while ( k > 0 && needle[k] != haystack[i] )
			k = pref[k-1];

		if ( needle[k] == haystack[i] )
			k++;

		if ( k == plen )
			index = (i-plen+1);
	}
	//return -1;
	* /
	
	int k = 0;
	for (int i = 0; i <= slen; ++i)
	{
		while (k > 0 && needle[k] !=  haystack[i])
			k = pref[k-1];
			
		if (needle[k] == haystack[i])
			++k;
		if (k == plen)
		{
			index = i - plen + 1;
			cout << index << " ";
			//k = 0;
		}
	}
	
	/*
	cout << index << endl;
	for (; index < slen; ++index)
		cout << haystack[index];
	cout << endl;
	* /
}


void aft()
{
	string s; // входная строка
	const int alphabet = 256; // мощность алфавита символов, обычно меньше
	 
	s += '#';
	int n = (int) s.length();
	vector<int> pi = prefix_function (s);
	vector < vector<int> > aut (n, vector<int> (alphabet));
	for (int i=0; i<n; ++i)
		for (char c=0; c<alphabet; ++c)
			if (i > 0 && c != s[i])
				aut[i][c] = aut[pi[i-1]][c];
			else
				aut[i][c] = i + (c == s[i]);
}

void SubFind()
{
	const int N = 3, M = 20;
	char t;
	char str[N][M];
	char sub[] = {'s', 'u', 'b', '\0'};
	
	for (int i = 0; i < N; ++i)
	{
		cout << "Input " << "<" << i+1 << "> : ";
		int j;
		for (j = 0; j < M - 1; str[i][j] = t, ++j)
		{
			cin.get(t);
			if (t == '\n')
				break;
		}
		str[i][j] = 0;
	}	
	
	cout << "------------------" << endl;
	
	int lenSub = u_strlen(sub);
	for (int i = 0; i < N; ++i)
	{
		int lenStr = u_strlen(str[i]);
		if (lenStr >= lenSub)
		{
			for (int j = 0; str[i][j] != '\0'; ++j)
			{
				int k;
				for (k = 0; sub[k] != '\0'; ++k)
					if (str[i][j+k] != sub[k])
						break;
						
				if (sub[k] == 0)
				{
					cout << "<" << i+1 << "> " << str[i] << endl;
					break;
				}
			}
		}
	}
}
*/









