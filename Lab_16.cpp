// Week19.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

struct result
{
	char last[40];
	char first[40];
	int age;
	char email[40];
	struct result *next;
};

struct result *CreateNode(struct result *next, char *dataLine);
struct result *CreateList(struct result *head, char *dataLine);
struct result *AddNode(struct result *head, char *dataLine);
void PrintAge(struct result *head,int age);
int main()
{
	bool isRunning = true;
	int userInput;

	struct result *head = NULL;
	struct result *current = NULL;
	struct result *previous = NULL;

	
	FILE *fp;
	fp = fopen("users.txt", "r+");

	for (int i = 0; i <101; i++)
	{
		char temp[100];
		fgets(temp, 100, fp);

		if (i > 0)
		{
			if (i == 1)
			{
				head = CreateList(head, temp);
				previous = head;
			}
			else
			{
				current = CreateNode(NULL, temp);
				previous->next = current;
				previous = current;
			    
			}
			
		}
	}

	while (isRunning == true)
	{
		fflush(stdin);

		printf("Enter age you want to search for:");
		scanf("%d", &userInput);
		if (userInput != 0)
		{
			PrintAge(head, userInput);
			
		}
		else {
			isRunning = false;
		}
		
	}

	return 0;
}

struct result *CreateNode(struct result *next, char *dataLine)
{
	struct result *temp = (result *)malloc(sizeof(struct result));
	char *token;

	token = strtok(dataLine, ",");
	strcpy(temp->last, token);

	token = strtok(NULL, ",");
	strcpy(temp->first, token);

	token = strtok(NULL, ",");
	temp->age = atoi(token);

	token = strtok(NULL, ",");
	strcpy(temp->email, token);

	temp->next = next;

	return temp;

}

struct result *CreateList(struct result *head, char *dataLine)
{
	struct result *newNode = CreateNode(head, dataLine);
	head = newNode;
	return head;
}

struct result *AddNode(struct result *head, char *dataLine)
{
	struct result *current = head;
	 while(current->next!=NULL)
	 {
		 current = current->next;
	 }
	 struct result *newNode = CreateNode(NULL, dataLine);

	 return head;
}
void PrintAge(struct result *head, int age)
{
	struct result *current = head;
	bool foundAge = false;
	do
	{
		if (current->age == age)
		{
			printf("%s %s \n", current->first, current->last);
			foundAge = true;
		}
		current = current->next;
	} while (current!= NULL);
	if (foundAge == false)
	{
		printf("Age not found\n");
	}
}

