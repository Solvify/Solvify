#include <iostream>
using namespace std;
int fact(int n) {
    if(n==1)    return 1;
    else return n *fact(n-1);
}
string find_permutation_sequence(int l,int u,int n, int k) {
    if(1) {

    } else {
        int next_l,next_u;
        int steps = u/n;

        for(int i=l; i<=u; i+=steps){
            if(i>k) {
                next_u = i-1;
                next_l = i- steps;
                break;
            }
        }

        find_permutation_sequence(1,steps,n-1,k-next_l+1)

    }
}
int main() {
    int n,k;

    cin>>n>>k;

    find_permutation_sequence(1,fact(n),n,k);
    return 0;
}