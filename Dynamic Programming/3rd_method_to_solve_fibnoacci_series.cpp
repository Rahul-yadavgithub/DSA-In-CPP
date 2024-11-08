#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int f(int n){
    int a =0; 
    int b =1;
    int c =0;
    if(n == 0|| n ==1) return n;
    int i=2;
    while(i<= n){
       c = a+b;
       a = b;
       b =c; 
       i++;
    }
    return c;
}

int main(){
    int n ;
    cin>>n;
    cout<<f(n)<<"\n";
    return 0;

}