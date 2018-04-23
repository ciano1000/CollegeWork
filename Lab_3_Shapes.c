// Shapes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define TRIANGLE 1
#define RECTANGLE 2
#define TRAPEZOID 3
#define CIRCLE 4
#define SECTOR 5

#define PI 3.14159265358979323846

void triangleArea()
{
	float base = 0;
	float height = 0;
	printf("Enter Base Width: ");
	scanf_s("%f", &base);
	printf("Enter Vertical Height: ");
	scanf_s("%f", &height);

	float area = ((base / 2)*height);

	printf("Area: %.2fm^2\n", area);

}

void rectangleArea()
{
	float width = 0;
	float height = 0;
	printf("Enter Width: ");
	scanf_s("%f", &width);
	printf("Enter Height: ");
	scanf_s("%f", &height);

	float area = width*height;

	printf("Area: %.2fm^2\n", area);
}

void trapezoidArea()
{
	float topWidth = 0;
	float bottomWidth = 0;
	float verticalHeight = 0;

	printf("Enter Top Width: ");
	scanf_s("%f", &topWidth);
	printf("Enter bottomWidth");
	scanf_s("%f", &bottomWidth);
	printf("Enter Vertical Height: ");
	scanf_s("%f", &verticalHeight);

	float area = ((topWidth + bottomWidth) / 2)*verticalHeight;

	printf("Area: %.2fm^2\n", area);
}

void circleArea()
{
	float radius = 0;

	printf("Enter Radius: ");
	scanf_s("%f", &radius);

	float area = (radius*radius)*(float)PI;

	printf("Area: %.2fm^2\n", area);
}

void sectorArea()
{
	float radius = 0;
	float angle = 0;

	printf("Enter Radius: ");
	scanf_s("%f", &radius);

	int counter = 0;

	while (counter == 0)
	{
		printf("Enter Angle: ");
		scanf_s("%f",&angle);
		
		if ((angle <= 360) && (angle >= 0))
		{
			counter = 1;
		}
		else
		{
			printf("ERROR: Enter an angle between 0 and 360 degrees\n");
		}
	}
	

	float area = ((radius*radius)*PI)*(angle/360.00f);
	
	printf("Area: %.2fm^2\n", area);
}

int main()
{
	int choice = 0;
	int counter = 0;

	while (counter == 0)
	{
		printf("Area Calculator\nEnter Choice\n1 <Triangle>\n2 <Rectangle>\n3 <Trapezoid>\n4 <Circle>\n5 <Sector>\n ");
		scanf_s("%d", &choice);
		if ((choice <= 5) && (choice >= 1))
		{
			counter = 1;
		}
		else
		{
			printf("Area Calculator will now restart: ERROR enter a number between 1-5\n");
		}
	}
	printf("Choice:%d\n",choice);
	switch (choice)
	{
	case TRIANGLE:
		
		triangleArea();
		break;

	case RECTANGLE:
		rectangleArea();
		break;

	case TRAPEZOID:
		trapezoidArea();
		break;

	case CIRCLE:
		circleArea();
		break;

	case SECTOR:
		sectorArea();
		break;


	}

    return 0;
}





