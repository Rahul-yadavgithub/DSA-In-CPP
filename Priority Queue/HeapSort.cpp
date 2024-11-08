#include<iostream>
#include<vector>
using namespace std;

class MaxHeap{
    public:
    vector<int>arr;
    int idx;
    MaxHeap(int x){
        idx =1;
        vector<int>a(x);
        arr = a;
    }
    int top(){
        return arr[1];
    }
    void push(int y){
        arr[idx] = y;
        int i = idx;
        idx++;

        while(i!=1){
            int parent = i/2;
            if(arr[i]>arr[parent]){
                swap(arr[i], arr[parent]);
            }
            else break;
            i = parent;
        }
    }
    int size(){
        return idx-1;
    }

    void pop(vector<int>& ans){
        int m = arr[1];
        idx--;
        arr[1] = arr[idx];
        ans[idx] = m;
        int i =1;
        while(true){
            int left = 2*i;
            int right = 2*i+1;
            if(left > idx-1) break;
            if(right> idx-1){
                if(arr[i]< arr[left]){
                    swap(arr[i], arr[left]);
                    i = left;
                }
                break;
            }

            if(arr[left]> arr[right]){
                if(arr[i] < arr[left]){
                    swap(arr[i], arr[left]);
                    i = left;
                }
                else break;
            }
            else{
                if(arr[i]< arr[right]){
                    swap(arr[i], arr[right]);
                    i =right;
                }
                else break;
            }
        }

    }

};

int main(){
    int n;
    cout<<"Enter the Capacity of the heap -> ";
    cin>>n;
    MaxHeap pq(n);
    pq.push(40);
    pq.push(20);
    pq.push(13);
    pq.push(10);
    pq.push(9);
    pq.push(2);
    cout<<pq.top()<<endl;
    int m = pq.size();
    vector<int>arr(m);
    for(int i=0; i<arr.size(); i++){
        pq.pop(arr);
    }
    for(int i=1; i<= arr.size(); i++){
        cout<<arr[i]<<" ";
    }
   

}