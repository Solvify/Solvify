#include <iostream>
#include "Readme.h"
using namespace std;
int main() {

    Readme readme;

    // 1672

    string id = "1480";

    // Problem link
    // https://leetcode.com/problems/richest-customer-wealth/
    string plink = "https://leetcode.com/problems/running-sum-of-1d-array/";

    // Problem name
    // Richest Customer Wealth
    string pname = "Running Sum of 1d Array";


    // Solution file relative path
    // leetcode/2021/february/practice/cpp/1672-RichestCustomerWealth.cpp 
    // Note : separator  should be forward slash not backword
    string relativePath = "leetcode/2021/february/practice/java/1480-RunningSumof1dArray.java ";


    //  "leetcode", "codechef", "hackerearth", "hackerrank" 
    string platform = "leetcode";

    Data data(id, plink, pname, readme.generateSolutionLink(relativePath), platform);
    // Add new Row
    readme.addRow(data);

    return 0;
}

