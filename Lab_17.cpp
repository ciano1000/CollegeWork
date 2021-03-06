// Week21.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdarg.h>
#include "string.h"
#include "stdlib.h"

struct Time
{
	int hour, minute;
};
struct Date 
{
	int day, month, year;
};
struct workTime
{
	int employeeID;
	struct Date date;
	struct Time startTime;
	struct Time endTime;
};

char months[12][20] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
struct Time getTime(char *string);
struct Date getDate(char *string);
void AddRecord(struct workTime Record, FILE *fp);
void SearchRecords(int ID, FILE *fp);
void PrintRecords(FILE *fp);

int main(int argc, char *argv[])
{
	struct workTime temp;
	char *inputPath;
	FILE *fp;

	int i;
	int ID;

	inputPath = argv[1];

	fp = fopen("Data.txt", "a+");

	if (fp == NULL)
	{
		puts("Coudn't open file, closing \n");
		return 1;
	}

	if (!strcmp(argv[2], "/a"))
	{
		i = 3;

		while (1)
		{
			if (argv[i] == NULL)
			{
				break;
			}
			temp.employeeID = atoi(argv[i]);
			i++;
			temp.date = getDate(argv[i]);
			i++;
			temp.startTime = getTime(argv[i]);
			i++;
			temp.endTime = getTime(argv[i]);

			AddRecord(temp, fp);
			i++;

		}
	}

	if (!strcmp(argv[2], "/p"))
	{
		PrintRecords(fp);
	}

	if (!strcmp(argv[2], "/s"))
	{
		ID = atoi(argv[3]);
		SearchRecords(ID, fp);
	}


    return 0;
}

struct Time getTime(char *string)
{
	char *token;
	char delim[2] = ":";

	struct Time time;

	token = strtok(string, delim);
	time.hour = atoi(token);
	token = strtok(NULL, delim);
	time.minute = atoi(token);

	return time;
}

struct Date getDate(char *string)
{
	struct Date date;
	char *token;
	char delim[2] = "/";

	token = strtok(string, delim);
	date.day = atoi(token);
	token = strtok(NULL, delim);
	date.month = atoi(token);
	token = strtok(NULL, delim);
	date.year = atoi(token);

	return date;

}

void AddRecord(struct workTime Record, FILE *fp)
{
	char temp[200];

	sprintf(temp, "\"%s %d %d\",\"%d\",\"%d:%d\",\"%d:%d\"\n",months[Record.date.month -1],Record.date.day,Record.date.year,Record.employeeID,Record.startTime.hour,Record.startTime.minute,Record.endTime.hour,Record.endTime.minute );
	fputs(temp, fp);
}

void PrintRecords(FILE *fp)
{
	int i;
	struct workTime record;
	char line[200];
	char *token;
	char delim[5] = "\", :";
	rewind(fp);
	fgets(line, 200, fp);

	while (!feof(fp))
	{
		token = strtok(line, delim);
		for (i = 0; i < 12; i++)
		{
			if (!strcmp(months[i], token))
			{
				record.date.month = i + 1;
				break;
			}
		}

		token = strtok(NULL, delim);
		record.date.day = atoi(token);
		token = strtok(NULL, delim);
		record.date.year = atoi(token);
		token = strtok(NULL, delim);
		record.employeeID = atoi(token);
		token = strtok(NULL, delim);
		record.startTime.hour = atoi(token);
		token = strtok(NULL, delim);
		record.startTime.minute = atoi(token);
		token = strtok(NULL, delim);
		record.endTime.hour = atoi(token);
		token = strtok(NULL, delim);
		record.endTime.minute = atoi(token);

		printf("Date: %d/%d/%d Employee: %d started at %d:%d and finished at %d:%d\n", record.date.day, record.date.month, record.date.year, record.employeeID, record.startTime.hour, record.startTime.minute, record.endTime.hour, record.endTime.minute);

		fgets(line, 200, fp);
	}
}

void SearchRecords(int ID, FILE *fp)
{
	int i;
	struct workTime record;
	char line[200];
	char *token;
	char delim[5] = "\", :";
	rewind(fp);
	fgets(line, 200, fp);

	while (!feof(fp))
	{
		token = strtok(line, delim);
		for (i = 0; i < 12; i++)
		{
			if (!strcmp(months[i], token))
			{
				record.date.month = i + 1;
				break;
			}
		}
		token = strtok(NULL, delim);
		record.date.day = atoi(token);
		token = strtok(NULL, delim);
		record.date.year = atoi(token);
		token = strtok(NULL, delim);
		record.employeeID = atoi(token);
		token = strtok(NULL, delim);
		record.startTime.hour = atoi(token);
		token = strtok(NULL, delim);
		record.startTime.minute = atoi(token);
		token = strtok(NULL, delim);
		record.endTime.hour = atoi(token);
		token = strtok(NULL, delim);
		record.endTime.minute = atoi(token);

		if (record.employeeID == ID)
		{
			printf("Date: %d/%d/%d Employee: %d started at %d:%d and finished at %d:%d\n", record.date.day, record.date.month, record.date.year, record.employeeID, record.startTime.hour, record.startTime.minute, record.endTime.hour, record.endTime.minute);
		}
		fgets(line, 200, fp);
	}
}