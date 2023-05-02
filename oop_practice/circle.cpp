#include <iostream>
using namespace std;

class Circle
{
public:
        int radius;
        Circle();
        Circle(int radi);
        double getArea();

};

Circle::Circle(){
    radius = 1; // set member variable
}

Circle::Circle(int r){
    radius = r; // set member variable
}


double Circle::getArea(){
    return 3.14 * radius * radius;
}

int main(){
    Circle donut;
    double area = donut.getArea();
    cout << "Area of donut: " << area << endl;

    Circle pizza(30);
    area = pizza.getArea();
    cout << "Area of pizza: " << area << endl;
}