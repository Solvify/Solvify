#include <iostream>
using namespace std;
unsigned long int fact(unsigned int n) {
    unsigned long int res = 1;
    for (int i = 1; i <= n; ++i) {
        res *= i;
    }
    return res;
}

unsigned long int binomialCoefficient(unsigned int n, unsigned int k) {
    unsigned long int res = 1;

    if (k > n - k)
        k = n - k;

    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

unsigned long int catalan(unsigned int n) {
    unsigned long int c = binomialCoefficient(2*n, n);
    return c/(n+1);
}

int numTrees(int n) {
    unsigned long int count = catalan(n);
    return count;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}