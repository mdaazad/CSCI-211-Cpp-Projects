//Md Azad
//CSCI 211 Lab
//the 8 queens 2 dimensional array program with backtracking (i.e. print the board)

#include <iostream> 
//using namespace std;
using std:: cout;
using std:: endl;

int main (){
    static int solutionNumber = 1;//Declairing a static integer variable and initializing to 1
    int q[8][8] = {0}; //initializing a 2D array to represent a 8x8 chessboard
    int r = 0, c = 0;
    q[r][c] = 1;//placing the first queen at position (0,0) on the chessboard

nc: //a lebel used as a target for goto statements to continue the algorithm by moving to the next column
    c++; //column incrementing
    if (c == 8) goto print; //checking position
    r = -1; //resets the row index
nr: //next row used for goto statements to continue the algorithm
    r++; //row incrementing
    if (r == 8) goto backtrack; //checking position
    
    for(int i = 0; i < c; i++){ //row test 
        if(q[r][i] == 1) goto nr;
    }
    
    for(int i = 1;r - i >= 0 && c - i >= 0; i++){ //updiagonal test 
        if(q[r-i][c-i] == 1) goto nr;
    }
    
    for(int i = 1; r + i < 8 && c - i >= 0; i++){ //downdiagonal test 
        if(q[r+i][c-i] == 1) goto nr;
    }

    q[r][c] = 1; // setting up a queen in the position after passing all the test 
    goto nc; 
backtrack:
    c--; //column decrementing
    if (c == -1) return 0; //checking position
    r = 0; 
    while(q[r][c] != 1){ // continue to iterate to the next row until finding the queen.
        r++;
    }
    q[r][c]=0; //removing the queen
    goto nr;
print:
    cout << "The solution number is: " << solutionNumber++ << endl; // printing out the solution number 

    for(int i = 0; i < 8; i++){ // printing out the chess board. 
        for (int j = 0; j < 8; j++){
            cout << q[i][j] << " "; 
        }
        cout << endl;
    }

    goto backtrack; //finding the next solution


    return 0;
}