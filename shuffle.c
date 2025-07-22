/*
============================
   15-PUZZLE GAME INSTRUCTIONS
============================

How to Play:
------------
- The goal is to arrange the numbers in order from 1 to 15, with the empty space (0) at the bottom-right corner.
- Use the arrow keys on your keyboard to move the empty space:
    - Up Arrow    : Move the empty space up
    - Down Arrow  : Move the empty space down
    - Left Arrow  : Move the empty space left
    - Right Arrow : Move the empty space right
- Only tiles adjacent to the empty space can be moved.
- Each move increases your move count, shown at the bottom of the grid.
- When all numbers are in order, you win!
- Press 'Esc' to exit the game at any time.

Enjoy the challenge!
============================
*/
#include<stdio.h>
#include<dos.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

// Draws the puzzle grid using box-drawing characters
void boxes();
// Displays the current state of the puzzle
void display();
// Checks if the puzzle is solved and counts moves
void check();
// Gets a key press from the user (arrow keys, etc.)
int getkey();
void gotoxy(int x, int y);
void show_instructions();

int arr[4][4] = {
    {1,4,15,7},
    {8,10,2,11},
    {4,3,6,13},
    {2,9,5,0}
};

// Main function: handles game loop and user input for moving tiles
int main(){
    show_instructions(); // Show instructions at start
    int row = 3, col = 3, t, ch;
    boxes();      // Draw the puzzle grid
    display();    // Show initial puzzle state
    while(1){
        ch = getkey(); // Get user key press (fixed typo)
        switch(ch){
            case 80 : // Down arrow key
                if(row == 0){
                    printf("\a"); // Beep if move not possible
                    break;
                }
                t = arr[row][col];
                arr[row][col] = arr[row - 1][col];
                arr[row - 1][col] = t;
                row--;
                display();
                break;
            case 77 : // Right arrow key
                if(col == 0){
                    printf("\a");
                    break;
                }
                t = arr[row][col];
                arr[row][col] = arr[row][col - 1];
                arr[row][col - 1] = t;
                col--;
                display();
                break;
            case 72 : // Up arrow key
                if(row == 3){
                    printf("\a");
                    break;
                }
                t = arr[row][col];
                arr[row][col] = arr[row + 1][col];
                arr[row + 1][col] = t;
                row++;
                display();
                break;
            case 75 : // Left arrow key
                if(col == 3){
                    printf("\a");
                    break;
                }
                t = arr[row][col];
                arr[row][col] = arr[row][col + 1];
                arr[row][col + 1] = t;
                col++;
                display();
                break;
            case 1: // Exit key
                exit(0);    // Fixed exit usage
        }
        check(); // Fixed typo and call
    }
    return 0;
}

// Displays the game instructions
void show_instructions() {
    system("cls");
    printf("============================\n");
    printf("   15-PUZZLE GAME INSTRUCTIONS\n");
    printf("============================\n\n");
    printf("How to Play:\n");
    printf("------------\n");
    printf("- The goal is to arrange the numbers in order from 1 to 15, with the empty space (0) at the bottom-right corner.\n");
    printf("- Use the arrow keys on your keyboard to move the empty space:\n");
    printf("    - Up Arrow    : Move the empty space up\n");
    printf("    - Down Arrow  : Move the empty space down\n");
    printf("    - Left Arrow  : Move the empty space left\n");
    printf("    - Right Arrow : Move the empty space right\n");
    printf("- Only tiles adjacent to the empty space can be moved.\n");
    printf("- Each move increases your move count, shown at the bottom of the grid.\n");
    printf("- When all numbers are in order, you win!\n");
    printf("- Press 'Esc' to exit the game at any time.\n\n");
    printf("Enjoy the challenge!\n");
    printf("============================\n\n");
    printf("Press any key to start the game...");
    getch();
    system("cls");
}

// Checks if the puzzle is solved and counts the number of moves
void check(){
    static int move = 0;
    int k = 1, i, j;
    move++;
    gotoxy(30,24);
    printf("no of moves = %d", move);
    for(i = 0; i <= 3; i++){
        for(j = 0; j <= 3; j++){
            if (arr[i][j] == 0){ // Skip empty tile (fixed srr to arr)
                continue;
            }
            else{
                if(arr[i][j] == k){ // Check if tile is in correct position
                    k++;
                }
                else{
                    return; // Puzzle not solved
                }
            }
        }
    }
    // If all tiles are in correct position, print win message and exit
    gotoxy(30,26);
    printf("Congratulations! Puzzle solved in %d moves.\n", move);
    exit(0);
}

// Draws the puzzle grid using box-drawing characters
void boxes(){
    int r, c;
    for(c = 30; c <= 42; c++){
        for(r = 8; r <= 16; r++){
            gotoxy(c, r);
            printf("%c", 196);
        }
    }
    // Draw vertical lines
    for(r = 8; r <= 16; r++){
        for(c = 30; c <= 42; c += 3){
            gotoxy(c, r);
            printf("%c", 179);
        }
    }
    // Draw intersections
    for(c = 33; c <= 39; c += 3){
        gotoxy(c, 8);
        printf("%c", 194);
        gotoxy(c, 16);
        printf("%c", 193);
    }
    for(r = 10; r <= 14; r += 2){
        gotoxy(30, r);
        printf("%c", 195);
        gotoxy(42, r);
        printf("%c", 180);
    }
    for(r = 10; r <= 14; r += 2){
        for(c = 33; c <= 39; c += 3){
            gotoxy(c, r);
            printf("%c", 197);
        }
    }
    // Draw corners
    gotoxy(30, 8);
    printf("%c", 218);
    gotoxy(42, 8);
    printf("%c", 191);
    gotoxy(30, 16);
    printf("%c", 192);
    gotoxy(42, 16);
    printf("%c", 217);
}

// Displays the current state of the puzzle
void display(){
    int i, j, r = 9, c = 31;
    for(i = 0; i <= 3; i++){
        for(j = 0; j <= 3; j++){
            if(arr[i][j] == 0){ // Empty tile
                gotoxy(c, r);
                printf("   ");
            }
            else{
                gotoxy(c, r);
                printf("%d ", arr[i][j]); // Print tile value
            }
            c = c + 3;
        }
        r = r + 2;
        c = 31;
    }
}

// Gets a key press from the user (arrow keys, etc.)
int getkey(){
    int ch = getch(); // Wait for key press
    // For arrow keys, getch() returns 0 or 224 first, then the actual code
    if (ch == 0 || ch == 224) {
        ch = getch();
    }
    return ch;
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
