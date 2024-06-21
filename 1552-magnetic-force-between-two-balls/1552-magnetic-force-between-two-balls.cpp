class Solution {
public:
    bool isPossible(vector<int>& pos, int dist, int m) {
        int last = pos[0];
        int cnt = 1;
        for (int i = 1; i < pos.size(); ++i) {
            if (pos[i] - last >= dist) {
                last = pos[i];
                cnt++;
            } 
        }
        return cnt >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int lo = 1, hi = (position[n - 1] - position[0]) / (m - 1) + 1;
        while (lo + 1 < hi) {
            int dist = (lo + hi) / 2;
            if (isPossible(position, dist, m)) lo = dist;
            else hi = dist;
        } 
        return lo;
    }
};