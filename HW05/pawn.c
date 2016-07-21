/*----------------------------------------------------------------------------*/
/* HW05_151044001_Deniz_Can_Erdem_Yılmaz                                      */
/* pawn.c                                                                     */
/* Created on 04/04/2016 by Deniz_Can_Erdem_Yılmaz                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This c file contains the GIT's CSE102 Homework-5 Part-1 pawn function      */
/* This function checks the validness of the move of a pawn on the board      */
/*                                                                            */
/* Note(s)                                                                    */
/* -------                                                                    */
/* - Coding in this homework designed as the given code convention by         */
/*   teachers. Tab size is 4 and column limit in a row is 80                  */
/*----------------------------------------------------------------------------*/



/* Include(s) */
#include<stdio.h>



/*----------------------------------------------------------------------------*/
/* int isPawnMovable(char *board , char sourceCol, int sourceRow, char        */
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
int isPawnMovable(char *board , char sourceCol, int sourceRow, char 
targetCol, int targetRow);



/* Function Implementation(s)                                                 */
/* ---------------------------------------------------------------------------*/
/* Function isPawnMovable                                                     */
/* ------------------------                                                   */
/* This function finds all of the cells that pawn can move. Checks if given   */
/* target cell is one of those movable cells. If it is then it checks for the */
/* target cell's current status. If everything is fine and pawn can move to   */
/* cell function returns 1, else 0                                            */
/* ---------------------------------------------------------------------------*/
int isPawnMovable(char *board , char sourceCol, int sourceRow, char targetCol, 
int targetRow)
{
	/* Return value, represents validness of move */
	int returnValue;
	
	/* Index of first and target cells */
	int sourceIndex;
	int targetIndex;
	
	/* Piece variables for the first and target cell */
	char piece;
	char targetPiece;
	
	/* A free pawn can make 3 way of moves, forward and cross ways */
	int firstMove;
	int secondMove;
	int thirdMove;
	
	/* Target cells row number for controls */
	int targetRowStart;
	int targetRowEnd;
	
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
	
	/* If piece is white */
	if (piece == 'P')
	{
		/* A row has 8 columns. So substracting 8 from pawns index will give */
		/* the index of the front cell of the pawn. (+1) and (-1) of that */
		/* index will give the corss ways' indexes */
		secondMove = sourceIndex - 8;
		firstMove = secondMove - 1;
		thirdMove = secondMove + 1;
		
		
		/* If the pawn is near the edge of the board the crossway move */
		/* is not valid. But thinking of the indexes program may say that */
		/* the move is valid. So we need to check if the target cells row */
		/* is in front of the source row */
		
		/* The secondMove variable represents the pawns front cell. So int */
		/* divison of that cell will give us that rows constant value used */
		/* for finding index. Then multiplying with 8 again will give  */
		/* the first column of the available row. Adding 7 to it will give */
		/* the last column of the available row. So we can check for the */
		/* row overflow due to index order using this variables */
		targetRowStart = (secondMove/8) * 8 ;
		targetRowEnd = targetRowStart + 7;
	}
	
	/* If piece is black */
	else if (piece == 'p')
	{
		/* A row has 8 columns. So adding 8 to pawns index will give */
		/* the index of the front cell of the pawn. (+1) and (-1) of that */
		/* index will give the corss ways' indexes */
		secondMove = sourceIndex + 8;
		firstMove = secondMove - 1;
		thirdMove = secondMove + 1;
		
		/* If the pawn is near the edge of the board the crossway move */
		/* is not valid. But thinking of the indexes program may say that */
		/* the move is valid. So we need to check if the target cells row */
		/* is in front of the source row */
		
		/* The secondMove variable represents the pawns front cell. So int */
		/* divison of that cell will give us that rows constant value used */
		/* for finding index. Then multiplying with 8 again will give  */
		/* the first column of the available row. Adding 7 to it will give */
		/* the last column of the available row. So we can check for the */
		/* row overflow due to index order using this variables */
		targetRowStart = (secondMove/8) * 8 ;
		targetRowEnd = targetRowStart + 7;
	}
	
	
	/* If target piece is opponent then function will return 1, if it is ally */
	/* it will return 0 otherwise which means it's ' ' (blank) cell return -1 */
	opponentValue = isOpponent(piece,targetPiece);

	/* Checking the target row's row number to prevent row overflow */
	/* All three possible moves must be on the same row */
	if (targetIndex >= targetRowStart && targetIndex <= targetRowEnd)
	{
		/* If there is a valid piece */
		if (piece != ' ')
		{
			/* If target index equals to first movable cell */
			if (targetIndex == firstMove)
			{
				/* Check the target cell's value. It must be opponent to */
				/* move cross way */
				if (opponentValue == 1)
				{
					/* If all conditions are provided then set return value */
					/* to 1 */
					returnValue = 1;	
				}
			}
			
			/* If target index equals to second movable cell */
			else if (targetIndex == secondMove)
			{
				/* Check the target cell's value. It must be blank to */
				/* move forward */
				if (targetPiece == ' ')
				{
					/* If all conditions are provided then set return value */
					/* to 1 */
					returnValue = 1;
				}
			}
			
			/* If target index equals to third movable cell */
			else if (targetIndex == thirdMove)
			{
				/* Check the target cell's value. It must be opponent to */
				/* move cross way */
				if (opponentValue == 1)
				{
					/* If all conditions are provided then set return value */
					/* to 1 */
					returnValue = 1;
				}
			}
		}
	}
	
	/* Returning the return value */
	return (returnValue);
}

/* End of pawn.c */