//Md Azad
//CSCI 211 Lab
//Stable Marriage

#include <iostream>
using namespace std;


bool ok(int q[], int col){
  
   static int mPr[3][3] = { { 0, 2, 1 }, { 0, 2, 1 }, { 1, 2, 0 } };
   //Static 2D array 'mPr' representing men's preferences. Each row corresponds to a man and each column to a woman


   static int wPr[3][3] = { { 2, 1, 0 }, { 0, 1, 2 }, { 2, 0, 1 } };
   //Static 2D array 'wPr' representing women's preferences. Each row corresponds to a woman and each column to a man
  
   for (int i=0; i<col; i++){
       if(q[col] == q[i] || (mPr[i][q[col]] < mPr[i][q[i]] && wPr[q[col]][i] < wPr[q[col]][col])
       || (mPr[col][q[i]] < mPr[col][q[col]] && wPr[q[i]][col] < wPr[q[i]][i]))
      //Checks if the current woman 'q[col]' is already matched or if there's a more preferred match according to both men's and women's preferences
       
       return false; //If any condition for instability is met, return false
       }
       return true; // If no instability found, return true
       }


void print(int q[]){
   static int sol = 0; // Static variable to count solutions.
   cout << "The Solution Number #" << ++sol << ":\nMen\t\tWomen\n"; // Prints the solution number
   for (int i=0; i<3; i++){
       cout << i << "\t\t" << q[i] << endl; // Prints the man and his matched woman
   }
}


int main(){
    int q[3], col = 0; q[0] = 0; // Array 'q' for storing women matched to men, 'col' for the current man


       while (col>=0){//outer while loop for checking the position
           col++;//incrementing men column
           if (col==3){ // If all men have been considered
               print(q);
               col--; //backtrack to find more solutions
           }

           else q[col] = -1;


           while (col>=0){//inner while loop for women
               q[col]++;//incrementing women row
               if (q[col]==3) // If all women have been considered without finding a match
                   col--; //backtrack to the previous man
               else if (ok(q, col))
                   break;//The inner loop is exiting in order to continue with the next man
           }//inner while loop end
       }//outer while loop end


   return 0;
}