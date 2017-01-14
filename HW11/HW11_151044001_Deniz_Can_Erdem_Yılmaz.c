/*----------------------------------------------------------------------------*/
/*                                                                            */
/* HW11_151044001_Deniz_Can_Erdem_Yılmaz                                      */
/* HW11_151044001_Deniz_Can_Erdem_Yılmaz.c                                    */
/* Created on 14/05/2016 by Deniz_Can_Erdem_Yılmaz                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This is the GIT's homework 11 for the CSE102 lecture. This program takes   */
/* an binary input file which contains an unknown pile of same structure.     */
/* Program is intended to find the type of variables of the structure         */
/*                                                                            */
/* Notes                                                                      */
/* -----                                                                      */
/* This file is written by considering the rules on code convention. So a row */
/* is max 80 column, tab width is 4 and coded with the desired code design    */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/* Include(s) */
#include<stdio.h>

/* Define(s) */
#define MAX_DATA 10
#define MODE "rb"
#define STRUCTS 1000

/* Function Prototypes                                                        */
/*----------------------------------------------------------------------------*/
/* int hwDecode(const char filename[], int arr_out[])                         */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
/* ----------                                                                 */
/* filename[] - Name of the input file                                        */
/* arr_out[]  - Output array to keep type order                               */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* -1 for non existing file                                                   */
/* 0 for proccessed file                                                      */
/* Also returns edited output array                                           */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function decodes the binary file and finds the types of variables     */
/* that structure contains                                                    */
/*----------------------------------------------------------------------------*/
int hwDecode(const char filename[], int arr_out[]);

/*----------------------------------------------------------------------------*/
/* void arrReset(int arr[])                                                   */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
/* ----------                                                                 */
/* arr[] - Array to reset its elements                                        */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* No return value due to void function but returns resetted array            */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function sets all of given array's elements as -1                     */
/*----------------------------------------------------------------------------*/
void arrReset(int arr[]);

/*----------------------------------------------------------------------------*/
/* int sizeFinder(const char filename[])                                      */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
/* ----------                                                                 */
/* filename[] - Name of the input file                                        */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Returns the size of the given file                                         */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function finds the size of given file                                 */
/*----------------------------------------------------------------------------*/
int sizeFinder(const char filename[]);



/* Function Implementation(s)                                                 */
/*----------------------------------------------------------------------------*/
/* Function hwDecode                                                          */
/* -------------                                                              */
/* This function takes input file name and an output array to decode a binary */
/* file which contains 1000 unknown structure. Function first checks the      */
/* validness of the file. If file is not available it returns -1 immidiately. */
/* Else it proccess the file and tries to find the type of variables that     */
/* structure contains. Makes an ordered list to output array and returns 0    */
/*----------------------------------------------------------------------------*/
int hwDecode(const char filename[], int arr_out[])
{
	/* Variables for; */
	/* Input file */
	FILE *inp;
	
	/* File size */
	int byteCount;
	
	/* Single struct size */
	int structSize;
	
	/* Return value for status */
	int returnValue;
	


	
	/* Opening the input file */
	inp = fopen(filename,MODE);
	
	
	/* Countinue if input file is not NULL */
	if (inp != NULL)
	{
		/* First of all cleaning the given count array */
		arrReset(arr_out);

		/* Then finding the size of the file */
		byteCount = sizeFinder(filename);

		/* Dividing the size of the file to the given struct number will give */
		/* the exact size of repeated structure */
		structSize = byteCount / STRUCTS;
	
		
		/* Returning 0 due to success */
		returnValue = 0;
	}
	
	/* If input file does not exist */
	else
	{
		/* Do not proccess and return -1 */
		returnValue = -1;
	}
	
	/* Returning the return value */
	return (returnValue);
}



/*----------------------------------------------------------------------------*/
/* Function arrReset                                                          */
/* -------------                                                              */
/* This function takes an int array and sets all of its elements to -1        */
/*----------------------------------------------------------------------------*/
void arrReset(int arr[])
{
	/* Loop control variable */
	int i;
	
	
	/* Cleaning the given array by setting all elements as -1 */
	for (i=0;i<MAX_DATA;i++)
	{
		arr[i] = -1;
	}

	return;
}



/*----------------------------------------------------------------------------*/
/* Function sizeFinder                                                        */
/* -------------                                                              */
/* This function takes a file name and finds the total size of the given file */
/*----------------------------------------------------------------------------*/
int sizeFinder(const char filename[])
{
	/* Input file */
	FILE *inp;
	
	/* File size */
	int count;
	
	/* Character read from file */
	char c;

	
	/* Initializing counter as 0 */
	count = 0;
	
	/* Opening the input file */
	inp = fopen(filename,MODE);
	
	
	/* Creating a loop to find the total size of the file */
	/* Unless the character taken from input file is EOF, keep increasing */
	/* the counter */
	for (c=getc(inp);c!=EOF;c=getc(inp))
	{
		count = count + 1;
	}
	
	/* Closing the input file */
	fclose(inp);
	
	
	/* Returning the size of file */
	return (count);
}



int main()
{
	int *arr;
	hwDecode("input.dat",arr);
	return (0);
}
