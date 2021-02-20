#include <iostream>
using namespace std;
int main() {
   int t;
   cin>>t;
   while (t--) {
       int n;
       cin>>n;
       long skips=0;
       long curr,prev;
       for(int i=0; i<n; i++) {
           cin>>curr;
           if(i==0) {
               prev = curr;
           } else {
               skips+=abs(curr-prev)-1;
               prev = curr;
           }
       }
       cout<<skips<<endl;
   }
    return 0;
}