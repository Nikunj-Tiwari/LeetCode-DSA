class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            int reverseAlphabetPos = 'z' - s[i] + 1;
            ans += reverseAlphabetPos * (i + 1);
        }
        return ans;
    }
};