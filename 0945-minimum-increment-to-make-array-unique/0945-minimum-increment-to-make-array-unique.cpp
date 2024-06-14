class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        unordered_map<int, int> m;
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 0;
        for (auto n : nums) {
            m[n]++;
            if (m[n] > 1)
                pq.push(n);
        }
        int u = 1;
        while (!pq.empty()) {
            int n = pq.top();
            pq.pop();
            while (u <= n || m[u] > 0)
                u++;
            ans += u - n; 
            m[u]++;
        }
        return ans;
    }
};