#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int withdraw;
    double sum;
    cin>>withdraw>>sum;
    if( withdraw >0 && withdraw < sum) {
        if(withdraw%5==0){
            sum-=(withdraw+0.5);
        }
    }
    cout << fixed << setprecision (2) << sum;
    return 0;
}