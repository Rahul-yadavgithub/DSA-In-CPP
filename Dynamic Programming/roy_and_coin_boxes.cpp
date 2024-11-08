#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> f(n+1, 0);
    int m;
    cin>> m;
    vector<int> l(n+1, 0);
    vector<int> r(n+1,0);
    for(int i=0; i< m; i++){
        int L , R ; // hear L and R is the indexes of the l and r array
        cin>>L>>R;
        l[L]++;
        r[R]++;
    }
    f[1] = l[1];  // This is our base case means in this frist place always l[1] aayega and not affected by any other 
    for(int i=2; i<= n; i++){
        f[i] = l[i] - r[i-1] + f[i-1];   // This is generalised formula come from the derivation 

    }

    // Making the array which tell the no of boxes with i coins

    vector<int> c(10000005, 0);   
    for(int i=0; i<= n; i++){
        int coins = f[i];
        c[coins]++;
    }

    // Now we need to calculate the suffics sum
    for(int i= c.size()-2; i>=0; i--){
        c[i] = c[i] + c[i+1];
    }

    // for quries
    int q;
    cin>> q;
    while(q--){
        int num;
        cin>> num;
        cout<<c[num]<< "\n";
    }



}