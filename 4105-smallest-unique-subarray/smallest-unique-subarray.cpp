class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        const uint64_t MOD1 = 1000000007ULL, BASE1 = 131542391ULL;
        const uint64_t MOD2 = 998244353ULL,  BASE2 = 1000000021ULL;

        auto existsUnique = [&](int L) -> bool {
            uint64_t pow1 = 1, pow2 = 1;
            for (int i = 0; i < L - 1; i++) {
                pow1 = (pow1 * BASE1) % MOD1;
                pow2 = (pow2 * BASE2) % MOD2;
            }

            uint64_t h1 = 0, h2 = 0;
            for (int i = 0; i < L; i++) {
                uint64_t v1 = (uint64_t)(long long)nums[i] % MOD1;
                uint64_t v2 = (uint64_t)(long long)nums[i] % MOD2;
                h1 = (h1 * BASE1 + v1) % MOD1;
                h2 = (h2 * BASE2 + v2) % MOD2;
            }

            unordered_map<uint64_t, int> count;
            count[h1 * MOD2 + h2]++;

            for (int i = L; i < n; i++) {
                uint64_t outV1 = (uint64_t)(long long)nums[i - L] % MOD1;
                uint64_t outV2 = (uint64_t)(long long)nums[i - L] % MOD2;
                uint64_t inV1  = (uint64_t)(long long)nums[i] % MOD1;
                uint64_t inV2  = (uint64_t)(long long)nums[i] % MOD2;

                h1 = (h1 + MOD1 - (outV1 * pow1) % MOD1) % MOD1;
                h1 = (h1 * BASE1 + inV1) % MOD1;

                h2 = (h2 + MOD2 - (outV2 * pow2) % MOD2) % MOD2;
                h2 = (h2 * BASE2 + inV2) % MOD2;

                count[h1 * MOD2 + h2]++;
            }

            for (auto& [key, c] : count) {
                if (c == 1) return true;
            }
            return false;
        };

        int lo = 1, hi = n, ans = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (existsUnique(mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};