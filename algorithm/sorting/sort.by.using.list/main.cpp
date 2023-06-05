#include "file.io/file.io.hpp"

#include <iostream>
#include <cstring>
#include <sstream>
#include <list>

using namespace std;

struct Student
{
    int age;
    string name;

    auto operator<(const Student& rhs) -> bool
    {
        return this->age < rhs.age;
    }
};

typedef list<Student> StudentList;

auto get_student_info(string& student) -> Student
{
    Student s;
    string name;
    int age;
    stringstream ss(student);

    ss >> age >> name;
    s.age = age;
    s.name = name;

    return s;
}

auto make_student_list(vector<string>& students) -> StudentList
{
    StudentList stduent_list;

    for (auto student : students) 
        stduent_list.push_back(get_student_info(student));

    return stduent_list;
}

auto compare_by_name(const Student& a, const Student& b) -> bool
{
    return strcmp(a.name.c_str(), b.name.c_str()) < 0;
}

int main()
{
    auto students = read_text_file("../students.txt");
    auto student_list = make_student_list(students);

    // sort by age
    student_list.sort();

    cout << "sort by age\n";
    for (auto student : student_list)
        cout << student.age << " " << student.name << endl;

    //  sort by name
    cout << "\nsort by name\n";
    student_list.sort(compare_by_name);
    for (auto student : student_list)
        cout << student.age << " " << student.name << endl;

    return 0;
}