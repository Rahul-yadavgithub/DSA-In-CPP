#include<iostream>
#include<climits>
using namespace std;
int main(){
    int arr[] = {-2,4,5,-6,3,-8,7};
    int n= sizeof(arr)/ sizeof(arr[0]);
    int maxSum= 0;
    for(int i= 0; i<n; i++){
        maxSum+= arr[i];
    }
    int i=0; 
    int j=0;
    int sum=0;
    int initialIdx=0;
    int endIdx=0;
    while(j<n){
        sum += arr[i];
        while(sum>maxSum){
            initialIdx=i;
            endIdx= j;
            maxSum= max(sum, maxSum);
            sum-= arr[i];
            i++;
        }
        j++;
    }
    for(int i=initialIdx; i<=endIdx; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<maxSum;
}