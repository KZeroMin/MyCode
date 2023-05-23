#include "string_util.hpp"
#include <sstream>

namespace util::str {

  void split(string_view in, char delim, vector<string>& elems)
  {
    try
    {
      stringstream ss(in.data());
      string item;
      while (getline(ss, item, delim))
        elems.push_back(item);
    }
    catch(...)
    {
      elems.clear();  //  vector= elem)를 비운다
    }
  }

  auto split(string_view in, char delim) -> vector<string>
  {
    vector<string> result;

    split(in, delim, result);

    return result;
  }
}

