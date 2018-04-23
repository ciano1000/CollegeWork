// Lab11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include <stdlib.h>

#define X 2000
char getRandomLowercaseLetter()
{
	return (rand() % (26)) + 97;
	
}

void initialiseArray(int array[], int len)
{
	for (int i = 0; i < len; i++)
	{
		array[i] = 0;

	}

}

int main()
{
	int frequency[26];
	int scaledFrequency[26];

	int min = X;
	int max = 0;
	int minScale = 0;
	int maxScale = 40;
	char letter;

	initialiseArray(frequency, 26);

	for (int i = 0; i < X; i++)
	{
		letter = getRandomLowercaseLetter();
		frequency[letter - 97] += 1;
	}
	for (int i = 0; i < 26; i++)
	{
		
		if (frequency[i]>max)
		{
			max = frequency[i];
		}
		if (frequency[i]<min)
		{
			min= frequency[i];
		}

	}

	int m = (max - min) / (40);

	for (int i = 0; i < 26; i++)
	{
		scaledFrequency[i] = ((maxScale - minScale )* (frequency[i] - min) / (max - min))+minScale;
	}
	
	printf("Num Throws = %d , Max Freq = %d , scale = %d - %d \n", X, max, minScale, maxScale);

	for (int i = 0; i < 26;i++)
	{
		printf("%c\t %d \t", 97 + i, frequency[i]);
		for (int j = 0; j < scaledFrequency[i]; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	
    return 0;
}

