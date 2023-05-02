#include <iostream>
using namespace std;

class Character
{
public:
    int hp; // member variable
    int speed;
    string name;
    void move(int dir); // member function
    void jump();
    void hit();
        

};

void Character::move(int dir){

}

void Character::jump(){
    cout << "Jump!!\n";
}

void Character::hit(){

}

int main(){
    Character mario;    // make instance
    mario.name = "Super mario";
    mario.jump();   // call member function "jump()"
}