/*----------------------------------------------------------------------------*/
/* HW07_151044001_Deniz_Can_Erdem_Yılmaz                                      */
/* HW07_151044001_Deniz_Can_Erdem_Yılmaz_part2.c                              */
/* Created on 14/04/2016 by Deniz_Can_Erdem_Yılmaz                            */
/* -----------------------------------------------                            */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This is the GIT's homework 7 - part 2 for the CSE102 lecture. This program */
/* will check the goal situation by the given width, length, radius and angle */,
/* variables. If it is a goal then function returns 1, otherwise (not goal or */
/* invalid parameters) it will return 0                                       */
/*                                                                            */
/*                                                                            */
/* Notes                                                                      */
/* -----                                                                      */
/* This file is written by considering the rules on code convention. So a row */
/* is max 80 column, tab width is 4 and coded with the desired code design    */
/*                                                                            */
/* Also it is a must to code functions with recursion for this homework       */
/*----------------------------------------------------------------------------*/



/* Include(s) */
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

/* Defines(s) */
#define PI 3.14159265
#define WIDTH 100	
#define HEIGHT 26
#define ANGLE 45
#define GOAL 2
#define CENTER 6
#define RADIUS 5



/* Function Prototype(s) */
/*----------------------------------------------------------------------------*/
/* int kickDisc(double wallWidth, double wallHeight, double ballCenterX,      */
/* double kickAngle, double ballRadius, double goalWidth);                    */
/* ------------------------------------------------------                     */
/*                                                                            */
/*                                                                            */
/* Parameter(s)                                                               */
/* ----------                                                                 */
/* wallWidth   - Width value of the wall                                      */
/* wallHeight  - Height value of wall                                         */
/* ballCenterX - Ball's center's x axis value                                 */
/* kickAngle   - Angle between ball's direction and x axis                    */
/* ballRadius  - Radius of the ball                                           */
/* goalWidth   - Width of the goal on the top of the wall                     */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* 0 - If it is not goal or there is/are invalid input(s)                     */
/* 1 - If it is goal                                                          */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes a pile of parameters explained upside and then         */
/* calculates the ball's last destination through the game board between      */
/* walls and checks if result of the kick is goal or not                      */
/*----------------------------------------------------------------------------*/
int kickDisc(double wallWidth, double wallHeight, double ballCenterX, double
kickAngle, double ballRadius, double goalWidth);

/*----------------------------------------------------------------------------*/
/* int reflection(int angle)                                                  */
/* -------------------------                                                  */
/*                                                                            */
/*                                                                            */
/* Parameter(s)                                                               */
/* ----------                                                                 */
/* angle - The angle between ball direction and x axis                        */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* angle - Returns angle value back after adding random number                */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes an angle parameter, generates a random number and then */
/* returns the angel value after adding the random number                     */
/*----------------------------------------------------------------------------*/
int reflection(int angle);

int randNumber(int angle);



int main()
{
	printf ("%d\n",kickDisc(WIDTH,HEIGHT,CENTER,ANGLE,RADIUS,GOAL));
	return (0);
}



int randNumber(int angle)
{
	srand(angle);
	return rand();
}


/* Function Implementation(s)                                                 */
/*----------------------------------------------------------------------------*/
/* Function reflection                                                        */
/* -------------                                                              */
/* This function takes an angle value. Calls randNumber function to generate  */
/* random number which is has 9 digits. After that takes mode of 11 and       */
/* assigns remainer to randomInt variable. After mode operator randomInt can  */
/* only be between 0 and 11. Using switch case, it gets a random number       */
/* between -5 and +5. Adds it to the angle parameter and returns angle back   */ 
/*----------------------------------------------------------------------------*/
int reflection(int angle)
{
	/* One variable for the raw number and other for the modified to get */
	/* random number between -5 & +5 */
	int randomRaw;
	int randomInt;
	
	/* Raw random number is the one comes from randomNumber function */
	randomRaw = randNumber(angle);
	
	/* Number mode 11 can only produce numbers between 0 and 10*/
	randomRaw = randomRaw % 11;
	
	/* Assigning the random number between -5 and 5 to randomInt using switch */
	/* to add with case given angle */
	switch (randomRaw)
	{
		case 0: randomInt = 5; break;
		case 1: randomInt = 4; break;
		case 2: randomInt = 3; break;
		case 3: randomInt = 2; break;
		case 4: randomInt = 1; break;
		case 5: randomInt = 0; break;
		case 6: randomInt = -1; break;
		case 7: randomInt = -2; break;
		case 8: randomInt = -3; break;
		case 9: randomInt = -4; break;
		case 10: randomInt = -5; break;
	}
	
	/* Adding random number to angle value */
	angle = angle + randomInt;
	
	/* If angle is bigger than 175 degrees change the value to 175 */
	if (angle>175)
	{
		angle = 175;
	}
	
	/* If angle is lesser than 5 degrees change the value to 5 */
	if (angle<5)
	{
		angle = 5;
	}
	
	/* Returning the modified angle value */
	return (angle);
}




/*----------------------------------------------------------------------------*/
/* Function int kickDisc(double wallWidth, double wallHeight, double          */
/* ballCenterX, double kickAngle, double ballRadius, double goalWidth)        */
/* -------------                                                              */
/* This function will calculate ball's way through the end of the game board  */
/* and checks if hit will resulted with goal or not. If it is a goal then it  */
/* returns 1 otherwise returns 0                                              */
/*----------------------------------------------------------------------------*/
int kickDisc(double wallWidth, double wallHeight, double ballCenterX, double
kickAngle, double ballRadius, double goalWidth)
{
	
	/* A variable to convert degree to radian */
	double radian;
	
	/* A variable to find ball's final x value */
	double finalBallX;
	
	/* Two variables to store start and end of the goal */
	double goalFirstX;
	double goalSecondX;
	
	/* Return value variable */
	int returnValue;




	/* Controlling if the given ball radius and wall width values are enough */
	/* to make a valid hit. Ball size can't be bigger than the game board */
	/* sizes. So ball diameter must be lesser than width and height. Height */
	/* can be half size of diameter (which means on the size of radius) */
	/* because first hit considered as the ball's half part is on the */
	/* outside of the game board */
	if (wallHeigth>ballRadius && wallWidth>2*ballRadius)
	{
		/* Setting new wall sizes due to ball radius. After the adjustment */
		/* program will make calculations as the ball is a point mass */
		wallHeight = wallHeight - ballRadius;
	
		/* Subtracting 2 times radius from width for left and right walls */
		wallWidth = wallWidth - (2 * ballRadius);
		
		/* Controlling if the angle is bigger than 90 which means ball is */
		/* going to hit the left side of the wall */
		if (kickAngle>90)
		{
			/* Converting degrees to radians to make calculations usin tan */
			/* function in math library */
			radian = (180.0 - kickAngle) * (PI/180.0);
		
			/* Checking if tangent angle of ballCenter lesser than wallHeight */
			/* Multiplication of tangent(radian) and ballCenter gives the */
			/* ball's distance on y axis until it hits the wall */
			/* If wallHeight is bigger then ball is gonna travel through */
			/* the wall on it's way */
			if (tan(radian)*(ballCenterX) < wallHeight)
			{
				/* Setting parameters for the next function call which is the */
				/* recursive part */
			
				/* Substracting the ball's path through y axis from total */
				/* height of the wall */
				wallHeight = wallHeight - (tan(radian)*(wallWidth-ballCenterX));
			
				/* Ball just hit the left side of the wall which means it's */
				/* on the left edge of the game board right now. So ball's */
				/* center's distance to wall is equals to its own radius */
				ballCenterX = ballRadius;
				
				/* New kickAngle will be supplementary of the former angle */
				/* Also reflection function will add an random integer */
				/* between -5 and +5 for the reflection angle */
				kickAngle = reflection(180.0-kickAngle);

				/* Changing back the wall sizes to the given sizes to call */
				/* the function to do recursive calculation */
				wallHeight = wallHeight + ballRadius;
				wallWidth = wallWidth + (2 * ballRadius);
		
				/* Return value equals to the result of next hit which means */
				/* the next disc kick from the adjusted location */
				returnValue = kickDisc(wallWidth,wallHeight,ballCenterX,
				kickAngle,ballRadius,goalWidth);
			}
		
			/* If wallHeight is equals to or lesser than the distance ball */
			/* could take than it will hit to the top of the walls. So this */
			/* is base control for the end */
			else
			{
				/* Converting degrees to radians */
				radian = (kickAngle - 90) * (PI/180.0);
			
				/* Finding the balls final x coordinate */
				finalBallX = ballCenterX - (tan(radian)*wallHeight);

				/* Finding the start and end coordinates of the goal */
				goalFirstX = (wallWidth/2) - (goalWidth/2); 
				goalSecondX = (wallWidth/2) + (goalWidth/2);

				/* If ball's x value is in the range goalFirst's and */
				/* goalSecond's x value then it is a goal, set return value */
				/* to one */
				if (goalFirstX<=finalBallX && goalSecondX>=finalBallX)
				{
					returnValue = 1;
				}
			
				/* Else it isn't goal, return 0 */
				else
				{
					returnValue = 0;
				}
			}
		}

	
	
		else if (kickAngle<90)
		{
			/* Converting degrees to radians */
			radian = (180.0-kickAngle) * (PI/180.0);


			/* Checking if tangent angle of ballCenter lesser than wallHeight */
			/* Multiplication of tangent(radian) and ballCenter gives the */
			/* ball's distance on y axis until it hits the wall 
			/* If wallHeight is bigger then ball is gonna travel through */
			/* the wall on it's way */
			if (tan(radian)*(wallWidth-ballCenterX) < wallHeight)
			{
				/* Setting parameters for the next function call which is the */
				/* recursive part */
					
				/* Substracting the ball's path through y axis from total */
				/* height of the wall */
				wallHeight = wallHeight - (tan(radian)*(wallWidth-ballCenterX));
			
				/* New kickAngle will be supplementary of the former angle */
				/* Also reflection function will add an random integer */
				/* between */
				/* -5 and +5 for the reflection angle */
				kickAngle = reflection(180.0-kickAngle);
			
				/* Ball just hit the right side of the wall therefore center */
				/* x is equals to wallWidth which means it's on the right edge of */
				/* the game board right now */
				ballCenterX = wallWidth;
				
				/* Changing back the wall sizes to the given sizes to call */
				/* the function to do recursive calculation */
				wallHeight = wallHeight + ballRadius;
				wallWidth = wallWidth + (2 * ballRadius);
			
				/* Return value equals to the result of next hit which means */
				/* the next disc kick from the adjusted location */
				returnValue = kickDisc(wallWidth,wallHeight,ballCenterX,kickAngle,
				ballRadius,goalWidth);
			}
		
			else
			{
				/* Converting degrees to radians */
				radian = (90 - kickAngle) * (PI/180.0);

				/* Finding the balls final x coordinate */
				finalBallX = ballCenterX + (tan(radian)*wallHeight);

				/* Finding the start and end coordinates of the goal */
				goalFirstX = (wallWidth/2) - (goalWidth/2); 
				goalSecondX = (wallWidth/2) + (goalWidth/2);

				/* If ball's x value is in the range goalFirst's and goalSecond's */
				/* x value then it is a goal, set return value to one */
				if(goalFirstX<=finalBallX && goalSecondX>=finalBallX)
				{
					returnValue = 1;
				}
			
				/* Else it isn't goal, return 0 */
				else
				{
					returnValue = 0;
				}
			}
		}
	
		/* If kick angle is 90 degrees */
		else if (kickAngle==90)
		{
			/* Finding the start and end coordinates of the goal */
			goalFirstX = (wallWidth/2) - (goalWidth/2);
			goalSecondX = (wallWidth/2) + (goalWidth/2);
		
			/* If ball's x value is in the range goalFirst's and goalSecond's */
			/* x value then it is a goal, set return value to one */
			if(goalFirstX<=ballCenterX && goalSecondX>=ballCenterX)
			{
				returnValue = 1;
			}
		
			/* Else it isn't goal, return 0 */
			else
			{
				returnValue = 0;
			}
		}
	
		/* If kick angle is invalid */
		else
		{
			/* Return 0 directly */
			returnValue = 0;
		}
	}
	
	/* If inputs are invalid */
	else
	{
		returnValue = 0;
	}
	
	
	/* Returning the return value */
	return (returnValue);
}

/* End of HW07_151044001_Deniz_Can_Erdem_Yılmaz_part2.c */
