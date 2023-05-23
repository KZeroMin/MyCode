#include <iostream>

using namespace std;

template < typename T, typename ...Types >
void print(const T& firstArg, const Types& ... args)
{
  cout << firstArg << endl;
  if constexpr(sizeof...(args) > 0)
  {
    print(args...);
  }
}

int main()
{
  print(1,2,3,4,0.5f,'z');
  return 0;
}