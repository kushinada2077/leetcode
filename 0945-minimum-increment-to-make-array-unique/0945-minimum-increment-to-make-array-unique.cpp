class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int u = 0, ans = 0;
        for (auto n : nums) {
            u = max(u, n);
            ans += u - n;
            u++;
        }
        return ans;
    }
};