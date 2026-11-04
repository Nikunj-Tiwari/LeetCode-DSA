class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> left, right;
        long long leftSum = 0, rightSum = 0;
        int need = (x + 1) / 2;

        auto balance = [&]() {
            int target = min(need, (int)(left.size() + right.size()));

            while (left.size() > target) {
                int val = *left.rbegin();
                left.erase(left.find(val));
                leftSum -= val;
                right.insert(val);
                rightSum += val;
            }

            while (left.size() < target) {
                int val = *right.begin();
                right.erase(right.find(val));
                rightSum -= val;
                left.insert(val);
                leftSum += val;
            }
        };

        auto add = [&](int val) {
            if (left.empty() || val <= *left.rbegin()) {
                left.insert(val);
                leftSum += val;
            } else {
                right.insert(val);
                rightSum += val;
            }
            balance();
        };

        auto remove = [&](int val) {
            auto it = left.find(val);

            if (it != left.end()) {
                left.erase(it);
                leftSum -= val;
            } else {
                right.erase(right.find(val));
                rightSum -= val;
            }

            balance();
        };

        vector<long long> cost(n - x + 1);

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x)
                remove(nums[i - x]);

            if (i >= x - 1) {
                long long median = *left.rbegin();

                cost[i - x + 1] =
                    median * left.size() - leftSum +
                    rightSum - median * right.size();
            }
        }

        const long long INF = 1LL << 60;

        vector<long long> prev(n + 1, 0);

        for (int t = 1; t <= k; t++) {
            vector<long long> curr(n + 1, INF);

            for (int i = 1; i <= n; i++) {
                curr[i] = curr[i - 1];

                if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(curr[i],
                        prev[i - x] + cost[i - x]);
                }
            }

            prev = curr;
        }

        return prev[n];
    }
};