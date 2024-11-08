#include<bits/stdc++.h>
using namespace std;

void permutations(string str, int i){
    if(i == str.size()-1){
        cout<<str<<"\n";
        return ;
    }

    unordered_set<char> s;
    for(int idx = i ; idx< str.size(); idx++){

        // Frist Two line pron the step means -> we know that by doing this we didn't get any thing in future their is no need to go further
        if(s.count(str[idx])) continue;

        s.insert(str[idx]);
        swap(str[idx], str[i]);
        permutations(str, i+1);
        swap(str[idx], str[i]);
        // This last step is the Backtracking step where we unchange the thing which are changed during the recursive call initalisation 
    }
}
int main(){
    string str = "aad";
    permutations(str, 0);

}