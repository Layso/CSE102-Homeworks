/*----------------------------------------------------------------------------*/
/* HW05_151044001_Deniz_Can_Erdem_Yılmaz                                      */
/* helper.c                                                                   */
/* Created on 04/04/2016 by Deniz_Can_Erdem_Yılmaz                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This c file contains the GIT's CSE102 Homework-5 helper functions          */
/* These functions are basic helper functions to find a piece's index, find   */
/* the piece on an index,
/*                                                                            */
/* Note(s)                                                                    */
/* -------                                                                    */
/* - Coding in this homework designed as the given code convention by         */
/*   teachers. Tab size is 4 and column limit in a row is 80                  */
/*----------------------------------------------------------------------------*/



/* Include(s) */
#include<stdio.h>



/* Function Prototypes                                                        */
/*----------------------------------------------------------------------------*/
/* int positionFinder(char column, int row)                                   */
/* ---------------------------                                                */
/*                                                                            */
/* Parameter(s)                                                               */
/* ----------                                                                 */
/* column - Column character of the chess board                               */
/* row    - Row number of the chess board                                     */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Returns the given cells index                                              */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes address of a cell and calculates it's index number on  */
/* the chess board array                                                      */
/*----------------------------------------------------------------------------*/ 
int positionFinder(char column, int row);

/*----------------------------------------------------------------------------*/
/* char pieceFinder(char board[], int index)                                  */
/* ---------------------------                                                */
/*                                                                            */
/* Parameter(s)                                                               */
/* ----------                                                                 */
/* board[] - Chess board array to find piece on given cell                    */
/* index   - Index number to find piece on given cell                         */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Returns the piece character on the given index on chess board array        */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes an index and assigns value of array on that index to   */
/* return value                                                               */
/*----------------------------------------------------------------------------*/ 
char pieceFinder(char board[], int index);

/*----------------------------------------------------------------------------*/
/* int isOpponent(char source, char target)                                   */
/* ---------------------------                                                */
/*                                                                            */
/* Parameter(s)                                                               */
/* ----------                                                                 */
/* source - Piece on the source cell                                          */
/* target - Piece on the target cell                                          */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* 1 if pieces are opponents                                                  */
/* 0 if pieces are on same team                                               */
/* -1 if target cell is blank                                                 */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function controls the target cell to clarify the move. If one piece   */
/* is black and the other one is wihte then one of them must be capital and   */
/* the other one must be lower. If there is no piece on target cell then it   */
/* also is available to move                                                  */
/*----------------------------------------------------------------------------*/
int isOpponent(char source, char target);

/*----------------------------------------------------------------------------*/
/* int isValidCell(char col, int row)                                         */
/* ---------------------------                                                */
/*                                                                            */
/* Parameter(s)                                                               */
/* ----------                                                                 */
/* col - Column character                                                     */
/* row - Row number                                                           */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* 1 if given column and row are valid on chess board                         */
/* 0 if given column and row are invalid on chess board                       */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function controls the given cells validity on a chess board           */
/*----------------------------------------------------------------------------*/
int isValidCell(char col, int row);

/*----------------------------------------------------------------------------*/
/* void getPosition(char *col, int *row)                                      */
/* ---------------------------                                                */
/*                                                                            */
/* Parameter(s)                                                               */
/* ----------                                                                 */
/* *col - Character pointer for the column                                    */
/* *row - Integer pointer for the row                                         */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* No return value                                                            */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes inputs remain in the buffer after user's move call     */
/*----------------------------------------------------------------------------*/
void getPosition(char *col, int *row);

/*----------------------------------------------------------------------------*/
/* int isPieceMovable(char *board)                                            */
/* ---------------------------                                                */
/*                                                                            */
/* Parameter(s)                                                               */
/* ----------                                                                 */
/* *board - Chess board array                                                 */
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
/* This function calls the special control function of the piece on the       */
/* source                                                                     */
/*----------------------------------------------------------------------------*/
int isPieceMovable(char *board);



/* Function Implementation(s)                                                 */
/* ---------------------------------------------------------------------------*/
/* Function isPieceMovable                                                    */
/* ------------------------                                                   */
/* This is the main function that makes necessary function calls. This        */
/* function takes source and target cell informations, defines the source and */
/* target pieces (if there is) and checks the validness of move by calling    */
/* the helper functions                                                       */
/* ---------------------------------------------------------------------------*/
int isPieceMovable(char *board)
{
	/* Empty variable for space character */
	char empty;
	
	/* First and target cell variables */
	char col1;
	char col2;
	int row1;
	int row2;
	
	/* First cells index */
	int pieceIndex;
	
	/* Piece variable for the first cell */
	char piece;
	
	/* Return variable */
	int returnValue;
	
	
	/* Calling getPosition for taking the first cell addresses */
	getPosition(&col1,&row1);
	
	/* Getting the space character */
	scanf ("%c",&empty);
	
	/* Calling getPositions for taking the target cell addresses */
	getPosition(&col2,&row2);
	
	/* Setting the return value */
	returnValue = 0;
	
	
	/* Controlling if given cells are exists */
	if (isValidCell(col1,row1))
	{
		if (isValidCell(col2,row2))
		{
			/* If they exist then check for validness of move */
			/* First step is finding the index of cell on the board */
			/* Then call a function to get the value on the cell */
			pieceIndex = positionFinder(col1,row1);
			
			/* Assigning the piece char to its variable */
			piece = pieceFinder(board,pieceIndex);
			
			/* Now calling true function to check if piece is movable. If */
			/* they are moveable then they will change returnValue with the */
			/* return value of called functions */
			switch (piece)
			{
				case 'p':
				case 'P': returnValue = isPawnMovable(board, col1, row1, col2,
				row2); break;
				case 'r':
				case 'R': returnValue = isRookMovable(board, col1, row1, col2,
				row2); break;
				case 'n':
				case 'N': returnValue = isKnightMovable(board, col1, row1, col2,
				row2); break;
				case 'b':
				case 'B': returnValue = isBishopMovable(board, col1, row1, col2,
				row2); break;
				case 'q':
				case 'Q': returnValue = isQueenMovable(board, col1, row1, col2,
				row2); break;
				case 'k':
				case 'K': returnValue = isKingMovable(board, col1, row1, col2,
				row2); break;
				case ' ': returnValue = 0; break;
			}
		}
	}

	/* Returning the return value */
	return (returnValue);
}



/*----------------------------------------------------------------------------*/
/* Function positionFinder                                                    */
/* -------------                                                              */
/* This function takes row number and column character values of a cell on    */
/* game board and finds the index on the game board array                     */
/*----------------------------------------------------------------------------*/
int positionFinder(char column, int row)
{
	/* Index on the board of the given cell */
	int arrayIndex;
	
	/* Constants of variable value */ 
	int columnValue;
	int rowValue;
	
	/* Setting the column value */
	switch (column)
	{
		case 'a': columnValue = 0; break;
		case 'b': columnValue = 1; break;
		case 'c': columnValue = 2; break;
		case 'd': columnValue = 3; break;
		case 'e': columnValue = 4; break;
		case 'f': columnValue = 5; break;
		case 'g': columnValue = 6; break;
		case 'h': columnValue = 7; break;
	}
	
	/* Setting the row value */
	switch (row)
	{
		case 1: rowValue = 56; break;
		case 2: rowValue = 48; break;
		case 3: rowValue = 40; break;
		case 4: rowValue = 32; break;
		case 5: rowValue = 24; break;
		case 6: rowValue = 16; break;
		case 7: rowValue = 8; break;
		case 8: rowValue = 0; break;
	}
	
	/* Sum of column and row values equals the index of cell in array */
	arrayIndex = columnValue + rowValue;
	
	/* Returning the index */
	return (arrayIndex);
}



/*----------------------------------------------------------------------------*/
/* Function pieceFinder                                                       */
/* -------------                                                              */
/* This function takes game board array and an index value to find the piece  */
/* on the cell                                                                */
/*----------------------------------------------------------------------------*/
char pieceFinder(char board[], int index)
{
	/* Return value, the piece on the cell */
	char piece;

	/* Assigning the value on the cell to the piece variable */
	piece = board[index];
	
	/* Returning the piece */
	return(piece);
}



/*----------------------------------------------------------------------------*/
/* Function isOpponent                                                        */
/* -------------                                                              */
/* This function takes two characters both represents pieces from game board  */
/* and controls the relation between pieces. They may be on same team,        */
/* opposite teams or target value may be blank. Returns 3 different return    */
/* values depends to that situations                                          */
/*----------------------------------------------------------------------------*/
int isOpponent(char source, char target)
{
	/* Return value, depends on the target and source pieces */
	int returnValue;
	
	/* Setting return value to 0 */
	returnValue = 0;

	/* Checking the source piece if it is black then the piece will be */
	/* lower case */
	if (source>='a' && source<='z')
	{
		/* Return 1 if target is white which means upper case */
		if (target>='A' && target<='Z')
		{
			/* Setting the return value */
			returnValue = 1;
		}
		
		/* Return -1 if target cell is blank */
		else if (target == ' ')
		{
			/* Setting the return value */
			returnValue = -1;
		}
	}
	
	/* If source is upper case then program will continue with this else */
	/* statement */
	else
	{
		/* Return 1 if target is black which means lower case */
		if (target>='a' && target<='z')
		{
			/* Setting the return value */
			returnValue = 1;
		}
		
		/* Return -1 if target cell is blank */
		else if (target == ' ')
		{
			/* Setting the return value */
			returnValue = -1;
		}
	}

	/* Returning the return value */
	return (returnValue);
}



/*----------------------------------------------------------------------------*/
/* Function getPosition                                                       */
/* -------------                                                              */
/* This function takes column and row values of a cell on the game board and  */
/* checks if the given cell exist in the game board                           */
/*----------------------------------------------------------------------------*/
void getPosition(char *col, int *row)
{
	/* Taking the inputs remain in the buffer */
	scanf ("%c%d",col,row);
	
	return;
}



/*----------------------------------------------------------------------------*/
/* Function isValidCell                                                       */
/* -------------                                                              */
/* This function takes column and row values of a cell on the game board and  */
/* checks if the given cell exist in the game board. If there is an invalid   */
/* situation about existence of the cell returns 0, otherwise returns 1       */
/*----------------------------------------------------------------------------*/
int isValidCell(char col, int row)
{
	/* Return variable */
	int returnValue;
	
	/* Setting the return value */
	returnValue = 0;
	
	/* Control for the column parameter */
	if ((col>='a' && col<='h') || (col>='A' && col<='Z'))
	{
		if (row>=1 && row<=8)
		{
			/* If both column and row are valid then return 1 else 0 */
			returnValue = 1;
		}
	}
	
	/* Returning the return value */
	return (returnValue);
}

/* End of helper.c */