#include <iostream>

using namespace std;

#ifndef ROW_H
#define ROW_H

struct Row {
    int id;
    string idWithLink;
    string problem;
    string solution;
    Row* next;
    Row() : id(0), idWithLink(""), next(nullptr) {}
    Row(int id, string idWithLink, string problem, string solution) : id(id), idWithLink(idWithLink), problem(problem), solution(solution), next(nullptr) {}
    Row(int id, string idWithLink, string problem, string solution, Row* next) : id(id), idWithLink(idWithLink), problem(problem), solution(solution), next(next) {}
    string toRow() {
        return  "|" + idWithLink + "|" + problem + "|" + solution + "|";
    }
};
#endif
