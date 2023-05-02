#include <iostream>
using namespace std;

class Character
{
public:
    int hp;
    int speed;
    string name;
    void move(int dir);
    void jump();
    void hit();
        

};

void Character::move(int dir){

}

void Character::jump(){

}

void Character::hit(){

}

int main(){
    Character mario;
    mario.name = "Super mario";
    mario.jump();
}