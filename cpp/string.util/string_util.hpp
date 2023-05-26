#pragma once

#include <string>
#include <numeric>
#include <vector>
#include <string_view>



namespace util::str {

  using namespace std;  // namespace를 사용하여, 함수와 변수의 이름 충돌 방지, 코드 구조화


  //  두 개의 반복자(ff, ll)을 받아 해당 범위에 있는 요소들을 구분자(seq로 받는다)로 연결
  //  accumulate함수를 사용하여 수행
  template<typename ForwardIterator>
  auto join(ForwardIterator ff, ForwardIterator ll, string const& sep=";") 
    -> string
  {
    return accumulate(ff, ll, ""s, [sep](const auto& l, const auto& r) {  //   초기값으로 빈 문자열을 사용,  ""s는 C++14 이상에서 제공되는 문자열 리터럴 표기법으로, 빈 문자열을 생성
      return l.empty() ? r : l + sep + r; }                               //    l: 이전의 누적결과, r: 현재 처리중인 요소
    );
  }

  auto split(string_view in, char delim, vector<string>& elems) -> void;  //  string_view: 문자열을 참조하기 위한 가변 길이 시퀀스

  auto split(string_view in, char delim) -> vector<string>;

}
