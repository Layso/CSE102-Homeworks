/*----------------------------------------------------------------------------*/
/*                                                                            */
/* HW10_151044001_Deniz_Can_Erdem_Yılmaz                                      */
/* HW10_151044001_Deniz_Can_Erdem_Yılmaz.c                                    */
/* Created on 04/05/2016 by Deniz_Can_Erdem_Yılmaz                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This is the GIT's homework 10 for the CSE102 lecture. This program takes   */
/* an binary input file, writes all data to structures and then creates a new */
/* human readable text file with some summary information                     */
/*                                                                            */
/* Notes                                                                      */
/* -----                                                                      */
/* This file is written by considering the rules on code convention. So a row */
/* is max 80 column, tab width is 4 and coded with the desired code design    */
/*                                                                            */
/*----------------------------------------------------------------------------*/


/* Include(s) */
#include<stdio.h>
#include<string.h>


/* Define(s) */
#define STRING_SIZE 30
#define ARRAY_SIZE 20
#define DAY_SIZE 7
#define INPUT_FILE "input.dat"
#define OUTPUT_FILE "deneme.txt"


/* Typedef(s) */
typedef struct
{
	int ID;
	char name[STRING_SIZE];
	char surname[STRING_SIZE];
} student;


typedef struct
{
	char role[STRING_SIZE];
	int ID;
	char name[STRING_SIZE];
	char surname[STRING_SIZE];
} teacher;


typedef struct
{
	int code;
	char name[STRING_SIZE];
	int ID;
} lesson;


typedef struct
{
	char className[STRING_SIZE];
	char day[STRING_SIZE];
	int time;
	int duration;
	int code;
} schedule;


typedef struct
{
	int ID;
	int code;
} course;



/* Function Prototypes                                                        */
/*----------------------------------------------------------------------------*/
/* int lessonNumFinder(student *studentArr,course *courseArr,int i)           */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
/* ----------                                                                 */
/* *studentArr - Array that holds student informations                        */
/* *courseArr  - Array that holds course informations                         */
/* i           - Indicator of the student                                     */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Returns the number of the lessons student takes                            */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function searches for the all lessons student takes and then returns  */
/* that number                                                                */
/*----------------------------------------------------------------------------*/
int lessonNumFinder(student *studentArr,course *courseArr,int i);

/*----------------------------------------------------------------------------*/
/* int studentNumFinder(lesson *lessonArr,course *courseArr,int i)            */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
/* ----------                                                                 */
/* *lessonArr  - Array that holds lesson  informations                        */
/* *courseArr  - Array that holds course informations                         */
/* i           - Indicator of the lesson                                      */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* Returns the number of the students that takes the lesson                   */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function searches for the all students to find who takes the lesson   */
/* counts it and then returns the number of the students                      */
/*----------------------------------------------------------------------------*/
int studentNumFinder(lesson *lessonArr,course *courseArr,int i);

/*----------------------------------------------------------------------------*/
/* void teacherNameFinder(teacher *teacherArr,lesson *lessonArr,int i,        */
/* char *arr)                                                                 */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
/* ----------                                                                 */
/* *teacherArr - Array that holds teacher informations                        */
/* *lessonArr  - Array that holds lesson informations                         */
/* i           - Indicator of the lesson                                      */
/* *arr        - String pointer                                               */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* No return value due to void function, changes value of a string pointer    */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function finds the teacher who gives lectures of indicated lesson and */
/* changes string pointer's value to name of the teacher                      */
/*----------------------------------------------------------------------------*/
void teacherNameFinder(teacher *teacherArr,lesson *lessonArr,int i,char *arr);

/*----------------------------------------------------------------------------*/
/* void teacherSurnameFinder(teacher *teacherArr,lesson *lessonArr,int i,     */
/* char *arr)                                                                 */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
/* ----------                                                                 */
/* *teacherArr - Array that holds teacher informations                        */
/* *lessonArr  - Array that holds lesson informations                         */
/* i           - Indicator of the lesson                                      */
/* *arr        - String pointer                                               */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* No return value due to void function, changes value of a string pointer    */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function finds the teacher who gives lectures of indicated lesson and */
/* changes string pointer's value to surname of the teacher                   */
/*----------------------------------------------------------------------------*/
void teacherSurnameFinder(teacher *teacherArr,lesson *lessonArr,int i,
char *arr);

/*----------------------------------------------------------------------------*/
/* void dayFinder(schedule *scheduleArr,student *studentArr,course *courseArr */
/* ,int i,FILE *file,int *status)                                             */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
/* ----------                                                                 */
/* *scheduleArr - Array that holds schedule informations                      */
/* *studentArr  - Array that holds student informations                       */
/* *courseArr   - Array that holds course informations                        */
/* i            - Indicator of the student                                    */
/* *file        - Output file pointer                                         */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* No return value due to void function                                       */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function finds the days that student goes to lectures and writes them */
/* to the output file                                                         */
/*----------------------------------------------------------------------------*/
void dayFinder(schedule *scheduleArr,student *studentArr,course *courseArr,
int i,FILE *file);

/*----------------------------------------------------------------------------*/
/* int statusChange(int *flag,char *name)                                     */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
/* ----------                                                                 */
/* *flag - Array of the day status                                            */
/* *name - String for day name                                                */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* No return value due to void function                                       */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes status array of the days and a name of the day to      */
/* change the status of given day to 1                                        */
/*----------------------------------------------------------------------------*/
void statusChange(int *flag,char *name);

/*----------------------------------------------------------------------------*/
/* int statusCheck(int *flag,char *name)                                      */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
/* ----------                                                                 */
/* *flag - Array of the day status                                            */
/* *name - String for day name                                                */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* 1 if day status is 1                                                       */
/* 0 if day status is 0                                                       */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes status array of the days and a name of the day to      */
/* check if that day is printed or not                                        */
/*----------------------------------------------------------------------------*/
int statusCheck(int *flag,char *name);



int main()
{
	/* Source and target file pointers */
	FILE *srcFL;
	FILE *trgFL;
	
	/* Arrays for the structures */
	student studentArr[ARRAY_SIZE];
	teacher teacherArr[ARRAY_SIZE];
	lesson lessonArr[ARRAY_SIZE];
	schedule scheduleArr[ARRAY_SIZE];
	course courseArr[ARRAY_SIZE];
	
	/* Struct counts which indicate the array's sizes */
	int studentSize;
	int teacherSize;
	int lessonSize;
	int scheduleSize;
	int courseSize;
	
	/* Loop control variable */
	int i;
	
	/* Variables for file writing */
	char teacherName[STRING_SIZE];
	char teacherSurname[STRING_SIZE];
	
	
	/* Opening the input file */
	srcFL = fopen(INPUT_FILE,"rb");

	/* Checking if input file is valid */
	if (srcFL == NULL)
	{
		/* If file pointer equals to NULL print error message */
		printf ("File opening error.");
	}
	
	/* Else proccess the file */
	else
		{

		/* Taking the size of the students */
		fread(&studentSize,sizeof(int),1,srcFL);
		/* Taking a block of data to student structure */
		fread(studentArr,sizeof(student),studentSize,srcFL);
	
		/* Taking the size of the teachers */
		fread(&teacherSize,sizeof(int),1,srcFL);
		/* Taking a block of data to teacher structure */
		fread(teacherArr,sizeof(teacher),teacherSize,srcFL);
	
		/* Taking the size of the lessons */
		fread(&lessonSize,sizeof(int),1,srcFL);
		/* Taking a block of data to lesson structure */
		fread(lessonArr,sizeof(lesson),lessonSize,srcFL);
	
		/* Taking the size of the schedule */
		fread(&scheduleSize,sizeof(int),1,srcFL);
		/* Taking a block of data to schedule structure */
		fread(scheduleArr,sizeof(schedule),scheduleSize,srcFL);
	
		/* Taking the size of the courses */
		fread(&courseSize,sizeof(int),1,srcFL);
		/* Taking a block of data to course structure */
		fread(courseArr,sizeof(course),courseSize,srcFL);
	
		/* Closing the source file due to end of the formatted data */
		fclose(srcFL);
	
	
		/* Opening the output file */
		trgFL = fopen(OUTPUT_FILE,"w");
		
		/* Formatting first summary for output file */
		fprintf(trgFL,"Lectures-Lecturers\n");
		/* Creating a loop for printing the first summary */
		for (i=0;i<lessonSize;i++)
		{
			/* Calling helper functions to find teacher's name and surname */
			teacherNameFinder(teacherArr,lessonArr,i,teacherName); 
			teacherSurnameFinder(teacherArr,lessonArr,i,teacherSurname);
		
			fprintf(trgFL,"%s %s %s %d\n",lessonArr[i].name,teacherName,
			teacherSurname,studentNumFinder(lessonArr,courseArr,i));
		}
	
		/* Formatting second summary for output file */
		fprintf(trgFL,"\nStudent-Lecture\n");
		/* Creating a loop for printing the second summary */
		for (i=0;i<studentSize;i++)
		{
			fprintf(trgFL,"%d %s %s %d\n",studentArr[i].ID,studentArr[i].name,
			studentArr[i].surname,lessonNumFinder(studentArr,courseArr,i));
		}
	
		/* Formatting third summary for output file */
		fprintf(trgFL,"\nStudent-Day\n");
		/* Creating a loop for printing the third summary */
		for (i=0;i<studentSize;i++)
		{		
			fprintf(trgFL,"%d %s %s ",studentArr[i].ID,studentArr[i].name,
			studentArr[i].surname);
		
			/* Calling helper function to find lecture days of each student */
			dayFinder(scheduleArr,studentArr,courseArr,i,trgFL);
			fprintf(trgFL,"\n");
		}
		
		/* Closing the output file due to end of formatting summary */ 
		fclose(trgFL);
	}
	
	return (0);
}



/* Function Implementation(s)                                                 */
/*----------------------------------------------------------------------------*/
/* Function lessonNumFinder                                                   */
/* -------------                                                              */
/* This function takes student and course informations to find how many       */
/* lessons does student take and returns its number to the caller function    */
/*----------------------------------------------------------------------------*/
int lessonNumFinder(student *studentArr,course *courseArr,int i)
{
	/* Loop control variable */
	int k;
	
	/* Variable for return value */
	int returnValue;
	
	
	/* Initializing return value as 0 to count how many lessons does student */
	/* take */
	returnValue = 0;
	
	/* Creating a loop to check every course */
	for (k=0;k<ARRAY_SIZE;k++)
	{
		/* If there is a match for student ID on course struct increase the */
		/* returnValue */
		if (studentArr[i].ID == courseArr[k].ID)
		{
			/* Increasing the returnValue */
			returnValue = returnValue + 1;
		}
	}
	
	/* Returning the return value */
	return (returnValue);
}



/*----------------------------------------------------------------------------*/
/* Function studentNumFinder                                                  */
/* -------------                                                              */
/* This function takes student and course informations to find how many       */
/* students does take that lessons and returns its number to the caller       */
/* function                                                                   */
/*----------------------------------------------------------------------------*/
int studentNumFinder(lesson *lessonArr,course *courseArr,int i)
{
	/* Loop control variable */
	int k;
	
	/* Variable for return value */
	int returnValue;
	
	/* Initializing return value as 0 to count how many lessons does student */
	/* take */
	returnValue = 0;
	
	/* Creating a loop to check every course */
	for (k=0;k<ARRAY_SIZE;k++)
	{
		/* If there is a match for student ID on course struct increase the */
		/* returnValue */
		if (lessonArr[i].code == courseArr[k].code)
		{
			/* Increasing the returnValue */
			returnValue = returnValue + 1;
		}
	}
	
	/* Returning the return value */
	return (returnValue);
}



/*----------------------------------------------------------------------------*/
/* Function teacherNameFinder                                                 */
/* -------------                                                              */
/* This function takes teacher and lesson arrays and a pointer to find the    */
/* name of the teacher gives that lecture. Assigns name to the taken pointer  */
/* to return it                                                               */
/*----------------------------------------------------------------------------*/
void teacherNameFinder(teacher *teacherArr,lesson *lessonArr,int i,char *arr)
{
	/* Loop control variable */
	int k;

	/* Creating a loop to check every teacher */
	for (k=0;k<ARRAY_SIZE;k++)
	{
		/* If there is a match for lesson ID on teacher struct copy the */
		/* name string to the given pointer array */
		if (lessonArr[i].ID == teacherArr[k].ID)
		{
			/* Copying name to the pointer array */
			strcpy(arr,teacherArr[k].name);
		}
	}
	
	/* End the function */
	return;
}



/*----------------------------------------------------------------------------*/
/* Function teacherSurnameFinder                                              */
/* -------------                                                              */
/* This function takes teacher and lesson arrays and a pointer to find the    */
/* surname of the teacher gives that lecture. Assigns surname to the taken    */
/* pointer to return it                                                       */
/*----------------------------------------------------------------------------*/
void teacherSurnameFinder(teacher *teacherArr,lesson *lessonArr,int i,char *arr)
{
	/* Loop control variable */
	int k;
	
	/* Creating a loop to check every teacher */
	for (k=0;k<ARRAY_SIZE;k++)
	{
		/* If there is a match for lesson ID on teacher struct copy the */
		/* surname string to the given pointer array */
		if (lessonArr[i].ID == teacherArr[k].ID)
		{
			/* Copying surname to the pointer array */
			strcpy(arr,teacherArr[k].surname);
		}
	}
	
	/* End the function */
	return;
}



/*----------------------------------------------------------------------------*/
/* Function dayFinder                                                         */
/* -------------                                                              */
/* This function takes schedule, student and course arrays and a file pointer */
/* to find the given students days of school and write it to the given file   */
/*----------------------------------------------------------------------------*/
void dayFinder(schedule *scheduleArr,student *studentArr,course *courseArr,
int i,FILE *file)
{
	/* Loop control variables */
	int k;
	int j;
	
	/* Count variable to find how many days student goes to school */
	int count;
	
	/* Another variable to keep count value and compare it with its initial */
	/* value */
	int init;
		
	
	/* Initializing count as 0 to find how many days studeny goes to school */
	count = 0;

	
	/* Creating a loop to find count of days */
	for (k=0;k<ARRAY_SIZE;k++)
	{
		/* If student ID match with course ID it means student takes the */
		/* lesson so then check for the match of code of lesson on course and */
		/* schedule structs */
		if (studentArr[i].ID == courseArr[k].ID)
		{
			/* Creating a loop to find match of lesson codes */
			for (j=0;j<ARRAY_SIZE;j++)
			{
				/* If lesson codes matches increase count to find how many */
				/* days does student go to school */
				if (courseArr[k].code == scheduleArr[j].code)
				{
					/* Increasing the count */
					count = count + 1;
				}
			}
		}
	}
	
	/* Setting init variable to count's initial value */
	init = count;
	
	/* Creating a loop to find count of days */
	for (k=0;k<ARRAY_SIZE;k++)
	{
		/* If student ID match with course ID it means student takes the */
		/* lesson so then check for the match of code of lesson on course and */
		/* schedule structs */
		if (studentArr[i].ID == courseArr[k].ID)
		{
			/* Creating a loop to find match of lesson codes */
			for (j=0;j<ARRAY_SIZE;j++)
			{
				/* If lesson codes matches increase count to find how many */
				/* days does student go to school */
				if (courseArr[k].code == scheduleArr[j].code)
				{
					/* This if statement is for formatting the output text */
					/* If count is not equals to its initial value nor 0 */
					/* then print ',' to diverge the days on text */
					if (count>0 && count!=init)
					{
						fprintf (file,", ");
					}
					
					/* After the ',' control print the day of the course */
					fprintf(file,"%s",scheduleArr[j].day);					
					
					/* Decreasing the count to indicate days order */
					count = count - 1;
				}
			}
		}
	}
	
	/* End the function */
	return;
}



/*----------------------------------------------------------------------------*/
/* Function statusCheck                                                       */
/* -------------                                                              */
/* This function takes status array of the days and a name of the day to      */
/* check if that day is printed or not. If it is printed status of the day    */
/* will be 1 so statusCheck function returns 1 to indicate it. Otherwise it   */
/* returns 0 to indicate day has not printed yet and is printable to file     */
/*----------------------------------------------------------------------------*/
int statusCheck(int *flag,char *name)
{
	/* Variable for return value */
	int returnValue;
	
	returnValue = 0;
	
	int k;
	for (k=0;k<7;k++)
	{
		printf ("%d\n",flag[k]);
	}
	
	
	/* Finding which day is given */ 
	if (strcpy(name,"Mon") == 0)
	{
		/* Return value will be equal to the status */
		returnValue = flag[0];
	}
	
	else if (strcpy(name,"Tue") == 0)
	{
		/* Return value will be equal to the day's status */
		returnValue = flag[1];
	}
	
	else if (strcpy(name,"Wed") == 0)
	{
		/* Return value will be equal to the day's status */
		returnValue = flag[2];
	}

	else if (strcpy(name,"Thu") == 0)
	{
		/* Return value will be equal to the day's status */
		returnValue = flag[3];
	}
	
	else if (strcpy(name,"Fri") == 0)
	{
		/* Return value will be equal to the day's status */
		returnValue = flag[4];
	}
	
	else if (strcpy(name,"Sat") == 0)
	{
		/* Return value will be equal to the day's status */
		returnValue = flag[5];
	}
	
	else if (strcpy(name,"Sun") == 0)
	{
		/* Return value will be equal to the day's status */
		returnValue = flag[6];
	}
	
	printf ("Ret:%d\n",returnValue);
	return (returnValue);
}



/*----------------------------------------------------------------------------*/
/* Function statusChange                                                      */
/* -------------                                                              */
/* This function takes status array of the days and a name of the day to      */
/* change status to 1 to indicate program that day is already printed to the  */
/* file when it needed                                                        */
/*----------------------------------------------------------------------------*/
void statusChange(int *flag,char *name)
{
	/* Finding which day is given and changing its status value to 1 */
	if (strcmp("Mon",name) == 0)
	{
		flag[0] = 1;
	}

	else if (strcmp("Tue",name) == 0)
	{
		flag[1] = 1;
	}

	else if (strcmp("Wed",name) == 0)
	{
		flag[2] = 1;
	}

	else if (strcmp("Thu",name) == 0)
	{
		flag[3] = 1;
	}

	else if (strcmp("Fri",name) == 0)
	{
		flag[4] = 1;
	}

	else if (strcmp("Sat",name) == 0)
	{
		flag[5] = 1;
	}

	else if (strcmp("Sun",name) == 0)
	{
		flag[6] = 1;
	}
	
	return;
}
/* End of the HW10_151044001_Deniz_Can_Erdem_Yılmaz.c */
