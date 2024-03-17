class Solution {
public:
    struct SE {
        int s, e;
    };
    bool isOverlapped(SE se1, SE se2) {
        return !(se1.s > se2.e || se2.s > se1.e);
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int> newInterval){

        vector<vector<int>> ans;
        int ns = newInterval[0], ne = newInterval[1];
        int mn = ns, mx = ne;
        bool sw = true;
        for (auto se: intervals) {
            int s, e;
            s = se[0];
            e = se[1];

            if (isOverlapped({s, e}, {ns, ne})) {
                mn = min(s, mn);
                mx = max(e, mx); 
            }
            else ans.push_back(se);
        }

        ans.push_back({mn, mx});
        sort(ans.begin(), ans.end());
        return ans;
    };
};