#include<bits/stdc++.h>
using namespace std;

void permutations(string input, string output){

    // when input string puri tarah se empty ho jaye then return the output string
    if(input.size() == 0){
        cout<<output<<"\n";
        return;
    }

    for(int i = 0; i< input.size(); i++){
        char ch = input[i];  // means input ke first charectar ko ko ch me store karva do 
        string left = input.substr(0, i); /* substr is a function which is used in c++  for extracting the string upto given size in the substr 
        like hear substr(0, i) => denote that take the string from the 0 index upto that index when the length become to i
        */
       string right = input.substr(i+1);// i+1 the ke aage ke sari string ko le aao 

       // now left right ko cancatnate karke ROS banayenge -> that is -> rest of the string
       string ros = left + right;

       permutations(ros, output+ ch);// hear output+ ch ka matlab ouput vali string ke back me ham add karte jaa rhe hai

    }
}
int main(){

       permutations("abc", "");

}