// Lab9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define PI 3.14159265359

double triangleArea(double base, double height)
{
	return ((base / 2)*height);
}

double rectangleArea(double width, double height)
{
	return width*height;
}

double trapezoidArea(double topWidth, double bottomWidth, double verticalHeight)
{
	return ((topWidth + bottomWidth) / 2)*verticalHeight;
}

double circleArea(double radius)
{
	return ((radius*radius)*PI);
}

double sectorArea(double radius, double angle)
{
	return 0.5*(radius*radius)*angle;
}

double ellipse(double verticalRadius, double horizontalRadius)
{
	return PI*verticalRadius*horizontalRadius;
}

double square(double sideLength)
{
	return sideLength*sideLength;
}

double parallelogram(double base, double verticalHeight)
{
	return base * verticalHeight;
}
int main()
{
	printf("Area of Triangle (b=1.4, h=1.6) is %.2f \n", triangleArea(1.4, 1.6));
	printf("Area of Rectangle (w=2.0, h=3.0) is %.2f \n", rectangleArea(2.0, 3.0));
	printf("Area of Trapezoid (a=2.0, b=3.0, h=4.0) is %.2f \n", trapezoidArea(2.0,3.0,4.0));
	printf("Area of Circle (r=6.0) %.2f \n", circleArea(6.0));
	printf("Area of Sector (r=3.0, theta = 2 radians) is %.2f \n", sectorArea(3.0, 2));
	printf("Area of Square (a = 2.5) is %.2f \n", square(2.5));
	printf("Area of Ellipse (a= 3.0, b= 2.0) is %.2f \n", ellipse(3.0, 2.0));
	printf("Area of Parallelogram (b=2.5, h =1.4) is %.2f \n", parallelogram(2.5, 1.4));
    return 0;
}

