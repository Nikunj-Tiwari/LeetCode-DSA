class Solution {
    vector<vector<int>> g;
    vector<int> ans, last;
    string str;

    void dfs(int x, int par) {
        int c = str[x] - 'a';
        int np = last[c] == -1 ? par : last[c];
        int prev = last[c];
        last[c] = x;
        ans[x] = 1;
        for (int y : g[x]) dfs(y, x);
        last[c] = prev;
        if (x != 0) ans[np] += ans[x];
    }

public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        str = s;
        g.assign(n, {});
        ans.assign(n, 0);
        last.assign(26, -1);
        for (int i = 1; i < n; i++) g[parent[i]].push_back(i);
        dfs(0, -1);
        return ans;
    }
};