class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans = 0, sum = 0;
        queue<int> q;
        for (int i = 0; i < s.size(); ++i) {
            int diff = abs(s[i] - t[i]);
            while (!q.empty() && sum + diff > maxCost) {
                sum -= q.front();
                q.pop();
            }
            if (sum + diff > maxCost) continue;
            sum += diff;
            q.push(diff);
            ans = max(ans, (int)q.size());
        }

        return ans;
    }
};