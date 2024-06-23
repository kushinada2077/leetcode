class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 1, mn = nums[0];
        for (auto v : nums) {
            if (v - mn > k) {
                ans++;
                mn = v;
            }
        }
        return ans;
    }
};