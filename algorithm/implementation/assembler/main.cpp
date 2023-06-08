#include "file.io.hpp"

#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <bitset>
#include <cassert>

using namespace std;

auto convert_rd_ra_to_binary(int _rd, int _ra, bool flag) -> string;

auto convert_rb_to_binary(int _rb, bool flag) -> string;

auto check_condition(string& opcode) -> bool;

class Parser
{
public:
    Parser parser();

    auto parse_by_space(string& line) -> vector<string>
    {
        stringstream ss(line);
        vector<string> tokens;
        string token;   

        while (ss >> token)
            tokens.push_back(token);

        return tokens;
    }
};

class Assembler
{
public:
    Assembler()
    {
        parser = new Parser;
    };

    auto converter(string& assembly) -> string
    {
        string result{""};

        auto tokens = parser->parse_by_space(assembly);
        auto flag = check_condition(tokens[0]);
        bitset<4> opcode(opcode_list[tokens[0]]);

        auto rd_ra = convert_rd_ra_to_binary(stoi(tokens[1]), stoi(tokens[2]), flag);
        auto rb = convert_rb_to_binary(stoi(tokens[3]), flag);

        if (rd_ra.empty() || rb.empty())
            throw invalid_argument("invalid_argument");
        
        result += opcode.to_string() + rd_ra + rb;

        return result;
    }
    
private:
    unordered_map<string, int> opcode_list = 
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

    Parser* parser;
};

auto convert_rd_ra_to_binary(int _rd, int _ra, bool flag) -> string
{
    string ans {""};
    try
    {
        ans.push_back((flag ? '1' : '0'));
        ans.push_back('0');

        bitset<3> rd(_rd);
        bitset<3> ra(_ra);

        ans +=  (rd.to_string() + ra.to_string());
    }
    catch(...)  // 예외 타입을 지정하지 않고 사용가능하다.
    {
        return ""s;
    }
    
    return ans;
}

auto convert_rb_to_binary(int _rb, bool flag) -> string
{
    string ans {""};
    try
    {
        if (flag)
        {
            bitset<4> rb(_rb);
            ans += rb.to_string();
        }
        else
        {
            bitset<3> rb(_rb);
            ans += rb.to_string();
            ans += '0';
        }
    }
    catch (...)
    {
        return ""s;
    }
    
    return ans;
}

auto check_condition(string& opcode) -> bool
{
    if (opcode.back() == 'C')
    {
        opcode.pop_back();
        return true;
    }
    else
    {
        return false;
    }
}

auto run_test(const vector<string>& assembly, const vector<string>& correct, Assembler& assembler) -> void
{
    assert(assembly.size() == correct.size());

    for (size_t i = 0; i < assembly.size(); ++i)
    {
        try
        {
            string assemblyLine = assembly[i];
            string correctLine = correct[i];
            string result = assembler.converter(assemblyLine);

            assert(result == correctLine);
            cout << "Test Case " << i + 1 << ": Passed" << endl;
        }
        catch (const exception& ex)
        {
            cerr << "Test Case " << i + 1 << ": Failed. " << ex.what() << endl;
        }
    }
}

int main()
{
    Assembler assembler;
    auto assembly = read_text_file("../assembly.txt");
    auto correct = read_text_file("../correct.txt");

    run_test(assembly, correct, assembler);
    
    return 0;
}