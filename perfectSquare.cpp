//MD AZAD
//CSCI 211 LAB
//Perfect Square
//There won't be any correct solution for this problem

#include <iostream>
using namespace std;
int main(){
    int x = 0;     
    int c = 0;     
    while (x == 0){
        c++;
        int square = c * c; //calculating the square of c
        int lastDigit = square % 10; //extracting the last digit of square
        int secondLastDigit = (square  % 100)/10; //extracting the second to last digit of square
        if(lastDigit % 2 == 1 && secondLastDigit % 2 == 1){ //checking if the last two digits are odd
            x = square; 
            cout << x <<endl;
        }
    }
    
    return 0;
}
