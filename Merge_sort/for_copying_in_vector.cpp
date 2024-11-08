#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr[]= {1,3,4,5,7};
    int n1= sizeof(arr)/sizeof(arr[0]);
    vector<int> a(arr,arr+n1);
    for(int i=0; i<n1; i++){
        cout<<a[i]<<" ";
    }
}