#include "file.io/file.io.hpp"

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Student 
{
public:
    Student(int _age, const string& _name) : age(_age), name(_name) {}

    auto operator<(const Student& other) const -> bool 
    {
        if (age == other.age) {
            return name < other.name;
        }
        return age < other.age;
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

        students.emplace_back(age, name);
    }

    return students;        
}

auto compare_by_name(const Student& s1, const Student& s2) -> bool
{
    if (s1.get_age() == s2.get_age()) 
        return s1.get_name() < s2.get_name();
    
    return s1.get_age() < s2.get_age();
}


int main()
{
    auto inputs = read_text_file("../students.txt");
    auto students = get_student_info(inputs);
    
    // 1. 학생의 나이로 정렬
    sort(students.begin(), students.end());

    cout << "Sorted by age:\n";
    for (const auto& student : students)
        cout << "Age: " << student.get_age() << ", Name: " << student.get_name() << endl;

    // 2. 나이가 같은 경우 이름으로 정렬
    sort(students.begin(), students.end(), compare_by_name);

    cout << "\nSorted by age and name:\n";
    for (const auto& student : students)
        cout << "Age: " << student.get_age() << ", Name: " << student.get_name() << endl;

    return 0;
}
