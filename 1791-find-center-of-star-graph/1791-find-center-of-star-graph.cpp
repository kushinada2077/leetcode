class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> indeg(n + 1, 0);

        for (auto e : edges) {
            auto [v, u] = tie(e[0], e[1]);
            indeg[v]++;
            indeg[u]++;
            if (indeg[v] == n - 1)
                return v;
            if (indeg[u] == n - 1)
                return u;
        }

        return 0;
    }
};