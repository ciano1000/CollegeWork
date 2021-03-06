// Week18.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct
{
	char *UserName;
	char *firstName;
	char *lastName;
	char *displayName;
	char *jobTitle;
	char *department;
	char *officeNumber;
	char *officePhone;
	char *mobilePhone;
	char *fax;
	char *address;
	char *city;
	char *state;
	char *zip;
	char *country;
} contact;

contact SortData(char *dataLine);
void PrintContact(contact *theContact);
int NumLines();
int LineLength(int line);

int main()
{
	contact *contactPtr;
	FILE *fp;
	fp = fopen("contacts.txt", "r+");

	contactPtr = (contact *)malloc((NumLines()-1) * sizeof(contact));
	
	
	for (int i = 0; i < NumLines() + 1; i++)
	{
		int lineLength = LineLength(i + 1) + 2;
		char *temp = (char *)malloc(lineLength * sizeof(char));
		fgets(temp, lineLength, fp);
		if (i > 0)
		{
			contactPtr[i-1] = SortData(temp);
		}
	}

	for (int i = 0; i < NumLines(); i++)
	{
	PrintContact((contactPtr+i));
	}

    return 0;
}

contact SortData(char *dataLine)
{
	contact contact;
	
				char *token = strtok(dataLine, ",");
			
				contact.UserName = (char *)malloc(strlen(token) * sizeof(char));
				contact.UserName = token;

				token = strtok(NULL, ",");
				contact.firstName = (char *)malloc(strlen(token) * sizeof(char));
				contact.firstName = token;

				token = strtok(NULL, ",");
				contact.lastName = (char *)malloc(strlen(token) * sizeof(char));
				contact.lastName = token;


				token = strtok(NULL, ",");
				contact.displayName = (char *)malloc(strlen(token) * sizeof(char));
				contact.displayName = token;

				token = strtok(NULL, ",");
				contact.jobTitle = (char *)malloc(strlen(token) * sizeof(char));
				contact.jobTitle = token;

				token = strtok(NULL, ",");
				contact.department = (char *)malloc(strlen(token) * sizeof(char));
				contact.department = token;

				token = strtok(NULL, ",");
				contact.officeNumber = (char *)malloc(strlen(token) * sizeof(char));
				contact.officeNumber = token;

				token = strtok(NULL, ",");
				contact.officePhone = (char *)malloc(strlen(token) * sizeof(char));
				contact.officePhone = token;

				token = strtok(NULL, ",");
				contact.mobilePhone = (char *)malloc(strlen(token) * sizeof(char));
				contact.mobilePhone = token;

				token = strtok(NULL, ",");
				contact.fax = (char *)malloc(strlen(token) * sizeof(char));
				contact.fax = token;

				token = strtok(NULL, ",");
				contact.address = (char *)malloc(strlen(token) * sizeof(char));
				contact.address = token;

				token = strtok(NULL, ",");
				contact.city = (char *)malloc(strlen(token) * sizeof(char));
				contact.city = token;

				token = strtok(NULL, ",");
				contact.state = (char *)malloc(strlen(token) * sizeof(char));
				contact.state = token;

				token = strtok(NULL, ",");
				contact.zip = (char *)malloc(strlen(token) * sizeof(char));
				contact.zip = token;

				token = strtok(NULL, ",");
				contact.country = (char *)malloc(strlen(token) * sizeof(char));
				contact.country = token;
				
				return contact;
}
void PrintContact(contact *theContact)
{
	printf("User Name: %s\nFirst Name: %s\nLast Name: %s\nDisplay Name: %s\nJob Title: %s\nDepartment: %s\nOffice Number: %s\nOffice Phone: %s\nMobile Phone: %s\nFax: %s\nAddress: %s\nCity: %s\nState or Province: %s\nZip or Post Code: %s\nCountry or Region: %s\n",
			theContact->UserName,theContact->firstName, theContact->lastName, theContact->displayName, theContact->jobTitle,
			theContact->department, theContact->officeNumber, theContact->officePhone, theContact->mobilePhone, theContact->fax, 
			theContact->address, theContact->city, theContact->state, theContact->zip, theContact->country);
		   
		    
}

int NumLines()
{
	FILE *fp;

	int lines = 0;
	char ch;

	fp = fopen("contacts.txt", "r+");

	if (fp == NULL)
	{
		perror("Error opening file");
	}

	while (!feof(fp))
	{
		ch = fgetc(fp);
		if (ch == '\n')
		{
			lines++;
		}
	}
	fclose(fp);
	return lines;
}

int LineLength(int line)
{
	FILE *fp;
	fp = fopen("contacts.txt", "r+");
	int lineLength = 0;
	int currentLine = 1;
	char ch;
	while(!feof(fp))
	{
		ch = fgetc(fp);
		if (ch == '\n')
		{
			currentLine++;
		}
		if (currentLine == line)
		{
			lineLength++;
		}
	}
	fclose(fp);
	return lineLength;
}