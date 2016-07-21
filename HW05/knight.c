/*----------------------------------------------------------------------------*/
/* HW05_151044001_Deniz_Can_Erdem_Yılmaz                                      */
/* knight.c                                                                   */
/* Created on 04/04/2016 by Deniz_Can_Erdem_Yılmaz                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This c file contains the GIT's CSE102 Homework-5 Part-1 knight function    */
/* This function checks the validness of the move of a knight on the board    */
/*                                                                            */
/* Note(s)                                                                    */
/* -------                                                                    */
/* - Coding in this homework designed as the given code convention by         */
/*   teachers. Tab size is 4 and column limit in a row is 80                  */
/*----------------------------------------------------------------------------*/



/* Include(s) */
#include<stdio.h>



/*----------------------------------------------------------------------------*/
/* int isKnightMovable(char *board , char sourceCol, int sourceRow, char      */
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
int isKnightMovable(char *board , char sourceCol, int sourceRow, char 
targetCol, int targetRow);



/* ---------------------------------------------------------------------------*/
/* Function isKnightMovable                                                   */
/* ------------------------                                                   */
/* This function finds all of the cells that knight can move. Checks if given */
/* target cell is one of those movable cells. If it is then it checks for the */
/* target cell's current status. If everything is fine and knight can move to */
/* cell function returns 1, else 0                                            */
/* ---------------------------------------------------------------------------*/
int isKnightMovable(char *board , char sourceCol, int sourceRow, 
char targetCol, int targetRow)
{
	/* Return value, represents validness of move */
	int returnValue;
	
	/* A free knight can make 8 different moves; 2 forwards, 2 backwards, */
	/* 2 left and 2 right */
	int firstMove;
	int secondMove;
	int thirdMove;
	int fourthMove;
	int fifthMove;
	int sixthMove;
	int seventhMove;
	int eighthMove;
	
	/* Constant variables to find row number of the valid target cell */
	int firstConstant;
	int secondConstant;
	int thirdConstant;
	int fourthConstant;
	
	/* Indexes of first and target cells */
	int sourceIndex;
	int targetIndex;
	
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
	
	/* Top cells */
	firstMove = sourceIndex - 15;
	secondMove = sourceIndex - 17;
	firstConstant = (sourceIndex - 16)/8;
	
	/* Upper cells */
	thirdMove = sourceIndex - 10;
	fourthMove = sourceIndex - 6;
	secondConstant = (sourceIndex - 8)/8;
	
	/* Downside cells */
	fifthMove = sourceIndex + 6;
	sixthMove = sourceIndex + 10;
	thirdConstant = (sourceIndex + 8)/8;
	
	/* Bottom cells */
	seventhMove = sourceIndex + 15;
	eighthMove = sourceIndex + 17;
	fourthConstant = (sourceIndex + 16)/8;
	
	
	/* If target cell is a movable cell */
	if (opponentValue != 0)
	{
		/* Checking if target cell is on same row with top movable cells */
		if (firstConstant == targetIndex/8)
		{
			/* If rows match then compare cells */
			if (firstMove == targetIndex)
			{
				returnValue = 1;
			}

			else if (secondMove == targetIndex)
			{
				returnValue = 1;
			}
		}
		
		/* Checking if target cell is on same row with upper movable cells */
		else if (secondConstant == targetIndex/8)
		{
			/* If rows match then compare cells */
			if (thirdMove == targetIndex)
			{
				returnValue = 1;
			}
		
			else if (fourthMove == targetIndex)
			{
				returnValue = 1;
			}
		}
		
		/* Checking if target cell is on same row with downside movable cells */
		else if (thirdConstant == targetIndex/8)
		{
			/* If rows match then compare cells */
			if (fifthMove == targetIndex)
			{
				returnValue = 1;
			}
		
			else if (seventhMove == targetIndex)
			{
				returnValue = 1;
			}
		}
		
		/* Checking if target cell is on same row with bottom movable cells */
		else if (fourthConstant == targetIndex/8)
		{
			/* If rows match then compare cells */
			if (sixthMove == targetIndex)
			{
				returnValue = 1;
			}
			
			else if (eighthMove == targetIndex)
			{
				returnValue = 1;
			}
		}
	}
	return (returnValue);
}

/* End of knight.c */