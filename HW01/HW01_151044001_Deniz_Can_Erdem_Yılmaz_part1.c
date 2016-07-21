/*----------------------------------------------------------------------------*/
/* HW01_151044001_Deniz_Can_Erdem_Yılmaz                                      */
/* HW01_151044001_Deniz_Can_Erdem_Yılmaz.part1.c                              */
/* Created on 20/02/2016 by Deniz Can Erdem Yılmaz                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This c file contains the GIT's CSE102 Homework-1 Part-1                    */
/* The program intended to calculate the final note of a student              */
/* Student's all homework, midterm and final exam grades and weights taken    */
/* from the user as inputs and after the calculation the final note printed   */
/* to the screen to inform                                                    */
/*                                                                            */
/* Note(s)                                                                    */
/* -----                                                                      */
/* - Coding in this homework designed as the given code convention by         */
/*   teachers. Tab size is 4 and column limit in a row is 80                  */
/* - The calculation of final note should take only a single expression       */
/*----------------------------------------------------------------------------*/



/* Include(s) */
#include<stdio.h>



/* Function Prototype(s)                                                      */
/* ---------------------------------------------------------------------------*/
/* int main(void)                                                             */
/*                                                                            */
/* Parameter(s)                                                               */
/* ------------                                                               */
/* None                                                                       */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* No return variable, prints the final note                                  */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* There are 12 different inputs. 6 for grades and another 6 for weights      */
/* Each grade will be multiply with the percentage of its weight to calculate */
/* the incoming point from that grade. All earnings from grades will be added */
/* with each other to calculate the grand total                               */
/* ---------------------------------------------------------------------------*/



/* Function Implementation(s)                                                 */
/* ---------------------------------------------------------------------------*/
/* Function main                                                              */
/* -------------                                                              */
/* This homework does not require extra functions. All process will be done   */
/* in main function by taking inputs and making the calculation               */
/* ---------------------------------------------------------------------------*/
int main()
{
	/* 6 variables for midterm, homework and final weights, 6 variables   */
	/* for their grades and a variable for the calculated final note      */
	float MW1;
	float MW2;
	float MW3;
	float HW1;
	float HW2;
	float FW1;
	
	float MG1;
	float MG2;
	float MG3;
	float HG1;
	float HG2;
	float FG1;
	
	float total;
	
	
	/* Taking the first 6 input from user and assigning */
	/* them to the defined weight variables */
	printf ("Please enter the 1. midterm weight:");
	scanf ("%f",&MW1);
	printf ("Please enter the 2. midterm weight:");
	scanf ("%f",&MW2);
	printf ("Please enter the 3. midterm weight:");
	scanf ("%f",&MW3);
	printf ("Please enter the 1. homework weight:");
	scanf ("%f",&HW1);
	printf ("Please enter the 2. homework weight:");
	scanf ("%f",&HW2);
	printf ("Please enter the final exam weight:");
	scanf ("%f",&FW1);
	
	/* Taking the second 6 input from user and assigning */
	/* them to the defined grade variables */
	printf ("Please enter the 1. midterm grade:");
	scanf ("%f",&MG1);
	printf ("Please enter the 2. midterm grade:");
	scanf ("%f",&MG2);
	printf ("Please enter the 3. midterm grade:");
	scanf ("%f",&MG3);
	printf ("Please enter the 1. homework grade:");
	scanf ("%f",&HG1);
	printf ("Please enter the 2. homework grade:");
	scanf ("%f",&HG2);
	printf ("Please enter the final exam grade:");
	scanf ("%f",&FG1);
	
	
	/* The final grade asked to calculated in a single expression by teachers */
	/* Each grade is multiplied with its weight and divided by 100 to */
	/* calculatethe gain from each grade. Then all of them summed up to form */
	/* the final grade */
	total = ((MW1*MG1)+(MW2*MG2)+(MW3*MG3)+(HW1*HG1)+(HW2*HG2)+(FW1*FG1))/100;


	/* Printing the final result to the user */
	printf ("Your final grade is: %f\n",total);
	
	return (0);
}
/* End of HW01_151044001_Deniz_Can_Erdem_Yılmaz_part1.c */