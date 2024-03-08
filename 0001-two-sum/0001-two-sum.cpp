class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i];

            if (map.find(target - val) == map.end()) {
                map[val] = i;
            }
            else {
                ans = { i, map.at(target - val) };
                break;
            }
        }

        return ans;
    }
};