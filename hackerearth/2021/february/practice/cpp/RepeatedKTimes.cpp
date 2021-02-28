#include<iostream>
#include<map>

using namespace std;

int main() {

    int N, t, K;
    cin >> N;
    map<int, int> mp;
    while (N--) {
        cin >> t;
        mp[t]++;
    }
    cin >> K;

    for (auto const& p : mp) {
        if (p.second == K) {
            cout << p.first << endl;
            break;
        }

    }
}