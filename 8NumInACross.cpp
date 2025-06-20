//MD AZAD
//CSCI 211 Lab
//8 Number in a cross

#include <iostream>
using std::cout;
using std::endl;


bool ok(int q[], int c){//array for boxes which are adjacent to the box
    static int a[8][5] = {
        {-1}, //box 0
        {0, -1}, //box 1
        {0, -1}, //box 2
        {0, 1, 2, -1}, //box 3
        {0, 1, 3, -1}, //box 4
        {1, 4, -1}, //box 5
        {2, 3, 4, -1}, // box 6
        {3, 4, 5, 6, -1} // box 7
    };
    for(int i=0; i<c; i++){ //avoid repetion
        if(q[i] == q[c])
            return false; //If a number is already used in an earlier spot, return false
    }
    for(int i = 0; a[c][i] != -1; i++){ //avoid consecutive numbers and -1 because nothing to search against
        if(abs(q[c] - q[a[c][i]]) == 1) //If any adjacent position contains a number consecutive, the function returns false
            return false; 
    }
    return true;
}
void print(int q[]) // printing solution
{ // print function
    static int solution_Number = 0; 
    cout << "Solution Number: " << ++solution_Number << endl;
    cout << " " << q[0] << q[1] << endl; //first row for the box
    cout << q[2] << q[3] << q[4] << q[5] << endl;//second row for the box
    cout << " " << q[6] << q[7] << endl;//third row for the box
    cout << endl;
}
int main(){
    int q[8] = {0}; //initializing the array
    int c = 0; 
    q[c] = 1;

    while(c >= 0){ //checking position from outer while loop
        c++; //incrementing the column
        if (c == 8){
            print(q); //Prints the valid configuration and backtracks to find alternative configurations
            c--; 
        }
        else q[c] = 0; //Resets the current position to 0, preparing to try different numbers at this position
        while(c >= 0){//checking position from inner while loop
            q[c]++; //incrementing the row
            if(q[c] > 8){  //position check
                c--; 
                }
                else if (ok(q, c)){ 
            break; 
            }
        }
    }

    return 0; 
}