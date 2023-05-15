//  todo: find duplicated words
//  and then, delete duplication

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    vector<string> words;
    copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(words));  // get input string by cin before EOF(Ctrl + C)
    sort(words.begin(), words.end());   //  ASD
    unique_copy(words.begin(), words.end(), ostream_iterator<string>(cout, " "));   //  delete duplication and print unique word!

    return 0;
}