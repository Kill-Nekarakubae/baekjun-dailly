#include<algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) return s.size();

        bool exists[257];
        fill(exists, exists+257, false);
        int maxi = 1;

        int b = 0, e = 1;
        exists[s.at(b)] = true;
        while (b<=e) {
            if (e<s.size() && !exists[s.at(e)] ) {
                exists[s.at(e)] = true;
                e++;
            } else if (b<s.size()) {
                exists[s.at(b)] = false;
                b++;
            } else {
                b++;
            }
            maxi = max(maxi, e-b);
        }

        return maxi;
    }
};