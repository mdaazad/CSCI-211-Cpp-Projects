//Md Azad
//CSCI 211 lab
//1D 8 Queens With Backtracking Without GoTo

#include <iostream>
using namespace std;

bool ok(int q[], int c) {
        for (int r = 0; r < c; r++) {
            if (q[r] == q[c] || abs(q[c] - q[r]) == (c-r)) { // test vertial, horizontal and diagonal test 
                return false;
            }
        }
    return true;
}

void print(int q[])
{
    static int s = 0;
    cout << "Solution #" << ++ s << ": ";
    for (int i=0; i<8; i++) {       // prints array solution
        cout << q[i];
    }
    cout << endl;
    for (int i=0; i<8; i++) {         // prints the board
        for (int j=0; j<8; j++) {
            if (q[j] == i) 
                cout << " Q ";
            else 
                cout << " 0 ";
        }
        cout << endl;
    }

    cout << endl;
}

int main()
{
    int q[8], c = 0; //initialize to show positions
    q[0] = 0; 

        while (c >= 0) {
            c++;//increment c to the next column
            if (c == 8) { //check to see if position is filled
                print(q);
                c--; //backtracks by decrementing
            }
            else q[c] = -1; //start from first row of next column
            while (c >= 0) {//checks position for queen
                q[c]++;
                if (q[c] == 8)
                    c--; //Back to previous column
                else if (ok(q, c)) //function is called to check arguments
                    break; 
            } 
        }
    return 0;
}