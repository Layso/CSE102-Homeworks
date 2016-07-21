/*----------------------------------------------------------------------------*/
/* HW02_151044001_Deniz_Can_Erdem_Yılmaz                                      */
/* HW02_151044001_Deniz_Can_Erdem_Yılmaz_part2.c                              */
/* Created on 01/03/2016 by Deniz Can Erdem Yılmaz                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This c file contains the GIT's CSE102 Homework-2 Part-2                    */
/* Program calculates area and parameters of a rectangle, a square and a      */
/* circle. Width, height and radius informations are taken from user as       */
/* inputs.                                                                    */
/*                                                                            */
/* Note(s)                                                                    */
/* -------                                                                    */
/* - Coding in this homework designed as the given code convention by         */
/*   teachers. Tab size is 4 and column limit in a row is 80                  */
/* - Function prototypes are given by teachers with HW definition PDF         */
/* - I/O operations within the helper functions are not allowed               */
/*----------------------------------------------------------------------------*/



/* Include(s) */
#include<stdio.h>




/* Define(s) */
#define PI 3.14



/* Function Prototype(s)                                                      */
/* ---------------------------------------------------------------------------*/
/* int areaOfRectangle(int width, int height)                                 */
/*                                                                            */
/* Parameter(s)                                                               */
/* ------------                                                               */
/* width  - Width of rectangle                                                */
/* Height - Height of rectangle                                               */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Returns the area of the rectangle                                          */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes two parameters which represents the width and height   */
/* of a rectangle. Calculates the area of rectangle and returns the area.     */
/* ---------------------------------------------------------------------------*/
int areaOfRectangle(int width, int height);

/* ---------------------------------------------------------------------------*/
/* int areaOfSquare(int width)                                                */
/*                                                                            */
/* Parameter(s)                                                               */
/* ------------                                                               */
/* width  - Width of square                                                   */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Returns the area of the square                                             */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes a parameter which represents the width of a square.    */
/* Calculates the area of square and returns the area.                        */
/* ---------------------------------------------------------------------------*/
int areaOfSquare(int width);

/* ---------------------------------------------------------------------------*/
/* int areaOfCircle(int radius)                                               */
/*                                                                            */
/* Parameter(s)                                                               */
/* ------------                                                               */
/* radius  - Radius of circle                                                 */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Returns the area of the circle                                             */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes a parameter which represents the radius of a circle.   */
/* Calculates the area of circle and returns the area.                        */
/* ---------------------------------------------------------------------------*/
double areaOfCircle(int radius);

/* ---------------------------------------------------------------------------*/
/* int perimeterOfRectangle(int width, int height)                            */
/*                                                                            */
/* Parameter(s)                                                               */
/* ------------                                                               */
/* width  - Width of rectangle                                                */
/* Height - Height of rectangle                                               */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Returns the perimeter of the rectangle                                     */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes two parameters which represents the width and height   */
/* of a rectangle. Calculates the perimeter of rectangle and returns the      */
/* perimeter.                                                                 */
/* ---------------------------------------------------------------------------*/
int perimeterOfRectangle(int width, int height);

/* ---------------------------------------------------------------------------*/
/* int perimeterOfSquare(int width)                                           */
/*                                                                            */
/* Parameter(s)                                                               */
/* ------------                                                               */
/* width  - Width of square                                                   */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Returns the perimeter of the square                                        */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes a parameter which represents the width of a square.    */
/* Calculates the perimeter of square and returns the perimeter.              */
/* ---------------------------------------------------------------------------*/
int perimeterOfSquare(int width);

/* ---------------------------------------------------------------------------*/
/* int perimeterOfCircle(int radius)                                          */
/*                                                                            */
/* Parameter(s)                                                               */
/* ------------                                                               */
/* radius  - Radius of circle                                                 */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Returns the perimeter of the circle                                        */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes a parameter which represents the radius of a circle.   */
/* Calculates the perimeter of circle and returns the perimeter.              */
/* ---------------------------------------------------------------------------*/
double perimeterOfCircle(int radius);



int main()
{
	/* Variables for the length of the geometrical shapes */
	int widthRectangle;
	int heightRectangle;
	int widthSquare;
	int radiusCircle;
	
	/* Variables for the area and parameter of the geometrical shapes */
	int areaRec;
	int periRec;
	int areaSqu;
	int periSqu;
	double areaCirc;
	double periCirc;
	

	/* Taking the length informations about the rectangle */
	printf ("Please enter the width of the rectangle: ");
	scanf ("%d",&widthRectangle);
	
	printf ("Please enter the height of the rectangle: ");
	scanf ("%d",&heightRectangle);
	
	/* Calculating the area and perimeter of rectangle */
	areaRec = areaOfRectangle(widthRectangle, heightRectangle);
	periRec = perimeterOfRectangle(widthRectangle, heightRectangle);
	
	/* Printing the area and perimeter of rectangle */
	printf ("The area of the rectangle is: %d\n",areaRec);
	printf ("The perimeter of the rectangle is: %d\n",periRec);
	
	
	
	/* Taking the length informations about the square */
	printf ("Please enter the width of the square: ");
	scanf ("%d",&widthSquare);
	
	/* Calculating the area and perimeter of square */
	areaSqu = areaOfSquare(widthSquare);
	periSqu = perimeterOfSquare(widthSquare);
	
	/* Printing the area and perimeter of square */
	printf ("The area of the square is: %d\n",areaSqu);
	printf ("The perimeter of the square is: %d\n",periSqu);
	


	/* Taking the length informations about the circle */
	printf ("Please enter the radius of the circle: ");
	scanf ("%d",&radiusCircle);
	
	/* Calculating the area and perimeter of circle */
	areaOfCircle(radiusCircle);
	perimeterOfCircle(radiusCircle);
	
	/* Printing the area and perimeter of circle */
	printf ("The area of the circle is: %d\n",areaCirc);
	printf ("The perimeter of the circle is: %d\n",periCirc);
	
	
	return;
}




/* Function Implementation(s)                                                 */
/* ---------------------------------------------------------------------------*/
/* Function areaOfRectangle                                                   */
/* ------------------------                                                   */
/* Finds the area of a rectangle by multiplying its width with its height and */
/* returns the result of the calculation                                      */
/* ---------------------------------------------------------------------------*/
int areaOfRectangle(int width, int height)
{
	/* Return value */
	int area;
	
	/* Making the calculation */
	area = (width * height);
	
	/* Returning the result */
	return (area);
}



/* ---------------------------------------------------------------------------*/
/* Function areaOfSquare                                                      */
/* ---------------------                                                      */
/* Finds the area of a square by multiplying its width itself and returns the */
/* result of the calculation                                                  */
/* ---------------------------------------------------------------------------*/
int areaOfSquare(int width)
{
	/* Return value */
	int area;
	
	/* Making the calculation */
	area = (width * width);
	
	/* Returning the result */
	return (area);
}



/* ---------------------------------------------------------------------------*/
/* Function areaOfCircle                                                      */
/* ---------------------                                                      */
/* Finds the area of a circle by using the (pi*radius*radius) equation and    */
/* returns the result of the calculation                                      */
/* ---------------------------------------------------------------------------*/
int areaOfCircle(int radius)
{
	/* Return value */
	int area;
	
	/* Making the calculation */
	area = (PI * radius * radius);

	/* Returning the result */
	return (area);
}



/* ---------------------------------------------------------------------------*/
/* Function perimeterOfRectangle                                              */
/* -----------------------------                                              */
/* Finds the perimeter of a rectangle by multiplying the total of width and   */
/* height with 2 and returns the result of the calculation                    */
/* ---------------------------------------------------------------------------*/
perimeterOfRectangle(int width, int height)
{
	/* Return value */
	int perimeter;
	
	/* Making the calculation */
	perimeter = ((width + height) * 2);
	
	/* Returning the result */
	return (perimeter);
}



/* ---------------------------------------------------------------------------*/
/* Function perimeterOfSquare                                                 */
/* --------------------------                                                  */
/* Finds the perimeter of a square by multiplying width with 4 and returns    */
/* the result of the calculation                                              */
/* ---------------------------------------------------------------------------*/
perimeterOfSquare(int width)
{
	/* Return value */
	int perimeter;
	
	/* Making the calculation */
	perimeter = (width * 4);
	
	/* Returning the result */
	return (perimeter);
}



/* ---------------------------------------------------------------------------*/
/* Function perimeterOfCircle                                                 */
/* --------------------------                                                 */
/* Finds the perimeter of a circle by using the (2*pi*radius) equation and    */
/* returns the result of the calculation                                      */
/* ---------------------------------------------------------------------------*/
perimeterOfCircle(int radius)
{
	/* Return value */
	int perimeter;
	
	/* Making the calculation */
	perimeter = (2 * PI * radius);
	
	/* Returning the result */
	return (perimeter);
}
/* End of HW02_151044001_Deniz_Can_Erdem_Yılmaz_part2.c */
