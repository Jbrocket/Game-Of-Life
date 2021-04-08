// Jonathan Brockett
// lifefunc.c
//		defining the functions in playlife.c
#include <stdio.h>
#include "lifefunc.h"

void initialize() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
				GameReplica[i][j] = 'O';
				GameBoard[i][j] = 'O';
		}
	}
}

void homescreen() {
	printf("\n---------------Choose an Option---------------\n");
	printf("Enter an \"a\" followed by two numbers. These represent coordinates to place a block.\n");
	printf("Enter an \"r\" followed by two numbers. These represent coordinates to remove a block.\n");
	printf("Enter \"n\" to advance simulation to the next iteration.\n");
	printf("Enter \"q\" to quit out of the program.\n");
	printf("Enter \"p\" play the game continuously.\n");
}

void simulate() { /* advances program to next iteration */
	int iteration = 0;
	if (iteration % 2 == 0) {
		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLS; j++) 
				Another[i][j] = GameReplica[i][j];
		}
	}
	for (int i = 0; i < ROWS; i++) { /* Checks individual elements and around them */
		for (int j = 0; j < COLS; j++) {
			int count = 0;
			if ((i > 0) && (i < 39)) {
				if ((j > 0) && (j < 39)) {
					if (GameBoard[i-1][j] == 'X')
						count += 1;
					if (GameBoard[i+1][j] == 'X')
						count += 1;
					if (GameBoard[i][j-1] == 'X')
						count += 1;
					if (GameBoard[i][j+1] == 'X')
						count += 1;
					if (GameBoard[i+1][j+1] == 'X')
						count +=1;
					if (GameBoard[i-1][j+1] == 'X')
						count +=1;
					if (GameBoard[i-1][j-1] == 'X')
						count +=1;
					if (GameBoard[i+1][j-1] == 'X')
						count +=1;
				}
			}
			else if (i == 0) { /* Check around x when on top side of board */
				if (j == 0) {
					if (GameBoard[i+1][j] == 'X')
						count += 1;
					if (GameBoard[i][j+1] == 'X')
						count += 1;
					if (GameBoard[i+1][j+1] == 'X')
						count +=1;
				}
				else if (j == 39) {
					if (GameBoard[i+1][j] == 'X')
						count += 1;
					if (GameBoard[i][j-1] == 'X')
						count += 1;
					if (GameBoard[i+1][j-1] == 'X')
						count +=1;
				}
				else {
				if (GameBoard[i][j+1] == 'X')
					count += 1;
				if (GameBoard[i][j-1] == 'X')
					count += 1;
				if (GameBoard[i+1][j] == 'X')
					count += 1;
				if (GameBoard[i+1][j-1] == 'X')
						count +=1;
				if (GameBoard[i+1][j+1] == 'X')
						count +=1;
				}
			}
			else if (i == 39) { /* Check around 'X' when X is on bottom */
				if (j == 0) {
					if (GameBoard[i-1][j] == 'X')
						count += 1;
					if (GameBoard[i][j+1] == 'X')
						count += 1;
					if (GameBoard[i-1][j+1] == 'X')
						count +=1;
				}
				else if (j == 39) {
					if (GameBoard[i-1][j] == 'X')
						count += 1;
					if (GameBoard[i][j-1] == 'X')
						count += 1;
					if (GameBoard[i-1][j-1] == 'X')
						count +=1;
				}
				else {
					if (GameBoard[i][j+1] == 'X')
						count += 1;
					if (GameBoard[i][j-1] == 'X')
						count += 1;
					if (GameBoard[i-1][j] == 'X')
						count += 1;
					if (GameBoard[i-1][j+1] == 'X')
						count +=1;
					if (GameBoard[i-1][j-1] == 'X')
						count +=1;
				}
			}

			if (GameBoard[i][j] == 'X') { /* Make GameReplica based off of neighbors of Gameboard[i][j] */
				if ((count == 2) || (count == 3))
					GameReplica[i][j] = 'X';
				else
					GameReplica[i][j] = 'O';
			}
			if (GameBoard[i][j] != 'X') {
				if (count == 3) 
					GameReplica[i][j] = 'X';
			}
		}
	}
	iteration += 1;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) 
			GameBoard[i][j] = GameReplica[i][j];
	}
}

void display() { /* display each individual element, if they're not 'X', then puts a space instead */
	int count = 1;
	for (int i = 0; i < ROWS; i++){
		for (int j = 0; j < COLS; j++) {
			if (count % 40 == 0) { /* Modulus to keep each row at 40 COLS big */
				if (GameBoard[i][j] == 'X')
					printf("%c\n", GameBoard[i][j]);
				else
					printf(" \n");
			}
			else {
				if (GameBoard[i][j] == 'X')
					printf("%c", GameBoard[i][j]);
				else
					printf(" ");
			}
			count += 1;
		}
	}
}
