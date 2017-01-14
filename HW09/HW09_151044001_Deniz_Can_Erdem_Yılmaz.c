/*----------------------------------------------------------------------------*/
/* HW09_151044001_Deniz_Can_Erdem_Yılmaz                                      */
/* HW09_151044001_Deniz_Can_Erdem_Yılmaz.c                                    */
/* Created on 29/04/2016 by Deniz_Can_Erdem_Yılmaz                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This is the GIT's homework 9 for the CSE102 lecture. This program takes    */
/* orders from user to add a country to the strcut, compare area, military    */
/* power or try to find if a country is accessible from another               */
/*                                                                            */
/* Notes                                                                      */
/* -----                                                                      */
/* This file is written by considering the rules on code convention. So a row */
/* is max 80 column, tab width is 4 and coded with the desired code design    */
/*----------------------------------------------------------------------------*/


/* Include(s) */
#include<stdio.h>
#include <string.h>

/* Define(s) */
#define NAME_SIZE 25
#define MAX_NEIGHBOR 10
#define MAX_COUNTRY 100

/* Typedef(s)*/
typedef struct
{
	char name[NAME_SIZE];
	int population;
	double area;
	int military;
	char neighbor[MAX_NEIGHBOR][NAME_SIZE];
} country;



/* Function Prototypes                                                        */
/*----------------------------------------------------------------------------*/
/* void printPowerful(country country[])                                      */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
/* ----------                                                                 */
/* country[] - A country array of the countries                               */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* No return value due to void function, prints country with largest military */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes a country array and a country name as input inside it  */
/* then it look for the country, country's neighbor's and neighbor's of the   */
/* neighbors to find the largest number of the military in a vicinity         */
/*----------------------------------------------------------------------------*/
void printPowerful(country country[]);

/*----------------------------------------------------------------------------*/
/* void printLargest(country country[])                                       */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
/* ----------                                                                 */
/* country[] - A country array of the countries                               */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* No return value due to void function, prints country with largest area     */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes a country array and a country name as input inside it  */
/* then it look for the country, country's neighbor's and neighbor's of the   */
/* neighbors to find the largest area in a vicinity                           */
/*----------------------------------------------------------------------------*/
void printLargest(country country[]);

/*----------------------------------------------------------------------------*/
/* void totalPeople(country country[])                                        */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
/* ----------                                                                 */
/* country[] - A country array of the countries                               */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* No return value due to void function, prints people seen through the way   */
/* or 'inaccessible'                                                          */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes a country array and 2 country names as inputs inside   */
/* it to check if second country is reachable from the first by travelling    */
/* through their neighbors. If it is acceessible it prints how many people    */
/* has seen on the road else it prints inaccessible as an error message       */
/*----------------------------------------------------------------------------*/
void totalPeople(country country[]);

/*----------------------------------------------------------------------------*/
/* void structInitializer(country country[])                                  */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
/* ----------                                                                 */
/* country[] - A country array of the countries                               */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* No return value due to void function                                       */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes a country array to initialize its all components as    */
/* starting values as null and -1                                             */
/*----------------------------------------------------------------------------*/
void structInitializer(country country[]);

/*----------------------------------------------------------------------------*/
/* country addCountry(void)                                                   */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
/* ----------                                                                 */
/* None                                                                       */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* A country variable created upon user's inputs                              */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes a couple of informations about a country to create     */
/* edit its entry on the country list                                         */
/*----------------------------------------------------------------------------*/
country addCountry(void);

/*----------------------------------------------------------------------------*/
/* int countryControl(country country[],char name[])                          */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
/* ----------                                                                 */
/* country[] - A country array of the countries                               */
/* name[]    - A string array to indicate name of a country                   */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* -1 if country does not exist                                               */
/* Index of the country if it exist                                           */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This function takes a country name and country array to check if there is  */
/* any registy about that country. If there is it returns the index of the    */
/* country on the country list else returns -1                                */
/*----------------------------------------------------------------------------*/
int countryControl(country country[],char name[]);

/*----------------------------------------------------------------------------*/
/* int recHelper(country country[],char source[],char target[],int people)    */
/* ---------------------------                                                */
/*                                                                            */
/* Parameters                                                                 */
/* ----------                                                                 */
/* country[] - A country array of the countries                               */
/* source[]  - A string array to indicate name of the source country          */
/* target[]  - A string array to indicate name of the target country          */
/* people    - Number of people seen                                          */
/*                                                                            */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/* -1 if country does not exist                                               */
/* Index of the country if it exist                                           */
/*                                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/* This is a helper function for the totalPeople function for its recursion   */
/*----------------------------------------------------------------------------*/
int recHelper(country country[],char source[],char target[],int people);



int main()
{
	/* User's order */
	char userInput;
	
	/* Loop control variable */
	int i;
	
	/* Creating an array with country type elements */
	country countryBalls[MAX_COUNTRY];
	
	/* Initializing country array */
	structInitializer(countryBalls);

	/* Initializing user input and loop control variable for the loop */
	i = 0; 
	userInput = 'z';
	
	/* Continue until user types e letter */
	while (userInput != 'e')
	{
		/* Taking user's order */
		printf ("Make your choice:\n");
		scanf (" %c",&userInput);
		
		/* Calling the appropriate function for order */
		switch (userInput)
		{
			case 'a': countryBalls[i] = addCountry(); i = i + 1; break;
			case 'b': printPowerful(countryBalls); break;
			case 'c': printLargest(countryBalls); break;
			case 'd': totalPeople(countryBalls); break;
			case 'e': printf ("Good bye\n");
			default: break;
		}
	}
	
	return (0);
}



/* Function Implementation(s)                                                 */
/*----------------------------------------------------------------------------*/
/* Function recHelper                                                         */
/* -------------                                                              */
/* This function calls itself again and again until a base condition has      */
/* found to make recursion. It will sum up all people given in until error    */
/* value (-1) has been returned from any of them. Otherwise it will return    */
/* total people seen on the way                                               */
/*----------------------------------------------------------------------------*/
int recHelper(country country[],char source[],char target[],int people)
{
	/* Loop control variable*/
	int i;
	
	/* Source country's index number */
	int sourceIndex;
	
	/* Target country's index number */
	int targetIndex;
	
	/* Max population of the countries entered */
	int maxPopulation;
	
	/* Temporary minimum people varaible to find minimum people seen */
	int minPeople;
	
	/* Neighbor index variable */
	int neighborIndex;
	
	/* Return value variable */
	int returnValue;
	
	/* Temporary people variable to find minimum */
	int tempPeople;
	
	
	/* Initializing maxPopulation as 0 to count every populations on the */
	/* country list */
	maxPopulation = 0;

	
	/* Finding the maximum population on the country list with a loop */
	for (i=0;i<MAX_COUNTRY;i++)
	{
		/* If population isn't equals to -1 then it means country struct */
		/* created so count its population */
		if (country[i].population != -1)
		{
			/* Adding country's population to max population */
			maxPopulation = maxPopulation + country[i].population;
		}
	}
	
	/* Initializing minPeople as maxPopulation plus 1 to change it when a */
	/* lesser neighbor population found. If it needs to go through all */
	/* countries to reach the target country then minimum value will equals */
	/* to maxPopulation. So adding 1 to avoid conflictions */
	minPeople = maxPopulation + 1;

	/* Finding the indexes of source and target countries */
	sourceIndex = countryControl(country,source);
	targetIndex = countryControl(country,target);
	
	
	/* There are some conditions to let the function return -1 which means */
	/* target country is an inaccessible country. So if poepole seen has */
	/* passed the total number of the populations it means one or more */
	/* countries count twice while going to destinated country. But even if */
	/* it gets to go through every country to reach destination people seen */
	/* couldn't pass the maximum people entered. Another condition is target */
	/* and source country's have to be on the country list. So if their index */
	/* is not on the list (which means countryControl returns 0) it also */
	/* indicates target is inaccessible. Another condition is if source */
	/* country has no neighbors it also needs to return -1. But if source */
	/* country equals to target country then there is no need to check theese */
	/* conditions so it comes with an and condition */
	if ((people>maxPopulation || sourceIndex==-1 || targetIndex==-1 || 
	strcmp(country[sourceIndex].neighbor[0]," ")==0) && 
	strcmp(source,target) != 0)
	{
		returnValue = -1;
	}
	
	/* Here is the base condition for the recursion. If source country equals */
	/* to the destinated country which is target country then return the */
	/* people seen through the way and add the last country's population too */
	else if (strcmp(source,target)==0)
	{
		returnValue = people + country[targetIndex].population;
	}
	
	/* Here is the recursive part */
	else
	{
		/* Adding population of source country to the people seen */
		people = people + country[sourceIndex].population;
		
		/* Creating a loop to check all of source countries' neighbors to see */
		/* if target country is reachable */
		for (i=0;i<MAX_COUNTRY;i++)
		{
			/* Finding the country index of the i indexed neighbor */
			neighborIndex = countryControl(country,country[sourceIndex].neighbor[i]);
			printf ("Asd:%d\n",neighborIndex);
			/* Callin function again and assigning the return value to */
			/* tempPeople to check if it is a valid value */
			/* tempPeople = recHelper(country,country[neighborIndex].name,target,people); */
			
			/* If return came from recursive function is lesser than any */
			/* other one came from that loop it will change minimum value of */
			/* people seen if it is not equals to -1 which means it is an */
			/* invalid value so don't count it on */
			if (tempPeople<minPeople && tempPeople!=-1)
			{
				minPeople = tempPeople;
			}
		}
		
		/* After the loop if min people has changed then there is a valid */
		/* people value came from neighbors. So return that people value */
		/* to the caller function */
		if (minPeople != maxPopulation+1)
		{
			returnValue = minPeople;
		}
		
		/* If minPeople hasn't changed then it means all neighbors returned */
		/* -1 value which means target is inaccessible so return -1 */
		else
		{
			returnValue = -1;
		}
	}


	/* Returning the return value */
	return (returnValue);
}



/*----------------------------------------------------------------------------*/
/* Function structInitializer                                                 */
/* -------------                                                              */
/* This function sets all numbers as -1 and name as null to avoid any         */
/* conflictions during the function calls especially on the recursion         */
/*----------------------------------------------------------------------------*/
void structInitializer(country country[])
{
	/* Loop control variable */
	int i;
	
	for (i=0;i<MAX_COUNTRY;i++)
	{
		country[i].name[0] = '\0';
		country[i].population = -1;
		country[i].area = -1;
		country[i].military = -1;
	}
	
	return;
}



/*----------------------------------------------------------------------------*/
/* Function countryControl                                                    */
/* -------------                                                              */
/* This function increases index number until any name element of the country */
/* variale will match with the given name string. If there is a match then it */
/* will return the index to indicate the index of the country that given.     */
/* Otherwise it will retun -1 to indicate there is no registry for the country*/
/*----------------------------------------------------------------------------*/
int countryControl(country country[],char name[])
{
	/* Loop control variable */
	int i;

	/* Variable for return value which indicates the index of country */
	int returnValue;
	
	
	/* Setting return value to -1 as default. Return of this value means */
	/* there is no match */
	returnValue = -1;
	
	
	/* Creating a loop to check every single name element to see if given */
	/* country is created */
	for (i=0;i<MAX_COUNTRY;i++)
	{
		/* If a match has found */
		if (strcmp(country[i].name,name)==0)
		{
			/* Return the index of the country */
			returnValue = i;
		}
	}
	
	/* If country name is blank return -1 */
	if (strcmp(name," ") == 0 )
	{
		returnValue = -1;
	}
	
	/* Returning the return value */
	return (returnValue);
}



/*----------------------------------------------------------------------------*/
/* Function addCountry                                                        */
/* -------------                                                              */
/* This function takes inputs from user to give a form to a country variable  */
/* after creating the country variable then it returns to the main function   */
/* to equilize it to the country on the list                                  */
/*----------------------------------------------------------------------------*/
country addCountry(void)
{
	/* Loop control variable */
	int i;
	
	/* Input variable for ending loop */
	int input;

	/* Creating a new country variable */
	country newCountry;
	
	
	/* Setting i as 0 to use in loop */
	i = 0;
	
	
	/* Taking country's name */
	printf ("Country name: "); /* KALDIR */
	scanf ("%s",newCountry.name);
	
	/* Taking country's population */
	printf ("Country population: "); /* KALDIR */
	scanf ("%d",&newCountry.population);
	
	/* Taking country's area */
	printf ("Country area: "); /* KALDIR */
	scanf ("%lf",&newCountry.area);
	
	/* Taking country's military power */
	printf ("Country military: "); /* KALDIR */
	scanf ("%d",&newCountry.military);


	/* Creating a loop for taking neighbors maximum to 10 */
	while (i<MAX_NEIGHBOR)
	{
		printf("Country neighbor: "); /* KALDIR */
		
		/* If input equals to an integer control it to end loop */
		if (scanf("%d",&input)==1)
		{
			/* If input is -1 end the loop otherwise keep taking inputs */
			/* Also set last element of the array as NULL */
			if (input==-1)
			{
				/* Setting i in out of range to end loop */
				for (i=i;i<MAX_NEIGHBOR;i++)
				{
					/* Setting all other elements as blank */
					strcpy(newCountry.neighbor[i] ," ");
				}
			}
		}
		
		/* If input is not integer continue from here */
		else
		{
			/* Taking a string input to newCountry's neighbor component to */
			/* neighbor array indexed as i */
			scanf("%s",newCountry.neighbor[i]);
			
			/* Increasing i to count neighbors and set them in different */
			/* indexes in the neighbor array */
			i = i + 1 ;
		}
	}


	/* Returning the new country that just created to caller function */
	return (newCountry);
}



/*----------------------------------------------------------------------------*/
/* Function printLargest                                                      */
/* -------------                                                              */
/* This function takes input from user to the find largest country in terms   */
/* of land it possesses in vicinity of a given country                        */
/*----------------------------------------------------------------------------*/
void printLargest(country country[])
{
	/* Maximum are found */
	double maxArea;
	
	/* Largest area's index */
	int maxIndex;
	
	/* Loop control variables */
	int i;
	int j;
	int k;
	
	/* Country index */
	int firstCountryIndex;
	int secondCountryIndex;
	int thirdCountryIndex;
	
	/* Country to find largest area in vicinity of it */
	char userInput[NAME_SIZE];
	
	
	/* Setting maximum area and index variables to values they can't take */
	/* to force them change on the loop */
	maxArea = -1;
	maxIndex = -1;
	
	/* Taking the country to make area control */
	scanf("%s",userInput);
	
	/* Finding the country's index */
	firstCountryIndex = countryControl(country,userInput);
	
	/* If country found, index will be different than -1 */
	if (firstCountryIndex != -1)
	{
		/* Setting maxArea's first value as the given country's area and */
		/* maxIndex as country's index */
		maxArea = country[firstCountryIndex].area;
		maxIndex = firstCountryIndex;
		
		/* Creating a loop to control neighbors of country */
		for (i=0;i<MAX_NEIGHBOR;i++)
		{
			/* Finding if there is information about the neighbor country */
			secondCountryIndex = countryControl(country,
			country[firstCountryIndex].neighbor[i]);
			
			/* If neighbor informations exist control the areas */
			if (secondCountryIndex != -1)
			{
				/* If neighbor's area is bigger than maximum area */
				if (country[secondCountryIndex].area>maxArea)
				{
					/* Set maxArea as neighbor's area and maxIndex as */
					/* neighbor's index */
					maxArea = country[secondCountryIndex].area;
					maxIndex = secondCountryIndex;
				}
			}
			
			/* Creating another loop inside the loop to control neighbors */
			/* of neighbors */
			for (j=0;j<MAX_NEIGHBOR;j++)
			{
				/* Finding if there is information about the neighbor country */
				thirdCountryIndex = countryControl(country,
				country[secondCountryIndex].neighbor[j]);
				
				/* If neighbor informations exist control the areas */
				if (thirdCountryIndex != -1)
				{
					/* If neighbor's area is bigger than maximum area */
					if (country[thirdCountryIndex].area>maxArea)
					{
						/* Set maxArea as neighbor's area and maxIndex as */
						/* neighbor's index */
						maxArea = country[thirdCountryIndex].area;
						maxIndex = thirdCountryIndex;
					}
				}
			}
		}
	}
	
	
	/* If there is no entry for given country then check for the neighbor */
	/* informations */
	else
	{
		/* Create a loop to search all countries */
		for (i=0;i<MAX_COUNTRY;i++)
		{
			/* Search for all their neighbors */
			for (j=0;j<MAX_NEIGHBOR;j++)
			{
				/* If any neighbor matches with given country then check */
				/* for the max area in vicinity */
				if (strcmp(country[i].neighbor[j],userInput)==0)
				{
					/* If given country has found in a neighbor contribution */
					/* then the owner of the neighbors and it's neighbors */
					/* will be the the neighbor of neighbors of given country */
					if (country[i].area>maxArea)
					{
						/* If owner of the neighborhood of the given */
						/* country's area is bigger than max area set the */
						/* max area as country's area and max index as the */
						/* index of country */
						maxArea = country[i].area;
						maxIndex = i;
					}
					
					/* Checking the neighbors of neighbors of the country */
					for (k=0;k<MAX_NEIGHBOR;k++)
					{
						/* Finding the index of ccountry */
						secondCountryIndex = countryControl(country,
						country[i].neighbor[k]);
						
						/* If country found inside the entries */
						if (secondCountryIndex != -1)
						{
							/* If neighbor's area is bigger than maximum area */
							if (country[secondCountryIndex].area>maxArea)
							{
								/* Set maxArea as neighbor's area and */
								/* maxIndex as neighbor's index */
								maxArea = country[secondCountryIndex].area;
								maxIndex = secondCountryIndex;
							}
						}
					}
				}
			}
		}
	}
	
	
	/* If max index is not changed then print error message */
	if (maxIndex == -1)
	{
		printf ("INACCESSIBLE\n");
	}
	
	/* Otherwise print the largest country */
	else
	{
		printf ("%s\n",country[maxIndex].name);
	}
	
	return;
}



/*----------------------------------------------------------------------------*/
/* Function printPowerfu                                                      */
/* -------------                                                              */
/* This function takes input from user to the find the most powerful country  */
/* of military strength in vicinity of a given country                        */
/*----------------------------------------------------------------------------*/
void printPowerful(country country[])
{
	/* Maximum are found */
	int maxMilitary;
	
	/* Largest military's index */
	int maxIndex;
	
	/* Loop control variables */
	int i;
	int j;
	int k;
	
	/* Country index */
	int firstCountryIndex;
	int secondCountryIndex;
	int thirdCountryIndex;
	
	/* Country to find largest military in vicinity of it */
	char userInput[NAME_SIZE];
	
	
	/* Setting maximum military and index variables to values they can't take */
	/* to force them change on the loop */
	maxMilitary = -1;
	maxIndex = -1;
	
	/* Taking the country to make military power control */
	scanf("%s",userInput);
	
	/* Finding the country's index */
	firstCountryIndex = countryControl(country,userInput);
	
	
	/* If country found, index will be different than -1 */
	if (firstCountryIndex != -1)
	{
		/* Setting maxMilitary's first value as the given country's military */
		/* number maxIndex as country's index */
		maxMilitary = country[firstCountryIndex].military;
		maxIndex = firstCountryIndex;
		
		/* Creating a loop to control neighbors of country */
		for (i=0;i<MAX_NEIGHBOR;i++)
		{
			/* Finding if there is information about the neighbor country */
			secondCountryIndex = countryControl(country,
			country[firstCountryIndex].neighbor[i]);
			
			/* If neighbor informations exist control the military powers */
			if (secondCountryIndex != -1)
			{
				/* If neighbor's military is bigger than maximum military */
				if (country[secondCountryIndex].military>maxMilitary)
				{
					/* Set maxMilitary as neighbor's military and maxIndex as */
					/* neighbor's index */
					maxMilitary = country[secondCountryIndex].military;
					maxIndex = secondCountryIndex;
				}
			}
			
			/* Creating another loop inside the loop to control neighbors */
			/* of neighbors */
			for (j=0;j<MAX_NEIGHBOR;j++)
			{
				/* Finding if there is information about the neighbor country */
				thirdCountryIndex = countryControl(country,
				country[secondCountryIndex].neighbor[j]);
				
				/* If neighbor informations exist control the military powers */
				if (thirdCountryIndex != -1)
				{
					/* If neighbor's military is bigger than maximum military */
					if (country[thirdCountryIndex].military>maxMilitary)
					{
						/* Set maxMilitary as neighbor's military and */
						/* maxIndex as neighbor's index */
						maxMilitary = country[thirdCountryIndex].military;
						maxIndex = thirdCountryIndex;
					}
				}
			}
		}
	}
	
	
	
	/* If there is no entry for given country then check for the neighbor */
	/* informations */
	else
	{
		/* Create a loop to search all countries */
		for (i=0;i<MAX_COUNTRY;i++)
		{
			/* Search for all their neighbors */
			for (j=0;j<MAX_NEIGHBOR;j++)
			{
				/* If any neighbor matches with given country then check */
				/* for the max military in vicinity */
				if (strcmp(country[i].neighbor[j],userInput)==0)
				{
					/* If given country has found in a neighbor contribution */
					/* then the owner of the neighbors and it's neighbors */
					/* will be the the neighbor of neighbors of given country */
					if (country[i].military>maxMilitary)
					{
						/* If owner of the neighborhood of the given */
						/* country's military is bigger than max military set */
						/* the max military as country's military and max */
						/* index as the index of country */
						maxMilitary = country[i].military;
						maxIndex = i;
					}
					
					/* Checking the neighbors of neighbors of the country */
					for (k=0;k<MAX_NEIGHBOR;k++)
					{
						/* Finding the index of ccountry */
						secondCountryIndex = countryControl(country,
						country[i].neighbor[k]);
						
						/* If country found inside the entries */
						if (secondCountryIndex != -1)
						{
							/* If neighbor's military is bigger than maximum */
							/* military */
							if (country[secondCountryIndex].military>
							maxMilitary)
							{
								/* Set maxMilitary as neighbor's military and */
								/* maxIndex as neighbor's index */
								maxMilitary = country[secondCountryIndex]
								.military;
								maxIndex = secondCountryIndex;
							}
						}
					}
				}
			}
		}
	}
	
	
	/* If max index is not changed then print error message */
	if (maxIndex == -1)
	{
		printf ("INACCESSIBLE\n");
	}
	
	/* Otherwise print the largest country */
	else
	{
		printf ("%s\n",country[maxIndex].name);
	}
	
	
	return;
}



/*----------------------------------------------------------------------------*/
/* Function totalPeople                                                       */
/* -------------                                                              */
/* This function takes 2 inputs from user to find is second country is        */
/* reachable from the first country by travelling through the neighbors of    */
/* the first one and their neighbors and so on. If it is reachable it prints  */
/* how many people would seen on the way to the destination else it prints    */
/* inaccessible as an error message                                           */
/*----------------------------------------------------------------------------*/
void totalPeople(country country[])
{
	/* Return value variable */
	int returnValue;
	
	/* Source country */
	char userInput1[NAME_SIZE];
	
	/* Target country */
	char userInput2[NAME_SIZE];
	
	/* First people number to send recursive function */
	int people;
	
	
	/* Setting return value as -1. If countries does not exist then this */
	/* will stay as -1 and cause program to print error message */
	returnValue = -1;
	
	/* Initializing people number as 0 */
	people = 0;
	
	/* Taking source and target country names as inputs */
	scanf ("%s",userInput1);
	scanf ("%s",userInput2);
	
	
	/* If target and source countries are found on the country list then */
	/* countryControl will return integers different than -1. Countinue */
	/* with if statment if countries exists */
	if ((countryControl(country,userInput1) != -1) && 
	(countryControl(country,userInput2) != -1))
	{
		returnValue = recHelper(country,userInput1,userInput2,people);
	}
	
	
	/* If return value equals to -1 then it means program couldn't reach to */
	/* the target country from source country. So print error message */
	if (returnValue == -1)
	{
		printf ("INACCESSIBLE\n");
	}
	
	/* If returnValue is different than -1 it means target country has been */
	/* reached and total people seen returned from the recHelper function */
	/* So print how many people has seen */ 
	else
	{
		printf ("%d\n",returnValue);
	}
}

/* End of HW09_151044001_Deniz_Can_Erdem_Yılmaz.c */
