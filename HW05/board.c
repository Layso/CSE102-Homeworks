/*----------------------------------------------------------------------------*/
/* HW05_151044001_Deniz_Can_Erdem_Yılmaz                                      */
/* board.c                                                                    */
/* Created on 04/04/2016 by Deniz_Can_Erdem_Yılmaz                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This c file contains the GIT's CSE102 Homework-5 board functions           */
/* These functions are basic board operators to initialize the board and      */
/* print it.                                                                  */
/*                                                                            */
/* Note(s)                                                                    */
/* -------                                                                    */
/* - Coding in this homework designed as the given code convention by         */
/*   teachers. Tab size is 4 and column limit in a row is 80                  */
/*----------------------------------------------------------------------------*/



/* Include(s) */
#include<stdio.h>



/* Function Prototype(s)                                                      */
/*----------------------------------------------------------------------------*/
/* void printBoard(char board[])                                              */
/* -----------------------------                                              */
/*                                                                            */
/* Parameter(s)                                                               */
/* ----------                                                                 */
/* board[] - Chess board array                                                */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* No return value                                                            */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function prints the current situation of the chess board              */
/*----------------------------------------------------------------------------*/
void printBoard(char board[]);

/*----------------------------------------------------------------------------*/
/* int initBoard(char board[])                                                */
/* ---------------------------                                                */
/*                                                                            */
/* Parameter(s)                                                               */
/* ----------                                                                 */
/* board[] - Chess board array                                                */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Always returns 0                                                           */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes an char array to set it like beginning of a chess      */
/* board                                                                      */
/*                                                                            */
/*                                                                            */
/* Notes                                                                      */
/* -----                                                                      */
/* This function only sets board to beginning position                        */
/*----------------------------------------------------------------------------*/ 
int initBoard(char board[]);

/*----------------------------------------------------------------------------*/
/* char boardOrganizer(int index)                                             */
/* ------------------------------                                             */
/*                                                                            */
/* Parameter(s)                                                               */
/* ----------                                                                 */
/* index - Index of board array to place the piece                            */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Returns the piece character by index                                       */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes index of chess board array to return the piece value   */
/*                                                                            */
/*                                                                            */
/* Notes                                                                      */
/* -----                                                                      */
/* Used switch case to make controls before dead-line by using index numbers  */
/*----------------------------------------------------------------------------*/ 
char boardOrganizer(int index);



/* Function Implementation(s)                                                 */
/*----------------------------------------------------------------------------*/
/* Function printBoard                                                        */
/* -------------------                                                        */
/* This function takes game board array and prints it to the user. No return  */
/* value due to void function prototype                                       */
/*----------------------------------------------------------------------------*/
void printBoard(char *board)
{
	/* Variables for loop counter and row number */
	int i;
	int rowNumber;
	
	/* Initializing row number with 8 to print the row numers upside down */
	rowNumber = 8;
	
	/* Top of the border */
	printf ("  a b c d e f g h\n  - - - - - - - -\n%d|",rowNumber);
	
	/* Printing board array */
	for (i=0;i<64;i++)
	{
		/* Print the current array element */
		printf ("%c",board[i]);

		/* Controlling the end of the row */
		if (i%8==7)
		{
			/* The row number will be decreased */
			rowNumber = rowNumber - 1;
			
			/* If it is the end of the array finish with the last wall and */
			/* go to new line */
			if (i==63)
			{
				printf("|\n");
			}
			
			
			/* Else print another wall for the next row */
			else
			{
				printf("|\n%d|",rowNumber);
			}
		}
		
		/* If it isn't end of the row print blank */
		else 
		{
			printf (" ");
		}
	}
	/* Bottom of the border */
	printf ("  - - - - - - - -\n");
	
	return;
}



/*----------------------------------------------------------------------------*/
/* Function initBoard                                                         */
/* ------------------                                                         */
/* This function takes the game board array and places all pieces into it as  */
/* starting position                                                          */
/*----------------------------------------------------------------------------*/
int initBoard(char board[])
{
	/* Index variable */
	int i;
	
	for (i=0;i<64;i++)
	{
		/* For the index i call the boardOrganizer[i] and equalize it to */
		/* board i */
		board[i] = boardOrganizer(i);
	}
	
	return (0);
}



/*----------------------------------------------------------------------------*/
/* Function boardOrganizer                                                    */
/* -----------------------                                                    */
/* This function is a helper function for initBoard to place the pieces in    */
/* their right position by using switch case. Initializing the board may be   */
/* done by initBoard only, but this function also helps programmer to see     */
/* the index number of the pieces to make controls about game                 */
/*----------------------------------------------------------------------------*/
char boardOrganizer(int index)
{
	/* Character return value */
	char returnChar;
	
	/* To the given index parameter this switch case will send the true value */
	/* for the beginning position on a chess board */
	switch (index)
	{

		case 0: returnChar = 'r'; break;
		case 1: returnChar = 'n'; break;
		case 2: returnChar = 'b'; break;
		case 3: returnChar = 'q'; break;
		case 4: returnChar = 'k'; break;
		case 5: returnChar = 'b'; break;
		case 6: returnChar = 'n'; break;
		case 7: returnChar = 'r'; break;
		
		case 8: returnChar = 'p'; break;
		case 9: returnChar = 'p'; break;
		case 10: returnChar = 'p'; break;
		case 11: returnChar = 'p'; break;
		case 12: returnChar = 'p'; break;
		case 13: returnChar = 'p'; break;
		case 14: returnChar = 'p'; break;
		case 15: returnChar = 'p'; break;
		
		case 48: returnChar = 'P'; break;
		case 49: returnChar = 'P'; break;
		case 50: returnChar = 'P'; break;
		case 51: returnChar = 'P'; break;
		case 52: returnChar = 'P'; break;
		case 53: returnChar = 'P'; break;
		case 54: returnChar = 'P'; break;
		case 55: returnChar = 'P'; break;
		
		case 56: returnChar = 'R'; break;
		case 57: returnChar = 'N'; break;
		case 58: returnChar = 'B'; break;
		case 59: returnChar = 'Q'; break;
		case 60: returnChar = 'K'; break;
		case 61: returnChar = 'B'; break;
		case 62: returnChar = 'N'; break;
		case 63: returnChar = 'R'; break;
		default: returnChar = ' '; break;
		
	}
	
	/* Returning the return value */
	return (returnChar);	
}

/* End of board.c */