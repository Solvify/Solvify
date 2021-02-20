#include <iostream>
#include <vector>
using namespace std;
int check_lapindrome(string & s) {
    int n = s.size(),m=0;
    m = n/2;
    vector<int> frq(123,0);
    for(int i=0; i<m; i++) {
        frq[s[i]]++;
    }
    if(n%2==1)   m+=1;
    for(int i=n-1; i>=m; i--) {
        frq[s[i]]--;
    }
    m=1;
    for(int i=97; i<123; i++) {
       if(frq[i]!=0) {
           m=0;
       }
    }

    return m;
}
int main() {
    int t;
    cin>>t;
    while (t--) {
        string s;
        cin>>s;
        if(check_lapindrome(s)) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }

    }
}