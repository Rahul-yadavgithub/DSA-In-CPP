#include<iostream>
using namespace std;
#include<math.h>
class Solution{
    public:
    bool isPerfectSquare(int n){
        int root = sqrt(n);
        if(root*root== n)return true;
        else return false;
    }
    bool judgeSquareSum(int c){
        int x=0;
        int y=c;
        while(x<=y){
            if(isPerfectSquare(x) && isPerfectSquare(y)){
                return true;
            }
            else if(!isPerfectSquare(y)){
                y= (int)sqrt(y)*(int)sqrt(y);
                x= c-y;
            }
            else{  // x and y is not perfect square
                x= ((int)sqrt(x)*(int)sqrt(x));
                y= c-x;
            }
        }
        return false;
    }
  
};

int main(){
    int x;
    x=5;
    Solution sol;
    bool n=sol.judgeSquareSum(x);
    cout<<n;
}
