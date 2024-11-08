#include<bits/stdc++.h>
using namespace std;

void display(vector<int>& subset){
    int n = subset.size();
    cout<<"[";
    for(int i=0; i<n; i++){
        cout<<subset[i];
        if(i<n-1){
            cout<<",";
        }
    }
    cout<<"]"<<endl;
}

void subset( vector<int>arr){
    int n = arr.size();
    // The (1<<n) is the left sift which can also we write as the 2^n
    for(int i = 0; i<(1<<n); i++){

        vector<int>subset;

        for(int j = 0; j<n; j++){
            if(i &(1<<j)){
                subset.push_back(arr[j]);
            }
        }
        display(subset);
    }
}
int main(){
    int n;
    cout<<"Enter the Number: ";
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n; i++){
        int x;
        cout<<"Enter the value : ";
        cin>>x;
        arr.push_back(x);
    }
    subset(arr);
}