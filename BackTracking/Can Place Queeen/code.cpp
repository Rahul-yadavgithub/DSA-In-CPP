#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> grid;
vector<vector<string>> result;

bool canPlaceQueen(int row, int col, int n){

    // Now we need to check from which which position the attack is occuring 
    // 1-> their is no need to check for the row because in row we already decleared that no other that that queen we can place


    // for Column check
    for(int i = row-1; i>=0; i--){
        if(grid[i][col] == 'Q'){ // we are in the attack position so in that cell their is no possibility to fill the quene
           return false;
        }
    }

    // For left diagonal movement 
    for(int i = row-1, j = col-1; i>=0, j>=0; j--, i--){
        if(grid[i][j] == 'Q'){
            return false;
        }
    }

    // Right diagonal movement
    for(int i = row-1, j= col+1; i>=0, j<n; i--, j++){
        if(grid[i][j] == 'Q'){
            return false;
        }
    }

    // if no one condition hit means we are in safe position 
    return true;
}

void f(int row ,int n){
    if(row == n){
        // if we reached at the end means row == n means we got one answer so after we can print that combination and return the function for next call
        vector<string> temp;
        for(int i = 0; i<n; i++){
            string str = "";
            for(int j =0; j<n; j++){
                str += grid[i][j];
            }
            temp.push_back(str);
        }
        result.push_back(temp);
    }
    for(int col = 0; col< n; col++){
        if(canPlaceQueen(row, col, n)){
            grid[row][col] = 'Q';
            f(row+1, n);
            grid[row][col] = '.';
        }
    }
}

vector<vector<string>> queen(int n){
    grid.clear();
    result.clear();
    grid.resize(n, vector<char>(n, '.'));
    f(0,n);
    return result;
}

int main(){
    queen(4);

}