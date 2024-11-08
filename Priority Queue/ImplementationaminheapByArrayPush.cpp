#include<iostream>
using namespace std;

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
        // Swapping of i with parent till i ==1;

        while(i !=1){
            int parent = i/2;
            if(arr[i]<arr[parent]){
                swap(arr[i], arr[parent]);
            }
            else break;
            i = parent;
        }
    }
    int size(){
        return idx-1;
    }


};
int main(){
    MinHeap pq ;
    pq.push(10);
    pq.push(20);
    pq.push(11);
    cout<<pq.top()<<endl;
    cout<<pq.size();

}
