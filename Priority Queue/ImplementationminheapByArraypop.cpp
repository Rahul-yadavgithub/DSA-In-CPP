#include<iostream>
using namespace std;

// For POP method 
class MinHeap{
    public:
    int arr[40];
    int idx;
    MinHeap(){
        idx =1;
    }
    int top(){
        return arr[1];
    }
    void push(int x){
        arr[idx] =x;
        int i = idx;
        idx++;
        // Now for finding the parent node and rearranging the values
        while(i!=1){
            int parent = i/2;
            if(arr[parent]>arr[i]){
                swap(arr[parent], arr[i]);
            }
            else break;
            i = parent;
        }
    }
    int size(){
        return idx-1;
    }
    void pop(){
       // For rearrangement  
        idx--;
        arr[1]= arr[idx];
        int i = 1;
        while(true){
            int left = 2*i;
            int right = 2*i+1;
            if(left>idx-1) break; // means we can not move futher in our array
            if(right>idx-1){    // Their is no need to stop hear one more condition need to check
            if(arr[i]>arr[left]){
                swap(arr[i], arr[left]);
                i = left;
            }
            break;

            }
            if(arr[left]< arr[right]){
                if(arr[i]> arr[left]){
                    swap(arr[left], arr[i]);
                    i = left;
                }
                else break;
            }
            else{
                if(arr[i]> arr[right]){
                    swap(arr[i], arr[right]);
                    i = right;
                }
                else break;
            }
        }

    }
};

int main(){
    MinHeap pq;
    pq.push(30);
    pq.push(10);
    pq.push(2);
    pq.push(9);
    pq.push(1);
    cout<<pq.top()<<endl;
    cout<<pq.size()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;

}