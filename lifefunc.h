// Jonathan Brockett
// lifefunc.h
//		the header file for playlife.c

#define COLS 40
#define ROWS 40

char GameBoard[ROWS][COLS], GameReplica[ROWS][COLS], Another[ROWS][COLS];

void initialize();

void batch(char *file);

void interactive();

void simulate();

void display();

void play();

void interactive();

void homescreen();