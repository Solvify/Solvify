#include <iostream>

using namespace std;

#ifndef DATA_H
#define DATA_H


struct Data {
    string id;
    string problemLink;
    string problemName;
    string solutionLink;
    string platform;
    Data(string id, string solutionLink, string platform) : id(id), solutionLink(solutionLink), platform(platform) {}
    Data(string id, string problemLink, string problemName, string solutionLink, string platform) : id(id), problemLink(problemLink), problemName(problemName), solutionLink(solutionLink), platform(platform) {}
};

#endif
