#include <iostream>
#include <regex>
using namespace std;
class Solution {
public:
    string validIPAddress(string IP) {
        regex v4("(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])");
        if(regex_match(IP,v4))
            return "IPv4";

        regex v6("((([0-9a-fA-F]){1,4})\\:){7}(([0-9a-fA-f]){1,4})");
        if(regex_match(IP,v6))
            return "IPv6";

        return "Neither";
    }
};
int main() {
    Solution solution;
    string s = "172.16.254.1";
    string s1 = "20EE:FGb8:85a3:0:0:8A2E:0370:7334";
    cout<<solution.validIPAddress(s)<<endl;
    return 0;
}