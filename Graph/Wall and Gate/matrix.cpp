#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> DIR = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                if (mat[r][c] == 0) q.push({r, c});
                else mat[r][c] = -1; // Marked as not processed yet!

        while (!q.empty()) {
            auto cell = q.front();
            int r = cell.first;
            int c = cell.second;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nr = r + DIR[i][0], nc = c + DIR[i][1];
                if (nr < 0 || nr == m || nc < 0 || nc == n || mat[nr][nc] != -1) continue;
                mat[nr][nc] = mat[r][c] + 1;
                q.push({nr, nc});
            }
        }
        return mat;
    }
};

int main(){

}
