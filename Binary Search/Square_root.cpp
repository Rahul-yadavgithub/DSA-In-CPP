#include<iostream>
using namespace std;
int main(){
    int  low=0;
    int x=37 ;
    int high=x;
    while(low<=high){
        int mid= low+(high-low)/2;
        long long m= (long long)mid;
        long long y= (long long)x;
        if(m*m==y) return mid;
        else if(m*m>y) high= mid-1;
        else low= mid+1;
    }
    cout<<high;
}