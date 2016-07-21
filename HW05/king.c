/*----------------------------------------------------------------------------*/
/* HW05_151044001_Deniz_Can_Erdem_Yılmaz                                      */
/* pawn.c                                                                     */
/* Created on 04/04/2016 by Deniz_Can_Erdem_Yılmaz                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This c file contains the GIT's CSE102 Homework-5 Part-1 king function      */
/* This function checks the validness of the move of a king on the board      */
/*                                                                            */
/* Note(s)                                                                    */
/* -------                                                                    */
/* - Coding in this homework designed as the given code convention by         */
/*   teachers. Tab size is 4 and column limit in a row is 80                  */
/*----------------------------------------------------------------------------*/



/* Include(s) */
#include<stdio.h>



/*----------------------------------------------------------------------------*/
/* int isKingMovable(char *board , char sourceCol, int sourceRow, char        */
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
int isKingMovable(char *board , char sourceCol, int sourceRow, char 
targetCol, int targetRow);



/* Function Implementation(s)                                                 */
/* ---------------------------------------------------------------------------*/
/* Function isKingMovable                                                     */
/* ------------------------                                                   */
/* This function finds all of the cells that king can move. Checks if given   */
/* target cell is one of those movable cells. If it is then it checks for the */
/* target cell's current status. If everything is fine and king can move to   */
/* cell function returns 1, else 0                                            */
/* ---------------------------------------------------------------------------*/
int isKingMovable(char *board , char sourceCol, int sourceRow, 
char targetCol, int targetRow)
{
	/* Return variable */
	int returnValue;
	
	/* A free king can make 8 way of moves; forwards, backwards, left, right */
	/* and cross ways */
	int firstMove;
	int secondMove;
	int thirdMove;
	int fourthMove;
	int fifthMove;
	int sixthMove;
	int seventhMove;
	int eighthMove;
	
	/* Row constants for overflow control */
	int firstConstant;
	int secondConstant;
	int thirdConstant;
	
	/* Index of first and target cells */
	int sourceIndex;
	int targetIndex;
	
	/* Source and target cell variables */
	int piece;
	int targetPiece;	
	
	/* Target cell's occupier */
	int opponent;
	
	
	/* Setting the return value */
	returnValue = 0;
	
	/* Target must be a row front of the king */
	/* Finding the first and target cells index on the board */
	sourceIndex = positionFinder(sourceCol,sourceRow);
	targetIndex = positionFinder(targetCol,targetRow);

	/* Finding the pieces to learn if first piece is white or black */
	/* and if target cell is valid to move */
	piece = pieceFinder(board,sourceIndex);
	targetPiece = pieceFinder(board,targetIndex);
	
	/* Finding the all positions king can move and row constants */
	/* To find row constant best way is taking the mod of the valid cells on */
	/* the same column */
	/* These three are valid moves towards 8th row */
	firstMove = sourceIndex - 9;
	secondMove = sourceIndex - 8;
	thirdMove = sourceIndex - 7;
	firstConstant = 8 - (secondMove/8);
	
	/* These two are valid moves on same row with source between a-h col */
	fourthMove = sourceIndex - 1;
	fifthMove = sourceIndex + 1;
	secondConstant = 8 - (sourceIndex/8);
	
	/* Last three are valid moves towards 1st row */
	sixthMove = sourceIndex + 7;
	seventhMove = sourceIndex + 8;
	eighthMove = sourceIndex + 9;
	thirdConstant = 8 - (seventhMove/8);

	/* Taking the target cells movability information. If target cell is */
	/* blank (-1) or belongs to opponent (1) program will continue with */
	/* the if statement */
	opponent = isOpponent(piece,targetPiece);
	
	
	if (opponent == 1 || opponent == -1)
	{
		/* Checking if target index equals to any possible move */
		/* If it isn't then program will pass these if statments and will */
		/* return 0 */
		if (targetIndex == firstMove)
		{
			/* Checking target index's row number to prevent overflow */
			if (firstConstant == 8 - (targetIndex/8))
			{
				/* Target cells is movable, setting return value to 1 */
				returnValue = 1;
			}	
		}
	
		else if (targetIndex == secondMove)
		{
			/* Checking target index's row number to prevent overflow */
			if (firstConstant == 8 - (targetIndex/8))
			{
				/* Target cells is movable, setting return value to 1 */
				returnValue = 1;
			}		
		}
		
		else if (targetIndex == thirdMove)
		{
			/* Checking target index's row number to prevent overflow */
			if (firstConstant == 8 - (targetIndex/8))
			{
				/* Target cells is movable, setting return value to 1 */
				returnValue = 1;
			}
		}
		
		else if (targetIndex == fourthMove)
		{
			/* Checking target index's row number to prevent overflow */
			if (secondConstant == 8 - (targetIndex/8))
			{
				/* Target cells is movable, setting return value to 1 */
				returnValue = 1;
			}
		}
	
		else if (targetIndex == fifthMove)
		{
			/* Checking target index's row number to prevent overflow */
			if (secondConstant == 8 - (targetIndex/8))
			{
				/* Target cells is movable, setting return value to 1 */
				returnValue = 1;
			}
		}
	
		else if (targetIndex == sixthMove)
		{
			/* Checking target index's row number to prevent overflow */
			if (thirdConstant == 8 - (targetIndex/8))
			{
				/* Target cells is movable, setting return value to 1 */
				returnValue = 1;
			}
		}
	
		else if (targetIndex == seventhMove)
		{
			/* Checking target index's row number to prevent overflow */
			if (thirdConstant == 8 - (targetIndex/8))
			{
				/* Target cells is movable, setting return value to 1 */
				returnValue = 1;
			}
		}
	
		else if (targetIndex == eighthMove)
		{
			/* Checking target index's row number to prevent overflow */
			if (thirdConstant == 8 - (targetIndex/8))
			{
				/* Target cells is movable, setting return value to 1 */
				returnValue = 1;
			}
		}
	}
	
	/* Returning the return value */
	return (returnValue);
}

/* End of king.c */