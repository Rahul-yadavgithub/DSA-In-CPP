#include<iostream>
using namespace std;

class player{
    private:
    int score;
    int health;
    int age;
    bool alive;
    public:
    int getHealth(){
        return health;
    }
    int getAge(){
        return age;
    }
    int getScore(){
        return score;
    }
    int IsAlive(){
        return alive;
    }
    void setHealth(int health){
        this->health= health;
    }
    void setAge(int age){
        this->age= age;
    }
    void setScore(int score){
        this->score=score;
    }
    void setIsAlive(bool alive){
        this->alive= alive;
    }

};
//  void add(int a , int b){
//     cout<<a+b;

//  }

int addScore(player a, player b){
    return a.getScore()+ b.getScore();
}
player getMaxScoreplayer(player a, player b){
    if(a.getScore() < b.getScore())
    return a;

    else 
    return b;
}




int main(){
  player harsh; //object cretion 
  player rahul;
  harsh.setAge(21);
  harsh.setScore(100);
  harsh.setIsAlive(true);
  harsh.setHealth(70);

  rahul.setAge(22);
  rahul.setScore(20);
  rahul.setIsAlive(true);
  rahul.setHealth(100);

 cout<<addScore(harsh, rahul) ;

 getMaxScoreplayer(harsh , rahul);
}
