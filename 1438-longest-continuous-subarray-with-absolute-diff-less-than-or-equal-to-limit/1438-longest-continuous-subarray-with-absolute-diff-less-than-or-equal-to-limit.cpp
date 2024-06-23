class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> in;
        deque<int> de;
        int l = 0, ans = 1;
        for (int r = 0; r < nums.size(); ++r) {
            while (!in.empty() && nums[r] < in.back()) in.pop_back();
            in.push_back(nums[r]);
            while (!de.empty() && nums[r] > de.back()) de.pop_back();
            de.push_back(nums[r]);
            while (limit < de.front() - in.front()) {
                if (in.front() == nums[l]) in.pop_front();
                if (de.front() == nums[l]) de.pop_front();
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};