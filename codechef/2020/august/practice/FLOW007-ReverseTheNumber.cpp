#include <iostream>
using namespace std;
int reverse(int n) {
    int num=0;
    while (n>0) {
        num = num*10 + n%10;
        n/=10;
    }
    return num;
}
int main() {
    int t;
    int n;
    cin>>t;
    while (t--) {
        cin>>n;
        cout<<reverse(n)<<endl;
    }
    return 0;
}