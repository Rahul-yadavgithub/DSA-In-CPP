#include<iostream>
using namespace std;
class player{
    public:
    int score;
    int health;
    void showHealth(){
        cout<<"Health is :"<<health<<endl;
    }
    void showScore(){
        cout<<"Score :"<<score;
    }

};
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.text", "r",stdin);
    freopen("output.text", "w", stdout);
    #endif
    int score[100]= {};
    int health[100] ={};
    player amit;
    amit.score =90;
    amit.health=100;

    amit.showHealth();
    amit.showScore();

}