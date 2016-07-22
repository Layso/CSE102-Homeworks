/*----------------------------------------------------------------------------*/
/* HW06_151044001_Deniz_Can_Erdem_Yılmaz                                      */
/* HW06_151044001_Deniz_Can_Erdem_Yılmaz_part1.c                              */
/* Created on 07/04/2016 by Deniz_Can_Erdem_Yılmaz                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This c file contains the GIT's CSE102 Homework-6 Part-1                    */
/* This program takes a string and counts all the characters in it. Stores    */
/* the count in another int array and returns it                              */
/*                                                                            */
/* Note(s)                                                                    */
/* -------                                                                    */
/* - Coding in this homework designed as the given code convention by         */
/*   teachers. Tab size is 4 and column limit in a row is 80                  */
/* - This homework sent to teachers without main() function due to request on */
/*   homework description. main() function only makes a control by calling    */
/*   the desired function                                                     */
/* - count[] array in main function limited with 37 elements which represents */
/*   26 letters in ascending order, 10 numbers and 1 for the rest             */
/*----------------------------------------------------------------------------*/



/* Include(s) */
#include<stdio.h>



/* Function Prototype(s)                                                      */
/*----------------------------------------------------------------------------*/
/* void freq(char *str, int *fr)                                              */
/* -----------------------------                                              */
/*                                                                            */
/* Parameter(s)                                                               */
/* ----------                                                                 */
/* *str - Character array which presents string given by user                 */
/* *fr  - Integer array which presents the count of each character given      */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* str and fr arrays returned to caller function, no return value due to void */
/* function prototype                                                         */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes a string (character array) and counts all the letters  */
/* numbers and other characters and stores the count on second (integer)      */
/* array given on parameter                                                   */
/*----------------------------------------------------------------------------*/
void freq(char *str, int *fr);



int main()
{
	int i;
	
	int count[37];
	char str1[] = {" @ @ @ # # #"};
	
	
	for (i=0;i<37;i++)
	{
		printf ("Before:\n%d\n",count[i]);
	}
	
	
	freq(str1,count);

	
	for (i=0;i<37;i++)
	{
		printf ("After:\n%d\n",count[i]);
	}
	
	
	return (0);
}



/* Function Implementation(s)                                                 */
/*----------------------------------------------------------------------------*/
/* Function freq                                                              */
/* -------------                                                              */
/* This function takes 2 arrays. First one is char array and represents a     */
/* string. Other one is an integer array to store the counts of each letter,  */
/* digit and all other characters                                             */
/*----------------------------------------------------------------------------*/
void freq(char *str, int *fr)
{
	/* Index variable for the loops */
	int index;


	/* Making sure the given frequancy list's elements are all 0 */
	for (index=0;index<37;index++)
	{
		fr[index] = 0;
	}

	
	/* From start to end of the string (which means until indexed element */
	/* shows NULL) control the char on the index and increase 1 the counter */
	/* on the frequancy array */
	for (index=0;str[index]!='\0';index++)
	{
		/* Controlling the indexed character on the string array */
		switch(str[index])
		{
			case 'a':
			case 'A': fr[0] += 1; break;
			case 'b':
			case 'B': fr[1] += 1; break;
			case 'c':
			case 'C': fr[2] += 1; break;
			case 'd':
			case 'D': fr[3] += 1; break;
			case 'e':
			case 'E': fr[4] += 1; break;
			case 'f':
			case 'F': fr[5] += 1; break;
			case 'g':
			case 'G': fr[6] += 1; break;
			case 'h':
			case 'H': fr[7] += 1; break;
			case 'i':
			case 'I': fr[8] += 1; break;
			case 'j':
			case 'J': fr[9] += 1; break;
			case 'k':
			case 'K': fr[10] += 1; break;
			case 'l':
			case 'L': fr[11] += 1; break;
			case 'm':
			case 'M': fr[12] += 1; break;
			case 'n':
			case 'N': fr[13] += 1; break;
			case 'o':
			case 'O': fr[14] += 1; break;
			case 'p':
			case 'P': fr[15] += 1; break;
			case 'q':
			case 'Q': fr[16] += 1; break;
			case 'r':
			case 'R': fr[17] += 1; break;
			case 's':
			case 'S': fr[18] += 1; break;
			case 't':
			case 'T': fr[19] += 1; break;
			case 'u':
			case 'U': fr[20] += 1; break;
			case 'v':
			case 'V': fr[21] += 1; break;
			case 'w':
			case 'W': fr[22] += 1; break;
			case 'x':
			case 'X': fr[23] += 1; break;
			case 'y':
			case 'Y': fr[24] += 1; break;
			case 'z':
			case 'Z': fr[25] += 1; break;
			case '0': fr[26] += 1; break;
			case '1': fr[27] += 1; break;
			case '2': fr[28] += 1; break;
			case '3': fr[29] += 1; break;
			case '4': fr[30] += 1; break;
			case '5': fr[31] += 1; break;
			case '6': fr[32] += 1; break;
			case '7': fr[33] += 1; break;
			case '8': fr[34] += 1; break;
			case '9': fr[35] += 1; break;
			default : fr[36] += 1; break;
		}
	}

	/* Return call */
	return;
}

/* End of the HW06_151044001_Deniz_Can_Erdem_Yılmaz_part1.c */