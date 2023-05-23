#pragma once

#include <string>
#include <numeric>
#include <vector>
#include <string_view>

////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////
namespace util::str {

  using namespace std;

  template<typename ForwardIterator>
  auto join(ForwardIterator ff, ForwardIterator ll, string const& sep=";")
    -> string
  {
    return accumulate(ff, ll, ""s, [sep](const auto& l, const auto& r) {
      return l.empty() ? r : l + sep + r; }
    );
  }

  auto split(string_view in, char delim, vector<string>& elems) -> void;

  auto split(string_view in, char delim) -> vector<string>;

}

////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////
