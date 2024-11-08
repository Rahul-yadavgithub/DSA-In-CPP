#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
    public:
    int numIslands(vector<vector<char>>& grid){
        int rows = grid.size();
        int cols = grid[0].size();
        int cc= 0;
        for(int r = 0; r< rows; r++){
            for(int c =0; c< cols; c++){
                // if some water bodies present then we no need to do any thing contineu the loop
                if(grid[r][c] == '0'){
                    continue;
                }
                cc++;
                grid[r][c] = '0';
                queue<pair<int, int>> q;
                q.push({r, c});
                while(not q.empty()){
                    auto curr  = q.front();
                    q.pop();
                    int currRow = curr.first;
                    int currCol = curr.second;
                    // now we need to check the condition like 
                    // we can move upword or not 
                    if(currRow-1>= 0 && grid[currRow-1][currCol] == '1'){
                        grid[currRow-1][currCol] = '0';
                        q.push({currRow-1, currCol});
                    }
                    // for down word
                    if(currRow +1 < rows && grid[currRow+1][currCol] == '1'){
                        grid[currRow+1][currCol] = '0';
                        q.push({currRow+1,currCol});
                    }
                    // for right word movement
                    if(currCol-1 >= 0 && grid[currRow][currCol-1] == '1'){
                        grid[currRow][currCol-1] = '0';
                        q.push({currRow, currCol-1});
                    }
                    if(currCol+1 < cols && grid[currRow][currCol+1] == '1'){
                        grid[currRow][currCol+1] = '0';
                        q.push({currRow, currCol+1});
                    }
                }
            }
        }
        return cc;
    }

};
int main(){
    

}