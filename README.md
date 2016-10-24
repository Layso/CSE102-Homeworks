# CSE102-Homeworks
This repository contains all homeworks of the Gebze Institute of Technology, CSE 102 lecture, Spring 2016. Comments and coding style are edited before publishing but algorithm and coding kept same as the files sent to the teachers unless the code works. 
-
-
Homework #01
-

Part-1

Goal is calculating a student's final note by taking 3 midterm, 3 homework and a final exam weights and grades as inputs.

Part-2

First goal is calculating a persons age in day format. Second goal is calculating same person's age considering that the person is living in another planet and planet has different hour-day-month relation than Earth has.


-
Homework #02
-

Part-1

This part is similar to HW01 part1. Program intended to find the final note of a student by taking midterm, homework and final exam grade and weights as inputs. The difference is function has called three times to calculate 3 students final note.

Part-2

In this part program takes width and height informations from user and calculates the area and perimeter of certain geometric shapes.


-
Homework #03
-

Program asks users for an integer and checks if the number is an odd, a factorial or a narcissistic number, depending on the user choice.


Odd Number: Dividable by 2

Factorial Number: Multiplication of decreasing consecutive numbers from a number to 1

Narcissistic Number: A k-digit number n is called narcissistic if it is equal to the sum of k-th powers of its digits


-
Homework #04
-

Part-1

This part is a sine and cosine calculator by using the Taylor series.

Part-2

In this part program takes a number and a character as inputs from user and prints that number and a border written in that given character.


-
Homework #05
-

This program is the first part of a chess game. Functions in this program checks the validness of a piece's movement to a target cell on the chess board. Game will be completed in sooner homeworks. Due to the length of the homework, file divided into smaller files which contains group of related functions.

main.c

This file contains the functions completely given by teachers. main() function takes commands from user and makes proper function calls. emptyBuffer() function clears the buffer to take inputs without problems.

board.c

This file contains functions related to board. These functions initialize board at the starting position and prints the board.

helper.c

All the helper functions to check the validness of a piece (given by teachers or self written) are in this file.

pawn.c

Contains one function which checks the validness of a pawn's move.

rook.c

Contains one function which checks the validness of a rook's move.

knight.c

Contains one function which checks the validness of a knight's move.

bishop.c

Contains one function which checks the validness of a bishop's move.

queen.c

Contains one function which checks the validness of a queen's move.

king.c

Contains one function which checks the validness of a king's move.

This homework edited on 05.07.2016 due to an error on isBishopMovable() function.


-
Homework #06
-

Part-1

In this part of the homework, program will calculate the character frequency of a given string. It will handle only the ASCII letters and digits. Any other characters such as punctuation marks and whitespaces will not be considered.

Part-2

In this part, program will find the substring(s) in a given string. Instead of matching the exact substring, program will only match the odd indexed characters. 

Part-3

In this part, program will count the occurrences of a substring in the given string by using the matcher function on part2. Only odd indexed characters will match.
