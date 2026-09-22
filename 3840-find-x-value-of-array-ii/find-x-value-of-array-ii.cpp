class Solution {
    struct Node {
        int prod;
        array<int, 5> cnt{};
        Node(int p = 0) : prod(p) {}
    };
    int K;
    Node mergeNode(const Node& L, const Node& R) {
        Node res;
        res.prod = (L.prod * R.prod) % K;
        for (int x = 0; x < K; x++) {
            res.cnt[x] = L.cnt[x];
        }
        for (int x = 0; x < K; x++) {
            if (R.cnt[x]) {
                int rem = (L.prod * x) % K;
                res.cnt[rem] += R.cnt[x];
            }
        }
        return res;
    }
    Node makeNode(int val) {
        Node res;
        res.prod = val % K;
        res.cnt[res.prod] = 1;
        return res;
    }
public:
    vector<int> resultArray(vector<int>& nums, int k,
                            vector<vector<int>>& queries) {
        K = k;
        int n = nums.size();
        int size = 1;
        while (size < n)
            size <<= 1;
        vector<Node> tree(2 * size);
        for (int i = 0; i < n; i++) {
            tree[size + i] = makeNode(nums[i]);
        }
        for (int i = size - 1; i >= 1; i--) {
            tree[i] = mergeNode(tree[i << 1], tree[i << 1 | 1]);
        }
        Node identity;
        identity.prod = 1 % K;
        auto update = [&](int pos, int val) {
            int p = size + pos;
            tree[p] = makeNode(val);
            p >>= 1;
            while (p) {
                tree[p] = mergeNode(tree[p << 1],
                                    tree[p << 1 | 1]);
                p >>= 1;
            }
        };
        auto query = [&](int l, int r) {
            Node left = identity;
            Node right = identity;
            l += size;
            r += size;
            while (l < r) {
                if (l & 1) {
                    left = mergeNode(left, tree[l]);
                    l++;
                }
                if (r & 1) {
                    --r;
                    right = mergeNode(tree[r], right);
                }
                l >>= 1;
                r >>= 1;
            }
            return mergeNode(left, right);
        };
        vector<int> ans;
        ans.reserve(queries.size());
        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];
            update(index, value);
            Node res = query(start, n);
            ans.push_back(res.cnt[x]);
        }
        return ans;
    }
};