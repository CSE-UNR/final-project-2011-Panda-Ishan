//AUTHOR: ISHAN PANDA
//PROJECT: BATTLESHIP

#include<stdio.h>
#define NAME 256
#define EASY "easy.txt"
#define MEDIUM "medium.txt"
#define HARD "goodluckbud.txt"
#define DIM 10
//FUNCTIONS
char displaymenu();
char askdifficulty();
void clearscreen();
int loadDifficulty(char difficulty, char correctField[][DIM]);
void displayBoard(char correctField[][DIM]);
void getMove(int* colPtr, int* rowPtr, int* movesPtr);
int checkHit(int *colPtr, int *rowPtr,char correctField[][DIM], char playerField[][DIM], int hits);
int scoring(int moves, int hitsneeded);
void clear(char playerField[][DIM]);
//MAIN
int main(){
char correctField[DIM][DIM];
char playerField[DIM][DIM];
int colInd, rowInd;
char userinput = 'Y';
do{
int moves = 0;
int hits = 0;
clearscreen();
char difficulty = askdifficulty();
int hitsneeded = loadDifficulty(difficulty, correctField);
clearscreen();
clear (playerField);
printf("\n\n*****LET'S PLAY BATSHIP*****\n\n");


do{
	
	displayBoard(playerField);
	getMove(&colInd, &rowInd, &moves);
	hits = checkHit(&colInd, &rowInd, correctField, playerField, hits);
} while(hitsneeded != hits);
printf("CONGRATULATIONS!!!!\nIt took %d turns for you to hit %d spots and destroy all the ships\nYour score is %d!\n", moves, hitsneeded, scoring(moves, hitsneeded));
userinput = displaymenu();
} while (userinput != 'N');
return 0; //best practices
}



//END OF MAIN  










//DISPLAYMENU
char displaymenu(){
char userinput;
printf("Play again? (Y/N): ");
scanf(" %c", &userinput);
while(userinput != 'Y' && userinput != 'N'){
printf("Please enter a valid input: ");
scanf(" %c", &userinput);
}
return userinput;
}
//CLEAR SCREEN
void clearscreen(){
for(int i = 0; i<=100; i++){
printf("\n");
}
}
//DIFFICULTY
char askdifficulty(){
char difficulty;
printf("\nDifficulty (E for Easy, M for Medium, H for Hard): ");
scanf("%c", &difficulty);
while(difficulty != 'E' && difficulty != 'M'&& difficulty != 'H'){
printf("Please enter a valid input: ");
scanf("%c", &difficulty);
}
return difficulty;
}
//LOADBOARD
int loadDifficulty(char difficulty, char correctField[][DIM]){
FILE* fp;
int row = 0;
int hitsneeded = 0;
char temp;
if (difficulty == 'E'){
	fp = fopen(EASY, "r");
	hitsneeded = 31;
}
else if (difficulty == 'M') {
	fp = fopen(MEDIUM, "r");
	hitsneeded = 18;
}
else if (difficulty == 'H'){
	fp = fopen(HARD, "r");
	hitsneeded = 6;
}
if (fp == NULL){
	printf("Cannot load file. Exiting...");
	return 0;
}
for(int row = 0; row < DIM; row++){
for(int i = 0; i < DIM; i++){
	fscanf(fp, "%c", &correctField[row][i]);
	}
	fscanf(fp, "%c", &temp);
	}
fclose(fp);
return hitsneeded;
}

//DISPLAY BOARD
void displayBoard(char playerField[][DIM]){
printf("   A B C D E F G H I J\n");
for (int row = 0; row < DIM; row++){
if(row == 9){
printf("%d ", row + 1);
}
else{
printf("%d  ", row + 1);
}
for (int i = 0; i < DIM; i++){
printf("%c ", playerField[row][i]);
}
printf("\n");
}
printf("\n\n       FIRE AWAY!\n(enter a spot in the grid like A1) ");
}
//GET MOVE
void getMove(int* colPtr, int* rowPtr, int* movesPtr){
char Letter;
int number;
do{
scanf(" %c%d", &Letter, &number);
if ( Letter < 'A'||Letter > 'J'){
printf("\n\nInvalid column letter. Try again!\n(enter a spot in the grid like A1) ");
}
else if (number > 10 || number < 1){
printf("\n\nInvalid row number. Try again!\n(enter a spot in the grid like A1) ");
}
}
while(Letter > 'J' || Letter < 'A' || number > 10 || number < 1);
*rowPtr = number - 1;
*colPtr = (Letter - 'A');
(*movesPtr)++;
}

//CHECKHIT
int checkHit(int *colPtr, int *rowPtr,char correctField[][DIM], char playerField[][DIM], int hits){

if (correctField[*rowPtr][*colPtr] == 'S'){
if (playerField[*rowPtr][*colPtr] != 'X'){
playerField[*rowPtr][*colPtr] = 'X';
hits++;
}else{
playerField[*rowPtr][*colPtr] = 'X';
}
} else if (correctField[*rowPtr][*colPtr] == ' '){
playerField[*rowPtr][*colPtr] = 'O';
}
return hits;
}

//SCORE CALCULATION
int scoring(int moves, int hitsneeded){
int score = 100 - (moves - hitsneeded);
return score;
}

//CLEAR
void clear (char playerField[][DIM]){
for (int row = 0; row < DIM; row++){
for (int i = 0; i < DIM; i++){
playerField[row][i] = ' ';
}
}
}


/*Note: Considering this is the last project and assignment for the CS 135 term, I wanted to say thanks for the fun class and also the numerous jokes passed around. I didn't expect to laugh as much as I did during the labs and lecture and appreciated the thorough review as I don't think I would have understood pass by address without it or complete this project either. I'm not quite sure if I'll be taking another CS class in the future but if I do, I look forward to seeing you and Erin again! 

(I think Augustine will be the one reading this, but do forward my gratitude to Erin aswell and vice versa)*/










