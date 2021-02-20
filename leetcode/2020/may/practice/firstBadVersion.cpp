class Solution {
public:
    static bool isBadVersion(int m) {
        return m % 2 != 0;
    }

    static int firstBadVersion(int n) {
        int s = 1, e = n;

        while(s < e) {
            int m = s+(e-s)/2;

            if(isBadVersion(m)) {
                e = m;
            } else {
                s = m+1;
            }
        }
        return s;
    }
};