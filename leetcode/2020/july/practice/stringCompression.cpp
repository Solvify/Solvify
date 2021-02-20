#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int get_digits(int n) {
        int count=0;
        while (n>0) {
            count++;
            n/=10;
        }
        return count;
    }
    int compress(vector<char>& chars) {
        int ptr=0,prev_i=0,i=0,n = chars.size();
        while(i<n) {
            if(chars[prev_i]!=chars[i+1] || i==n-1) {
                cout<<"i : "<<i<<" prev_i : "<<prev_i<<endl;
                int frq = i-prev_i+1,no_of_digits = get_digits(frq);

                if(frq>1) {
                    ptr+=no_of_digits;
                }
                cout<<"c  : "<<c<<endl;
                if(c >'1') {
                    cout<<"Yes"<<endl;
                    chars[ptr+1] = c;
                    ptr+=no_of_digits(i-prev_i+1)+1;
                }
                prev_i=i+1;
            }
            ++i;
        }
        for(char x: chars) cout<<x<<" ";

        cout<<"\n"<<ptr<<endl;
        return 0;
    }
};
int main() {
    vector<char> v {'a','b','b','b','b','b','b','b','b','b','b','b','b'};//{'a','a','b','b','c','c','c','c','c'};
    Solution solution;
    cout<<solution.compress(v);
    return 0;
}