#include<bits/stdc++.h>
using namespace std;

void display(vector<int>& subset){
    int n = subset.size();
    cout<<"[";
    for(int i= 0; i<n; i++){
        cout<<subset[i];
        if(i<n-1){
            cout<<",";
        }
    }
    cout<<"]"<<"\n";
}
void search(int k, vector<int>& subset, vector<int>& arr){
    int n = arr.size();
    if(k== n){
        display(subset);
        return;
    }
    else{
        search(k+1, subset, arr);
        subset.push_back(k);
        search(k+1, subset, arr);
        subset.pop_back();
    }
}
int main(){
    vector<int> arr;
    vector<int> subset;
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"\n";
    for(int i=0; i<n; i++){
        cout<<"Enter the Element :";
        int x;
        cin>>x;
        arr.push_back(x);
    }

    search(0,subset,arr);

}