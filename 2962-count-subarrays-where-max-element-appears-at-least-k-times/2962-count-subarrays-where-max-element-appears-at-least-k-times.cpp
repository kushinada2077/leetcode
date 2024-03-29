class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        int left = 0, right = 0, n = nums.size();

        while (right < n) {
            k -= (nums[right++] == mx);
            while (k == 0) {
                k += (nums[left++] == mx);
            }
            ans += left;
        }

        return ans;
    }
};