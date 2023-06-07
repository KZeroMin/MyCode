#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cassert>

using namespace std;

auto to_binary(int num, int len) -> string;

class Assembler
{
public:
    Assembler()
    {
        opcode_table = 
        {
            { "ADD", 0 }, 
            { "SUB", 1 }, 
            { "MOV", 2 }, 
            { "AND", 3 }, 
            { "OR", 4 }, 
            { "NOT", 5 },
            { "MULT", 6 }, 
            { "LSFTL", 7 }, 
            { "LSFTR", 8 }, 
            { "ASFTR", 9 }, 
            { "RL", 10 }, 
            { "RR", 11 }
        };
    }

    auto check_and_reemove_conditional(string& opcode) -> bool 
    {
        if (opcode[opcode.size() - 1] == 'C')
        {
            opcode.pop_back();
            return true;
        }
        
        return false;
    }

    auto parse_assembly(const string& input) -> vector<string>
    {
        stringstream ss(input);
        vector<string> tokens;
        string token;

        while (ss >> token)
            tokens.push_back(token);

        return tokens;
    }

    auto append_opcode_to_binary(const string& opcode, string& ans) -> bool
    {
        auto it = opcode_table.find(opcode);
        if (it != opcode_table.end())
        {
            ans += to_binary(it->second, 4);
            return true;
        }

        return false;
    }

    auto append_rd_ra_to_binary(int rd, int ra, const bool& flag, string& ans) -> bool
    {
        ans.push_back((flag ? '1' : '0'));
        ans.push_back('0');
        ans += to_binary(rd, 3);
        ans += to_binary(ra, 3);

        return true;
    }   

    auto append_rb_to_binary(int rb, const bool& flag, string& ans) -> bool
    {
        if (flag)
            ans += to_binary(rb, 4);
        else
        {
            ans += to_binary(rb, 3);
            ans.push_back('0');
        }

        return true;
    }

    auto generate_machine_code(const string& input) -> string
    {
        string ans = "";
        auto tokens = parse_assembly(input);
        auto flag = check_and_reemove_conditional(tokens[0]);

        append_opcode_to_binary(ans, tokens[0]);    // bool타입을 반환함으로써 예외 처리 가능
        append_rd_ra_to_binary(stoi(tokens[1]), stoi(tokens[2]), flag, ans);
        append_rb_to_binary(stoi(tokens[3]), flag, ans);

        return ans;
    }

private:
    unordered_map<string, int> opcode_table;
};

auto to_binary(int num, int len) -> string
{
    vector<char> tmp;
    string ret;

    while (num)
    {
        tmp.push_back('0' + num % 2);
        num /= 2;
    }

    reverse(tmp.begin(), tmp.end());

    for (int i = 0; i < len - tmp.size(); i++)
        ret.push_back('0');

    for (auto& i : tmp)
        ret.push_back(i);

    return ret;
}

int main(void) {

    string input = "ADD 3 1 2";

    Assembler assembler;
    auto result = assembler.generate_machine_code(input);

    assert(result == "000110010100");

    return 0;
}