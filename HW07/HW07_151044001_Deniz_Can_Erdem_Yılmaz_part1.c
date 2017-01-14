/*----------------------------------------------------------------------------*/
/* HW07_151044001_Deniz_Can_Erdem_Yılmaz                                      */
/* HW07_151044001_Deniz_Can_Erdem_Yılmaz_part1.c                              */
/* Created on 12/04/2016 by Deniz_Can_Erdem_Yılmaz                            */
/* -----------------------------------------------                            */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This is the GIT's homework 7 - part 1 for the CSE102 lecture. This program */
/* checks the given string array if it is a palindrome or not.                */
/*                                                                            */
/*                                                                            */
/* Notes                                                                      */
/* -----                                                                      */
/* This file is written by considering the rules on code convention. So a row */
/* is max 80 column, tab width is 4 and coded with the desired code design    */
/*                                                                            */
/* Also it is a must to code functions with recursion for this homework       */
/*----------------------------------------------------------------------------*/



/* Include(s) */
#include<stdio.h>



/* Function Prototype(s) */
/*----------------------------------------------------------------------------*/
/* int isPalindrome(char *str)                                                */
/* ---------------------------                                                */
/*                                                                            */
/*                                                                            */
/* Parameter(s)                                                               */
/* ----------                                                                 */
/* *str - Character array which presents string given by user                 */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* 0 - If str parameter is not a palindrome                                   */
/* 1 - If str parameter is a palindrome                                       */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes a string (character array) and checks if the           */
/* character sequance is a palindrome or not. Which means its both same word  */
/* or sentence when read from backwards or straight                           */
/*----------------------------------------------------------------------------*/ 
int isPalindrome(char *str);



int main()
{
	printf ("%d\n",isPalindrome("ab!ab"));
	return (0);
}



/* Function Implementation(s)                                                 */
/*----------------------------------------------------------------------------*/
/* Function isPalindrome                                                      */
/* -------------                                                              */
/* This function takes an character array which represents a string. And then */
/* checks it. If it is a palindrome then function returns 1. Otherwise (Non   */
/* palindrome, NULL string or invalid input) it will return 0. The control    */
/* will made by recursion instead of iteration                                */ 
/*----------------------------------------------------------------------------*/
int isPalindrome(char *str)
{
	/* A temporary string array to clear string from non-letter characters */
	/* without changing the given data */
	char tempStr[5000];
	
	int index;
	int tempIndex;
	int length;
	int tempLength;
	int returnValue;
	
	/* Finding the length of str array by counting until the NULL character */
	while (str[length]!='\0')
	{
		length = length + 1;
	}
	
	
	/* With this loop program will control every character on the string and */
	/* create another string array with lower case letters only */
	for (index=0;index<length;index++)
	{
		/* Checking if character is lower case letter */
		if (str[index]>=97 && str[index]<=122)
		{
			/* Adding letter to temporary string array */
			tempStr[tempIndex] = str[index];
			
			/* Increasing secondary array's index for the next element */
			tempIndex = tempIndex + 1;
		}
		
		/* Checking if character is upper case letter */
		else if (str[index]>=65 && str[index]<=90)
		{
			/* Converting upper case to lower case by subtracting 32 */
			tempStr[tempIndex] = str[index] + 32;
			
			/* Increasing secondary array's index for the next element */
			tempIndex = tempIndex + 1;
		}
		/* Else nothing will happen so all junk characters will be eliminated */
	}
	
	
	/* Finding the length of secondary string array's length with same way */
	while (tempStr[tempLength]!='\0')
	{
		tempLength = tempLength + 1;
	}
	
	/* Here starts the first controls for recursion */
	/* Checking if string array has more than 1 character to comparison */
	if (tempLength>1)
	{
		/* If string array has odd numbers of character continue from here */
		if (tempLength%2==1)
		{
			/* Checking the palindrome condition */
			if (tempStr[0]==tempStr[tempLength-1])
			{
				/* If first and last characters are same than check for */
				/* second and penultimate character. To do this first of all */
				/* setting last element NULL to let program consider */
				/* penultimate as last character next time */
				tempStr[tempLength-1] = '\0';
				
				/* And after that sending the temp string from second */
				/* character's pointer will let program make same controls */
				/* with the cropped sub string array */
				returnValue = isPalindrome(&tempStr[1]);
			}
			
			else
			{
				/* If palindrome condition is not obtained return 0 */
				returnValue = 0;
			}
		}
		
		/* If string array has even numbers of character continue from here */
		else if(tempLength%2==0)
		{
			/* Even numbered strings will call isPalindrome function with */
			/* NULL array at the end of the recursion. So this is a special */
			/* check for it. If last two characters are same then return 1 */
			
			if (tempLength==2)
			{
				if (tempStr[0]==tempStr[tempLength-1])
				{
					returnValue = 1;
				}
			}
			
			/* If there are more characters left than two then continue with */
			/* normal control structure */
			
			else
			{
				/* Checking the palindrome condition */
				if (tempStr[0]==tempStr[tempLength-1])
				{
					/* Cropping string's last character from array */
					tempStr[tempLength-1] = '\0';
					
					/* Sending the array with second characters pointer to */
					/* process substring */
					returnValue = isPalindrome(&tempStr[1]);
				}
				
				/* If palindrome condition is not obtained return 0 */
				else
				{
					returnValue = 0;
				}
			}
		}
	}
	
	else if (tempLength==1)
	{
		/* If length is 1 then it is either a one elemented string array */
		/* or end of a odd numbered string. Both are considered as */
		/* palindromes. So return 1 */
		returnValue = 1;
	}
	
	else
	{
		/* Any other string array types considered as non palindrome string */
		/* (like a NULL or empty string) Therefore return 0 */ 
		returnValue = 0;
	}
	
	/* Returning the return value */
	return (returnValue);
}

/* End of HW07_151044001_Deniz_Can_Erdem_Yılmaz_part1.c */
