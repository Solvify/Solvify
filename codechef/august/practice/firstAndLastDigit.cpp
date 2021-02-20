#include <iostream>
using namespace std;
int find_sum_of_first_and_last_digit(int n) {
    int sum=n%10;
    if(n<=9) return 2*n;
    else {
        int first_digit=0;
        while (n>0) {
            first_digit = n%10;
            n/=10;
        }
        sum+=first_digit;
    }
    return sum;
}
int main() {
    int t,n;
    cin>>t;
    while (t--) {
        cin>>n;
        cout<<find_sum_of_first_and_last_digit(n)<<endl;
    }
    return 0;
}