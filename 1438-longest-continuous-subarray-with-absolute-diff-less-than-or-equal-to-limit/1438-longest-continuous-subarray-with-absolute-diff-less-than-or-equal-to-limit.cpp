class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> m;
        m.insert(nums[0]);
        int st = 0, en = 1, ans = 1;

        while (true) {
            int mx = *prev(m.end());
            int mn = *m.begin();
            while (limit < abs(mx - mn)) {
                m.erase(m.find(nums[st++]));
                mx = *prev(m.end());
                mn = *m.begin();
            }
            ans = max(ans, en - st);
            if (en >= nums.size()) break;
            if (limit >= abs(mx - mn))
                m.insert(nums[en++]);
        }
        return ans;
    }
};