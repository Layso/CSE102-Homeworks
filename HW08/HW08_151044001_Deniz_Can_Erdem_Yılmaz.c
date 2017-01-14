/*----------------------------------------------------------------------------*/
/* HW08_151044001_Deniz_Can_Erdem_Yılmaz                                      */
/* HW08_151044001_Deniz_Can_Erdem_Yılmaz.c                                    */
/* Created on 21/04/2016 by Deniz_Can_Erdem_Yılmaz                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This is the GIT's homework 8 for the CSE102 lecture. This program takes    */
/* cell values of a game board to play 2 player co-op chess                   */
/*                                                                            */
/* Notes                                                                      */
/* -----                                                                      */
/* This file is written by considering the rules on code convention. So a row */
/* is max 80 column, tab width is 4 and coded with the desired code design    */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/* Include(s) */
#include <stdio.h>

/* Define(s) */
#define BOARD_SIZE 8

/* Function Prototypes                                                        */
/*----------------------------------------------------------------------------*/
/* int initBoard(char board[])                                                */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
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
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
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

/*----------------------------------------------------------------------------*/
/* void getPosition(char *col, int *row)                                      */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
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
/*                                                                            */
/*----------------------------------------------------------------------------*/
void getPosition(char *col, int *row);

/*----------------------------------------------------------------------------*/
/* int isOpponent(char source, char target)                                   */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
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
/* is black and the other one is white then one of them must be capital and   */
/* the other one must be lower. If there is no piece on target cell then it   */
/* also is available to move                                                  */
/*                                                                            */
/*----------------------------------------------------------------------------*/
int isOpponent(char source, char target);

/*----------------------------------------------------------------------------*/
/* void printBoard(char board[])                                              */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
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
/*                                                                            */
/*----------------------------------------------------------------------------*/
void printBoard(char board[]);

/*----------------------------------------------------------------------------*/
/* int isValidCell(char col, int row)                                         */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
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
/*                                                                            */
/*----------------------------------------------------------------------------*/
int isValidCell(char col, int row);

/*----------------------------------------------------------------------------*/
/* int positionFinder(char column, int row)                                   */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
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
/*                                                                            */
/*----------------------------------------------------------------------------*/ 
int positionFinder(char column, int row);

/*----------------------------------------------------------------------------*/
/* char pieceFinder(char board[], int index)                                  */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
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
/*                                                                            */
/*----------------------------------------------------------------------------*/ 
char pieceFinder(char board[], int index);

/*----------------------------------------------------------------------------*/
/* int isPawnMovable(char *board , char sourceCol, int sourceRow, char        */
/* targetCol, int targetRow)                                                  */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
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
/*                                                                            */
/*----------------------------------------------------------------------------*/
int isPawnMovable(char *board , char sourceCol, int sourceRow, char 
targetCol, int targetRow);

/*----------------------------------------------------------------------------*/
/* int isRookMovable(char *board , char sourceCol, int sourceRow, char        */
/* targetCol, int targetRow)                                                  */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
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
/*                                                                            */
/*----------------------------------------------------------------------------*/
int isRookMovable(char *board , char sourceCol, int sourceRow, char 
targetCol, int targetRow);

/*----------------------------------------------------------------------------*/
/* int isKnightMovable(char *board , char sourceCol, int sourceRow, char      */
/* targetCol, int targetRow)                                                  */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
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
/*                                                                            */
/*----------------------------------------------------------------------------*/
int isKnightMovable(char *board , char sourceCol, int sourceRow, char 
targetCol, int targetRow);

/*----------------------------------------------------------------------------*/
/* int isBishopMovable(char *board , char sourceCol, int sourceRow, char      */
/* targetCol, int targetRow)                                                  */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
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
/*                                                                            */
/*----------------------------------------------------------------------------*/
int isBishopMovable(char *board , char sourceCol, int sourceRow, char 
targetCol, int targetRow);

/*----------------------------------------------------------------------------*/
/* int isKingMovable(char *board , char sourceCol, int sourceRow, char        */
/* targetCol, int targetRow)                                                  */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
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
/*                                                                            */
/*----------------------------------------------------------------------------*/
int isKingMovable(char *board , char sourceCol, int sourceRow, char 
targetCol, int targetRow);

/*----------------------------------------------------------------------------*/
/* int isQueenMovable(char *board , char sourceCol, int sourceRow, char       */
/* targetCol, int targetRow)                                                  */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
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
/*                                                                            */
/*----------------------------------------------------------------------------*/
int isQueenMovable(char *board , char sourceCol, int sourceRow, char 
targetCol, int targetRow);

/*----------------------------------------------------------------------------*/
/* int isPieceMovable(char *board, char sc, int sr, char tc, int tr)          */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
/* ----------                                                                 */
/* *board - Chess board array                                                 */
/* sc     - Source column character                                           */
/* sr     - Source row number                                                 */
/* tc     - Target column charater                                            */
/* tr     - Target row number                                                 */
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
/*                                                                            */
/*----------------------------------------------------------------------------*/
int isPieceMovable(char *board, char sc, int sr, char tc, int tr);

/*----------------------------------------------------------------------------*/
/* int isInCheck(char *board)                                                 */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
/* ----------                                                                 */
/* *board - Chess board array                                                 */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* 0 if there is no check situation                                           */
/* 1 if white king is in check                                                */
/* 2 if black king is in check                                                */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function controls the board to find if there is a check situation or  */
/* not                                                                        */
/*                                                                            */
/*----------------------------------------------------------------------------*/
int isInCheck(char *board);

/*----------------------------------------------------------------------------*/
/* void indexAnalyze(int index,int *row, char *col)                           */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
/* ----------                                                                 */
/* index - Index of the piece on the game board array                         */
/* *row - Pointer of the row number of the piece on index                     */
/* *col - Pointer of the column character of the piece on index               */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* No return value due to void function.                                      */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes index number of a piece on the game board. Makes       */
/* calculations to find the row number and column character of the piece.     */
/*                                                                            */
/*----------------------------------------------------------------------------*/
void indexAnalyze(int index,int *row, char *col);

/*----------------------------------------------------------------------------*/
/* int isBlack(char currPlayer)                                               */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
/* ----------                                                                 */
/* currPlayer - A piece (character) on the game board                         */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* 1 if given piece is black which means it is a lower case character         */
/* 0 if given piece is not black                                              */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes a character and checks if it is upper or lower case    */
/*                                                                            */
/*----------------------------------------------------------------------------*/
int isBlack(char currPlayer);

/*----------------------------------------------------------------------------*/
/* int isWhite(char currPlayer)                                               */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
/* ----------                                                                 */
/* currPlayer - A piece (character) on the game board                         */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* 1 if given piece is white which means it is an upper case character        */
/* 0 if given piece is not white                                              */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes a character and checks if it is upper or lower case    */
/*                                                                            */
/*----------------------------------------------------------------------------*/
int isWhite(char currPlayer);

/*----------------------------------------------------------------------------*/
/* int makeMove(char *board, char sc, int sr, char tc, int tr)                */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
/* ----------                                                                 */
/* *board - Chess board array                                                 */
/* sc     - Source column character                                           */
/* sr     - Source row number                                                 */
/* tc     - Target column charater                                            */
/* tr     - Target row number                                                 */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* 0 if given piece can't move to target cell or source cell is blank         */
/* 1 if move is invalid because player's king is on check                     */
/* 2 if given piece is moved to target cell                                   */
/* 3 if given piece is moved to target cell and caused check situation for    */
/*   opponent's king                                                          */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes board, target and source cell informations and makes   */
/* the move if it is valid or returns why move can't be done                  */
/*                                                                            */
/*----------------------------------------------------------------------------*/
int makeMove(char *board, char sc, int sr, char tc, int tr);

/*----------------------------------------------------------------------------*/
/* char getPlayer(char *board,char sc,int sr)                                 */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
/* ----------                                                                 */
/* *board - Chess board array to find piece on given cell                     */
/* sc     - Column character of the desired piece's cell                      */
/* sr     - Row number of the desired piece's cell                            */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Returns the piece character on the given index on chess board array        */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes cell informations and assigns value of piece on that   */
/* cell to return value. This is a similar function to pieceFinder but works  */
/* with column and row values instead of index                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/ 
char getPlayer(char *board,char sc,int sr);












int main() {
    char board [BOARD_SIZE*BOARD_SIZE], empty;
    int player = 1; /* 1 white, 0 black */
    char sc,tc; /* source/target cols */
    int sr,tr; /* source/target rows */
    int moveStatus = 0;
    int checkStatus = 0;
    char currPlayer;

    initBoard(board);

    do {
        printBoard(board);
        printf("%s player move > ", player ? "White" : "Black");
        getPosition(&sc,&sr);
        scanf("%c", &empty);
        getPosition(&tc,&tr);
        scanf("%c", &empty);
        currPlayer = getPlayer(board, sc,sr);

        if(!isValidCell(sc,sr)) {
            printf("Source position is invalid\n");
            continue;
        }
        if(!isValidCell(tc,tr)) {
            printf("Target position is invalid\n");
            continue;
        }
        if((isBlack(currPlayer) && player) ||
           (isWhite(currPlayer) && !player)) {
            printf("Illegal piece. \n");
            continue;
        }

        moveStatus = makeMove(board,sc,sr,tc,tr);
        switch(moveStatus) {
            case 0:
                printf("Invalid move!\n");
                break;
            case 1:
                printf("Your king is in check!\n");
                ++checkStatus;
                break;
            case 3:
                printf("Check!\n");
            case 2:
                player = !player;
                checkStatus = 0;
                break;
        }
    } while(checkStatus < 2);
    printf("%s player WINS!\n", player ? "Black" : "White");
    return 0;
}

















/* Function Implementation(s)                                                 */
/*----------------------------------------------------------------------------*/
/* Function makeMove                                                          */
/* -------------                                                              */
/* This function takes game board array, source cell's row number and column  */
/* character and target cell's row number and column numbers to make the move */
/* commanded by the user. A piece can easily move if it's king is not in      */
/* situaton. Otherwise piece can only move if it saves king from check. There */
/* are 4 return values that represent invalid move, valid move, opponent's    */
/* king in check and player's king in check situations                        */
/*----------------------------------------------------------------------------*/
int makeMove(char *board, char sc, int sr, char tc, int tr)
{
	/* Variable for return value */
	int returnValue;
	
	/* Source and target cell indexes to change them if move is valid */
	int sourceIndex;
	int targetIndex;
	
	/* Piece values of source and target cell to move it */
	char sourcePiece;
	char targetPiece;
	
	/* Temporary variables to change the position back if player makes an */
	/* invalid move in check situation */
	char tempSource;
	char tempTarget;
	
	
	/* Finding indexes of source and target cell to make move */
	sourceIndex = positionFinder(sc,sr);
	targetIndex = positionFinder(tc,tr);
	
	/* Finding the source and target pieces to make move */
	sourcePiece = pieceFinder(board,sourceIndex);
	targetPiece = pieceFinder(board,targetIndex);
	
	/* Setting temp variables */
	tempSource = sourcePiece;
	tempTarget = targetPiece;
	
	/* Function will continue depends on the isPieceMovable's return value */
	/* 1 -- If piece on source cell can move to target cell */
	/* 0 -- Otherwise */
	if (isPieceMovable(board,sc,sr,tc,tr))
	{
		/* If white king is on check */
		if (isInCheck(board) == 1)
		{
			/* And player is white */
			if (sourcePiece >= 'A' && sourcePiece <= 'Z')
			{
				/* Then let player move. But if check situation keeps */
				/* continuing after move then cancel the move, change it back */
				/* and return 1 */
				
				/* Moving the piece on the source cell */
				board[targetIndex] = sourcePiece;
				/* And empty the source cell */
				board[sourceIndex] = ' ';
				
				/* Controlling the check situation again */
				/* If player's or both kings are in check return 1 and take */
				/* move back */
				if (isInCheck(board) == 1 || isInCheck(board) == -1)
				{					
					/* Taking back the move */
					board[sourceIndex] = tempSource;
					board[targetIndex] = tempTarget;
					
					/* Returning 1 */
					returnValue = 1;
				}
				
				/* If opponent's king is in check then return 3 */
				else if (isInCheck(board) == 2)
				{
					returnValue = 3;
				}
				
				/* Otherwise return 2 */
				else
				{
					returnValue = 2;
				}
			}
		}
		
		
		/* If black king is on check */
		else if (isInCheck(board) == 2)
		{
			/* And player is black */
			if (sourcePiece >= 'a' && sourcePiece <= 'z')
			{
				/* Then let player move. But if check situation keeps */
				/* continuing after move then cancel the move, change it back */
				/* and return 1 */
				
				/* Moving the piece on the source cell */
				board[targetIndex] = sourcePiece;
				
				/* And empty the source cell */
				board[sourceIndex] = ' ';
				
				/* Controlling the check situation again */
				/* If player's or both kings are in check return 1 and take */
				/* move back */
				if (isInCheck(board) == 2 || isInCheck(board) == -1)
				{
					/* Taking back the move */
					board[sourceIndex] = tempSource;
					board[targetIndex] = tempTarget;
					
					
					returnValue = 1;
					

				}
				
				/* If opponent's king is in check then return 3 */
				else if (isInCheck(board) == 1)
				{
					returnValue = 3;
				}
				
				/* Otherwise return 2 */
				else
				{
					returnValue = 2;
				}
			}
		}
		
		
		/* If there is no check situation just make a normal move */
		else
		{
			/* Moving the piece on the source cell */
			board[targetIndex] = sourcePiece;
			/* And empty the source cell */
			board[sourceIndex] = ' ';
			

			/* Controlling the check situation after the move. If it doesn't */
			/* return 0 then there is a check situation */
			if (isInCheck(board) != 0)
			{
				/* If there is a check situation for white and player was */
				/* black or there is a check situation for black and player */
				/* was white then return 3 as check for opponent */
				if ((isInCheck(board)==1 && isBlack(sourcePiece)==1) || 
				(isInCheck(board)==2 && isWhite(sourcePiece)==1))
				{
					/* Setting return value */
					returnValue = 3;
				}
				
				/* If there is a check situation for black and player was */
				/* black or there is a check situation for white and player */
				/* was white or both kings are on check then this is an */
				/* invalid move, take back the move and return 0 */
				else if ((isInCheck(board)==1 && isWhite(sourcePiece)==1) || 
				(isInCheck(board)==2 && isBlack(sourcePiece)==1) || 
				isInCheck(board)==-1)
				{
					/* Taking back the move */
					board[sourceIndex] = tempSource;
					board[targetIndex] = tempTarget;

					/* Setting return value */
					returnValue = 0;
				}
				
			}
			
			/* If there is no check situation after move then this is a */
			/* move completed without any problems, return 2 */
			else
			{
				/* Setting return value */
				returnValue = 2;
			}
		}
	}
	
	/* If piece is not movable to target cell then return 0 */
	else
	{
		/* Setting return value */
		returnValue = 0;
	}
	
	/* Returning the return value */
	return (returnValue);
}



/*----------------------------------------------------------------------------*/
/* Function isInCheck                                                         */
/* -------------                                                              */
/* This function takes game board array and controls the kings to find if     */
/* there is a check situation on the board. There are 4 different return      */
/* values that represents white king is in check, black king is in check      */
/* both kings are in check or no check situations                             */
/*----------------------------------------------------------------------------*/
int isInCheck(char* board)
{
	/* Index variable to use in the loop that finds kings' indexes */
	int index;
	
	/* Chess boards row number */
	int row;
	
	/* Chess boards column character */
	char column;
	
	/* Cell and result information variables for white king */
	int whiteKingRow;
	char whiteKingColumn;
	int whiteKingIndex;
	int whiteCheck;
	
	/* Cell and result information variables for black king */
	int blackKingRow;
	char blackKingColumn;
	int blackKingIndex;
	int blackCheck;
	
	/* Variable for return value */
	int returnValue;
	
	/* Setting check values to 0. If there is a check situation then these */
	/* will change */
	whiteCheck = 0;
	blackCheck = 0;
	
	/* Creating a loop to find white kings' indexes */
	for (index=0;index<64;index++)
	{
		/* If upper k is found take index as white king index */
		if (board[index] == 'K')
		{
			/* Setting white king's index as index variable */
			whiteKingIndex = index;
		}
		
		/* If lower k is found take index as black king index */
		else if (board[index] == 'k')
		{
			/* Setting black king's index as index variable */
			blackKingIndex = index;
		}
	}
	
	/* Sending indexes to indexAnalyze function to find row number */
	/* and column characters of the kings */
	indexAnalyze(whiteKingIndex,&whiteKingRow,&whiteKingColumn);
	indexAnalyze(blackKingIndex,&blackKingRow,&blackKingColumn);
	
	
	/* Setting row as 8 and column as 'a' to indicate top left corner of */
	/* board which indicates the index 0. Increasing cloumn until 'i' and */
	/* decreasing row until 0 will give all the cells on game board */
	for (row=8;row>0;row--)
	{
		for (column='a';column<'i';column++)
		{
			/* If a piece in any cell can move to black king's cell then */
			/* this means it is in check so set black king's check situation */
			/* as 1 */
			if (isPieceMovable(board,column,row,blackKingColumn,blackKingRow))
			{
				blackCheck = 1;
			}
			
			/* If a piece in any cell can move to white king's cell then */
			/* this means it is in check so set white king's check situation */
			/* as 1 */
			if (isPieceMovable(board,column,row,whiteKingColumn,whiteKingRow))
			{
				whiteCheck = 1;
			}
		}
	}
	
	/* There are 4 different final results */
	
	/* If both kings are in check situation return -1 to indicate it. This */
	/* supposed to only happen if a king is trying to move in range of enemy */
	/* king which means both can attack other one */
	if (whiteCheck==1 && blackCheck==1)
	{
		returnValue = -1;
	}
	
	/* If white king is in check then return 1 to indicate it */
	else if (whiteCheck==1 && blackCheck==0)
	{
		returnValue = 1;
	}

	/* If black king is in check then return 2 to indicate it */
	else if (whiteCheck==0 && blackCheck==1)
	{
		returnValue = 2;
	}
	
	/* If there is no check situation return 0 to indicate it */
	else if (whiteCheck==0 && blackCheck==0)
	{
		returnValue = 0;
	}
	
	/* Returning the return value */
	return (returnValue);
}



/*----------------------------------------------------------------------------*/
/* Function indexAnalyze                                                      */
/* -------------                                                              */
/* This function takes an index from the game board and divides it into its   */
/* row number and column character components. Function doesnt return         */
/* anything but changes the values of given pointer parameters                */
/*----------------------------------------------------------------------------*/
void indexAnalyze(int index,int *row, char *col)
{
	/* Qutient from divison of index to 8 will give complementary of row */
	/* number. So substracting it from 8 will give real row number */
	*row = 8 - (index/8);
	
	/* Column characters are going in order with remainer of index division 8 */
	switch (index%8)
	{
		case 0: *col = 'a'; break;
		case 1: *col = 'b'; break;
		case 2: *col = 'c'; break;
		case 3: *col = 'd'; break;
		case 4: *col = 'e'; break;
		case 5: *col = 'f'; break;
		case 6: *col = 'g'; break;
		case 7: *col = 'h'; break;
	}
	
	return;
}



/*----------------------------------------------------------------------------*/
/* Function isPieceMovable                                                    */
/* -------------                                                              */
/* This function takes game board array, source cell's row number and column  */
/* character and target cell's row number and column numbers to control if    */
/* the given piece on source cell can move to target cell. There are 2 return */
/* values that represents piece is movable or not movable                     */
/*----------------------------------------------------------------------------*/
int isPieceMovable(char *board, char sc, int sr, char tc, int tr)
{
	/* Source and target cell variables */
	char col1;
	char col2;
	int row1;
	int row2;
	
	/* Index variable for the piece on source cell */
	int pieceIndex;
	
	/* Piece variable for the piece on source cell */
	char piece;
	
	/* Variable for return value */
	int returnValue;
	
	/* Setting column and row variables to adjust the function parameter */
	/* differences between HW5 and HW8 */
	col1 = sc;
	col2 = tc;
	row1 = sr;
	row2 = tr;	
	
	/* Controlling if given source cells are exists */
	if (isValidCell(col1,row1))
	{
		/* Controlling if given target cells are exists */
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
/* Function getPlayer                                                         */
/* -------------                                                              */
/* This function takes game board array, source cell's row number and column  */
/* character to find the piece on source cell. This is a similar function to  */
/* pieceFinder function but this one finds the piece by using row and column  */
/* instead of index                                                           */
/*----------------------------------------------------------------------------*/
char getPlayer(char *board,char sc,int sr)
{
	/* Index of the source cell */
	int index;
	
	/* Initial of the piece */
	char piece;
	
	/* Finding the index of source cell by calling positionFinder function */
	index = positionFinder(sc,sr);
	
	/* Finding the piece on the source cell by calling pieceFinder function */
	piece = pieceFinder(board,index);
	
	/* Returning the piece */
	return  (piece);
}



/*----------------------------------------------------------------------------*/
/* Function isBlack                                                           */
/* -------------                                                              */
/* This function takes a character which represents piece and controls if the */
/* piece belongs to the black team                                            */
/*----------------------------------------------------------------------------*/
int isBlack(char currPlayer)
{
	/* Variable for return value */
	int returnValue;
	
	/* Setting return value 0 as default */
	returnValue = 0;
	
	/* If currPlayer is lower case character */
	if (currPlayer>=97 && currPlayer<=122)
	{
		/* Reset return value to 1 */
		returnValue = 1;
	}
	
	/* Returning the return value */
	return (returnValue);
}



/*----------------------------------------------------------------------------*/
/* Function isWhite                                                           */
/* -------------                                                              */
/* This function takes a character which represents piece and controls if the */
/* piece belongs to the white team                                            */
/*----------------------------------------------------------------------------*/
int isWhite(char currPlayer)
{
	/* Variable for return value */
	int returnValue;
	
	/* Setting return value 0 as default */
	returnValue = 0;
	
	/* If currPlayer is upper case character */
	if (currPlayer>=65 && currPlayer<=90)
	{
		/* Reset return value to 1 */
		returnValue = 1;
	}
	
	/* Returning the return value */
	return (returnValue);
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
/* Function isPawnMovable                                                     */
/* -------------                                                              */
/* This function takes game board array, source row number, source column     */
/* character target row number and target column character to process them to */
/* find if the pawn given in source cell is able to move the target cell      */
/* Returns 1 if it is movable, 0 if it isn't.                                 */
/*----------------------------------------------------------------------------*/
int isPawnMovable(char *board , char sourceCol, int sourceRow, char targetCol, 
int targetRow)
{
	/* Return value, represents validness of move */
	int returnValue;
	
	/* Index of first and target cells */
	int firstIndex;
	int targetIndex;
	
	/* Piece variables for the first and target cell */
	char piece;
	char targetPiece;
	
	/* A free pawn can make 3 way of moves, forward and cross ways */
	int firstMove;
	int secondMove;
	int thirdMove;
	
	/* Target cells row number for overflow controls */
	int targetRowStart;
	int targetRowEnd;
	
	/* Variable for the control of the target cells occupier */
	int opponentValue;
	
	
	
	/* Setting returnValue to 0. Program will change it to 1 if the move */
	/* is valid and available after the controls */
	returnValue = 0;
	
	/* Target must be a row front of the pawn */
	/* Finding the first and target cells index on the board */
	firstIndex = positionFinder(sourceCol,sourceRow);
	targetIndex = positionFinder(targetCol,targetRow);
	
	/* Finding the pieces to learn if first piece is white or black */
	/* and if target cell is valid to move */
	piece = pieceFinder(board,firstIndex);
	targetPiece = pieceFinder(board,targetIndex);
	
	/* If piece is white */
	if (piece == 'P')
	{
		/* A row has 8 columns. So substracting 8 from pawns index will give */
		/* the index of the front cell of the pawn. (+1) and (-1) of that */
		/* index will give the corss ways' indexes */
		secondMove = firstIndex - 8;
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
		secondMove = firstIndex + 8;
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



/*----------------------------------------------------------------------------*/
/* Function isRookMovable                                                     */
/* -------------                                                              */
/* This function takes game board array, source row number, source column     */
/* character target row number and target column character to process them to */
/* find if the rook given in source cell is able to move the target cell      */
/* Returns 1 if it is movable, 0 if it isn't.                                 */
/*----------------------------------------------------------------------------*/
int isRookMovable(char *board , char sourceCol, int sourceRow, 
char targetCol, int targetRow)
{
	/* Return value, represents validness of move */
	int returnValue;
	
	/* Index of first and target cells and a temporary for first index */
	int firstIndex;
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
	firstIndex = positionFinder(sourceCol,sourceRow);
	targetIndex = positionFinder(targetCol,targetRow);
	
	
	/* Finding the pieces to learn if first piece is white or black */
	/* and if target cell is valid to move */
	piece = pieceFinder(board,firstIndex);
	targetPiece = pieceFinder(board,targetIndex);
	
	
	/* If target piece is opponent then function will return 1, if it is ally */
	/* it will return 0 otherwise which means it's ' ' (blank) cell return -1 */
	opponentValue = isOpponent(piece,targetPiece);
	
	
	/* Setting temp to first index to make controls with temp value */
	tempIndex = firstIndex;
	
	/* Checking if rook is moving horizontally */
	if (sourceCol == targetCol)
	{
		/* Checking if rook is moving upside or downside of the board */
		if (targetIndex>firstIndex)
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
		else if (targetIndex<firstIndex)
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
		if (targetIndex>firstIndex)
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
		else if (targetIndex<firstIndex)
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



/*----------------------------------------------------------------------------*/
/* Function isKnightMovable                                                   */
/* -------------                                                              */
/* This function takes game board array, source row number, source column     */
/* character target row number and target column character to process them to */
/* find if the knight given in source cell is able to move the target cell    */
/* Returns 1 if it is movable, 0 if it isn't.                                 */
/*----------------------------------------------------------------------------*/
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
	int targetConstant;
	
	/* Indexes of first and target cells */
	int firstIndex;
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
	firstIndex = positionFinder(sourceCol,sourceRow);
	targetIndex = positionFinder(targetCol,targetRow);
	
	
	/* Finding the pieces to learn if first piece is white or black */
	/* and if target cell is valid to move */
	piece = pieceFinder(board,firstIndex);
	targetPiece = pieceFinder(board,targetIndex);
	
	
	/* If target piece is opponent then function will return 1, if it is ally */
	/* it will return 0 otherwise which means it's ' ' (blank) cell return -1 */
	opponentValue = isOpponent(piece,targetPiece);
	
	/* Top cells */
	firstMove = firstIndex - 15;
	secondMove = firstIndex - 17;
	firstConstant = sourceRow + 2;
	
	/* Upper cells */
	thirdMove = firstIndex - 10;
	fourthMove = firstIndex - 6;
	secondConstant = sourceRow + 1;
	
	/* Downside cells */
	fifthMove = firstIndex + 6;
	sixthMove = firstIndex + 10;
	thirdConstant = sourceRow - 1;
	
	/* Bottom cells */
	seventhMove = firstIndex + 15;
	eighthMove = firstIndex + 17;
	fourthConstant = sourceRow - 2;
	
	/* Setting target constant to find the target cell's row number and */
	/* control with the possible cell constants */
	targetConstant = targetRow;

	/* If target cell is a movable cell continue with check situation */	
	if (opponentValue != 0)
	{
		/* If target row equals to first constant then knight is moving to */
		/* one of the top cells */
		if (firstConstant == targetConstant)
		{
			/* If any move index is equals to target cell's index set return */
			/* value to 1 to indicate it is a valid move */
			
			/* If knight moves to the top left cell */
			if (firstMove == targetIndex)
			{
				returnValue = 1;
			}
			
			/* If knight moves to the top right cell */
			else if (secondMove == targetIndex)
			{
				returnValue = 1;
			}
		}
		
		/* If target row equals to second constant then kight is moving to */
		/* one of the upper cells */
		else if (secondConstant == targetConstant)
		{
			/* If any move index is equals to target cell's index set return */
			/* value to 1 to indicate it is a valid move */
			
			/* If knigth moves upper left cell */
			if (thirdMove == targetIndex)
			{
				returnValue = 1;
			}
		
			/* If knight moves upper right cell */
			else if (fourthMove == targetIndex)
			{
				returnValue = 1;
			}
		}
		
		/* If target row equals to third constant then knight is moving to */
		/* lower cells */
		else if (thirdConstant == targetConstant)
		{
			/* If any move index is equals to target cell's index set return */
			/* value to 1 to indicate it is a valid move */
			
			/* If knight moves lower left cell */
			if (fifthMove == targetIndex)
			{
				returnValue = 1;
			}
		
			/* If knight moves lower right cell */
			else if (sixthMove == targetIndex)
			{
				returnValue = 1;
			}
		}
		
		/* If target row equals to fourth constant then knight is moving to */
		/* bottom cells */
		else if (fourthConstant == targetConstant)
		{
			/* If any move index is equals to target cell's index set return */
			/* value to 1 to indicate it is a valid move */
			
			/* If knight moves bottom left cell */
			if (seventhMove == targetIndex)
			{
				returnValue = 1;
			}
			
			/* If knight moves bottom right cell */
			else if (eighthMove == targetIndex)
			{
				returnValue = 1;
			}
		}
	}
	
	/* Returning the return value */
	return (returnValue);
}



/*----------------------------------------------------------------------------*/
/* Function isBishopMovable                                                   */
/* -------------                                                              */
/* This function takes game board array, source row number, source column     */
/* character target row number and target column character to process them to */
/* find if the bishop given in source cell is able to move the target cell    */
/* Returns 1 if it is movable, 0 if it isn't.                                 */
/*----------------------------------------------------------------------------*/
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



/*----------------------------------------------------------------------------*/
/* Function isKingMovable                                                     */
/* -------------                                                              */
/* This function takes game board array, source row number, source column     */
/* character target row number and target column character to process them to */
/* find if the king given in source cell is able to move the target cell      */
/* Returns 1 if it is movable, 0 if it isn't.                                 */
/*----------------------------------------------------------------------------*/
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
	int firstIndex;
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
	firstIndex = positionFinder(sourceCol,sourceRow);
	targetIndex = positionFinder(targetCol,targetRow);

	/* Finding the pieces to learn if first piece is white or black */
	/* and if target cell is valid to move */
	piece = pieceFinder(board,firstIndex);
	targetPiece = pieceFinder(board,targetIndex);
	
	/* Finding the all positions king can move and row constants */
	/* To find row constant best way is taking the mod of the valid cells on */
	/* the same column */
	/* These three are valid moves towards 8th row */
	firstMove = firstIndex - 9;
	secondMove = firstIndex - 8;
	thirdMove = firstIndex - 7;
	firstConstant = 8 - (secondMove/8);
	
	/* These two are valid moves on same row with source between a-h col */
	fourthMove = firstIndex - 1;
	fifthMove = firstIndex + 1;
	secondConstant = 8 - (firstIndex/8);
	
	/* Last three are valid moves towards 1st row */
	sixthMove = firstIndex + 7;
	seventhMove = firstIndex + 8;
	eighthMove = firstIndex + 9;
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



/*----------------------------------------------------------------------------*/
/* Function isQueenMovable                                                    */
/* -------------                                                              */
/* This function takes game board array, source row number, source column     */
/* character target row number and target column character to process them to */
/* find if the queen given in source cell is able to move the target cell     */
/* Returns 1 if it is movable, 0 if it isn't.                                 */
/*----------------------------------------------------------------------------*/
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



/*----------------------------------------------------------------------------*/
/* Function printBoard                                                        */
/* -------------                                                              */
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
/* Function initBoard                                                         */
/* -------------                                                              */
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
/* -------------                                                              */
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

/* End of HW08_151044001_Deniz_Can_Erdem_Yılmaz.c */
