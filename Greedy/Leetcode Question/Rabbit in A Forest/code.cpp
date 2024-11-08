#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int RabbitCount(vector<int>arr){
        unordered_map<int, int> mp;
        int result = 0;
        for(int i=0;i<arr.size(); i++){
            if(!mp[arr[i]+1]){
                result += arr[i]+1;
                if(arr[i]== 0) continue;
                /*
                The main reason why we use this (arr[i]==0)continue becz 
                Ex: [1,0,1,0,0] so frist time one rabbit say meri tarah koi nhi hai but when we next time 0 come so according to our else 
                conditon this if loop does not run and the 3 place rabbit which say meri tarah koi nhi hai vo add hi nhi hoga in the result which give the wrong anser
                */
                mp[arr[i]+1]= 1;
            }
            else{
                /*
                 So why we use this else loop The reason is 
                 Ex: [0,0,1,1,1] in this example we can see when first time rabbit say meri tarah 1 hai uska matlab ya to 3rd || 4th position me se koi ek rabbit hoga 
                 but jaise 3rd position vale rabbit ne bola ki uske jaise ek aur hai so ab agar 2nd place vale rabbit ne jisko bola tha agar vo ye 3rd place vala 
                 nikal gya to 4th place value rabbit kisi aur 1 rabbit ki baat kar rha jo ki es array me nhi hai 
                 so agar else condition naa lagaye to 
                 Ans: 4 
                 but exact ans : 6
                */
                mp[arr[i]+1]++;
                int key = arr[i]+1;
                int value = mp[key];
                if(key == value){
                    mp.erase(key);
                }
            }
        }
        return result;
    }
};
int main(){

    Solution ans;
    vector<int>ar;
    int n;
    cout<<"Value of n: ";
    cin>>n;
    for(int i=0;i<n; i++){
        int x;
        cout<<"No of rabbit: ";
        cin>>x;
        ar.push_back(x);
    }

    int rabbit = ans.RabbitCount(ar);
    cout<<rabbit;

}