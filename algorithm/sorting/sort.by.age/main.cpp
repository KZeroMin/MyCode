#include "file.io/file.io.hpp"

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

class Student 
{
public:
    Student(int _age, const string& _name) : age(_age), name(_name) {}

    auto operator<(const Student& rhs) -> bool
    {
        return this->age < rhs.age;
    }

    auto get_age() const -> int 
    {
        return age;
    }

    auto get_name() const -> const string& 
    {
        return name;
    }

private:
    int age;
    string name;
};

auto get_student_info(vector<string>& inputs) -> vector<Student>
{
    vector<Student> students;
    string name;
    int age;

    for (auto student : inputs)
    {
        stringstream ss(student);
        ss >> age >> name;

        students.emplace_back(age, name);   //  push_back과 달리 객채를 move함으로써 메모리 복사를 막는다.
    }
    return students;        
}

auto compare_by_name(const Student& s1, const Student& s2) -> bool
{
    return strcmp(s1.get_name().c_str(), s2.get_name().c_str()) < 0;    // 사전적으로 작을 때 -1 리턴한다.
}                                                                       

int main()
{
    auto inputs = read_text_file("../students.txt");
    auto students = get_student_info(inputs);
    
    // 1. 나이로 정렬
    sort(students.begin(), students.end());

    cout << "Sorted by age:\n";
    for (const auto& student : students)
        cout << student.get_age() << " " << student.get_name() << endl;

    // 2. 이름으로 정렬
    sort(students.begin(), students.end(), compare_by_name);

    cout << "\nSorted by name:\n";
    for (const auto& student : students)
        cout << student.get_age() << " " << student.get_name() << endl;

    return 0;
}
