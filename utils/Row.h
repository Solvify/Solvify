#include <iostream>

using namespace std;

#ifndef ROW_H
#define ROW_H

struct Row {
    string id;
    string idWithLink;
    string problem;
    string solution;
    Row* next;
    Row() : id(""), idWithLink(""), problem(""), solution(""), next(nullptr) {}
    Row(string id) : id(id) {}
    Row(string id, string idWithLink, string problem, string solution) : id(id), idWithLink(idWithLink), problem(problem), solution(solution), next(nullptr) {}
    Row(string id, string idWithLink, string problem, string solution, Row* next) : id(id), idWithLink(idWithLink), problem(problem), solution(solution), next(next) {}
    bool operator<(const Row& o) const { return id < o.id; }
    string toRow() {
        return  "|" + idWithLink + "|" + problem + "|" + solution + "|";
    }
};
#endif
