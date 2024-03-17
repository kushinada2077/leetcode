class Solution {
public:
    bool isOverlapped(int ns, int ne, int s, int e) {
        return (s <= ns && ns <= e) || (s <= ne && ne <= e)
         || (ns <= s && s <= ne) || (ns <= e && e <= ne);
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        if (!intervals.size())
            return {newInterval};

        vector<vector<int>> ans;
        int len = intervals.size();
        int sIdx = -1, eIdx = -1;
        int ns = newInterval[0], ne = newInterval[1];

        for (int i = 0; i < len; i++) {
            auto se = intervals[i];
            int s, e;
            s = se[0];
            e = se[1];
            if (isOverlapped(ns, ne, s, e)) {
                sIdx = i;
                break;
            }
        }

        for (int i = len - 1; i >= 0; i--) {
            auto se = intervals[i];
            int s, e;
            s = se[0];
            e = se[1];
            if (isOverlapped(ns, ne, s, e)) {
                eIdx = i;
                break;
            }
        }

        if (sIdx == -1 && eIdx == -1) {
            intervals.push_back(newInterval);
            sort(intervals.begin(), intervals.end());
            return intervals;
        }

        for (int i = 0; i < sIdx; i++)
            ans.push_back(intervals[i]);
        ans.push_back({min(intervals[sIdx][0], newInterval[0]),
                       max(intervals[eIdx][1], newInterval[1])});
        for (int i = eIdx + 1; i < len; i++)
            ans.push_back(intervals[i]);

        return ans;
    };
};