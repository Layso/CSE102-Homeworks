/*----------------------------------------------------------------------------*/
/* HW04_151044001_Deniz_Can_Erdem_Yılmaz                                      */
/* HW04_151044001_Deniz_Can_Erdem_Yılmaz_part1.c                              */
/* Created on 21/03/2016 by Deniz Can Erdem Yılmaz                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This c file contains the GIT's CSE102 Homework-4 Part-1                    */
/* Program calculates the sine and cosine for given angle by using the Taylor */
/* series.                                                                    */
/*                                                                            */
/* Note(s)                                                                    */
/* -------                                                                    */
/* - Coding in this homework designed as the given code convention by         */
/*   teachers. Tab size is 4 and column limit in a row is 80                  */
/* - Some function prototypes are given by teachers with HW definition PDF    */
/* - Math.h library does not allowed                                          */
/*----------------------------------------------------------------------------*/



/* Include(s) */
#include<stdio.h>



/* Define(s) */
#define PI 3.14



/* Function Prototype(s)                                                      */
/* ---------------------------------------------------------------------------*/
/* double power(double x, int n)                                              */
/*                                                                            */
/* Parameter(s)                                                               */
/* ------------                                                               */
/* x - Base number                                                            */
/* n - Power number                                                           */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Returns the x power n                                                      */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes a base and a power number and calculates the n power   */
/* x. Returns the result. This function is handwritten version of pow()       */
/* function inside the math.h library                                         */
/* ---------------------------------------------------------------------------*/
double power(double x, int n);

/* ---------------------------------------------------------------------------*/
/* int factorial(int x)                                                       */
/*                                                                            */
/* Parameter(s)                                                               */
/* ------------                                                               */
/* x - Number to calculate its factorial value                                */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Returns factorial of x                                                     */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes a number and calculates the factorial of it. Returns   */
/* the result                                                                 */
/* ---------------------------------------------------------------------------*/
int factorial(int x);

/* ---------------------------------------------------------------------------*/
/* double cosine(int degree, int n)                                           */
/*                                                                            */
/* Parameter(s)                                                               */
/* ------------                                                               */
/* int degree - Angle to find its cosine value                                */
/* int n      - Number of Taylor series step                                  */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Returns value of cosine(degree)                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function uses Taylor series to calculate the value of cosine at given */
/* angle and returns the result to the user                                   */
/* ---------------------------------------------------------------------------*/
double cosine(int degree, int n);

/* ---------------------------------------------------------------------------*/
/* double sine(int degree, int n)                                             */
/*                                                                            */
/* Parameter(s)                                                               */
/* ------------                                                               */
/* int degree - Angle to find its cosine value                                */
/* int n      - Number of Taylor series step                                  */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Returns value of sine(degree)                                              */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function uses Taylor series to calculate the value of sine at given   */
/* angle and returns the result to the user                                   */
/* ---------------------------------------------------------------------------*/
double sine(int degree, int n);

/* ---------------------------------------------------------------------------*/
/* void getInputs(int *degree, int *n, int *exit)                             */
/*                                                                            */
/* Parameter(s)                                                               */
/* ------------                                                               */
/* int *degree - Angle to find its cosine value                               */
/* int *n      - Number of Taylor series step                                 */
/* int *exit   - Control variable for the end of program                      */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* None                                                                       */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes inputs from user to calculate sine and cosine or exit  */
/* the program                                                                */
/* ---------------------------------------------------------------------------*/
void getInputs(int *degree, int *n, int *exit);



int main()
{
	/* 3 main variables to direct the program */
	int degree;
	int n;
	int exit;
	
	
	/* Declaring exit variale as 0 to indicate exit when returned to 1 */
	exit = 0;
	
	
	/* Creating a loop to countinue until user wants to exit */
	while (exit!=1)
	{
		/* Taking inputs from user */
		getInputs(&degree,&n,&exit);
		
		/* Calling functions to calculate sine and cosine values using */
		/* the angle and n data given by user */ 
		sine(degree,n); 
		cosine(degree,n); 
	}
	
	
	return (0);
}



/* Function Implementation(s)                                                 */
/* ---------------------------------------------------------------------------*/
/* Function getInputs                                                         */
/* ------------------------                                                   */
/* Takes either necessary data from user for calculations or 'e' character to */
/* end the program                                                            */ 
/* ---------------------------------------------------------------------------*/
void getInputs(int *degree, int *n, int *exit)
{
	/* Variable to check return value of scanf */
	int scanfValue;
	
	/* Variable to take char input if necessary */
	char exitValue;
	
	
	/* Taking input from user. If user gives numbers needed for calculation */
	/* scanf() will return 2, if user enters a character it will return 1 */
	scanfValue = scanf("%d %d",degree,n);
	
	
	/* Checking the return value of scanf() function */
	if (scanfValue != 2)
	{
		/* Assigning input to char variable if given data number is not */
		/* enough */
		scanf("%c",&exitValue);
		
		/* Checking if input is either 'e' or 'E' character */
		if (exitValue=='E' || exitValue=='e')
		{
			/* If it is change exit variable to 1 to indicate the end of */
			/* the program */
			*exit=1;
		}
		
		/* Else program continues */
		else
		{
			*exit=0;
		}
	}
	
	/* Else program continues */
	else
	{
		*exit=0;
	}
}



/* ---------------------------------------------------------------------------*/
/* Function power                                                             */
/* ------------------------                                                   */
/* This function is similar to pow() function in math.h library               */
/* ---------------------------------------------------------------------------*/
double power(double x, int n)
{
	/* Return variable */
	double result;
	
	/* Loop control variable */
	int i;
	
	
	/* Initializing result as 1 for identity element of multiplication */
	result = 1;
	
	
	/* Creating a loop to multply x with itself n times */
	for(i=0;i<n;i++)
	{
		/* Assigning resul to result variable */
		result = result * x;
	}
	
	
	/* Returning the result of the calculation */
	return (result);
}




/* ---------------------------------------------------------------------------*/
/* Function factorial                                                         */
/* ------------------------                                                   */
/* This function finds the factorial value of given number                    */
/* ---------------------------------------------------------------------------*/
int factorial(int x)
{
	/* Variables for the calculation */
	int initial;
	int result;
	
	
	/* Initializing counter variable as 1 */
	initial = 1;
	
	
	
	/* Calculation starts if given number is bigger than 0 */
	if (x>=0)
	{
		/* If number is 0 or 1 there is no need for calculation */
		if (x==0 || x==1)
		{
			result = 1;
		}

		/* Else calculate the factorial */
		else if (x>1)
		{
			/* Initializing result as 1 for identity element of */
			/* multiplication */
			result = 1;
			
			/* Creating a loop to calculate factorial. Multiplying result */
			/* with current number (initial) until the initial's value */
			/* reaches to given x number */
			while (initial <= x)
			{
				result = result * initial;
				initial = initial + 1; 
			}
		}
	}
	
	/* If given number is lesser than 0 then it is an invalid number */
	else
	{
		return (-1);
	}
	
	
	/* Returning the result of the calculation */
	return (result);
}



/* ---------------------------------------------------------------------------*/
/* Function sine                                                              */
/* ------------------------                                                   */
/* This function calcuates the sine value of given angle by using the Taylor  */
/* series and prints the result to the user                                   */
/* ---------------------------------------------------------------------------*/
double sine(int degree, int n){
	/* Variables for calculation */
	int i;
	double stepValue;
	double sumResult;
	double radian;
	int temp;
	
	
	/* Finding the radian equivalent of the given degree */
	temp = degree%180;
	radian = (temp*PI)/180;
	
	/* Initializing loop control variable and sumResult variable */
	i = 0;
	sumResult = 0;
	
	
	/* Creating a loop for the summation sign that keeps summation until */
	/* reaching the given n number */
	while (i<n)
	{
		/* Converting formula to expression */
		stepValue = (power(-1,i)*power(radian,(2*i)+1))/(factorial((2*i)+1));
		
		/* Adding calculated value of this step to grand total */
		sumResult = sumResult + stepValue;
		
		/* Increasing loop control variable */
		i = i + 1;
	}


	/* Sign change for the sine */
	if (degree>180 && degree<360)
	{
		sumResult = -sumResult;
	}
	
	
	/* Printing the result to the user */
	printf ("sin(%d) where n is %d = %.4f\n",degree,n,sumResult);
	
	
	return (degree);
}



/* ---------------------------------------------------------------------------*/
/* Function cosine                                                            */
/* ------------------------                                                   */
/* This function calcuates the cosine value of given angle by using the       */
/* Taylor series and prints the result to the user                            */
/* ---------------------------------------------------------------------------*/
double cosine(int degree, int n)
{
	/* Variables for calculation */
	int i;
	double stepValue;
	double sumResult;
	double radian;
	int temp;
	
	
	/* Finding the radian equivalent of the given degree */
	temp = degree%180;
	radian = (temp*PI)/180;
	
	/* Initializing loop control variable and sumResult variable */
	i = 0;
	sumResult = 0;
	
	
	/* Creating a loop for the summation sign that keeps summation until */
	/* reaching the given n number */
	while (i<n)
	{
		/* Converting formula to expression */
		stepValue = (power(-1,i) * power(radian,(2*i))) / (factorial((2*i)));
		
		/* Adding calculated value of this step to grand total */
		sumResult = sumResult + stepValue;
		
		/* Increasing loop control variable */
		i = i + 1;
	}
	
	
	/* Sign change for the sine */
	if (degree>180 && degree<270)
	{
		sumResult = -sumResult;
	}
	
	
	/* Printing the result to the user */
	printf ("cos(%d) where n is %d = %.4f\n",degree,n,sumResult);
	
	
	return (degree);
}
/* End of HW04_151044001_Deniz_Can_Erdem_Yılmaz_part1.c */