/*----------------------------------------------------------------------------*/
/* HW06_151044001_Deniz_Can_Erdem_Yılmaz                                      */
/* HW06_151044001_Deniz_Can_Erdem_Yılmaz_part2.c                              */
/* Created on 08/04/2016 by Deniz_Can_Erdem_Yılmaz                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This c file contains the GIT's CSE102 Homework-6 Part-2                    */
/* This program takes 2 strings and searches for the second one in the first  */
/* string. After that returns the pointer value of the first character of the */
/* match to the user                                                          */
/*                                                                            */
/* Note(s)                                                                    */
/* -------                                                                    */
/* - Coding in this homework designed as the given code convention by         */
/*   teachers. Tab size is 4 and column limit in a row is 80                  */
/* - This homework sent to teachers without main() function due to request on */
/*   homework description. main() function only makes a control by calling    */
/*   the desired function                                                     */
/* - Program will only match the odd indexed characters                       */
/*----------------------------------------------------------------------------*/



/* Include(s) */
#include<stdio.h>



/* Function Prototype(s)                                                      */
/*----------------------------------------------------------------------------*/
/* char *matcher(char *haystack, char *needle)                                */
/* -------------------------------------------                                */
/*                                                                            */
/* Parameter(s)                                                               */
/* ----------                                                                 */
/* *haystack - Character array to search if key word is included              */
/* *needle   - Character array which represents key word wanted to search     */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* If a match has found it will return haystack array from the match index    */
/* If has not then it will return NULL character                              */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes a string and checks if first string includes second    */
/* one. If there is a match then it will return the array from the first      */
/* matched index, if there is not then it will return NULL character          */
/*----------------------------------------------------------------------------*/
char *matcher(char *haystack, char *needle);



int main()
{
	
	
	char str1[] = {"ipsum l r m dolora sit amet."};
	char str2[] = {"madil"};
	char *ptr=matcher(str1,str2);
	
	
	
	printf ("%sA\n",ptr);
	
	
	
	
	return (0);
}



/* Function Implementation(s)                                                 */
/*----------------------------------------------------------------------------*/
/* Function matcher                                                           */
/* ----------------                                                           */
/* This function takes 2 arrays. Both are character arrays that represents    */
/* strings. Program finds the pointer of the needle word found in haystack    */
/* If there is no match then it will return NULL                              */
/*----------------------------------------------------------------------------*/
char *matcher(char *haystack, char *needle)
{	
	
	/* 3 types of index variable:
	 * index     : the main index goes 0 through end of the haystack array
	 * subIndex  : another main index goes 0 throuth end of the needle array
	 * tempIndex : when there is a match with first char of needle string
	               this temporary index will keep searching until the end of
	               the needle array while protecting main index */        
	      
	int index;
	int subIndex;
	int tempIndex;
	
	/* Source is haystack's and search is needle's length variable */
	int sourceLen;
	int searchLen;
	
	/* A control flag variable */
	int controlFlag;
	
	
	/* Initializing all control variables as 0 */
	index = 0;
	subIndex = 0;
	tempIndex = 0;
	sourceLen = 0;
	searchLen = 0;
	controlFlag = 0;
	
	
	/* Finding the length of haystack */
	while (haystack[sourceLen] != '\0')
	{
		sourceLen++;
	}
	
	/* Finding the length of needle */
	while (needle[searchLen] != '\0')
	{
		searchLen++;
	}


	/* If needle is longer than haystack than program will skip this if */
	/* and return Null */
	if (sourceLen>=searchLen)
	{
		/* A loop from index 0 to end of the haystack */
		while (index<sourceLen)
		{
			/* If there is a match with needle's first character then create */
			/* another loop to control the remain characters of the needle */
			if (haystack[index] == needle[0])
			{
				/* Creating a temporary index to save real index while going */
				/* through the haystack for other matches */
				tempIndex = index;
				
				/* Setting subIndex 0 for every match to control needle's */
				/* characters */
				subIndex = 0;
				
				/* Setting control flag 1 for every match to find diversty */
				/* between needle and haystack */
				controlFlag = 1;

			    /* Until haystack or needle reaches the end.. */
				while (tempIndex<sourceLen && subIndex<searchLen)
				{
				    /* .. check if there is any diversity */
					if (haystack[tempIndex] != needle[subIndex])
					{
					   /* If there is, set flag 0 to indicate it */
						controlFlag = 0;
					}
					/* Increasing control variables 2 to check even */
					/* indexes only */
					tempIndex += 2;
					subIndex += 2;
				}
			
			    /* If flag is 1 after the loop it means a match has found */
				if (controlFlag == 1 && index<sourceLen)
				{
				    /* Returning first matched index */
					return (&haystack[index]);
				}
			
			}
			
			/* Increasing the loop control variable */
			index++;
		}
	}
	
    /* If there is no match or needle is longer than haystack return Null */
	return NULL;
}

/* End of the HW06_151044001_Deniz_Can_Erdem_Yılmaz_part2.c */