#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    
    void dfs(vector<vector<char>> &grid, int currRow, int currCol){
        if(currRow <0 || currCol <0 || currRow > grid.size()-1 || currCol > grid[0].size()-1 || grid[currRow][currCol] == '0') return;

        grid[currRow][currCol] = '0';

        dfs(grid, currRow+1, currCol);
        dfs(grid, currRow-1, currCol);
        dfs(grid, currRow, currCol+1);
        dfs(grid , currRow, currCol-1);

        return ;
    }

    int numIslands(vector<vector<char>>& grid){
        int rows = grid.size();
        int cols = grid[0].size();
        int cc= 0;
        for(int r =0; r< rows; r++){
            for(int c = 0; c< cols; c++){
                if(grid[r][c] == '0'){
                    continue;
                }
                cc++;
                dfs(grid, r, c);
            }
        }
        return cc;
    }

};
int main(){

}