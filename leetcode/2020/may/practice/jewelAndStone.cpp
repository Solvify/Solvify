#include <iostream>

using namespace std;
//optimised solution in O(n+m).
int numJewelsInStones(string J, string S) {
    int result = 0,freq[123] {0};
    for(char c : S) ++freq[c];
    for(char c : J) if(freq[c] !=0) result+=freq[c];
    return result;
}
int main() {
    cout<<numJewelsInStones("aA","aAAbbbb");
    return 0;
}