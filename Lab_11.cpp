#include "stdafx.h"
#include <stdio.h>
#include <string.h>

void charAddresses(char *string); // 1st function to do
void commaToSpace(char *str); // 2nd function to do
void printWord(char *start); //3rd function to do
char *nextWord(char *start,int spaces); // 4th function to do

int callCount = 0;
void main()
{
	int i = 0;
	char location[200] = "7825,CREEK VALLEY,SACRAMENTO,95828,CA";
	char *ptr;

	// 1. call function to print out the address and content of each character in the input array
	charAddresses(location);

	// 2. call function to replace all the commas in the input string with tabs
	commaToSpace(location);

	puts("Without commas:");
	puts(location);
	puts("");

	// 3. instead of printing characters (using putchar) until a '\0', printWord prints characters until a space ' '
	puts("First Word");
	printWord(location);

	puts("Second Word");
	printWord(location + 5);

	puts("Third Word");
	printWord(location + 11);
	puts("");

	// starting from the first character in the input string, each call to "nextWord" should return the next word in the string
	// e.g. if the input string is "Hi there everyone" :
	// first call to nextWord should return the address of the letter 't' of "there"
	// second call to nextWord should return the address of the first letter 'e'of "everyone"
	// third call to nextWord should return NULL
	ptr = location;

	int spaces = 0;
	for (int i = 0;i < strlen(ptr);i++)
	{
		if (ptr[i] == ' ')
		{
			spaces++;
		}
	}
	
	while (ptr)
	{
		// instead of printing characters (using putchar) until a '\0', printWord prints characters until a space ' '
		printWord(ptr);
		printf("\n");
		ptr = nextWord(ptr,spaces);
	}


}

void charAddresses(char *string)
{
	printf("Addresses \t Char \n");
	int i = 0;
	while (string[i] != '\0')
	{
		printf("%p \t %c \n", &string[i], string[i]);
		i++;
	}
}
void commaToSpace(char *str)
{
	int i = 0;

	while (str[i-1] != '\0')
	{
		i++;
		if (str[i] == ',')
		{
			str[i] = ' ';
		}
		
	}
	
}

void printWord(char *start)
{
	int i = 0;
	while ((start[i] !='\0')&&(start[i]!=' '))
	{
		printf("%c", start[i]);
		i++;
	}
	printf("\n");
}

char *nextWord(char *start,int spaces)
{
	// insert your code here
	// of course it should only return NULL if there are no more words
	// HINT: 'return (start+i)' will return member [i] of the array (string) pointed at by 'start'
	callCount++;
	if (callCount == spaces+1)
	{
		return NULL;
		
	}

	for (int i = 0;i<strlen(start);i++)
	{
		if (start[i] == ' ') 
		{
				return (start+i+1);
		}
		
	}
	
	
}