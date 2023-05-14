//  code maker:
//  https://github.com/yielding/code/blob/master/cpp.fp/count.lines/count.lines1.cpp
//  problem: count line in files

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>  // read & write file!

using namespace std;

// read file list, the list is a string type vector that includes file paths
auto count_lines_in_files(const vector<string>& files) -> vector<int>
{
  vector<int> results(files.size());  // vector memory allocate

  for(auto& file : files)   //  reference original value by 'file'
  {
    ifstream in(file);  // file -> program
    auto c = in.good()
    ? count(istreambuf_iterator<char>(in),  // iterator continues to read tpye <T> data
            istreambuf_iterator<char>(),  // this is placeholder, indicates the end point of the iterator
            '\n')
    : 0;

    results.push_back(c);
  }

  return results;
}

int main(int argc, char* argv[])
{
  vector<string> files{
    "/Users/kimmi/Desktop/MyCode/oop_practice/stack.h",
    "/Users/kimmi/Desktop/MyCode/oop_practice/stack.cpp"
  };

  auto res = count_lines_in_files(files);

  for (auto r : res)
    cout << r << " ";

  //  the result is 0, 0, 48, 24
  //  The reason why 0,0 is added before it is because the vector is initialized to files.size() 
  //  and then the number of lines of the file actually read is attached with push_back().
  //  For the expected results, the following code can be applied.

  cout << "\n";
  for(size_t i=2; i < res.size(); i++){
    cout << res[i] << " "; 
  }

  return 0;
}
