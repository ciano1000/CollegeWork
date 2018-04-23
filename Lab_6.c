#include "stdafx.h"
#include <stdio.h>
#include "string.h"

void main()
{
	int i, j;
	char fullName[100];
	char firstName[30], middleName[30], surname[30];
	char initial;
	int stringLength;

	printf("enter full name: ");

	gets_s(fullName);
	printf("Thank you %s\n\n", fullName);
	j = 0;
	i = 0;
	
	stringLength = strlen(fullName);
	while (i!=stringLength+1)
	{
		if (fullName[i] == ' ')
		{
			if (j == 0)
			{
				strncpy_s(firstName, fullName, i);
				j++;
			}
			if (j == 1)
			{
				strncpy_s(middleName, &fullName[strlen(firstName)+1],i );
				j++;
			}
			}
		if (fullName[i] == '\0')
		{
		strncpy_s(surname, &fullName[strlen(firstName) + strlen(middleName) + 2], i);	
		}
		i++;
	}
	initial = middleName[0];
	printf("%s %c %s \n",firstName,initial,surname);
}





