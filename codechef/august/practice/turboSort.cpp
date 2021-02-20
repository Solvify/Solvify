#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int t, arr[1000001]={0}, b;
    cin>>t;
    while(t--) {
        cin>>b;
        arr[b]++;
    }
    for(int i=0; i<1000001; i++) {
        while(arr[i]>0) {
           cout<<i<<endl;
            arr[i]--;
        }
    }
    return 0;
}