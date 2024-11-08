#include<iostream>
using namespace std;
int main(){
  int arr[]= {1,2,3,3,3,4,5,5,5,6,7,8};
  int n=12;
  int x=5  ;
  int low =0;
  int high=n-1;
  bool flag= false;
  while(low<=high){
    int mid=low+(high-low)/2;
    if(arr[mid]==x){
        if(arr[mid-1]!=x){
            flag= true;
            cout<<mid;
            break;
        }
        else{
            high= mid-1;
        }
    }
    else if(arr[mid]<x) low= mid+1;
    else high= mid-1;
  }    
  if(flag==false)cout<<-1;
}