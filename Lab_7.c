// Lab8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>
#include "ctype.h"
#include "string.h"

#define M_PI        3.14159265358979323846264338327950288

int main()
{
	bool calculate = true;

	char function[10];
	char upperFunction[10];
	char answer;

	
	int angle = 0;

	double radians = 0;
	double result = 0;
	
	
	while(calculate == true)
	{
		
		printf_s("Enter calculation using degrees, e.g \"cos 45\" \n");
		fgets(function, 4, stdin);
		scanf_s("    %d", &angle);
		radians = (angle)*(M_PI / 180);
		
		if (strcmp("cos", function) ==0)
		{
			
			result = cos(radians);
		}
	    if (strcmp("sin", function) == 0)
		{
			result = sin(radians);
		}
		if (strcmp("tan", function) == 0)
		{
			result = tan(radians);
		}
		printf("%s<%d> = %2.2f \n", function, angle , result);
		printf("Do you want to perform another calculation?: Y/N \n");

		getchar();

		scanf_s("%c", &answer);

		getchar();
		
	    if (toupper(answer) == 'Y')
		{
			calculate = true;
		}
		else if (toupper(answer) == 'N')
		{
			calculate = false;
		}
		
	} 
	return 0;
}

