class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> map;
        map[0] = 1;
        int ans = 0;
        int sum = 0;

        for (auto num : nums) {
            sum += num;

            if (map.find(sum - goal) != map.end()) {
                ans += map[sum - goal];
            }

            map[sum]++;
        }

        return ans;
    }
};