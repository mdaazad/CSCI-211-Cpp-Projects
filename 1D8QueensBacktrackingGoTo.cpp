//MD AZAD
//CSCI 211 LAB
//1D 8 Queens With Backtrack and GoTo


#include <iostream> 
#include <cmath>
using std:: cout;
using std:: endl;

int main(){
static int solNum = 0; // static variable to count the number of solutions found
int q[8], c = 0; // array 'q' to store the row position of queens, 'c' for the current column
q[0] = 0; // start with the first queen at the first row of the first column

nc: // lebel for next column
    c++; // column incrementing
    if(c == 8) goto print; // go to print the solution If all 8 columns are filled
    q[c] = -1; //initializing the row position for the queen

nr: //lebel for next row
    q[c]++; // row incrementing
    if(q[c] == 8) goto backtrack;
    for(int i = 0; i < c; i++){ //checking confliction
        if(q[c] == q[i] || (c - i) == abs(q[c]-q[i])) goto nr; //Checking for same row or diagonal confliction
    }
    
    goto nc; // move to the next column when no confliction

backtrack:
    c--;
    if(c == -1) return 0; // end the program if backtracked beyond the first column
    goto nr;
print:
cout << "Solution #: " << ++solNum <<endl; // Printing the solution number

    for(int i = 0; i < 8; i++){ //for loop through each row
        for(int j = 0; j < 8; j++){ //nested for loop through each column
            if(q[j] == i) cout << " X "; // if a queen is placed in this position, print 'X'
            else cout << " O "; // otherwise, print O
        }
        cout << endl;
    }

goto backtrack; // After printing, backtracking for the next solution
}