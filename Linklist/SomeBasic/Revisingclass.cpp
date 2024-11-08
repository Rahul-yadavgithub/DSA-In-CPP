#include<iostream>
using namespace std;
class student{
    public:
     int ron;
     string name;
     float marks;
     student(string name, int ron, float marks){
        this->name= name;
        this->ron=ron;
        this->marks=marks;

     }
};

void change(student s){
    s.name="Harsh";

}
int main(){
    student s("Rahul", 76,89.4);
    cout<<s.name<<endl;
    change(s);
    cout<<s.name<<endl;
}
