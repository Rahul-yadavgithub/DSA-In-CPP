#include<bits/stdc++.h>
using namespace std;


class A{
    public: 
    int age;

};

class ComplexNumber {
    public:
    int imaginary;
    int real;

/* First method to solve the add problem : */

    // ComplexNumber add(ComplexNumber &c1){
    //     ComplexNumber c3;
    //     c3.imaginary = c1.imaginary + this->imaginary;
    //     c3.real = c1.real + this->real;

    //     return c3;        
    // }

    /* Second method to solve the add problem:*/

    /* Syntax of writting this is 
       <return-type> operator <operator> (){}

       <> inside this tell me that it is variable and normally the thing written like 
       operator outside this means that is normally name which can be any thing 
       <operator> in it we can give +,-, *,/ and etc 
    */

    ComplexNumber operator + (ComplexNumber &c1){
        ComplexNumber c3;
        c3.imaginary = c1.imaginary + this->imaginary;
        c3.real = c1.real + this->real;

        return c3;

    }
};

int main(){
    ComplexNumber a1 , a2;
    a1.imaginary  = 10;
    a1.real = 5;

    a2.imaginary = 2;
    a2.real = 4;

    ComplexNumber a3 = a1 + a2;


    cout<<"real : "<< a3.real <<" "<< "imaginary: "<<a3.imaginary<<endl;
}