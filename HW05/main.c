/*----------------------------------------------------------------------------*/
/* HW05_151044001_Deniz_Can_Erdem_Yılmaz                                      */
/* HW05_151044001_Deniz_Can_Erdem_Yılmaz.c                                    */
/* Created on 04/04/2016 by Deniz_Can_Erdem_Yılmaz                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This c file contains the GIT's CSE102 Homework-5 Part-1 main and helper    */
/* functions. This program takes orders from user to initialize chess board,  */
/* check a moves validness, print the board's current position or exit        */
/*                                                                            */
/* Note(s)                                                                    */
/* -------                                                                    */
/* - Functions are seperated as different c files to prevent mess             */
/* - Coding in this homework designed as the given code convention by         */
/*   teachers. Tab size is 4 and column limit in a row is 80                  */
/* - Some function prototypes are given by teachers with HW definition PDF    */
/* - main() function has given by the teachers                                */
/*----------------------------------------------------------------------------*/



/* Includes */
#include<stdio.h>



/* Function to clear buffer, given by teachers/TA's */
void emptyBuffer()
{
	while ( getchar() != '\n' );
}



/* Completely given by the teachers */
int main()
{
	char board [64];
	int initComplete = 0;
	char empty;

	int command;
	scanf("%d", &command);

	while(command!=4)
	{
		switch(command)
		{
			case 1: initBoard(board); 
				initComplete = 1; 
				printf("OK\n");
				break;
			case 2: 
				/*Read space character after command number*/
				scanf("%c", &empty);
				if (initComplete)
				{
					if(isPieceMovable(board))
						printf("YES\n");
					else
						printf("NO\n");
				}
				else
				{  
					printf("Board is not initialized!\n");
					emptyBuffer();
				}
				break;
			case 3: 
				if (initComplete)
					printBoard(board);
				else  
					printf("Board is not initialized!\n");
					emptyBuffer();
				break;

			default: printf("Invalid command!\n"); emptyBuffer(); break;

		}	
		
		scanf("%d", &command);
	
	}
	return 0;
}

/* End of HW05_151044001_Deniz_Can_Erdem_Yılmaz.c */