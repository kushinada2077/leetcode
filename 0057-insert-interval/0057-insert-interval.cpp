class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int> newInterval) {

        int i = 0;
        int len = intervals.size();
        int ns = newInterval[0], ne = newInterval[1];
        vector<vector<int>> ans;

        while (i < len && intervals[i][1] < ns) {
            ans.push_back(intervals[i++]);
        }

        if (i < len)
            ns = min(ns, intervals[i][0]);

        while (i < len && intervals[i][0] <= ne) {
            i++;
        }

        if (i)
            ne = max(ne, intervals[i - 1][1]);

        ans.push_back({ns, ne});

        while (i < len) {
            ans.push_back(intervals[i++]);
        }

        return ans;
    };
};