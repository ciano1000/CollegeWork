// Week16.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct data
{
	int year;
	double tmax[12];
	double tmin[12];
	int frostDays[12];
	double rain[12];
	double sun[12];
};

void SortWeatherData(char *dataLine, struct data *ptr, int *currYear);
void GetTMax(struct data *ptr);
void GetTMin(struct data *ptr);
void MaxFrost(struct data *ptr);
void RainMax(struct data *ptr);
void SunMax(struct data *ptr);

struct data weatherData[59];
const char * months[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

int main()
{

	char userOption;

	bool isRunning = true;

	FILE *fp;
	fp = fopen("WeatherData.txt", "r+");

	int currYear = 1959;

	if (fp == NULL)
	{
		perror("File coudn't open");
	}
	else
	{
		for (int i = 0; i < 716; i++)
		{
			char temp[150];
			fgets(temp, 150, fp);
			if (i > 6)
			{
				SortWeatherData(temp, weatherData, &currYear);
			}
		}

	}

	while (isRunning == true)
	{

		fflush(stdin);

		
		printf("\n Choose Option:\n [1]Temp Max\n [2]Temp Min\n [3]Air Frost Days Max\n [4]Rain Max\n [5]Sun Max\n [6]Exit\n");
		
		scanf(" %c", &userOption);

		switch (userOption)
		{
		case '1':
			GetTMax(weatherData);
			break;
		case '2':
			GetTMin(weatherData);
			break;
		case '3':
			MaxFrost(weatherData);
			break;
		case '4':
			RainMax(weatherData);
			break;
		case '5':
			SunMax(weatherData);
			break;
		case '6':
			isRunning = false;
			
			break;
		
		}
	}
    return 0;
}
void SortWeatherData(char *dataLine, struct data *ptr, int *currYear)
{
	int tempYear = 0;
	int tempMonth = 0;
	sscanf(dataLine, "%d %d", &tempYear, &tempMonth);

	if (tempYear == *currYear)
	{
		sscanf(dataLine, "%d %d %lf %lf %d %lf %lf", &ptr[tempYear-1959].year, &tempMonth,&ptr[tempYear - 1959].tmax[tempMonth-1], &ptr[tempYear - 1959].tmin[tempMonth-1], &ptr[tempYear - 1959].frostDays[tempMonth-1], &ptr[tempYear - 1959].rain[tempMonth-1], &ptr[tempYear - 1959].sun[tempMonth-1]);
	}
	else
	{
		*currYear = tempYear;
		sscanf(dataLine, "%d %d %lf %lf %d %lf %lf", &ptr[tempYear - 1959].year, &tempMonth, &ptr[tempYear - 1959].tmax[tempMonth - 1], &ptr[tempYear - 1959].tmin[tempMonth - 1], &ptr[tempYear - 1959].frostDays[tempMonth - 1], &ptr[tempYear - 1959].rain[tempMonth - 1], &ptr[tempYear - 1959].sun[tempMonth - 1]);
	}
}
void GetTMax(struct data *ptr)
{
	double currMax = 0;
	int currYear = 0;
	int currMonth = 0;

	for (int i = 0; i < 59; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			double tempMax = ptr[i].tmax[j];
			if (tempMax > currMax)
			{
				currMax = tempMax;
				currYear = ptr[i].year;
				currMonth = j;
			}
		}
	}
	printf("Max Temp was %.2f degrees C in %s of %d \n", currMax, months[currMonth], currYear);
}
void GetTMin(struct data *ptr)
{
	double currMin = 1000;
	int currYear = 0;
	int currMonth = 0;
	for (int i = 0; i < 59; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			double tempMin = ptr[i].tmin[j];
			if (currMin> tempMin)
			{
				currMin = tempMin;
				currYear = ptr[i].year;
				currMonth = j;
			}
		}
	}
	printf("Min Temp was %.2f degrees C in %s of %d \n", currMin, months[currMonth], currYear);
}

void MaxFrost(struct data *ptr)
{
	int currMax = 0;
	int currYear = 0;
	int currMonth = 0;
	for (int i = 0; i < 59; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			int tempMax = ptr[i].frostDays[j];
			if (currMax< tempMax)
			{
				currMax = tempMax;
				currYear = ptr[i].year;
				currMonth = j;
			}
		}
	}
	printf("Max Air Frost Days was %d days in %s of %d \n", currMax, months[currMonth], currYear);
}

void RainMax(struct data *ptr)
{
	double currMax = 0;
	int currYear = 0;
	int currMonth = 0;

	for (int i = 0; i < 59; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			double tempMax = ptr[i].rain[j];
			if (tempMax > currMax)
			{
				currMax = tempMax;
				currYear = ptr[i].year;
				currMonth = j;
			}
		}
	}
	printf("Max Rain was %.2f mm in %s of %d \n", currMax, months[currMonth], currYear);
}
void SunMax(struct data *ptr)
{
	double currMax = 0;
	int currYear = 0;
	int currMonth = 0;

	for (int i = 0; i < 59; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			double tempMax = ptr[i].sun[j];
			if (tempMax > currMax)
			{
				currMax = tempMax;
				currYear = ptr[i].year;
				currMonth = j;
			}
		}
	}
	printf("Max Sun was %.2f hours in %s of %d \n", currMax, months[currMonth], currYear);
}

