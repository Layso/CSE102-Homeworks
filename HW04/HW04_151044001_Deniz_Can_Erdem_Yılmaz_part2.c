/*----------------------------------------------------------------------------*/
/* HW04_151044001_Deniz_Can_Erdem_Yılmaz                                      */
/* HW04_151044001_Deniz_Can_Erdem_Yılmaz_part2.c                              */
/* Created on 22/03/2016 by Deniz Can Erdem Yılmaz                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This c file contains the GIT's CSE102 Homework-4 Part-2                    */
/* The program intended to print a number taken as input inside borders with  */
/* using a specific character given by user as input                          */
/*                                                                            */
/* Note(s)                                                                    */
/* -------                                                                    */
/* - Coding in this homework designed as the given code convention by         */
/*   teachers. Tab size is 4 and column limit in a row is 80                  */
/* - Some function prototypes are given by teachers with HW definition PDF    */
/*----------------------------------------------------------------------------*/



/* Include(s) */
#include<stdio.h>



/* Function Prototype(s)                                                      */
/* ---------------------------------------------------------------------------*/
/* void getInputs(int* num, int* borderWidth, char* borderChar)               */
/*                                                                            */
/* Parameter(s)                                                               */
/* ------------                                                               */
/* num         - Number to print on screen                                    */
/* borderWidth - Width of the border around the printed number                */
/* borderChar  - Specific character to print both number and border with      */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* None                                                                       */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes inputs from the user and do needed function calls to   */
/* print the number and border to the screen                                  */
/* ---------------------------------------------------------------------------*/
void getInputs(int* num, int* borderWidth, char* borderChar);

/* ---------------------------------------------------------------------------*/
/* int printNumber(int num, int borderWidth, char borderChar)                 */
/*                                                                            */
/* Parameter(s)                                                               */
/* ------------                                                               */
/* num         - Number to print on screen                                    */
/* borderWidth - Width of the border around the printed number                */
/* borderChar  - Specific character to print both number and border with      */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* 1 - If given number is invalid                                             */
/* 0 - If everything went well                                                */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function prints an integer to screen with a border by using a         */
/* specific character. Number, border width and that specific character are   */
/* taken as parameters. If number is beyond the limit (0<x<100.000) function  */
/* does nothing but returning 1. Else function prints number and returns 0    */
/* ---------------------------------------------------------------------------*/
int printNumber(int num, int borderWidth, char borderChar);

/* ---------------------------------------------------------------------------*/
/* int digitCounter(int number)                                               */
/*                                                                            */
/* Parameter(s)                                                               */
/* ------------                                                               */
/* number - Number to find its digit count                                    */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Returns the number of digits                                               */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function finds given integer parameter's digit count                  */
/* ---------------------------------------------------------------------------*/
int digitCounter(int number);

/* ---------------------------------------------------------------------------*/
/* int printFunction(int num, int borderWidth, char borderChar, int           */
/* lineNumber, int digitCount)                                                */
/*                                                                            */
/* Parameter(s)                                                               */
/* ------------                                                               */
/* num         - Number to print on screen                                    */
/* borderWidth - Width of the border around the printed number                */
/* borderChar  - Specific character to print both number and border with      */
/* lineNumber  - Row number of the number has been printing                   */
/* digitCount  - Digit count of the number                                    */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Returns 0 to indicate function works properly                              */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function prints a row for each digit number has                       */
/* ---------------------------------------------------------------------------*/
int printFunction(int num, int borderWidth, char borderChar, int lineNumber, 
int digitCount);

/* ---------------------------------------------------------------------------*/
/* int numberSwitch(int number, int lineNumber, char borderChar)              */
/*                                                                            */
/* Parameter(s)                                                               */
/* ------------                                                               */
/* number     - Number to print on screen                                     */
/* borderChar - Specific character to print both number and border with       */
/* lineNumber - Row number of the number has been printing                    */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Returns 0 to indicate function works properly                              */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function calls function to print a number on given row                */
/* ---------------------------------------------------------------------------*/
int numberSwitch(int number, int lineNumber, char borderChar);

/* ---------------------------------------------------------------------------*/
/* int number0Printer(int height, char symbol)                                */
/*                                                                            */
/* Parameter(s)                                                               */
/* ------------                                                               */
/* height - Next line number of the number has been printing                  */
/* symbol - Character to use while printing the number                        */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Returns 0 to indicate function works properly                              */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function print a row of the number '0'                                */
/* ---------------------------------------------------------------------------*/
int number0Printer(int height, char symbol);

/* ---------------------------------------------------------------------------*/
/* int number1Printer(int height, char symbol)                                */
/*                                                                            */
/* Parameter(s)                                                               */
/* ------------                                                               */
/* height - Next line number of the number has been printing                  */
/* symbol - Character to use while printing the number                        */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Returns 0 to indicate function works properly                              */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function print a row of the number '1'                                */
/* ---------------------------------------------------------------------------*/
int number1Printer(int height, char symbol);

/* ---------------------------------------------------------------------------*/
/* int number2Printer(int height, char symbol)                                */
/*                                                                            */
/* Parameter(s)                                                               */
/* ------------                                                               */
/* height - Next line number of the number has been printing                  */
/* symbol - Character to use while printing the number                        */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Returns 0 to indicate function works properly                              */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function print a row of the number '2'                                */
/* ---------------------------------------------------------------------------*/
int number2Printer(int height, char symbol);

/* ---------------------------------------------------------------------------*/
/* int number3Printer(int height, char symbol)                                */
/*                                                                            */
/* Parameter(s)                                                               */
/* ------------                                                               */
/* height - Next line number of the number has been printing                  */
/* symbol - Character to use while printing the number                        */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Returns 0 to indicate function works properly                              */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function print a row of the number '3'                                */
/* ---------------------------------------------------------------------------*/
int number3Printer(int height, char symbol);

/* ---------------------------------------------------------------------------*/
/* int number4Printer(int height, char symbol)                                */
/*                                                                            */
/* Parameter(s)                                                               */
/* ------------                                                               */
/* height - Next line number of the number has been printing                  */
/* symbol - Character to use while printing the number                        */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Returns 0 to indicate function works properly                              */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function print a row of the number '4'                                */
/* ---------------------------------------------------------------------------*/
int number4Printer(int height, char symbol);

/* ---------------------------------------------------------------------------*/
/* int number5Printer(int height, char symbol)                                */
/*                                                                            */
/* Parameter(s)                                                               */
/* ------------                                                               */
/* height - Next line number of the number has been printing                  */
/* symbol - Character to use while printing the number                        */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Returns 0 to indicate function works properly                              */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function print a row of the number '5'                                */
/* ---------------------------------------------------------------------------*/
int number5Printer(int height, char symbol);

/* ---------------------------------------------------------------------------*/
/* int number6Printer(int height, char symbol)                                */
/*                                                                            */
/* Parameter(s)                                                               */
/* ------------                                                               */
/* height - Next line number of the number has been printing                  */
/* symbol - Character to use while printing the number                        */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Returns 0 to indicate function works properly                              */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function print a row of the number '6'                                */
/* ---------------------------------------------------------------------------*/
int number6Printer(int height, char symbol);

/* ---------------------------------------------------------------------------*/
/* int number7Printer(int height, char symbol)                                */
/*                                                                            */
/* Parameter(s)                                                               */
/* ------------                                                               */
/* height - Next line number of the number has been printing                  */
/* symbol - Character to use while printing the number                        */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Returns 0 to indicate function works properly                              */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function print a row of the number '7'                                */
/* ---------------------------------------------------------------------------*/
int number7Printer(int height, char symbol);

/* ---------------------------------------------------------------------------*/
/* int number8Printer(int height, char symbol)                                */
/*                                                                            */
/* Parameter(s)                                                               */
/* ------------                                                               */
/* height - Next line number of the number has been printing                  */
/* symbol - Character to use while printing the number                        */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Returns 0 to indicate function works properly                              */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function print a row of the number '8'                                */
/* ---------------------------------------------------------------------------*/
int number8Printer(int height, char symbol);

/* ---------------------------------------------------------------------------*/
/* int number9Printer(int height, char symbol)                                */
/*                                                                            */
/* Parameter(s)                                                               */
/* ------------                                                               */
/* height - Next line number of the number has been printing                  */
/* symbol - Character to use while printing the number                        */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Returns 0 to indicate function works properly                              */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function print a row of the number '9'                                */
/* ---------------------------------------------------------------------------*/
int number9Printer(int height, char symbol);



int main()
{
	/* Defining variables to call getInputs function */
	int num;
	int borderWidth;
	char borderChar;
	

	/* Calling the function */
	getInputs(&num,&borderWidth,&borderChar);
	
	
	return (0);
}



/* Function Implementation(s)                                                 */
/* ---------------------------------------------------------------------------*/
/* Function getInputs                                                         */
/* ------------------------                                                   */
/* Takes number, border width and character inputs from the user and calls    */
/* function to print the number                                               */
/* ---------------------------------------------------------------------------*/
void getInputs(int* num, int* borderWidth, char* borderChar)
{
	/* Taking inputs from user */
	scanf("%d %d %c",num,borderWidth,borderChar);
	
	/* Calling the number printer */
	printNumber(*num,*borderWidth,*borderChar);
}



/* ---------------------------------------------------------------------------*/
/* Function digitCounter                                                      */
/* ------------------------                                                   */
/* Finds the count of digits of the given number by dividing the number to 10 */
/* until it reaches 0 and returns the count                                   */
/* ---------------------------------------------------------------------------*/
int digitCounter(int number)
{
	/* Count of digits */
	int counter;
	
	
	/* Due to finding its count by dividing to 10 until number becomes 0 */
	/* if given number is 0 no calculation is needed */
	if (number==0)
	{
		counter = 1;
	}
	
	/* Calculation for the number other than 0 */
	else
	{
		/* Setting count to 0 */
		counter = 0;
		
		/* Creating a loop to division until number becomes 0 */
		while (number!=0)
		{
			/* Cropping last digit and increasing counter each step */
			number = number / 10;
			counter = counter + 1;
		}
	}
	
	
	/* Returning the digit count */
	return (counter);
}



/* ---------------------------------------------------------------------------*/
/* Function printNumber                                                       */
/* ------------------------                                                   */
/* This function adjusts number and border print queue. Prints the top of the */
/* border first, then prints numbers line by line with the side borders and   */
/* finally prints the bottom of the border                                    */
/* ---------------------------------------------------------------------------*/
int printNumber(int num, int borderWidth, char borderChar)
{
	/* Variable for the number's digit count */
	int digitCount;
	
	/* Loop control variables for printing the number and border */
	int widthCounter;
	int borderTop;
	int topLimit;
	int borderLeft;
	int borderRight;
	int height;
	
	
	/* Number of digits */
	digitCount = digitCounter(num);
	
	/* Each number is 7 column long and both sides equals to twice of */
	/* the border width. Top limit is the total column number of top and */
	/* bottom borders */
	topLimit = (digitCount*7) + (2*borderWidth);
	
	/* Setting counters to 0 */
	widthCounter = 0;
	height = 0;
	
	
	/* If number is invalid return 1 */
	if (num<0 || num>99999)
	{
		return (1);
	}
	
	/* Else print number */
	else
	{
		/* Creating a loop to print top of the border. Every step prints */
		/* a row. Repeating until border width will complete the top */
		while (widthCounter<borderWidth)
		{
			/* Another loop that prints a column each step. Repeating until */
			/* limit will complete a row */
			for (borderTop=0;borderTop<topLimit;borderTop++)
			{
				printf ("%c",borderChar);
			}
			
			/* New line after each row */
			printf ("\n");
			
			/* Incresing counter */
			widthCounter += 1;
		}


		/* Another loop for the printing number section. Each step prints a */
		/* row. Repeating until a number's column number will print each */
		/* number and borders covering them */
		while (height<7)
		{
			/* Loop to print left side of the border */
			for (borderLeft=0;borderLeft<borderWidth;borderLeft++)
			{
				printf ("%c",borderChar);
			}

			/* Calling the number printer function */
			printFunction(num,borderWidth,borderChar,height,digitCount);
		
			/* Loop to print right side of the border */
			for (borderRight=0;borderRight<borderWidth;borderRight++)
			{
				printf ("%c",borderChar);
			}
		
			/* New line after each row */
			printf ("\n");
			
			/* Increasing counter */
			height += 1;
		}

		
		/* Resetting width counter and creating a loop just like the top for */
		/* the bottom of the border */
		widthCounter = 0;	
		while (widthCounter<borderWidth)
		{
			/* Another loop that prints a column each step. Repeating until */
			/* limit will complete a row */ 
			for(borderTop=0;borderTop<(digitCount*7)+(2*borderWidth);borderTop++)
			{
				printf ("%c",borderChar);
			}
			
			/* New line after each row */
			printf ("\n");
			
			/* Increasing counter */
			widthCounter += 1;
		}
	}
	
	
	return (0);
}



/* ---------------------------------------------------------------------------*/
/* Function printFunction                                                     */
/* ------------------------                                                   */
/* This function splits given number to its digits and calls helper           */
/* number printer functions line by line using the given line number          */ 
/* ---------------------------------------------------------------------------*/
int printFunction(int num, int borderWidth, char borderChar, int lineNumber, 
int digitCount)
{
	/* Variables to split a number into digits */
	int onesPlace;
	int tensPlace;
	int hundredsPlace;
	int thousandsPlace;
	int tenThousandsPlace;


	/* Assigning each digit to its variable */
	onesPlace = num%10;
	tensPlace = (num/10)%10;
	hundredsPlace = (num/100)%10;
	thousandsPlace = (num/1000)%10;
	tenThousandsPlace = (num/10000)%10;
	
	
	/* Calling number switch function for each digit by the number of digits */
	if (digitCount==1)
	{
		numberSwitch(onesPlace,lineNumber,borderChar);
	}
	
	else if (digitCount==2)
	{
		numberSwitch(tensPlace,lineNumber,borderChar);
		numberSwitch(onesPlace,lineNumber,borderChar);
	}
	
	else if (digitCount==3)
	{
		numberSwitch(hundredsPlace,lineNumber,borderChar);
		numberSwitch(tensPlace,lineNumber,borderChar);
		numberSwitch(onesPlace,lineNumber,borderChar);
	}
	
	else if (digitCount==4)
	{
		numberSwitch(thousandsPlace,lineNumber,borderChar);
		numberSwitch(hundredsPlace,lineNumber,borderChar);
		numberSwitch(tensPlace,lineNumber,borderChar);
		numberSwitch(onesPlace,lineNumber,borderChar);
	}
	
	else if (digitCount==5)
	{
		numberSwitch(tenThousandsPlace,lineNumber,borderChar);
		numberSwitch(thousandsPlace,lineNumber,borderChar);
		numberSwitch(hundredsPlace,lineNumber,borderChar);
		numberSwitch(tensPlace,lineNumber,borderChar);
		numberSwitch(onesPlace,lineNumber,borderChar);
	}
	
	
	return (0);
}



/* ---------------------------------------------------------------------------*/
/* Function numberSwitch                                                      */
/* ------------------------                                                   */
/* This function splits given number to its digits and calls helper           */
/* number printer functions line by line using the given line number          */ 
/* ---------------------------------------------------------------------------*/
int numberSwitch(int number, int lineNumber, char borderChar)
{
	/* This switch calls proper function for the given number to print given */
	/* line */
	switch (number)
	{
		case 0: number0Printer(lineNumber,borderChar); break;
		case 1: number1Printer(lineNumber,borderChar); break;
		case 2: number2Printer(lineNumber,borderChar); break;
		case 3: number3Printer(lineNumber,borderChar); break;
		case 4: number4Printer(lineNumber,borderChar); break;
		case 5: number5Printer(lineNumber,borderChar); break;
		case 6: number6Printer(lineNumber,borderChar); break;
		case 7: number7Printer(lineNumber,borderChar); break;
		case 8: number8Printer(lineNumber,borderChar); break;
		case 9: number9Printer(lineNumber,borderChar); break;
	}
	
	
	return (0);
}



/* ---------------------------------------------------------------------------*/
/* Function number0Printer                                                    */
/* ------------------------                                                   */
/* This function prints '0' line by line depends ond the given line number    */
/* ---------------------------------------------------------------------------*/
int number0Printer(int height, char symbol)
{	
	/* Each if statement prints a line */
	if (height==0)
	{
		printf ("       ");
	}
	
	else if (height==1)
	{
		printf ("  %c%c%c  ",symbol,symbol,symbol);
	}
	
	else if (height==2)
	{
		printf ("  %c %c  ",symbol,symbol);
	}
	
	else if (height==3)
	{
		printf ("  %c %c  ",symbol,symbol);
	}
	
	else if (height==4)
	{
		printf ("  %c %c  ",symbol,symbol);
	}
	
	else if (height==5)
	{
		printf ("  %c%c%c  ",symbol,symbol,symbol);
	}
	
	else if (height==6)
	{
		printf ("       ");
	}
	
	
	return (0);
}



/* ---------------------------------------------------------------------------*/
/* Function number1Printer                                                    */
/* ------------------------                                                   */
/* This function prints '1' line by line depends ond the given line number    */
/* ---------------------------------------------------------------------------*/
int number1Printer(int height, char symbol)
{
	/* Each if statement prints a line */
	if (height==0)
	{
		printf ("       ");
	}
	
	else if (height==1)
	{
		printf ("   %c   ",symbol);
	}
	
	else if (height==2)
	{
		printf ("  %c%c   ",symbol,symbol);
	}
	
	else if (height==3)
	{
		printf ("   %c   ",symbol);
	}
	
	else if (height==4)
	{
		printf ("   %c   ",symbol);
	}
	
	else if (height==5)
	{
		printf ("  %c%c%c  ",symbol,symbol,symbol);
	}
	
	else if (height==6)
	{
		printf ("       ");
	}
	
	
	return (0);
}



/* ---------------------------------------------------------------------------*/
/* Function number2Printer                                                    */
/* ------------------------                                                   */
/* This function prints '2' line by line depends ond the given line number    */
/* ---------------------------------------------------------------------------*/
int number2Printer(int height, char symbol)
{
	/* Each if statement prints a line */
	if (height==0)
	{
		printf ("       ");
	}
	
	else if (height==1)
	{
		printf ("  %c%c%c  ",symbol,symbol,symbol);
	}
	
	else if (height==2)
	{
		printf ("    %c  ",symbol);
	}
	
	else if (height==3)
	{
		printf ("  %c%c%c  ",symbol,symbol,symbol);
	}
	
	else if (height==4)
	{
		printf ("  %c    ",symbol);
	}
	
	else if (height==5)
	{
		printf ("  %c%c%c  ",symbol,symbol,symbol);
	}
	
	else if (height==6)
	{
		printf ("       ");
	}
	
	
	return (0);
}



/* ---------------------------------------------------------------------------*/
/* Function number3Printer                                                    */
/* ------------------------                                                   */
/* This function prints '3' line by line depends ond the given line number    */
/* ---------------------------------------------------------------------------*/
int number3Printer(int height, char symbol)
{
	/* Each if statement prints a line */
	if (height==0)
	{
		printf ("       ");
	}
	
	else if (height==1)
	{
		printf ("  %c%c%c  ",symbol,symbol,symbol);
	}
	
	else if (height==2)
	{
		printf ("    %c  ",symbol);
	}
	
	else if (height==3)
	{
		printf ("   %c%c  ",symbol,symbol);
	}
	
	else if (height==4)
	{
		printf ("    %c  ",symbol);
	}
	
	else if (height==5)
	{
		printf ("  %c%c%c  ",symbol,symbol,symbol);
	}
	
	else if (height==6)
	{
		printf ("       ");
	}
	
	
	return (0);
}



/* ---------------------------------------------------------------------------*/
/* Function number4Printer                                                    */
/* ------------------------                                                   */
/* This function prints '4' line by line depends ond the given line number    */
/* ---------------------------------------------------------------------------*/
int number4Printer(int height, char symbol)
{
	/* Each if statement prints a line */
	if (height==0)
	{
		printf ("       ");
	}
	
	else if (height==1)
	{
		printf ("  %c %c  ",symbol,symbol);
	}
	
	else if (height==2)
	{
		printf ("  %c %c  ",symbol,symbol);
	}
	
	else if (height==3)
	{
		printf ("  %c%c%c  ",symbol,symbol,symbol);
	}
	
	else if (height==4)
	{
		printf ("    %c  ",symbol);
	}
	
	else if (height==5)
	{
		printf ("    %c  ",symbol);
	}
	
	else if (height==6)
	{
		printf ("       ");
	}
	
	
	return (0);
}



/* ---------------------------------------------------------------------------*/
/* Function number5Printer                                                    */
/* ------------------------                                                   */
/* This function prints '5' line by line depends ond the given line number    */
/* ---------------------------------------------------------------------------*/
int number5Printer(int height, char symbol)
{
	/* Each if statement prints a line */
	if (height==0)
	{
		printf ("       ");
	}
	
	else if (height==1)
	{
		printf ("  %c%c%c  ",symbol,symbol,symbol);
	}
	
	else if (height==2)
	{
		printf ("  %c    ",symbol);
	}
	
	else if (height==3)
	{
		printf ("  %c%c%c  ",symbol,symbol,symbol);
	}
	
	else if (height==4)
	{
		printf ("    %c  ",symbol);
	}
	
	else if (height==5)
	{
		printf ("  %c%c%c  ",symbol,symbol,symbol);
	}
	
	else if (height==6)
	{
		printf ("       ");
	}
	
	
	return (0);
}



/* ---------------------------------------------------------------------------*/
/* Function number6Printer                                                    */
/* ------------------------                                                   */
/* This function prints '6' line by line depends ond the given line number    */
/* ---------------------------------------------------------------------------*/
int number6Printer(int height, char symbol)
{
	/* Each if statement prints a line */
	if (height==0)
	{
		printf ("       ");
	}
	
	else if (height==1)
	{
		printf ("  %c%c%c  ",symbol,symbol,symbol);
	}
	
	else if (height==2)
	{
		printf ("  %c    ",symbol);
	}
	
	else if (height==3)
	{
		printf ("  %c%c%c  ",symbol,symbol,symbol);
	}
	
	else if (height==4)
	{
		printf ("  %c %c  ",symbol,symbol);
	}
	
	else if (height==5)
	{
		printf ("  %c%c%c  ",symbol,symbol,symbol);
	}
	
	else if (height==6)
	{
		printf ("       ");
	}
	
	
	return (0);
}



/* ---------------------------------------------------------------------------*/
/* Function number7Printer                                                    */
/* ------------------------                                                   */
/* This function prints '7' line by line depends ond the given line number    */
/* ---------------------------------------------------------------------------*/
int number7Printer(int height, char symbol)
{
	/* Each if statement prints a line */
	if (height==0)
	{
		printf ("       ");
	}
	
	else if (height==1)
	{
		printf ("  %c%c%c  ",symbol,symbol,symbol);
	}
	
	else if (height==2)
	{
		printf ("    %c  ",symbol);
	}
	
	else if (height==3)
	{
		printf ("    %c  ",symbol);
	}
	
	else if (height==4)
	{
		printf ("    %c  ",symbol);
	}
	
	else if (height==5)
	{
		printf ("    %c  ",symbol);
	}
	
	else if (height==6)
	{
		printf ("       ");
	}
	
	
	return (0);
}



/* ---------------------------------------------------------------------------*/
/* Function number8Printer                                                    */
/* ------------------------                                                   */
/* This function prints '8' line by line depends ond the given line number    */
/* ---------------------------------------------------------------------------*/
int number8Printer(int height, char symbol)
{
	/* Each if statement prints a line */
	if (height==0)
	{
		printf ("       ");
	}
	
	else if (height==1)
	{
		printf ("  %c%c%c  ",symbol,symbol,symbol);
	}
	
	else if (height==2)
	{
		printf ("  %c %c  ",symbol,symbol);
	}
	
	else if (height==3)
	{
		printf ("  %c%c%c  ",symbol,symbol,symbol);
	}
	
	else if (height==4)
	{
		printf ("  %c %c  ",symbol,symbol);
	}
	
	else if (height==5)
	{
		printf ("  %c%c%c  ",symbol,symbol,symbol);
	}
	
	else if (height==6)
	{
		printf ("       ");
	}
	
	
	return (0);
}



/* ---------------------------------------------------------------------------*/
/* Function number1Printer                                                    */
/* ------------------------                                                   */
/* This function prints '1' line by line depends ond the given line number    */
/* ---------------------------------------------------------------------------*/
int number9Printer(int height, char symbol)
{
	/* Each if statement prints a line */
	if (height==0)
	{
		printf ("       ");
	}
	
	else if (height==1)
	{
		printf ("  %c%c%c  ",symbol,symbol,symbol);
	}
	
	else if (height==2)
	{
		printf ("  %c %c  ",symbol,symbol);
	}
	
	else if (height==3)
	{
		printf ("  %c%c%c  ",symbol,symbol,symbol);
	}
	
	else if (height==4)
	{
		printf ("    %c  ",symbol);
	}
	
	else if (height==5)
	{
		printf ("  %c%c%c  ",symbol,symbol,symbol);
	}
	
	else if (height==6)
	{
		printf ("       ");
	}
	
	
	return (0);
}
