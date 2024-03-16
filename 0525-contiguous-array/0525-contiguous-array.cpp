class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> map;
        int sum = 0;
        int ans = 0;
        map[0] = -1;

        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i] ? 1 : -1;
            sum += val;

            if (map.find(sum) != map.end()) {
                ans = max(ans, i - map[sum]);
            }

            if (sum && map.find(sum) == map.end()) map[sum] = i;
        }

        return ans;
    }
};