// MinMaxAverage.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	double numbers[10];
	double max = 0, min = 0,total = 0,average = 0;
	int size;
	

	printf("Program to calculate Min, Max and Average of up to 10 floating point numbers \nEnter up to 10 numbers <enter 0.0 to end input>\n");
	
	for (int i = 0; i < 10; i++)
	{
		
		printf("#%d:\t", i+1);
		scanf_s("%lf", &numbers[i]);
		
		
		total += numbers[i];
		if (numbers[i] == 0.0f)
		{
			size = i;
			if (numbers[0] == 0.0f) 
			{
				printf("No numbers entered-quitting.\n");
					return 0;
			}
			average = total / (i);
			break;
		}
		average = total / 10;
		
	}
	
	max = numbers[0];
	min = numbers[0];

	for (int i = 0; i < size; i++)
	{
		if (max < numbers[i]) 
		{
			max = numbers[i];
		}
		if (min > numbers[i]) 
		{
			min = numbers[i];
		}
	}
	
	printf("Average:%lf, Min:%lf, Max:%lf\n", average, min, max);

	

    return 0;
}

