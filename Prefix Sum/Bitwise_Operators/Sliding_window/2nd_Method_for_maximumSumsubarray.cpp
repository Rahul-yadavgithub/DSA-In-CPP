#include<iostream>
#include<climits>
using namespace std;
int main(){
    int arr[]= {1,3,4,5,6,9,8};
    int n= sizeof(arr)/sizeof(arr[0]);
    int k= 4;
    int maxSum= INT_MIN;
    int maxIdx= 0;
    int sum= 0;
    for(int i=0;i<k;i++){
        sum+= arr[i];
    }
    maxSum= sum;
    // Applying the sliding window concept 
    int i=1;
    int j=k;
    while(j<n){
        sum= sum+arr[j]-arr[i-1];
        if(maxSum<sum){
            maxSum= sum;
            maxIdx= i;
        }
        i++;
        j++;
    }
    cout<<maxSum<<endl;
    cout<<maxIdx;

}