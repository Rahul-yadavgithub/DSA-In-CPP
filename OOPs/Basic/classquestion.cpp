#include<iostream>
using namespace std;

class Book{
    public:
    char name;
    int price;
    int noOfpages;
    
    int countBooks(int p){
        if(price<p){
            return 1;
        }
        else{
            return 0;
        }
    }
        bool isBookPresent(char book){
         if(name==book){
            return true;
         }
         else{
            return false;
         }
        }
    
    };

    int main(){
        #ifndef ONLINE_JUDGE
        freopen("input.text", "r", stdin);
        freopen("output.text", "w",stdout);
        #endif
        Book harryPotter;
        harryPotter.name ='H';
        harryPotter.price =1000;
        harryPotter.noOfpages= 500;

        cout<<harryPotter.isBookPresent('H');

    }