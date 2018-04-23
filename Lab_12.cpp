// S2Lab02.cpp : Defines the entry point for the console application.


#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct date
{
	int day, month, year;
};
struct student
{
	int studentID;
	char firstName[20];
	char lastName[20];
	char courseID[10];
	int year;
	struct date registrationDate;
	struct date dateOfBirth;
	int averageGrade;
};
void SortStudentInfo(char *dataLine,struct student* ptr);
void WriteStudentInfo(struct student *students,int lines);
int GetNumLines();

struct student students[50];

int main()
{
	FILE *fp;
	int lines = 0;
	lines = GetNumLines();
	
	fp = fopen("students.txt", "r+");

	if (fp == NULL)
	{
		perror("File could not open");
	}

	for (int i = 0; i <lines; i++)
	{
		char temp[100];
	    fgets(temp, 100, fp);
		SortStudentInfo(temp,&students[i]);
		int randomGrade = (rand() % (100 + 1 - 1)) +1;
		students[i].averageGrade = randomGrade;
		
	}
	WriteStudentInfo(students,lines);
	
	fclose(fp);

    return 0;
}

int GetNumLines()
{
	int lines = 0;
	char ch;

	FILE *fp;
	fp = fopen("students.txt", "r");
	if (fp == NULL)
	{
		perror("File could not open");
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

void SortStudentInfo(char *dataLine,struct student* ptr)
{
	sscanf(dataLine, "%d %s %s %s %d %d %d %d %d %d", &ptr->studentID,ptr->firstName,ptr->lastName,ptr->courseID,&ptr->registrationDate.day,&ptr->registrationDate.month,
		&ptr->registrationDate.year,&ptr->dateOfBirth.day,&ptr->dateOfBirth.month,&ptr->dateOfBirth.year);
}

void WriteStudentInfo(struct student *students, int lines)
{
	FILE *fp;
	fp = fopen("students.txt", "w+");

	if (fp == NULL)
	{
		perror("File could not open");
	}

	for (int i = 0; i < lines; i++)
	{
		fprintf(fp, "%d %s %s %s %d %d %d %d %d %d %d \n", students[i].studentID, students[i].firstName, students[i].lastName, students[i].courseID, students[i].registrationDate.day,
			students[i].registrationDate.month, students[i].registrationDate.year, students[i].dateOfBirth.day, students[i].dateOfBirth.month, students[i].dateOfBirth.year, students[i].averageGrade);
	}
	fclose(fp);
}