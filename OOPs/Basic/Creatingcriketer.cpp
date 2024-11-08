#include<iostream>
using namespace std;

class Cricketer{
    public:
    char name;
    int age;
    int noOfTestMatches;
    int average;


};


int main(){

  Cricketer virat; 

  virat.name ='v';
  virat.age =30;
  virat.noOfTestMatches =100;
  virat.average=80;  

  Cricketer Dhoni;
  Dhoni.name= 'D';
  Dhoni.age=34;
  Dhoni.noOfTestMatches=30;
  Dhoni.average=80;
   Cricketer cricketer[2] ={virat , Dhoni};
   for(int i=0 ; i<2 ; i++){
    cout<<cricketer[i].name<<endl;
    cout<<cricketer[i].age<<endl;
    cout<<cricketer[i].noOfTestMatches<<endl;
    cout<<cricketer[i].average<<endl;
   }
}