#include<bits/stdc++.h>
using namespace std;


class ComplexNumber {
    private:
    int p;
    public:
    int imaginary;
    int real;
    
    friend ComplexNumber operator + (ComplexNumber &c1, ComplexNumber &c2);

    friend class primeNumber;
};

ComplexNumber operator +(ComplexNumber &c1, ComplexNumber &c2){
    ComplexNumber c3;
    c3.imaginary = c1.imaginary + c2.imaginary;
    c3.real = c1.real + c2.real;
    return c3;
}

class primeNumber{
    void show(ComplexNumber &c){
        c.p = 10;
    }

};

class A{
    private:
    int a_private =10;
    public: 
    friend void show(A &a);
    // void show2(){
    //     cout<<a_private<<endl;
    // }
};

void show(A &a){
    cout<<a.a_private<<endl;
}

int main(){
    ComplexNumber a1 , a2;
    a1.imaginary  = 10;
    a1.real = 5;

    a2.imaginary = 2;
    a2.real = 4; 

    ComplexNumber c3 = a1+ a2;
    cout<<c3.real<<" "<< c3.imaginary<<endl;

}