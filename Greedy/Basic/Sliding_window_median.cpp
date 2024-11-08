#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<climits>
using namespace std;

double getMedian(priority_queue<int>& maxHeap, priority_queue<int, vector<int> , greater<int>>& minHeap, int x, int y){
    int totalSize = x+y;
    if(totalSize %2 !=0){
        // odd cases 
        return minHeap.top();
    }
    else{
        // even cases
        return (maxHeap.top()+ minHeap.top())/2.0;
    }
}

bool isBalanced( int x, int y){
    return (x== y)or(x+1 == y);
}

void removeMedian(priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int>>& minHeap){
    if(maxHeap.size() == minHeap.size()){
        // even 
        maxHeap.pop();
        
    }
    else{
        // odd 
        minHeap.pop();
    }
}

vector<double> sliding_median(vector<int>& arr, int n , int k){
    priority_queue<int> maxHeap;
    priority_queue< int, vector<int> , greater<int>> minHeap;
    int x =0, y=0;
    minHeap.push(arr[0]);
    y++;

    for(int i=1; i< k; i++){
        int curr = arr[i];
        double med = getMedian(maxHeap, minHeap,x,y);
        if(curr< med){
            // go maxHeap
            maxHeap.push(curr);
            x++;
            if(!isBalanced(x,y)){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                x--;
                y++;
            }
        }
        else{
            minHeap.push(curr);
            y++;
            if(!isBalanced(x,y)){
                maxHeap.push(minHeap.top());
                minHeap.pop();
                y--;
                x++;
            }
        }
    }

    double m =  getMedian(maxHeap, minHeap, x, y);
    vector<double> result;
    unordered_map<int, int> mp;
    result.push_back(m);
    for(int i =k; i<n; i++){
        int newElementIndex = i;
        int oldElementIndex = i-k;
        double med = getMedian(maxHeap, minHeap, x, y);
        if(arr[newElementIndex]> med){
            // go in minHeap
            minHeap.push(arr[newElementIndex]);
            y++;
            if(!isBalanced(x,y) ){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                y++;
                x--;
            }
        }
        else{
            // Go in maxHeap
            maxHeap.push(arr[newElementIndex]);
            x++;
            if(!isBalanced(x,y)){
                maxHeap.push(minHeap.top());
                minHeap.pop();
                x++;
                y--;

            }
        }
        mp[arr[oldElementIndex]] = oldElementIndex;
        while(!maxHeap.empty() && mp[maxHeap.top()]){
            mp.erase(maxHeap.top());
            maxHeap.pop();
            x--;
            if(!isBalanced(x,y)){
                maxHeap.push(minHeap.top());
                minHeap.pop();
                y--;
                x++;

            }
        }
        while(!minHeap.empty() && mp[minHeap.top()]){
            mp.erase(minHeap.top());
            minHeap.pop();
            y--;
            if(!isBalanced(x,y)){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                y++;
                x--;
            }
        }
        result.push_back(getMedian(maxHeap, minHeap, x,y));
    }
    return result;

}

int main(){
    // ios_base :: sync_with_stdio(0);// use of this line => 1-> make faster our input and output 2-> take large number of input and output effectively
    // cin.tie(0);
    // cout.tie(0);
    // int t =1;
    int n;
    int k;
    vector<int> arr(n);
    for(int i=0;i<n; i++){
        cin>> arr[i];
    }
    vector<double> ans = sliding_median(arr, n,k);
    for(int i=0; i< ans.size(); i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}