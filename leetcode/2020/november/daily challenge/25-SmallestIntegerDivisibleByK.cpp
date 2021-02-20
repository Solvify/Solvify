#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int K) {
        unordered_map<int,int> remenders;
        int len = 1, curr_rem = 1;
        while (1){
            int rem = curr_rem % K;
            if(rem == 0)    return len;
            if(remenders[rem])  return -1;
            remenders[rem]++;
            curr_rem = rem*10 +1;
            len++;
        }
        
       return -1;
    }

    // Fastest Solution
    
    int smallestRepunitDivByKFastest(int K) {
        int rm=0;
        for (int i = 1; i <= K; i++) {
            cout << i << endl;
            if ( (rm = (rm * 10 + 1) % K) == 0)
                    return i;
        }
        return -1;
    }
    
};

int main() {
    Solution solution;
    cout << solution.smallestRepunitDivByKFastest(23) << endl;
    return 0;
}