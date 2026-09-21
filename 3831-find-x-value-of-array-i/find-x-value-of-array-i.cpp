class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> answer(k, 0);
        vector<long long> dp(k, 0);
        for (int num : nums) {
            vector<long long> next(k, 0);
            int value = num % k;
            next[value] = 1;
            for (int remainder = 0; remainder < k; ++remainder) {
                int newRemainder = (remainder * value) % k;
                next[newRemainder] += dp[remainder];
            }
            for (int remainder = 0; remainder < k; ++remainder) {
                answer[remainder] += next[remainder];
            }
            dp = next;
        }
        return answer;
    }
};