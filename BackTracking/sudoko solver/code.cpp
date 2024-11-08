#include<bits/stdc++.h>
using namespace std;


class Solution {
public:


   bool isSafe(vector<vector<char>>& board, int row, int col, int num){

    // check that does their is any value equal to num present in the column or not 

    for(int i = 0; i<9; i++){
        if(board[row][i]-'0' == num) return false; /*  if you find any value which is equal to the given number then directly retuen the false form their    ->   and hear we can see that  board[row][i] -'0'  means we making the board which is charector into the number */
    }

    // check for the row 

    for(int i = 0; i< 9; i++){
        if(board[i][col]-'0' == num) return false;
    }

    int x = (row/3)*3; /*  This is denoted that at the current time in which bigger box you are  =>  their are total 9 bigger boxes in which 3 are in row and 3 are in column so if your get x = 0 means your are currently in the row 1st box  */

    int y = (col/3)*3; /*  this is similarly used for finding that currently wherer are you so that you can eassily check the condition on the given number of box*/
   

   // Now we need to iterate in each box and find  the number which you want to fill

   for(int i = x; i< x+3; i++){
    for(int j = y; j< y+3; j++){
        if(board[i][j]-'0' == num) return false;
    }
   }

   return true; 

   }


    bool f(vector<vector<char>>& board, int row, int col){
        if(row == 9) return true;
        if(col == 9){
           return f(board, row+1, 0); // go to the next row
        }
        if(board[row][col] != '.') {
            return f(board, row, col+1); // mean move one column next to that colum
        }

        // Now we need to itreate in the column for the filling exact and correct number

        for(int j =1; j<= 9; j++){
            if(isSafe(board, row, col, j)){
                board[row][col] = '0'+ j;   // we use '0' for making our j as a charector so that we can store in

                // Now if we find that the value which is fit on the given column then we can move to the next
                bool retval  = f(board, row, col+1);
                if(retval == true) return true;
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {

        f(board, 0,0);
        
    }
};


// class Solution {
// public:

//    bool isSafe(vector<vector<char>>& board, int row, int col, int num){

//     // Check if the value equal to num is present in the row
//     for(int i = 0; i < 9; i++){
//         if(board[row][i] - '0' == num) return false; 
//     }

//     // Check if the value equal to num is present in the column
//     for(int i = 0; i < 9; i++){
//         if(board[i][col] - '0' == num) return false;
//     }

//     // Determine the starting row and column of the 3x3 subgrid
//     int x = (row / 3) * 3;
//     int y = (col / 3) * 3;

//     // Iterate through the 3x3 subgrid
//     for(int i = x; i < x + 3; i++){
//         for(int j = y; j < y + 3; j++){
//             if(board[i][j] - '0' == num) return false;
//         }
//     }

//     return true; 
//    }

//     bool f(vector<vector<char>>& board, int row, int col){
//         if(row == 9) return true;
//         if(col == 9){
//             return f(board, row + 1, 0); // Go to the next row
//         }
//         if(board[row][col] != '.') {
//             return f(board, row, col + 1); // Move to the next column
//         }

//         // Iterate through possible values (1-9) and attempt to fill the cell
//         for(int j = 1; j <= 9; j++){ // **Corrected range for j (1 to 9)**
//             if(isSafe(board, row, col, j)){
//                 board[row][col] = '0' + j;   // Convert number to character

//                 // Attempt to solve the rest of the board
//                 bool retval = f(board, row, col + 1);
//                 if(retval == true) return true;

//                 board[row][col] = '.'; // Backtrack if no solution is found
//             }
//         }
//         return false;
//     }

//     void solveSudoku(vector<vector<char>>& board) {
//         f(board, 0, 0);
//     }
// };

int main(){

}