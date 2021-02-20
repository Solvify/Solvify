#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int num;
    cout << "Enter the number ";
    cin>>num;
    double sqrt_root = sqrt(num);
    num = sqrt_root;
    if(sqrt_root==(double)num) {
        cout<<"Yes";
    } else {
        cout<<"No";
    }
    return 0;
}