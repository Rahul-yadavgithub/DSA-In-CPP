#include<iostream>
using namespace std;
class student{
    private:
    int age;
    char name;
    int height;
    float weight;
    public:
    int getAge(){
        return age;
    }
    int getName(){
        return name;
    }
    int getHeight(){
        return height;
    }
    int getWeight(){
        return weight;
    }
    void setAge(int age){
        this->age= age;
    }
    void setName(char name){
        this->name= name;
    }
    void setHeight(int height){
        this->height= height;
    }
    void setWeight(float weight){
        this->weight= weight;
    }
     
};

int main(){
    student rahul;
    student rohit;
    rohit.setAge(21);
    rohit.setHeight(162);
    rohit.setWeight(45);

    rahul.setAge(23);
    rahul.setWeight(46);
    rahul.setHeight(166);

    cout<<rahul.getAge();
    
}