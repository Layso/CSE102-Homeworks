/*----------------------------------------------------------------------------*/
/* HW03_151044001_Deniz_Can_Erdem_Yılmaz                                      */
/* HW03_151044001_Deniz_Can_Erdem_Yılmaz_part1.c                              */
/* Created on 09/03/2016 by Deniz Can Erdem Yılmaz                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This c file contains the GIT's CSE102 Homework-3 Part-1                    */
/* It contains a program that takes an integer input from user, checks the    */
/* input value and if it's valid (positive, integer) number then asks user to */
/* choose a test to perform. Returns the test result to the user              */
/*                                                                            */
/* Note(s)                                                                    */
/* -------                                                                    */
/* - Coding in this homework designed as the given code convention by         */
/*   teachers. Tab size is 4 and column limit in a row is 80                  */
/* - Function prototypes are given by teachers with HW definition PDF         */
/*----------------------------------------------------------------------------*/



/* Include(s) */
#include<stdio.h>
#include<math.h>



/* Function Prototype(s)                                                      */
/* ---------------------------------------------------------------------------*/
/* int functionSelection()                                                    */
/*                                                                            */
/* Parameter(s)                                                               */
/* ------------                                                               */
/* None                                                                       */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Returns the number of the choosen test                                     */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function only prints the test selection menu and asks user for an     */
/* input to complete the selection. Then  returns the selected test number    */
/* for the next steps                                                         */
/* ---------------------------------------------------------------------------*/
int functionSelection();

/* ---------------------------------------------------------------------------*/
/* int oddFunction(int parameter)                                             */
/*                                                                            */
/* Parameter(s)                                                               */
/* ------------                                                               */
/* parameter - Number given by user to test                                   */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Returns 0 to indicate function ended without problem                       */
/* Prints the result of the test                                              */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes the user defined number and checks if that number is   */
/* an odd number. If it is, function will print success message. If it isn't  */
/* function will print failure message                                        */
/* ---------------------------------------------------------------------------*/
int oddFunction(int parameter);

/* ---------------------------------------------------------------------------*/
/* int factorialFunction(int parameter)                                       */
/*                                                                            */
/* Parameter(s)                                                               */
/* ------------                                                               */
/* parameter - Number given by user to test                                   */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Returns 0 to indicate function ended without problem                       */
/* Prints the result of the test                                              */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes the user defined number and checks if that number is   */
/* equals to any factorial number. If it is, function will print success      */
/* message. If it isn't function will print failure message                   */
/* ---------------------------------------------------------------------------*/
int factorialFunction(int parameter);

/* ---------------------------------------------------------------------------*/
/* int narcisstisticFunction(int parameter)                                   */
/*                                                                            */
/* Parameter(s)                                                               */
/* ------------                                                               */
/* parameter - Number given by user to test                                   */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Returns 0 to indicate function ended without problem                       */
/* Prints the result of the test                                              */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes the user defined number and checks if that number is   */
/* a narcisstistic number. If it is, function will print success message. If  */
/* it isn't function will print failure message                               */
/* ---------------------------------------------------------------------------*/
int narcisstisticFunction(int parameter);

/* ---------------------------------------------------------------------------*/
/* int digitFounder(int number)                                               */
/*                                                                            */
/* Parameter(s)                                                               */
/* ------------                                                               */
/* number - Number to find how many digits does it have                       */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Returns the number of digits                                               */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes a number and finds the digit number of it. Then        */
/* returns the digit number                                                   */
/* ---------------------------------------------------------------------------*/
int digitFounder(int number);



int main()
{
	/* userInt  -- User's number to test */
	/* userChar -- User's command to test again or quit */
	int userInt;
	char userChar;
	
	
	/* Declaring userChar as 'y' to indicate user wants to continue */
	userChar = 'y';
	
	
	/* Greeting message */
	printf ("******************************************************\n");
	printf ("*                    WELCOME!                        *\n");
	printf ("*  This program checks whether the given number      *\n");
	printf ("* is an odd, a factorial  or a narcissistic number   *\n");
	printf ("*                                                    *\n");
	printf ("******************************************************\n");
	
	
	/* Creating a loop until user enters 'n' character to indicate stop the */
	/* program */
	while (userChar!='n')
	{
		/* Taking user defined number to test */
		printf ("Please enter a positive integer : ");
		scanf ("%d",&userInt);
		
		/* Checking if taken number is valid */
		if (userInt>0)
		{
			/* functionSelection function takes an input which is test number */
			/* and then triggers the switch case */
			switch(functionSelection())
			{
				case 1: oddFunction(userInt); break;
				case 2: factorialFunction(userInt); break;
				case 3: narcisstisticFunction(userInt); break;
				default: printf ("Please try again\n");
			}
		}
		
		/* If it isn't valid there will be an error message and program is */
		/* going to ask user program should continue */
		else
		{
			printf ("The entered number is not positive\n");
		}
		
		
		/* After the test, program asks users permit to continue. Input 'y' */
		/* will make the loop start again and 'n' will break it */
		printf ("Do you want to continue (y/n)? ");
		scanf (" %c",&userChar);
		
		if (userChar=='y')
		{
			/* A new line at the end of the loop to prevent the mess */
			printf ("\n");
		}
		
		if (userChar=='n')
		{
			/* If user types 'n' it will break the loop and eventually */
			/* finishes the program. So when loop breaks this final text will */
			/* show up and program ends */
			printf ("Good bye ! \n");
		}
	}
	
	
	return (0);
}



/* Function Implementation(s)                                                 */
/* ---------------------------------------------------------------------------*/
/* Function functionSelection                                                 */
/* --------------------------                                                 */
/*                                                                            */
/* This function only prints the test selection menu and asks user for an     */
/* input to complete the selection. Then  returns the selected test number    */
/* for the next steps                                                         */
/* ---------------------------------------------------------------------------*/
int functionSelection()
{
	/* Users choice */
	int userSelection;
	
	/* Printing the test selection menu */
	printf ("Which property would you like to check\n");
	printf ("1)Odd number\n");
	printf ("2)Factorial number\n");
	printf ("3)Narcisstistic number\n");
	
	/* Taking the user input */
	printf ("Please enter (1/2/3): ");
	scanf ("%d",&userSelection);
	
	
	/* Returning the choosen test to trigger switch case */
	return (userSelection);
}



/* ---------------------------------------------------------------------------*/
/* Function oddFunction                                                       */
/* --------------------                                                       */
/*                                                                            */
/* This function takes the users choosen number and checks if that number is  */
/* an odd number. If it is, function will print success message. If it isn't  */
/* function will print failure message                                        */
/* ---------------------------------------------------------------------------*/
int oddFunction(int parameter)
{
	/* Parameter is the user defined number to test. To test if given number */
	/* is an odd number function needs to know the remain from number's */
	/* division to 2. A simple mod operator will help to find out if input is */
	/* even or odd */
	if ((parameter%2)==0)
	{
		printf ("%d is not an odd number !\n",parameter);
	}
	
	else if ((parameter%2)==1)
	{
		printf ("%d is an odd number !\n",parameter);
	}
	
	
	return (0);
}



/* ---------------------------------------------------------------------------*/
/* Function factorialFunction                                                 */
/* --------------------------                                                 */
/*                                                                            */
/* This function takes the user defined number and checks if that number is   */
/* equals to any factorial number. If it is, function will print success      */
/* message. If it isn't function will print failure message                   */
/* ---------------------------------------------------------------------------*/
int factorialFunction(int parameter)
{
	/* Variables for number and its factorial */
	int n;
	int f;
	
	
	/* Initializing both as 1 and 1! to start process */
	f=1;
	n=1;
	
	
	/* To check if given number is a factorial number function will calculate */
	/* all numbers factorial from 1 until the factorial is equal or bigger */
	/* than the parameter. If factorial is equal to parameter then given */
	/* number is a factorial number. If factorial gets bigger than parameter */
	/* then given number is not a factorial number */
	
	/* Creating a loop until factorial gets bigger or equal to the parameter */
	while (f<parameter)
	{
		/* Finding a number's factorial is just multiplying last factorial */
		/* equivalent with the number itself */
		n=n+1;
		f=f*n;
	}

	
	/* After the loop checking if the parameter equals to the factorial. If */
	/* it is equal function will print success message */
	if (f==parameter)
	{
		printf ("%d is a factorial number !\n",parameter);
	}

	/* If factorial is bigger than the parameter function will print a */
	/* failure message */
	else if (f>parameter)
	{
		printf ("%d is not a factorial number !\n",parameter);
	}
	
	
	return (0);
}



/* ---------------------------------------------------------------------------*/
/* Function narcisstisticFunction                                             */
/* ------------------------------                                             */
/*                                                                            */
/* This function takes the user defined number and checks if that number is   */
/* a narcisstistic number. If it is, function will print success message. If  */
/* it isn't function will print failure message                               */
/* ---------------------------------------------------------------------------*/
int narcisstisticFunction(int parameter)
{
	/* If the sum of a numbers own digits each raised to the power of the */
	/* number of digits equals itself then the number is narcissistic number */
	/* To test it function will simply do the math with numbers digits and */
	/* check if result is equal to the number itself */
	
	
	/* Variable for the result of the calculation */
	int result;
	
	/* Digit count variable for the calculation */
	int digitCount;
	
	/* Temporary variable to save the given parameter */
	int temp;
	
	/* Loop control variable */
	int i;
	
	
	
	/* Setting the initial values */
	digitCount = digitFounder(parameter);
	temp = parameter;
	result = 0;
	

	for (i=0; i<digitCount; i++)
	{
		/* This loop finds the last digits power of total digit count and */
		/* sums it with the current result value. Divides temp variable to 10 */
		/* to apply same calculation to all of parameter's digits */
		result = ((result) + pow((temp%10),digitCount)) ;
		temp = temp/10;
	}
		
		
	/* If result equals to parameter itself then it is a narcissistic number  */
	/* and function will print success message                                */
	if (result==parameter)
	{
		printf ("%d is a narcisstistic number !\n",parameter);
	}
	
	/* If result is not equals to parameter then function will print failure   */
	/* message */
	else
	{
		printf ("%d is not a narcisstistic number !\n",parameter);
	}
	
	return (0);
}



/* ---------------------------------------------------------------------------*/
/* Function digitFounder                                                      */
/* --------------------------                                                 */
/*                                                                            */
/* This function takes a number and divides it to 10 until reaching zero      */
/* Sums the step number and returns it as digit count                         */
/* ---------------------------------------------------------------------------*/
int digitFounder(int number)
{
	/* Digit count of the number */
	int digit;
	
	
	/* Initializing the digit counter */
	digit = 0;
	
	
	/* If number is not 0 */
	if (number!=0)
	{
		/* Creating a loop to find the digit count of the number */
		while (number!=0)
		{
			/* To find the digit count this function keeps dividing the */
			/* giving number to 10 until reaching zero */
			number = number / 10;
			digit = digit + 1;		
		}
	}
	
	/* If number is 0 the function would skip the loop on the upside */
	else
	{
		/* Setting digit by hand for 0 */
		digit = 1;
	}
	
	
	return (digit);
}
/* End of HW03_151044001_Deniz_Can_Erdem_Yılmaz_part1.c */