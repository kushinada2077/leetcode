class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> map;
        int sum = 0;
        int ans = 0;
        map[0] = -1;

        for (int i = 0; i < n; i++) {
            int val = nums[i] ? 1 : -1;
            sum += val;

            if (map.find(sum) != map.end())
                ans = max(ans, i - map[sum]);
            else if (sum)
                map[sum] = i;
        }

        return ans;
    }
};