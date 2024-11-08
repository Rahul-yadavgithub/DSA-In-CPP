#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
class Solution{
    public:

     vector<vector<int>> dir  = {{1,0}, {-1,0}, {0,1}, {0,-1}};
     int rows;
     int cols;

    void wallsAndGates(vector<vector<int>>& rooms){
        rows = rooms.size();
        cols = rooms[0].size();

        queue<pair<int, int>> q;

        for(int i = 0; i< rows; i++){
            for(int j = 0; j< cols; j++){
                if(rooms[i][j] == 0){
                    q.push({i,j});
                }
                if(rooms[i][j] == INT_MIN){
                    rooms[i][j] = 1;
                }
            }
        }

        while(! q.empty()){
            auto cell = q.front();
            q.pop();
            int i = cell.first;
            int j = cell.second;
            for(int d = 0; d< 4; d++){
                int newRow = i+ dir[d][0];
                int newCol = j+ dir[d][1];
                
                if(newRow < 0 || newCol< 0 || newRow >= rows || newRow >= cols|| rooms[newRow][newCol] == -1 )continue;
                if(rooms[newRow][newCol] == 1){
                    // mean not visited;
                    rooms[newRow][newCol] = rooms[i][j] +1;
                }
                if(rooms[newRow][newCol] != 1){
                    // smaller value fill into the box
                    if(rooms[newRow][newCol] >  rooms[i][j]+1){
                        rooms[newRow][newCol] = rooms[i][j] +1;
                        q.push({newRow, newCol});
                    }
                }

            }
        }

    }
};
int main(){

}