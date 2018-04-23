// Lab10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>

void printShortestName(char names[][100], int numNames)
{
	
	int shortLength = 10;
	int tempLength = 0;
	int shortestI;
	
	for (int i = 0; i < numNames; i++)
	{
		for (int j = 0;j < 10; j++)
		{
			if (names[i][j] == '\0')
			{
				tempLength = j - 2;
				if (shortLength > tempLength)
				{
					shortLength = tempLength;
					shortestI = i;
				}
				break;
			}
		}
		
	}
	printf("\n Shortest Name is <%d characters>", shortLength);
	for (int i = 0; i <= shortLength; i++)
	{
		printf("%c", names[shortestI][i]);
	}

}

void printLongestName(char names[][100], int numNames)
{
	int longLength = 0;
	int tempLength = 0;
	int longI;

	for (int i = 0; i < numNames; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (names[i][j] == '\0')
			{
				tempLength = j - 2;
				if (longLength < tempLength)
				{
					longLength = tempLength;
					longI = i;
				}
				break;
			}
		}
	}
	printf("\n Longest Name is <%d characters>", longLength);
	for (int i = 0; i <= longLength; i++)
	{
		printf("%c", names[longI][i]);
	}
}


int main()
{
	char names[100][100];
	char temp[10];

	int numNames;
	int strLength;
	
	printf("How many names are you entering? ");
	scanf_s("%d", &numNames);

	int i = 0;
	int j = 0;
	getchar();

	while(i<numNames)
	{
		
		printf_s("\n Enter name # %d: ", i);
		
		fgets(temp, sizeof(temp), stdin);
		
		
		strLength = strlen(temp);
		
		for (j = 0; j < strLength; j++)
		{
			names[i][j] = temp[j];
		}
		names[i][j + 1] = '\0';
		names[i][j + 2] = (char)strLength;
		i++;
		}
	
	printShortestName(names, numNames);
	printLongestName(names, numNames);
    return 0;
}

