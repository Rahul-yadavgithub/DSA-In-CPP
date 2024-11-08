#include<bits/stdc++.h>
using namespace std;
void permutations(string& str, int i){
    if(i == str.size()-1){
        cout<<str<<"\n";
        return ;
    }

    for(int idx = i; idx< str.size(); idx++){
        swap(str[idx] , str[i]);
        permutations(str, i+1);
        // Backtracking Step is =>

        swap(str[idx], str[i]);

        // same only difference is we change after the recursive call
    }
}
int main(){
    string str = "abcde";
    permutations(str, 0);

}