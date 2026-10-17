class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> sorted;
        sorted.reserve(n);

        for (int x : nums) {
            int sum = 0;
            for (int y = x; y > 0; y /= 10) {
                sum += y % 10;
            }
            sorted.push_back({sum, x});
        }

        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> targetIndex;
        for (int i = 0; i < n; ++i) {
            targetIndex[sorted[i].second] = i;
        }

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i] || targetIndex[nums[i]] == i) {
                continue;
            }

            int cycleLength = 0;
            int current = i;

            while (!visited[current]) {
                visited[current] = true;
                current = targetIndex[nums[current]];
                ++cycleLength;
            }

            swaps += cycleLength - 1;
        }

        return swaps;
    }
};