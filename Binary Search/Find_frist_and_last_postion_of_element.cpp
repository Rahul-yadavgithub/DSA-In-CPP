#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,3,3,4,5,5,6,7,8};
    int n= 11;
    int x=5;
    bool flag= false;
    int low= 0;
    int high= n-1;
    while(low<= high){
      int  mid= low+ (high-low)/2;
      if(arr[mid]==x){
        if(arr[mid-1]!=x){
            flag= true;
            cout<<("Lower bound of the element index:");
            cout<<mid;
            break;
        }
        else{
            high= mid-1;
        }
      }
       if(arr[mid]>x){
        if(arr[mid-1]==x){
            cout<<("Upper bound element index:");
            cout<<mid-1;
            cout<<endl;
            high= mid-1;
        }
       }
      if(arr[mid]<x) low= mid+1;
    }
    if(flag==false) cout<<-1;
  
}