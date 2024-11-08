#include<iostream>
using namespace std;
class Gun{
    public:
    int ammo;
    int damage;
    int scope;
};
class player{
    private:
     class Helmet{
        int hp;
        int level;

        public:
        int getHp(){
            return hp;
        }
        int getLevel(){
            return level;
        }

        void setHp(int hp){
            this->hp=hp;
        }
        void setLevel(int level){
            this->level=level;
        }
    }; 
    int health;
    int score;
    int age;
    bool alive;
    Gun gun;
    Helmet helmet;

   

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
    int getAlive(){
        return alive;
    }
    Gun getGun(){
        return gun;
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
    void setAlive(bool alive){
        this->alive= alive;

    }
    void setGun(Gun gun){
        this->gun=gun;
    }

    void setHelmet(int level){
        Helmet *helmet = new Helmet;
        helmet->setLevel(level);
        int health;
        if(level==1){
            health=25;
        }
        else if(level==2){
            health=50;
        }
        else if(level==3){
            health=75;
        }
        else if(level==4){
            health=100;
        }
        else{
            cout<<"error ,invalid level!!";
        }
        helmet->setHp(health);
        this->helmet=*helmet;
    }
    Helmet getHelmet(){
        return helmet;
    }


};

int addScore(player a, player b){
    return a.getScore()+ b.getScore();
}

player getMaxScoreplayer(player a, player b){
    if(a.getScore()> b.getScore()){
        return a;
    }
    else{
        return b;
    }
}
int main(){
    player harsh;
    player rahul;
    player*rohit = new player;

   Gun akm;
   akm.ammo=100;
   akm.damage=50;
   akm.scope=4;
   harsh.setAge(21);
   harsh.setScore(100);
   harsh.setHealth(70);
   harsh.setAlive(true);
   harsh.setGun(akm);
   harsh.setHelmet(2);

Gun awn;
awn.ammo=15;
awn.damage=150;
awn.scope=8;


   rahul.setAge(20);
   rahul.setScore(500);
   rahul.setHealth(400);
   rahul.setAlive(true);
   rahul.setGun(awn);
   rahul.setHelmet(3);

   Gun gun123 = harsh.getGun();
   cout<<gun123.damage<<endl;
   cout<<gun123.ammo<<endl;
   cout<<gun123.scope<<endl;

 




}