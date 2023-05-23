#include <iostream>
#include <numeric>
#include <vector>

int main() {
  std::vector<int> numbers = {1, 2, 3, 4, 5};

  // 덧셈 연산을 사용하여 요소들을 누적
  int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
  std::cout << "Sum: " << sum << std::endl;

  // 문자열을 결합
  std::vector<std::string> strings = {"Hello", " ", "world", "!"};
  std::string result = std::accumulate(strings.begin(), strings.end(), std::string(""));
  std::cout << "Result: " << result << std::endl;

  return 0;
}
