/*----------------------------------------------------------------------------*/
/* HW06_151044001_Deniz_Can_Erdem_Yılmaz                                      */
/* HW06_151044001_Deniz_Can_Erdem_Yılmaz_part3.c                              */
/* Created on 08/04/2016 by Deniz_Can_Erdem_Yılmaz                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This c file contains the GIT's CSE102 Homework-6 Part-3                    */
/* This program searches the substring in the given string and returns back   */
/* the count of occurances to the user                                        */
/*                                                                            */
/* Note(s)                                                                    */
/* -------                                                                    */
/* - Coding in this homework designed as the given code convention by         */
/*   teachers. Tab size is 4 and column limit in a row is 80                  */
/* - This homework sent to teachers without main() function due to request on */
/*   homework description. main() function only makes a control by calling    */
/*   the desired function                                                     */
/* - Program will only match odd indexed characters                           */
/*----------------------------------------------------------------------------*/



/* Function Prototype(s)                                                      */
/*----------------------------------------------------------------------------*/
/* int count(char *str, char *substr)                                         */
/* ----------------------------------                                         */
/*                                                                            */
/* Parameter(s)                                                               */
/* ----------                                                                 */
/* *str    - Character array to search how many times key word is repeated    */
/* *substr - Character array which represents key word wanted to search       */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Returns the count of repeat                                                */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes a string and checks how many times the substring is    */
/* included inside the string itself. Returns the repeat count to user as     */
/* integer format                                                             */
/*----------------------------------------------------------------------------*/ 
int count(char *str, char *substr);



/* Include(s) */
#include<stdio.h>



int main()
{
	int i;
	
	
	char str1[] = {"leromleromlerom"};
	char str2[] = {"lerom"};
	
	
	i = count(str1,str2);

	
	printf ("%d\n",i);
	
	
	return (0);
}



/* Function Implementation(s)                                                 */
/*----------------------------------------------------------------------------*/
/* Function count                                                             */
/* --------------                                                             */
/* This function takes 2 arrays. Both are character arrays that represents    */
/* strings. Program controls the count of the occurances of the sub string    */
/* on the string array. Returns the count of occurence to the user            */
/*----------------------------------------------------------------------------*/
int count(char *str, char *substr)
{
	/* Count is the return value of this function */
	int count;
	
	/* 3 types of index variable:
	 * index     : the main index goes 0 through end of the str array
	 * subIndex  : another main index goes 0 throuth end of the substr array
	 * tempIndex : when there is a match with first char of needle string
	               this temporary index will keep searching until the end of
	               the substr array while protecting main index
	*/              
	int index;
	int subIndex;
	int tempIndex;
	
	/* source is str's and search is substr's length variable */
	int sourceLen;
	int searchLen;
	
	/* A control flag variable */
	int controlFlag;


	/* Initializing all variables as 0 */
	count = 0;
	index = 0;
	subIndex = 0;
	tempIndex = 0;
	sourceLen = 0;
	searchLen = 0;
	controlFlag = 0;


	/* Finding the length of str array */
	while (str[sourceLen] != '\0')
	{
		sourceLen += 1;
	}
	
	/* Finding the length of substr array */
	while (substr[searchLen] != '\0')
	{
		searchLen += 1;
	}


	/* If keyword is longer than source string there won't be match so */
	/* program will automatically return 0 */
	if (sourceLen >= searchLen)
	{
		/* Starting a loop from index 0 to end of the str array */
		while(index<sourceLen)
		{
			/* If indexed char matches with substring's first character */
			/* then it will continue to check for the rest of the array */
			if (str[index]==substr[0])
			{
				/* Setting flag to 1, it will change to 0 if unwanted */
				/* situation happens */
				controlFlag = 1;
				
				/* Setting a temporary index to check the array from index to */
				/* length of substr array long while keeping the real index */
				/* safe */
				tempIndex = index;
				
				/* A loop until one of the string arrays reach or pass NULL */
				/* character */
				while (sourceLen>tempIndex && searchLen>subIndex)
				{
					/* Checking the rest of the string from the match of */
					/* first characters. If there is an unmatched character */
					/* in the loop then flag will change to 0 */
					if (str[tempIndex] != substr[subIndex])
					{
						controlFlag = 0;
					}
					
					/* Incresing control variables 2 to check the even */
					/* indexed characters only */
					subIndex += 2;
					tempIndex += 2;
				}
				
				/* After the loop if flag is 0, or 1 because it couldnt reach */
				/* the if statment in the loop due to reaching end of the */
				/* array it will just skip here too. Else it will increase */
				/* count */
				if (controlFlag==1 && (index+searchLen)<sourceLen+1)
				{
					count += 1;
				}
			}
			
			/* Setting subIndex to 0 again to check the first character of */
			/* substr array with indexed str array element */
			subIndex = 0;
			
			/* Incresing the index, the loop control variable */
			index += 1;
		}
	}
	
	/* Returning the repeat count of substr in str */
	return (count);
}

/* End of the HW06_151044001_Deniz_Can_Erdem_Yılmaz_part3.c */