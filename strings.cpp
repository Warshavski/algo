#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <vector>

//#include "stdafx.h"
//#include "sorting.h"

using namespace std;

int tstrlen(char a[])
{
	int i;
	for (i = 0; a[i] != 0; ++i);
	return i;
}

void tstrcpy(char a[], char b[])
{
	for (int i = 0; (a[i] = b[i]) != 0; ++i);
}

int tstrcmp(char a[], char b[])
{
	int i;
	for (i = 0; a[i] == b[i] != 0; ++i)
		if (a[i] == 0)
			return 0;
	return a[i] - b[i];
}

int tstrncmp(char a[], char b[], int n)
{
	for (int i = 0; i < n && a[i] != 0; ++i)
		if (a[i] != b[i])
			return a[i] - b[i];
	return 0;
}

void tstrcat(char a[], char b[])
{
	tstrcpy(a + tstrlen(a), b);
}

void SimbolCount(char str[])
{
	int len = tstrlen(str);
	
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (str[i] != '\n')
		{
			cout << str[i] << " : ";
			int count = 1;
			for (int j = i + 1; str[j] != '\0'; ++j)
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
	//cout << str << endl;
}

bool StringPalindrome(char str[])
{
	//char str[] = {'i','f',' ','i',' ','h','a','d',' ','a',' ','h','i','f','i','\0'};
	
	int len = tstrlen(str);
	int len2 = len % 2 == 0 ? (len-2)/2 + 1 : (len-2)/2;
	for (int i = 0, j = len - 2; i <= len2 || j >= len2; ++i, --j)
	{
		for (; i <= len2 && str[i] == ' '; ++i);
		for (; j >= len2 && str[j] == ' '; --j);
		
		if (str[i] != str[j])
			return false; //cout << str[i] << str[j] << endl;
	}
	return true;
}

void ZipArray(char str[])
{
	bool isSpace = false;
	int j = 0;
	for (int i = 0; str[i+1] != '\0'; ++i)
	{
		if (str[i] == ' ' && !isSpace)
		{
			isSpace = true;
			str[j++] = str[i];
		}
		else if (str[i] != ' ')
		{
			str[j++] = str[i];
			isSpace = false;
		}
	}	
	str[j] = '\0';
}

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

/*
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
*/

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
	*/
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
	*/
	
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
	*/
}

/*
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
*/
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
	
	int lenSub = tstrlen(sub);
	for (int i = 0; i < N; ++i)
	{
		int lenStr = tstrlen(str[i]);
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

void SpaceCount(char str[])
{
	
}


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

void reverseString(char str[], const int lenght)
{
	for (int i = 0, j = lenght - 1; i < lenght / 2 ; ++i, --j)
	{
		int bufferValue = str[i];
		str[i] = str[j];
		str[j] = bufferValue;
	}
}

void substringSearch(char str[], char subStr[])
{
	for (int i = 0; str[i] != '\0'; ++i)
	{
		
	}	
}

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

int calcLenght(char str[])
{
	int i = 0;
	while (str[i] != '\0')
		++i;
	return i;
}

void prefix(char str[])
{
	int size = calcLenght(str);
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

bool isEqualStr(char str1[], char str2[])
{
	for (int i = 0; str1[i] == str2[i] != 0; ++i)
		if (str1[i] == 0)
			return true;
			
	return false;
}

void searchString(char strSequence[], char strKey[])
{
	int sequenceLenght = calcLenght(strSequence);
	int keyLenght = calcLenght(strKey);
	
	bool isFound = false;
	
	for (int j = 0, i = 0; j < keyLenght && i < sequenceLenght; ++j, ++i)
	{
		if (strSequence[i] != strKey[j])
		{
			j = 0;
			while (strSequence[i] != ' ')
				++i;
		}
		
		if (j == keyLenght - 1 && strSequence[i + 1] == ' ')
		{
			isFound = true;
			cout << "string found!" << endl;
		}
	}
	
	if (!isFound)
		cout << "string not found" << endl;
}

int main()
{
	char str[] = "word or not a word, just some very long sentence";
	char subStr[] = "or";
	char pref_str[] = "abcabcd";
	
	cout << str << endl;
	
	//reverseString(str);
	//cout << str << endl;
	substringSearch(str,subStr);
	cout << '\n' << endl;
	
	prefix(pref_str);
	
	searchString(str, subStr);
	/*
	substringSearch(str, calcLenght(str), 
		subStr, calcLenght(subStr));
	*/
	return 0;
}









