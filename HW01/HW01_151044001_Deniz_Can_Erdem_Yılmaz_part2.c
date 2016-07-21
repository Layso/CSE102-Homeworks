/*----------------------------------------------------------------------------*/
/* HW01_151044001_Deniz_Can_Erdem_Yılmaz                                      */
/* HW01_151044001_Deniz_Can_Erdem_Yılmaz_part2.c                              */
/* Created on 21/02/2016 by Deniz Can Erdem Yılmaz                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This c file contains the GIT's CSE102 Homework-1 Part-2                    */
/* The program intended to calculate the age of the user in day type for      */
/* the earth, year-month-day type for another planet described by the         */
/* user                                                                       */
/*                                                                            */
/* Note(s)                                                                    */
/* -------                                                                    */
/* - Coding in this homework designed as the given code convention by         */
/*   teachers. Tab size is 4 and column limit in a row is 80                  */
/* - A month is 30 days (standardazed), a year is still 365 days              */
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
/* No return variable, prints the users age under the given conditions        */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* The program takes the current date in order to calculate how many days     */
/* passed since the birth of Christ. And then takes users birth date to       */
/* calculate how many day passed when the user was born. Current total lived  */
/* days minus total lived days on the users birth date gives users age in     */
/* day type                                                                   */
/* ---------------------------------------------------------------------------*/


/* Function Implementation(s)                                                 */
/* ---------------------------------------------------------------------------*/
/* Function main                                                              */
/* -------------                                                              */
/* This homework does not require extra functions. All process will be done   */
/* in main function by taking inputs and making the calculations              */
/* ---------------------------------------------------------------------------*/
int main()
{
	/* Defining the inputs in groups in order to tell them apart from each    */
	/* other. First four variables are for the assigning current date's year, */
	/* month, day and total days lived until now. Other four are for the      */
	/* users birth date and how many days passed until user born. Next group  */
	/* of three variables are for the inputs to give form to another planet   */
	/* And the last six variables are for to assign results of calculations   */
	int yearCurrent;
	int monthCurrent;
	int dayCurrent;
	int currentDays;
	
	int yearBirth;
	int monthBirth;
	int dayBirth;
	int birthDays;
	
	int hoursOfDay;
	int daysOfMonth;
	int monthsOfYear;
	
	int yearPlanet;
	int monthPlanet;
	int dayPlanet;
	int hourPlanet;
	
	int totalDays;
	int totalHours;


	/* Takig the current date from user as years, months and days format */
	printf ("Please enter the current date.\n");
	printf ("Year:");
	scanf ("%d",&yearCurrent);
	printf ("Month:");
	scanf ("%d",&monthCurrent);
	printf ("Day:");
	scanf ("%d",&dayCurrent);
	
	/* Calculation for 'how many days equals to this date. A year is 365 days */
	/* and a month is 30 days. But current month and year is not over so we */
	/* need to subtract 1 from both of them */
	currentDays = dayCurrent + ((monthCurrent-1)*30) + ((yearCurrent-1)*365);
	
	
	/* Taking the birth date from user as years, months and days format */
	printf ("Please enter your birthday.\n");
	printf ("Year:");
	scanf ("%d",&yearBirth);
	printf ("Month:");
	scanf ("%d",&monthBirth);
	printf ("Day:");
	scanf ("%d",&dayBirth);
	
	/* Calculation for 'how many days equals to this date. A year is 365 days */
	/* and a month is 30 days. But current month and year is not over so we   */
	/* need to minus 1 from both of them */
	birthDays = dayBirth + ((monthBirth-1)*30) + ((yearBirth-1)*365);
	
	
	/* To calculate total days user lived we need to find the gap between     */
	/* current date and birth date. And printing the result                   */
	totalDays = currentDays-birthDays;
	printf ("You have lived %d days.\n",totalDays);
	
	
	
	/* And second part for the program we need user to define a planet        */
	/* Taking 'how many hours a day', 'how many days is a month' and 'how     */
	/* many months is a year' informations */
	printf ("Please enter about the time of another planet\n");
	printf ("How many hours is a day?");
	scanf ("%d",&hoursOfDay);
	printf ("How many days is a month?");
	scanf ("%d",&daysOfMonth);
	printf ("How many months is a year?");
	scanf ("%d",&monthsOfYear);
	
	
	/* To calculate the age in another planet we first need to how many hours */
	/* in a year on the planet (hourPlanet) and how many hours the user lived */
	/* (totalHours). Multiplying total days with 24 gives us totalHours. And  */
	/* multiplying the other planet's hour, day, month informations gives us  */
	/* hourPlanet. So if we divide totalHours to hourPlanet the quotient is   */
	/* how many years would user lived in the planet. The remainder still     */
	/* contains months and days. So we will divide the remainder to hours of  */
	/* a day times days of a month to find how many months would user lived   */
	/* in the planet. And again the remainder from last calculation will be   */
	/* divided by hours of a day to find how many days would user lived in    */
	/* planet                                                                 */
	totalHours = totalDays * 24;
	hourPlanet = hoursOfDay * daysOfMonth * monthsOfYear;
	yearPlanet = totalHours / (hourPlanet);
	monthPlanet = (totalHours%(hourPlanet)) / (hoursOfDay*daysOfMonth);
	dayPlanet = (totalHours%(hourPlanet))%(hoursOfDay*daysOfMonth)/(hoursOfDay);
	

	/* After the calculations printing the users age on other planet */
	printf ("If you lived in a planet where a day is %d hours, a month is %d " 
	"days and a year is %d months: you were %d years, %d months and %d days "
	"old\n",hoursOfDay,daysOfMonth,monthsOfYear,yearPlanet,monthPlanet,
	dayPlanet);	
	
	return (0);
}
/* End of HW01_151044001_Deniz_Can_Erdem_Yılmaz_part2.c */