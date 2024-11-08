#include<iostream>
using namespace std;
#include<stack>
string removeDuplicates(string s){
    stack<char>st;
    st.push(s[0]);
    for(int i=1; i<s.length(); i++){
        if(s[i]!= st.top()) st.push(s[i]);
    }
    s = "";
    while(st.size()>0){
        s+=st.top();
        st.pop();
    }
    int i=0 ;
    int j= s.length()-1;
    while(i<=j){
        char temp= s[i];
        s[i]= s[j];
        s[j]= temp;
        i++;
        j--;
    }
    return s;
}
int main(){
    string s= "aaabbcddaabffg";
    cout<<s<<endl;
    s=removeDuplicates(s);
    cout<<s<<endl;
}
