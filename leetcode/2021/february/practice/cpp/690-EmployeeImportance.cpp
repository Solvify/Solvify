#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;


// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int importance = 0;
        int index = distance(employees.begin(), find_if(employees.begin(), employees.end(), [&](const Employee* o) { return o->id == id;}));
        Employee* emp = employees[index];
        importance += emp->importance;
        for (int id : emp->subordinates) {
            importance += getImportance(employees, id);
        }
        return importance;
    }
};

int main() {
    Solution solution;

    Employee emp1;
    emp1.id = 1;
    emp1.importance = 2;
    vector<int> subordinates1{ 2 };
    emp1.subordinates = subordinates1;

    Employee emp2;
    emp2.id = 2;
    emp2.importance = 3;
    vector<int> subordinates2{};
    emp1.subordinates = subordinates2;

    vector<Employee*> employees{ &emp1,&emp2 };
    cout << solution.getImportance(employees, 2) << endl;
    return 0;
}