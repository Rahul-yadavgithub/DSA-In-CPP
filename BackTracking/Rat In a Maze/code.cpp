#include<bits/stdc++.h>
using namespace std;

 int sum ;
 bool canWeGo(vector<vector<int>>& grid, int i, int j , int n){
    return i>= 0 && j>=0 && i<n && j<n && grid[i][j] == 0;
 }

 void f(vector<vector<int>>& grid, int i, int j, int n){
    if(i == n-1 && j == n-1){
        sum += 1;
        return ;
    }

    // Now marked that cell as visited in which you are currently presnent

    grid[i][j] = 2; // hear 2 mean your are visited that cell

    // now we need to check in which direction we can go from the following cell

    // for up

    if(canWeGo(grid, i-1, j, n)){
        f(grid, i-1, j, n);
    }

    // For down

    if(canWeGo(grid, i+1, j, n)){
        f(grid, i+1, j, n);
    }

    // For left 
    if(canWeGo(grid, i, j-1, n)){
        f(grid, i, j-1,n);
    }

    // For Right 
    if(canWeGo(grid, i, j+1, n)){
        f(grid, i, j+1, n);
    }

    // Now we need to do back Tracking for which we need to unchange the things that we are chaged

    grid[i][j] = 0;

     
}

int ratInMaze(vector<vector<int>>& grid, int n){
    sum  = 0;
    f(grid, 0, 0, n);
    return sum;

}
int main(){

    vector<vector<int>> grid = {
        {0,0,1,0,0,1,0},
        {1,0,1,1,0,0,0},
        {0,0,0,0,1,0,1},
        {1,0,1,0,0,0,0},
        {1,0,1,1,0,1,0},
        {1,0,0,0,0,1,0},
        {1,1,1,1,0,0,0}
    };
    int n = grid.size();

    cout<<ratInMaze(grid, n);


}