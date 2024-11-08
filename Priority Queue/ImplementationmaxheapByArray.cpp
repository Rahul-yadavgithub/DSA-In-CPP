#include<iostream>
using namespace std;

// For maxheap
class MaxHeap{
    public:
    int arr[40];
    int idx;
    MaxHeap(){
        idx =1;
    }
    int top(){
        return arr[1];
    }
    // For pushing the value
    void push(int x){
        arr[idx] =x;
        int i = idx;
        idx++;
        while(i!= 1){
            int parent = i/2;
            if(arr[i]> arr[parent]){
                swap(arr[i], arr[parent]);
            }
            else break;
            i = parent;
        }
    }
    int size(){
        return idx-1;
    }

   // For pop method

   void pop(){
    idx--;
    arr[1] = arr[idx];
    int i =1;
    while(true){
        int left = 2*i;
        int right =2*i+1;
        
        if(left > idx-1) break;
        if(right> idx-1){
            if(arr[left]> arr[i]){
                swap(arr[i], arr[left]);
                i = left;
            }
             break;
        }

        if(arr[left]> arr[right]){
            if(arr[i]< arr[left]){
                swap(arr[i], arr[left]);
                i = left;
            }
            else break;

        }
        else{
            if(arr[i]<arr[right]){
                swap(arr[i], arr[right]);
                i= right;
            }
            else break;
        }


    } 
   }  
};

int main(){

    MaxHeap pq;
    pq.push(30);
    pq.push(3);
    pq.push(20);
    pq.push(12);
    pq.push(9);
    pq.push(23);
    cout<<pq.top()<<endl;
    cout<<pq.size()<<endl;

    pq.pop();
    pq.pop();
    cout<<pq.top()<<endl;

}