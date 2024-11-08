#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color == image[sr][sc])return image;
        dfs(image, sr, sc, image[sr][sc], color);
        return image;
        
    }

    //  The below function will do dfs from currRow currCol to it's neighbours cantainig initialColor
    void dfs(vector<vector<int>> & image ,int currRow , int currCol, int initialColor, int newColor){
         
         int n = image.size();  // total rows
         int m = image[0].size();  // total cols
         if(currRow< 0 || currCol <0 ||currRow>=n || currCol>= m){
            return; // means you are outside the gride
         }
         /** and also for which other we can return the function 
         if the cell you landed is not of initial color
         */
         if(image[currRow][currCol] != initialColor) return ;

         // and if non of the condition hit then you can move any direction

         image[currRow][currCol] = newColor;
         dfs(image, currRow+1, currCol, initialColor, newColor);// we move the downword
         dfs(image, currRow-1, currCol, initialColor, newColor);// we move the upword
         dfs(image, currRow, currCol+1, initialColor, newColor); // we move the rightside
         dfs(image, currRow, currCol-1, initialColor, newColor); // we move the leftside



    }
};

int main(){

}
