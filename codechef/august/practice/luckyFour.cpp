#include <iostream>
using namespace std;
int lucky_four(long n) {
    int count=0;
    while (n>0) {
        if(n%10==4) count++;
        n/=10;
    }
    return count;
}
int main() {
    int t;
    long n;
    cin>>t;
    while (t--) {
        cin>>n;
        cout<<lucky_four(n)<<endl;
    }
    return 0;
}