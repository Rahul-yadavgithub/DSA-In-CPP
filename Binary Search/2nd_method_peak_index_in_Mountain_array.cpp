#include<iostream>
using namespace std;
int main(){
    int arr[]={1,3,5,4,3,2,1,0};
    int n=7;
    int low=0;
    int high= n-1;
    while(low<=high){
        int mid= low+ (high-low)/2;
        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]){
            cout<<arr[mid];
            break;
        }
        else if(arr[mid]>arr[mid+1]) high= mid-1;
        else low= mid+1;
    }

}
