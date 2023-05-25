#include <iostream>
#include <memory>

using namespace std;

int main()
{
    //
    //  delete로 동적으로 할당된 메모리를 가르키는 포인터를 소멸시키지 않는다면
    //  그 포인터는 Heap에서 계속 메모리를 차지하게 됨
    //  아래와 같은 경우 4 x 100 = 400 bytes의 메모리 손실 발생
    //
    int *array;
    array = new int[400];
    delete array;   // 동적으로 할당된 메모리 소멸자 호출, delete연산자는 동적으로 할당된 메모리를 해제하기 위해 포인터를 사용

    //
    //  일반적인 포인터가 아닌, 포인터 '객체' 로 만들어서 자신이 소멸 될 때,
    //  자신이 가리키고 있는 데이터도 같이 delete 한다 -> smart pointer
    //

    //  unique_ptr: 어떤 포인터에 객체의 유일한 소유권을 부여해서, 
    //  이 포인터 말고는 객체를 소멸시킬 수 없도록 한다

    unique_ptr<int[]> int_arr(new int[100]);

    return 0;
}