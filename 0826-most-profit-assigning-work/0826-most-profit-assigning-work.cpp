class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size(), m = worker.size(), ans = 0;
        vector<int> pro_idx;
        for (int i = 0; i < n; ++i) pro_idx.push_back(i);
        sort(pro_idx.begin(), pro_idx.end(), [profit](int a, int b) {
            return profit[a] > profit[b];
        });
        for (auto i : pro_idx) {
            int d = difficulty[i];
            for (int j = 0; j < m; ++j) {
                int w = worker[j];
                if (w >= d) {
                    worker[j] = 0;
                    ans += profit[i];
                }
            }
        }
        return ans;
    }
};