/*----------------------------------------------------------------------------*/
/* HW05_151044001_Deniz_Can_Erdem_Yılmaz                                      */
/* rook.c                                                                     */
/* Created on 04/04/2016 by Deniz_Can_Erdem_Yılmaz                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This c file contains the GIT's CSE102 Homework-5 Part-1 rook function      */
/* This function checks the validness of the move of a rook on the board      */
/*                                                                            */
/* Note(s)                                                                    */
/* -------                                                                    */
/* - Coding in this homework designed as the given code convention by         */
/*   teachers. Tab size is 4 and column limit in a row is 80                  */
/*----------------------------------------------------------------------------*/



/* Include(s) */
#include<stdio.h>



/*----------------------------------------------------------------------------*/
/* int isRookMovable(char *board , char sourceCol, int sourceRow, char        */
/* targetCol, int targetRow)                                                  */
/* ---------------------------                                                */
/*                                                                            */
/* Parameter(s)                                                               */
/* ----------                                                                 */
/* *board - Chess board array                                                 */
/* sourceCol - Source cells column character                                  */
/* sourceRow - Source cells row number                                        */
/* targetCol - Target cells column character                                  */
/* targetRow - Target cells row number                                        */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* 1 if given piece can move to target cell                                   */
/* 0 if given piece can't move to target cell                                 */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function checks if the piece on the sourceColumn-sourceRow can move   */
/* to the targetColumn-targetRow                                              */
/*----------------------------------------------------------------------------*/
int isRookMovable(char *board , char sourceCol, int sourceRow, char 
targetCol, int targetRow);



/* ---------------------------------------------------------------------------*/
/* Function isRookMovable                                                     */
/* ------------------------                                                   */
/* This function finds all of the cells that rook can move. Checks if given   */
/* target cell is one of those movable cells. If it is then it checks for the */
/* target cell's current status. If everything is fine and rook can move to   */
/* cell function returns 1, else 0                                            */
/* ---------------------------------------------------------------------------*/
int isRookMovable(char *board , char sourceCol, int sourceRow, 
char targetCol, int targetRow)
{
	/* Return value, represents validness of move */
	int returnValue;
	
	/* Index of first and target cells and a temporary for first index */
	int sourceIndex;
	int targetIndex;
	int tempIndex;
	
	/* Piece variables for the first and target cell */
	char piece;
	char targetPiece;
	
	/* Variable for the control of the target cells occupier */
	int opponentValue;
	
	/* Setting returnValue to 0. Program will change it to 1 if the move */
	/* is valid and available after the controls */
	returnValue = 0;
	
	
	/* Target must be a row front of the pawn */
	/* Finding the first and target cells index on the board */
	sourceIndex = positionFinder(sourceCol,sourceRow);
	targetIndex = positionFinder(targetCol,targetRow);
	
	
	/* Finding the pieces to learn if first piece is white or black */
	/* and if target cell is valid to move */
	piece = pieceFinder(board,sourceIndex);
	targetPiece = pieceFinder(board,targetIndex);
	
	
	/* If target piece is opponent then function will return 1, if it is ally */
	/* it will return 0 otherwise which means it's ' ' (blank) cell return -1 */
	opponentValue = isOpponent(piece,targetPiece);
	
	
	/* Setting temp to first index to make controls with temp value */
	tempIndex = sourceIndex;
	
	/* Checking if rook is moving horizontally */
	if (sourceCol == targetCol)
	{
		/* Checking if rook is moving upside or downside of the board */
		if (targetIndex>sourceIndex)
		{
			/* Checking if target cell is empty or occupied by an opponent */
			if (opponentValue == -1 || opponentValue == 1)
			{
				/* If all conditions are provided then return 1 */
				returnValue = 1;
			}
			
			/* Now cehcking for the rooks way on the target cell */
			/* if there is another piece which blocks it */
			tempIndex = tempIndex + 8; 
			
			/* Control loop until source row passes target row */
			while (tempIndex<targetIndex)
			{
				/* If cell equals anything other than ' ' (blank) the return */
				/* value will set to 0 again */
				if (board[tempIndex] != ' ')
				{
					/* Setting the return value */
					returnValue = 0;
				}
				 
				/* Adding 8 to get the next cell */ 
				tempIndex = tempIndex + 8;
			}
		}
		
		/* Checking if rook is moving to upside */
		else if (targetIndex<sourceIndex)
		{
			/* Checking if target cell is empty or occupied by an opponent */
			if (opponentValue == -1 || opponentValue == 1)
			{
				/* If all conditions are provided then return 1 */
				returnValue = 1;
			}
			
			
			/* Now cehcking for the rooks way on the target cell */
			/* if there is another piece which blocks it */
			tempIndex = tempIndex - 8; 
			
			/* Control loop until source row passes target row */
			while (tempIndex>targetIndex)
			{
				/* If cell equals anything other than ' ' (blank) the return */
				/* value will set to 0 again */
				if (board[tempIndex] != ' ')
				{
					/* Setting the return value */
					returnValue = 0;
				}
				 
				/* Adding 8 to get the next cell */ 
				tempIndex = tempIndex - 8;
			}
			
			
		}
	}
	
	
	/* If rook moves vertically it will continue with this if condition */
	else if (sourceRow == targetRow)
	{
		/* Checking if rook is moving to right */
		if (targetIndex>sourceIndex)
		{
			/* Setting temp variable one cell right of the source cell */
			tempIndex = tempIndex + 1;
			
			/* Checking if target cell is empty or occupied by an opponent */
			if (opponentValue == -1 || opponentValue == 1)
			{
				/* If all conditions are provided then return 1 */
				returnValue = 1;
			}
			
			/* Control loop until source row gets equals to target row */
			while (sourceCol<targetCol-1)
			{
				/* If cell equals anything other than ' ' (blank) the return */
				/* value will set to 0 again */
				if (board[tempIndex] != ' ')
				{
					/* Setting the return value */
					returnValue = 0;
				}
				
				/* Increasing the control variables */
				sourceCol = sourceCol + 1;
				tempIndex = tempIndex + 1;
			}
		}
		
		/* If rook is moving to left */
		else if (targetIndex<sourceIndex)
		{
			/* Setting temp variable one cell left of the source cell */
			tempIndex = tempIndex - 1;
			
			/* Checking if target cell is empty or occupied by an opponent */
			if (opponentValue == -1 || opponentValue == 1)
			{
				/* If all conditions are provided then return 1 */
				returnValue = 1;
			}
			
			/* Control loop until source row gets equals to target row */
			while (sourceCol>targetCol+1)
			{
				/* If cell equals anything other than ' ' (blank) the return */
				/* value will set to 0 again */
				if (board[tempIndex] != ' ')
				{
					/* Setting the return value */
					returnValue = 0;
				}
				
				/* Decreasing the control variables */
				sourceCol = sourceCol - 1;
				tempIndex = tempIndex - 1;
			}
		}
	}

	return (returnValue);
}

/* End of rook.c */