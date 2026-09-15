class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        vector<vector<bool>> pal(n, vector<bool>(n, false));
        for (int r = 0; r < n; ++r) {
            dp[r + 1] = dp[r];
            for (int l = r; l >= 0; --l) {
                if (s[l] == s[r] && (r - l < 2 || pal[l + 1][r - 1])) {
                    pal[l][r] = true;
                    if (r - l + 1 >= k) {
                        dp[r + 1] = max(dp[r + 1], dp[l] + 1);
                    }
                }
            }
        }
        return dp[n];
    }
};