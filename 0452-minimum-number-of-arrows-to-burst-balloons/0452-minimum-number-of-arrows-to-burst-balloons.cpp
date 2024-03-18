class Solution {
public:
    bool isOverlapped(vector<int> a1, vector<int> a2) {
        return !(a1[1] < a2[0] || a1[1] < a2[0]);
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        vector<int> pre = points[0];
        int ans = 1, len = points.size();
        
        for (int i = 1; i < len; i++) {
            auto se = points[i];
            int s = se[0], e = se[1];

            if (isOverlapped(pre, se)) {
                pre = { max(s, pre[0]), min(e, pre[1])};
            }
            else {
                ans++;
                pre = points[i];
            }
        }

        return ans;
    }
};