class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size(), m = worker.size(), ans = 0;
        vector<int> pro_idx;
        for (int i = 0; i < n; ++i) pro_idx.push_back(i);
        sort(pro_idx.begin(), pro_idx.end(), [profit](int a, int b) {
            return profit[a] > profit[b];
        });
        priority_queue<int> pq(worker.begin(), worker.end());
        for (auto i : pro_idx) {
            int d = difficulty[i];
            int p = profit[i];
            while (!pq.empty() && pq.top() >= d) {
                ans += p;
                pq.pop();
            }
            if (pq.empty()) break;
        }
        return ans;
    }
};