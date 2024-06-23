#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ll ans = 0;
        int n = nums.size();
        int st = -1, mn = -1, mx = -1;
        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            if (v > maxK || v < minK) st = i;
            if (v == maxK) mx = i;
            if (v == minK) mn = i;
            int tmp = min(mx, mn) - st;
            ans += tmp > 0 ? tmp : 0;
        }
        return ans;
    }
};