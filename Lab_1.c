// Lab12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	int hours = 0;
	float basicRate = 25.00;
	float overtimeRate = 50.00;
	float pay = 0.0;

	printf("Enter hours worked:");
	scanf_s("%d", &hours);

	if (hours <= 40)
	{
		pay = hours*basicRate;
		printf("You worked %d hours, and earned %.2f", hours, pay);
	}
	else
	{
		pay = 40 * basicRate + ((hours - 40)*overtimeRate);
		printf("You worked %d hours, and earned %.2f \n", hours, pay);
	}

	
	//printf("Pay = %.2f \n", pay);
    return 0;
}

