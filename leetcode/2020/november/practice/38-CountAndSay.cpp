#include <iostream>
#include<string>

using namespace std;

class Solution
{
public:
  string countAndSay(int n, string s) {
    if (n == 0) return s;
    int frq = 0;
    char prev = '\0';
    string new_string = "";
    for (char ch : s) {
      if (prev == ch) frq++;
      else {
        if(frq > 0 )  new_string += to_string(frq) + prev;
        prev = ch;
        frq = 1;
      }
    }
    if(frq > 0) new_string += to_string(frq) + prev;
    
    return countAndSay(--n, new_string);
  }
  string countAndSay(int n) {
    return countAndSay(--n, "1");
  }
};

int main() {
  Solution solution;

  cout << solution.countAndSay(10) << endl;

  return 0;
}