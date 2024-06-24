class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size(), m = worker.size(), ans = 0;
        priority_queue<int> pq(worker.begin(), worker.end());
        priority_queue<pair<int, int>> job;
        for (int i = 0; i < n; ++i) {
            int p = profit[i];
            int d = difficulty[i];
            job.push({p, d});
        }

        while (!job.empty() && !pq.empty()) {
            auto [p, d] = job.top();
            job.pop();
            while (!pq.empty() && pq.top() >= d) {
                ans += p;
                pq.pop();
            }
        } 
        return ans;
    }
};