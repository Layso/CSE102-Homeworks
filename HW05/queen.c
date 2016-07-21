/*----------------------------------------------------------------------------*/
/* HW05_151044001_Deniz_Can_Erdem_Yılmaz                                      */
/* queen.c                                                                    */
/* Created on 04/04/2016 by Deniz_Can_Erdem_Yılmaz                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This c file contains the GIT's CSE102 Homework-5 Part-1 queen function     */
/* This function checks the validness of the move of a queen on the board     */
/*                                                                            */
/* Note(s)                                                                    */
/* -------                                                                    */
/* - Coding in this homework designed as the given code convention by         */
/*   teachers. Tab size is 4 and column limit in a row is 80                  */
/*----------------------------------------------------------------------------*/



/* Include(s) */
#include<stdio.h>



/*----------------------------------------------------------------------------*/
/* int isQueenMovable(char *board , char sourceCol, int sourceRow, char       */
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
int isQueenMovable(char *board , char sourceCol, int sourceRow, char 
targetCol, int targetRow);



/* ---------------------------------------------------------------------------*/
/* Function isQueenMovable                                                    */
/* ------------------------                                                   */
/* This function checks the validness of the queen move on the board by       */
/* simply calling the bishop and rooks helper functions. If one of them       */
/* indicates that move is valid, this function returns same result            */
/* ---------------------------------------------------------------------------*/
int isQueenMovable(char *board , char sourceCol, int sourceRow, 
char targetCol, int targetRow)
{
	/* Return variable */
	int returnValue;
	
	/* Sub move control variables */
	int bishopControl;
	int rookControl;
	
	/* Setting return value to 0 */
	returnValue = 0;
	
	/* Sub move control with rook and bishop */
	bishopControl = isBishopMovable(board,sourceCol,sourceRow,targetCol,
	targetRow);
	rookControl = isRookMovable(board,sourceCol,sourceRow,targetCol,targetRow);
	
	/* If one of them returns 1, this means queen can move to target cell */
	if (bishopControl || rookControl)
	{
		/* Setting return value 1 */
		returnValue = 1;
	}
	
	/* Returning return value */
	return (returnValue);
}

/* End of queen.c */