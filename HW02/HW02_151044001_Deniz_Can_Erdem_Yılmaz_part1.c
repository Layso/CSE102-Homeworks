/*----------------------------------------------------------------------------*/
/* HW02_151044001_Deniz_Can_Erdem_Yılmaz                                      */
/* HW02_151044001_Deniz_Can_Erdem_Yılmaz_part1.c                              */
/* Created on 29/02/2016 by Deniz Can Erdem Yılmaz                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This c file contains the GIT's CSE102 Homework-2 Part-1                    */
/* The program intended to calculate the final note of 3 different students.  */
/* Students' all homework, midterm and final exam grades and weights taken    */
/* from the user as inputs and after the calculation the final note printed   */
/* to the screen to inform students                                           */
/*                                                                            */
/* Note(s)                                                                    */
/* -------                                                                    */
/* - Coding in this homework designed as the given code convention by         */
/*   teachers. Tab size is 4 and column limit in a row is 80                  */
/* - Function prototypes are given by teachers with HW definition PDF         */
/*----------------------------------------------------------------------------*/



/* Include(s) */
#include<stdio.h>



/* Function Prototype(s)                                                      */
/* ---------------------------------------------------------------------------*/
/* void calculateLastGrade()                                                  */
/*                                                                            */
/* Parameter(s)                                                               */
/* ------------                                                               */
/* None                                                                       */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* No return variable, prints the final notes                                 */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes 6 inputs from user which are homework, midterm and     */
/* final exam grades calculates the student's final grade and then prints the */
/* final grade                                                                */
/* ---------------------------------------------------------------------------*/
void calculateLastGrade();



int main()
{
	calculateLastGrade();
	calculateLastGrade();
	calculateLastGrade();
	return (0);
}



/* Function Implementation(s)                                                 */
/* ---------------------------------------------------------------------------*/
/* Function calculateLastGrade                                                */ 
/* ---------------------------                                                */
/* This function takes midterm, homework and a final exam grade and wight to  */
/* calculate the final note of a student                                      */
/* ---------------------------------------------------------------------------*/
void calculateLastGrade()
{
	/* These three variables are for the weights taken as inputs */
	double weightMidterm;
	double weightHomework;
	double weightFinal;
	
	/* These three variables are for the grades taken as input */
	double gradeMidterm;
	double gradeHomework;
	double gradeFinal;
	
	/* These four variables are for the calculation. User will only see the */
	/* last variable as output named totalGrade which represents the final */
	/* grade of the student */
	double gainMidterm;
	double gainHomework;
	double gainFinal;
	double totalGrade;
	
	
	/* Taking the inputs declared on upside */
	/* Midterm weight */
	printf ("Please enter the 1. midterm weight: ");
	scanf ("%lf",&weightMidterm);
	
	/* Homework weight */
	printf ("Please enter the 1. homework weight: ");
	scanf ("%lf",&weightHomework);
	
	/* Final exam weight */
	printf ("Please enter the final exam weight: ");
	scanf ("%lf",&weightFinal);
	
	/* Midterm grade */
	printf ("Please enter the 1. midterm grade: ");
	scanf ("%lf",&gradeMidterm);
	
	/* Homework grade */
	printf ("Please enter the 1. homework grade: ");
	scanf ("%lf",&gradeHomework);
	
	/* Final exam grade */
	printf ("Please enter the final exam grade: ");
	scanf ("%lf",&gradeFinal);
	
	
	
	/* Making the calclations */
	/* Calculation divided to 3 parts to avoid overflow of 80 characters */
	/* Each grades gain will be calculated on the following 3 lines */
	/* Sum of all gains will give the final grade */
	gainMidterm = (weightMidterm*gradeMidterm)/100;
	gainHomework = (weightHomework*gradeHomework)/100;
	gainFinal = (weightFinal*gradeFinal)/100;
	totalGrade = gainMidterm + gainHomework + gainFinal;
	
	/* Outputting the final grade with print function */
	printf ("Your final grade is: %f\n",totalGrade);
}

/* End of HW02_151044001_Deniz_Can_Erdem_Yılmaz_part1.c */