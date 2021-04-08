// Jonathan Brockett
// playlife.c
//		the driver program for Conway's Game of Life.

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "lifefunc.h"

int main(int argc, char *argv[]) {
	char BoardTemp[ROWS][COLS];
	FILE *fp;

	initialize();

	if (argc == 2) { // batch mode
		fp = fopen(argv[1], "r");
		char *file = argv[1];
		if (!fp) {
			printf("file %s not found\n", argv[1]);
			return 1;
		}
		batch(file);
		return 0;
	}
	

	else if (argc == 1) { // interactive mode
		interactive();

	}
	else {
		printf("Error 342: too many arguments, only input one file.\n");
		return 1;
	}
	return 0;
}


void batch(char *file) {
	char temp;
	int a, b, x = 1;
	FILE *fp;

	fp = fopen(file, "r");

	while(x == 1) {
		fscanf(fp, "%c", &temp);
		if (isupper(temp))
			temp = tolower(temp);
		switch (temp) {
			case 'a':
				fscanf(fp, "%d %d", &a, &b);
				GameBoard[a][b] = 'X';
				break;
			case 'r':
				fscanf(fp, "%d %d", &a, &b);
				GameBoard[a][b] = 'O';
				break;
			case 'n':
				simulate();
				display();
				break;
			case 'q':
				x = 0;
				break;
			case 'p':
				play();
				x = 0;
				break;
		}
	}
}

void interactive() {
	int x = 1, a, b;
	char response;
	while(x == 1) {
		display();
		homescreen();
		response = getc(stdin);
		switch (response) {
			case 'a':
				scanf("%d %d", &a, &b);
				GameBoard[a][b] = 'X';
				break;
			case 'r':
				scanf("%d %d", &a, &b);
				GameBoard[a][b] = 'O';
				break;
			case 'n':
				simulate();
				display();
				break;
			case 'q':
				x = 0;
				break;
			case 'p':
				play();
				x = 0;
				break;
		}
	}
}

void play() {
	int X = 1;
	while(X == 1) { /* --stuff commented out because it'll stop after they become the same image repeatedly
		X = 0;
		for (int i = 0; i < ROWS; i++){
			for (int j = 0; j < COLS; j++) {
				if (GameBoard[i][j] != Another[i][j])
				X = 1;
			}
		} */
		display();
		usleep(200000);
		system("clear");
		simulate();
	}
}
