#include<iostream>
using namespace std;

class player{
    private:
    int score;
    int age;
    int health;
    bool alive;
    public:
    int getScore(){
        return score;

    }
    int getAge(){
        return age;
    }
    int getHealth(){
        return health;
    }
    int getAlive(){
        return alive;
    }
    void setScore(int score){
        this-> score= score;
    }
    void setAge(int age){
        this->age= age;
    }
    void setHealth(int health){
        this->health=health;
    }
    void setAlive(bool alive){
        this-> alive= alive;
    }

};

int addScore(player a , player b){
    return a.getScore()+ b.getScore();
}

player getMaxScoreplayer(player a , player b){
    if(a.getScore()< b.getScore())
    return a;
    else
    return b;
}

int main(){
    player harsh;
    player rahul;
    player*rohit =new player;
    player suraj= *rohit;
    harsh.setAge(20);
    harsh.setHealth(70);
    harsh.setAlive(true);
    harsh.setScore(100);

    rahul.setAge(19);
    rahul.setScore(400);
    
    // suraj.setAge(29);
    // suraj.setScore(400);
    // cout<<suraj.getScore();
    // or we can use another  method for this
    rohit->setScore(200);
    rohit->setAge(40);
    cout<<rohit->getScore();  
    




}
