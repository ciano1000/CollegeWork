// Lab2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"



int main()
{
	int englishMark = 0;
	int scienceMark = 0;
	int frenchMark = 0;
	int irishMark = 0;
	int economicsMark = 0;
	int highestMark = 0;

	float averageMark = 0.0f;

	bool failedEnglish;
	bool failedScience;
	bool failedFrench;
	bool failedIrish;
	bool failedEconomics;

	


	printf("Enter English mark:\t");
	scanf_s("%d", &englishMark);
	printf("Enter Science mark:\t");
	scanf_s("%d", &scienceMark);
	printf_s("Enter French mark:\t");
	scanf_s("%d", &frenchMark);
	printf("Enter Irish mark:\t");
	scanf_s("%d", &irishMark);
	printf_s("Enter Economics Mark:\t");
	scanf_s("%d", &economicsMark);
	
	averageMark = (englishMark + scienceMark + frenchMark + irishMark + economicsMark)/5;

	printf("The average mark is:%.2f \n", averageMark);

	failedIrish = (irishMark < 40);
	failedScience = (scienceMark < 40);
	failedFrench = (frenchMark < 40);
	failedEconomics = (economicsMark < 40);
	failedEnglish = (englishMark < 40);

	printf("Fails:");

	if (failedIrish)
	{
		printf("Irish, ");
	}

	if (failedEconomics)
	{
		printf("Economics, ");
	}

	if (failedEnglish)
	{
		printf("English, ");
	}
	if (failedFrench)
	{
		printf("French, ");
	}
	if (failedScience)
	{
		printf("Science, ");
	}
	
	printf("\nPassed:");

	if (!failedIrish)
	{
		printf("Irish, ");
	}

	if (!failedEconomics)
	{
		printf("Economics, ");
	}

	if (!failedEnglish)
	{
		printf("English, ");
	}
	if (!failedFrench)
	{
		printf("French, ");
	}
	if (!failedScience)
	{
		printf("Science, ");
	}
	
	if ((englishMark > scienceMark)&&(englishMark>irishMark)&&(englishMark>economicsMark)&&(englishMark>frenchMark))
	{
		highestMark = englishMark;
	}
	if ((scienceMark > englishMark) && (scienceMark>irishMark) && (scienceMark>economicsMark) && (scienceMark>frenchMark))
	{
		highestMark = scienceMark;
	}
	if ((frenchMark > scienceMark) && (frenchMark>irishMark) && (frenchMark>economicsMark) && (frenchMark>englishMark))
	{
		highestMark = frenchMark;
	}
	if ((irishMark > scienceMark) && (irishMark>englishMark) && (irishMark>economicsMark) && (irishMark>frenchMark))
	{
		highestMark = irishMark;
	}
	if ((economicsMark > scienceMark) && (economicsMark>irishMark) && (economicsMark>englishMark) && (economicsMark>frenchMark))
	{
		highestMark = economicsMark;
	}

	printf("\nHighest Mark:%d \n",highestMark);
    return 0;
}

