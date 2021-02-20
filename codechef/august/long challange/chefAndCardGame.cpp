#include <iostream>
using namespace std;
 long find_sum_of_digits(long long n) {
     long sum=0;
    while (n>0) {
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        int chef_p=0,morty_p=0;
        while (n--) {
            long long c,m;
            cin>>c>>m;
            if(find_sum_of_digits(c)>find_sum_of_digits(m)) {
                chef_p++;
            } else if(find_sum_of_digits(c)<find_sum_of_digits(m)) {
                morty_p++;
            } else {
                chef_p++;
                morty_p++;
            }
        }
        if(chef_p > morty_p) {
            cout<<0<<" "<<chef_p<<endl;
        } else if(chef_p < morty_p) {
            cout<<1<<" "<<morty_p<<endl;
        } else {
            cout<<2<<" "<<chef_p<<endl;
        }
    }
    return 0;
}