class Solution {
public:
    bool isAvail(set<int>& nums, int inte, int m, int st) {
        int cnt = 0, cur = st;
        while (cnt < m) {
            auto lo = nums.lower_bound(cur);
            if (lo == nums.end())
                return false;
            cur = *lo + inte;
            cnt++;
        }
        return true;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        set<int> nums(position.begin(), position.end());
        int lo = 1, hi = 1e9;
        while (lo + 1 < hi) {
            int inte = (lo + hi) / 2;
            cout << hi << " " << lo << " " << inte << "\n";
            if (isAvail(nums, inte, m, position[0]))
                lo = inte;
            else
                hi = inte;
        }
        return lo;
    }
};