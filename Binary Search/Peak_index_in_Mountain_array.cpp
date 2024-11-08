#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,2,1};
    int n= 6;
    int idx= -1;
    for(int i=1; i<=n-2; i++){
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
            idx= i;
            break;
        }
    }
    cout<<arr[idx];
}