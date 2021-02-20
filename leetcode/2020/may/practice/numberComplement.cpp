#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int num, complement = 0, power = 0;
    cin>>num;
    while (num>0) {
        int rem;
        rem = num%2;
        if(rem==0) {
            complement+=pow(2,power);
        }
        ++power;
        num/=2;
    }

    cout<<complement;

    return 0;
}