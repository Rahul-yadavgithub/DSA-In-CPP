#include<bits/stdc++.h>
using namespace std;


class A{
    private:
    int a_ka_private;

    public: 
    int a_ka_public;
};

class B:virtual public A{
    public:
    int b_ka_public;

};

class C:virtual public A{
    public:
    int c_ka_public;

};

class D: public C, public B{
    public:
    int d_ka_public;

    void show(){
        cout<<a_ka_public<<endl;

    }
};
int main(){
    B b;
    b.b_ka_public = 10;

}