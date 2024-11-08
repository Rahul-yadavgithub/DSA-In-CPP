#include<iostream>
#include<climits>
using namespace std;
int main(){
    int arr[]= {-5 ,-5, 4, 3,  8,-7 };
    int n= sizeof(arr)/sizeof(arr[0]);
    int t=0;
    int i=0;
    int j=1;
    while(t<n){
        if(i%2==0 && arr[i]<0 && j%2!=0 && arr[j]>0){
            i=i+2;
            j=j+2;
        }
        else if(i%2==0 && arr[i]>0 && j%2!=0 && arr[j]<0){
            int temp= arr[i];
            arr[i]= arr[j];
            arr[j]= temp;
            i=i+2;
            j=j+2;
        }
        else if(t>i && t>j && arr[t]<0){
            if(i%2==0 && arr[i]>0 && j%2!=0 && arr[j]>0){
                int k=t;
                while(k!=i){
                    int temp= arr[k];
                    arr[k]= arr[k-1];
                    arr[k-1]= temp;
                    k--;

                }
            }
        }
        else if(t>i && t>j && arr[t]>0){
            if(i%2==0 && arr[i]<0 && j%2!=0 && arr[j]<0){
                int k=t;
                while(k!=j){
                    int temp= arr[k];
                    arr[k]= arr[k-1];
                    arr[k-1]= temp;
                    k--;

                }
            }
        }
        t++;
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}