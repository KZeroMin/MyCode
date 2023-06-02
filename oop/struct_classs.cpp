#include <iostream>
using namespace std;

/*
    구조체 sturct는 데이터와 코드가 분리
    단점: 데이터 따로, 코드 따로 -> 데이터를 수동적인 존재로 인식하고 개발
*/
struct A
{
    int a;
    int b;
};

void showA(struct A temp)
{
    cout << temp.a << endl;
    cout << temp.b << endl;
}

/*
    클래스 class는 데이터와 코드가 한 번에 존재
    장점: 코드 재활용성이 좋아짐, 객체들이 서로 소통하는 것을 생각하며 개발
*/
class B
{
public:
        int a;
        int b;
        void showB();
};

void B::showB()
{
    cout << a << endl;
    cout << b << endl;
}

int main()
{
    struct A structA;
    structA.a = 10;
    structA.b = 20;
    showA(structA);

    B classB;
    classB.a = 30;
    classB.b = 40;
    classB.showB();

    return 0;
}