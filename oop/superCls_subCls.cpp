#include <iostream>
using namespace std;

/*
    Class inheritance: 기존에 정의되어 있는 클래스의 모든 멤버 변수와 멤버 함수를 물려받아, 새로운 클래스를 작성한다.
    크게 Super class와 Sub class로 나뉜다.
*/
class Person
{
public:
    int age;
    string name;
    void PersonInfo();
};

void Person::PersonInfo(){
    cout << "name: " << name << endl;
    cout << "age: " << age << endl;
}
/*
    Sub class
    1. Super class의 접근할 수 있는 모든 멤버 변수들이 저장된다.
    2. Super class의 접근할 수 있는 모든 모든 멤버 함수를 사용할 수 있다.
    3. Sub class에 필요한 만큼 멤버를 추가할 수 있다.
*/
class Student:public Person
{
public:
    int std_id;
    void stdInfo();
};

void Student::stdInfo()
{
    PersonInfo();
    cout << "student id: " << std_id << endl;
}

int main(){
    Student A;
    A.name = "Min";
    A.age = 25;
    A.std_id = 21800000;

    A.stdInfo();

    return 0;
}