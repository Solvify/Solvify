#include <iostream>
using namespace std;
int main() {
    long n;
    cin>>n;
    int i=0;
    while (true) {
        if(n<i) break;
        n-=i;
        i++;
    }
    cout<<i-1<<endl;
    return 0;
}