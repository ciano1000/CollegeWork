// Week17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

struct address {
	char house[30];
	char city[20];
	char county[30];
	char state[5];
	char zip[10];
};
struct data {
	char firstName[30];
	char secondName[50];
	char companyName[70];
	struct address address;
	char phone1[15];
	char phone2[15];
	char email[70];
	char web[100];
};

struct data people[501];

struct data SortData(char *dataLine);
void SearchByName(char *name, struct data *ptr);
void SearchByCompany(char *company, struct data *ptr);
void SearchByCity(char *city, struct data *ptr);
void SearchByCounty(char *county, struct data *ptr);
void SearchByState(char *state, struct data *ptr);
void SearchByZip(char *zip, struct data *ptr);
void StringToUpper(char *string);

int main()
{
	char userOption;
	char userInput[50];
	bool isRunning = true;

	FILE *fp;
	fp = fopen("people.txt", "r+");

	if (fp == NULL)
	{
		perror("File coudn't open");
	}
	else
	{
		for (int i = 0; i < 501; i++)
		{
			char temp[200];
			fgets(temp, 200, fp);
			if (i > 0)
			{
				people[i] = SortData(temp);
				
			}
		}

	}

	while (isRunning == true)
	{
		fflush(stdin);

		printf("\n Choose Option:\n [1]Search by name\n[2]Search by company\n[3]Search by city\n[4]Search by county\n[5]Search by state\n[6]Search by zip\n[0]Exit\n");
		scanf(" %c", &userOption);

		switch (userOption)
		{
		case '1':
			printf("Input all or part of the first name or surname: \n");
			scanf(" %s", userInput);
			SearchByName(userInput, people);
			break;
		case '2':
			printf("Input all or part of the company name: \n");
			fflush(stdin);
			scanf(" %s", userInput);
			SearchByCompany(userInput, people);
			break;
		case '3':
			printf("Input all or part of the city name:\n");
			fflush(stdin);
			scanf(" %s", userInput);
			SearchByCity(userInput, people);
			break;
		case '4':
			printf("Input all or part of the county name: \n");
			fflush(stdin);
			scanf(" %s", userInput);
			SearchByCounty(userInput, people);
			break;
		case '5':
			printf("Input all or part of the state name: \n");
			fflush(stdin);
			scanf(" %s", userInput);
			SearchByState(userInput, people);
			break;
		case '6':
			printf("Input all or part of the zip code:\n");
			fflush(stdin);
			scanf(" %s", userInput);
			SearchByZip(userInput, people);
		}
	}
    return 0;
}

struct data SortData(char *dataLine)
{
	struct data temp;
	char *token;

	token = strtok(dataLine, ",");
	strcpy(temp.firstName, token);
	StringToUpper(temp.firstName);

	token = strtok(NULL, ",");
	strcpy(temp.secondName, token);
	StringToUpper(temp.secondName);

	token = strtok(NULL, ",");
	strcpy(temp.companyName, token);

	token = strtok(NULL, ",");
	strcpy(temp.address.house, token);

	token = strtok(NULL, ",");
	strcpy(temp.address.city, token);

	token = strtok(NULL, ",");
	strcpy(temp.address.county, token);

	token = strtok(NULL, ",");
	strcpy(temp.address.state, token);

	token = strtok(NULL, ",");
	strcpy(temp.address.zip, token);

	token = strtok(NULL, ",");
	strcpy(temp.phone1, token);

	token = strtok(NULL, ",");
	strcpy(temp.phone2, token);

	token = strtok(NULL, ",");
	strcpy(temp.email, token);

	token = strtok(NULL, ",");
	strcpy(temp.web, token);

	return temp;
}

void SearchByName(char *name, struct data *ptr)
{
	StringToUpper(name);
	for (int i = 0; i < 501; i++)
	{
		if ((strstr(ptr[i].firstName,name)!= NULL)||(strstr(ptr[i].secondName,name)!=NULL))
		{
			printf("First Name: %s\nLastName:%s\nCompany Name: %s\nAddress: %s\nCity: %s\nCounty: %s\nState: %s\nZip: %s\nPhone #1:%s\nPhone #2: %s\n Email: %s\nWeb: %s\n",
				ptr[i].firstName,ptr[i].secondName,ptr[i].companyName,ptr[i].address.house,ptr[i].address.city,ptr[i].address.county,ptr[i].address.state,ptr[i].address.zip,ptr[i].phone1,ptr[i].phone2,ptr[i].email,ptr[i].web);
		}
		
	}
}
void SearchByCompany(char *name, struct data *ptr)
{
	StringToUpper(name);
	for (int i = 0; i < 501; i++)
	{
		if (strstr(ptr[i].companyName, name) != NULL)
		{
			printf("First Name: %s\nLastName:%s\nCompany Name: %s\nAddress: %s\nCity: %s\nCounty: %s\nState: %s\nZip: %s\nPhone #1:%s\nPhone #2: %s\n Email: %s\nWeb: %s\n",
				ptr[i].firstName, ptr[i].secondName, ptr[i].companyName, ptr[i].address.house, ptr[i].address.city, ptr[i].address.county, ptr[i].address.state, ptr[i].address.zip, ptr[i].phone1, ptr[i].phone2, ptr[i].email, ptr[i].web);
		}

	}
}
void SearchByCity(char *name, struct data *ptr)
{
	StringToUpper(name);
	for (int i = 0; i < 501; i++)
	{
		if (strstr(ptr[i].address.city, name) != NULL)
		{
			printf("First Name: %s\nLastName:%s\nCompany Name: %s\nAddress: %s\nCity: %s\nCounty: %s\nState: %s\nZip: %s\nPhone #1:%s\nPhone #2: %s\n Email: %s\nWeb: %s\n",
				ptr[i].firstName, ptr[i].secondName, ptr[i].companyName, ptr[i].address.house, ptr[i].address.city, ptr[i].address.county, ptr[i].address.state, ptr[i].address.zip, ptr[i].phone1, ptr[i].phone2, ptr[i].email, ptr[i].web);
		}

	}
}
void SearchByZip(char *name, struct data *ptr)
{
	StringToUpper(name);
	for (int i = 0; i < 501; i++)
	{
		if (strstr(ptr[i].address.zip, name) != NULL)
		{
			printf("First Name: %s\nLastName:%s\nCompany Name: %s\nAddress: %s\nCity: %s\nCounty: %s\nState: %s\nZip: %s\nPhone #1:%s\nPhone #2: %s\n Email: %s\nWeb: %s\n",
				ptr[i].firstName, ptr[i].secondName, ptr[i].companyName, ptr[i].address.house, ptr[i].address.city, ptr[i].address.county, ptr[i].address.state, ptr[i].address.zip, ptr[i].phone1, ptr[i].phone2, ptr[i].email, ptr[i].web);
		}

	}
}
void SearchByCounty(char * name, struct data *ptr)
{
	StringToUpper(name);
	for (int i = 0; i < 501; i++)
	{
		if (strstr(ptr[i].address.county, name) != NULL)
		{
			printf("First Name: %s\nLastName:%s\nCompany Name: %s\nAddress: %s\nCity: %s\nCounty: %s\nState: %s\nZip: %s\nPhone #1:%s\nPhone #2: %s\n Email: %s\nWeb: %s\n",
				ptr[i].firstName, ptr[i].secondName, ptr[i].companyName, ptr[i].address.house, ptr[i].address.city, ptr[i].address.county, ptr[i].address.state, ptr[i].address.zip, ptr[i].phone1, ptr[i].phone2, ptr[i].email, ptr[i].web);
		}

	}
}
void SearchByState(char *name,struct data *ptr)
{
	StringToUpper(name);
	for (int i = 0; i < 501; i++)
	{
		if (strstr(ptr[i].address.state, name) != NULL)
		{
			printf("First Name: %s\nLastName:%s\nCompany Name: %s\nAddress: %s\nCity: %s\nCounty: %s\nState: %s\nZip: %s\nPhone #1:%s\nPhone #2: %s\n Email: %s\nWeb: %s\n",
				ptr[i].firstName, ptr[i].secondName, ptr[i].companyName, ptr[i].address.house, ptr[i].address.city, ptr[i].address.county, ptr[i].address.state, ptr[i].address.zip, ptr[i].phone1, ptr[i].phone2, ptr[i].email, ptr[i].web);
		}

	}
}
void StringToUpper(char *string)
{
	int i = 0;
	while (*string) {
		*string = toupper((unsigned char)*string);
		string++;
	}
}