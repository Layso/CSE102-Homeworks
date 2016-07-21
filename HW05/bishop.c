/*----------------------------------------------------------------------------*/
/* HW05_151044001_Deniz_Can_Erdem_Yılmaz                                      */
/* bishop.c                                                                   */
/* Created on 04/04/2016 by Deniz_Can_Erdem_Yılmaz                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This c file contains the GIT's CSE102 Homework-5 Part-1 bishop function    */
/* This function checks the validness of the move of a bishop on the board    */
/*                                                                            */
/* Note(s)                                                                    */
/* -------                                                                    */
/* - Coding in this homework designed as the given code convention by         */
/*   teachers. Tab size is 4 and column limit in a row is 80                  */
/*----------------------------------------------------------------------------*/



/* Include(s) */
#include<stdio.h>



/*----------------------------------------------------------------------------*/
/* int isBishopMovable(char *board , char sourceCol, int sourceRow, char      */
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
int isBishopMovable(char *board , char sourceCol, int sourceRow, char 
targetCol, int targetRow);



/* ---------------------------------------------------------------------------*/
/* Function isBishopMovable                                                   */
/* ------------------------                                                   */
/* This function finds all of the cells that bishop can move. Checks if given */
/* target cell is one of those movable cells. If it is then it checks for the */
/* target cell's current status. If everything is fine and bishop can move to */
/* cell function returns 1, else 0                                            */
/* ---------------------------------------------------------------------------*/
int isBishopMovable(char *board , char sourceCol, int sourceRow, 
char targetCol, int targetRow)
{
	/* Return value, represents validness of move */
	int returnValue;
	
	/* Indexes on the array of the first and target cells */
	int sourceIndex;
	int targetIndex;
	
	/* Piece variables for first and target cells */
	char sourcePiece;
	char targetPiece;
	
	/* Temporary value for control loop */
	int temp;
	
	/* Control variables for row overflow */
	int rowCounter;
	
	
	/* Setting raturn value to 1. If move is invalid then it will reset to */
	/* 0 after the controls */
	returnValue = 1;
	
	/* Initializing as 1 because loops will ignore last cell on the */
	/* destination */
	rowCounter = 1;
	
	/* Finding the indexes of first and target cells on the board array */
	sourceIndex = positionFinder(sourceCol,sourceRow);
	targetIndex = positionFinder(targetCol,targetRow);
	
	/* Finding the pieces on both target and source cell to make controls */
	/* and decide the validness of move */
	sourcePiece = pieceFinder(board,sourceIndex);
	targetPiece = pieceFinder(board,targetIndex);

	/* Checking the relation between target and source cell */
	if (isOpponent(sourcePiece,targetPiece) != 0)
	{
		/* If both pieces are not on same team or target cell is blank */
		/* continue from here */
		
		/* A bishop can move 4 cross ways. If it goes upper left the index */
		/* of the piece decreases by 9. If it goes upper right the index */
		/* decreases 7. If it goes bottom left then index increases 7 and if */
		/* piece goes bottom right index increases 9 on every move. Dividing */
		/* the flow of program to 2 with if statement for upper and lower */
		/* moves. And dividing each 'if' to 2 for left or right moves */
		
		/* If bishop moves upper */
		if (sourceIndex>targetIndex)
		{
			/* First of all checking if difference between source and target */
			/* cells is divisible by 9 or 7 to find if target cell is on the */
			/* path of bishop */
			
			/* If difference is divisible by 9 then bishop moves upper left */
			if ((sourceIndex-targetIndex)%9==0)
			{	
				/* Creating a loop to control the cells occupiers on the */
				/* bishops way through target cell */			
				for (temp=sourceIndex-9;temp>targetIndex;temp=temp-9)
				{
					/* If there is any cell that is note empty then return */
					/* 0 because bishop can not go to target cell */
					if (board[temp] != ' ')
					{
						returnValue = 0;
					}
					
					/* Counting how many rows bishop moved */
					rowCounter = rowCounter + 1;

				}
				
				/* If bishop moved more or lesser than it should go than it */
				/* indicates that there is an overflow situation. So checking */
				/* if row numbers plus start point (sourceRow) is equals to */
				/* target cell's row number will let program find it. If */
				/* there is an inequality return 0 due to overflow */ 
				if (rowCounter+sourceRow != targetRow)
				{
					returnValue = 0;
				}	
				
			}
			
			
			/* If difference is divisible by 7 then bishop moves upper right */ 
			else if ((sourceIndex-targetIndex)%7==0)
			{
				for (temp=sourceIndex-7;temp>targetIndex;temp=temp-7)
				{
					/* If there is any cell that is note empty then return */
					/* 0 because bishop can not go to target cell */
					if (board[temp] != ' ')
					{
						returnValue = 0;
					}
					
					/* Counting how many rows bishop moved */
					rowCounter = rowCounter + 1;

				}
				
				/* If bishop moved more or lesser than it should go than it */
				/* indicates that there is an overflow situation. So checking */
				/* if row numbers plus start point (sourceRow) is equals to */
				/* target cell's row number will let program find it. If */
				/* there is an inequality return 0 due to overflow */ 
				if (rowCounter+sourceRow != targetRow)
				{
					returnValue = 0;
				}
			}
			
			/* If source cell is not on the path of bishop return 0 */
			else
			{
				returnValue = 0;
			}
		}

		/* Else if bishop goes lower */
		else if (sourceIndex<targetIndex)
		{
			/* First of all checking if difference between source and target */
			/* cells is divisible by 9 or 7 to find if target cell is on the */
			/* path of bishop */
			
			/* If difference is divisible by 7 then bishop moves lower left */
			if ((targetIndex-sourceIndex)%7==0)
			{
				for (temp=sourceIndex+7;temp<targetIndex;temp=temp+7)
				{
					/* If there is any cell that is note empty then return */
					/* 0 because bishop can not go to target cell */
					if (board[temp] != ' ')
					{
						returnValue = 0;
					}
					
					/* Counting how many rows bishop moved */
					rowCounter = rowCounter + 1;

				}
				
				/* If bishop moved more or lesser than it should go than it */
				/* indicates that there is an overflow situation. So checking */
				/* if row numbers plus start point (sourceRow) is equals to */
				/* target cell's row number will let program find it. If */
				/* there is an inequality return 0 due to overflow */
				
				if (sourceRow-rowCounter != targetRow)
				{
					returnValue = 0;
				}
			}
			
			
			/* If difference is divisible by 9 then bishop moves lower right */ 
			else if ((targetIndex-sourceIndex)%9==0)
			{
				for (temp=sourceIndex+9;temp<targetIndex;temp=temp+9)
				{
					/* If there is any cell that is note empty then return */
					/* 0 because bishop can not go to target cell */
					if (board[temp] != ' ')
					{
						returnValue = 0;
					}
					/* Counting how many rows bishop moved */
					rowCounter = rowCounter + 1;

				}
				
				/* If bishop moved more or lesser than it should go than it */
				/* indicates that there is an overflow situation. So checking */
				/* if row numbers plus start point (sourceRow) is equals to */
				/* target cell's row number will let program find it. If */
				/* there is an inequality return 0 due to overflow */ 
				if (sourceRow-rowCounter != targetRow)
				{
					returnValue = 0;
				}
			}
			
			/* If source cell is not on the path of bishop return 0 */
			else
			{
				returnValue = 0;
			}
		}
		
		
		
		
		/* If indexes are equals then user tries to move to its own cell */
		/* which is an invalid move */
		else
		{
			/* So return 0 */
			returnValue = 0;
		}
	}
	
	/* If they are on same team then simply return 0 */
	else
	{
		returnValue = 0;
	}
	
	
	/* Returning the return value */
	return (returnValue);
}

/* End of bishop.c */