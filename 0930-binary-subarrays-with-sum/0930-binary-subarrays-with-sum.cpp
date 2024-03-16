class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> map;
        map[0] = -1;
        int sum = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            sum += val;
            if (map.find(sum - goal) != map.end()) {
                int from = map[sum - goal] + 1;
                ans++;

                while (from < i && nums[from] == 0) {
                    ans++;
                    from++;
                }
            }

            if (map.find(sum) == map.end()) map[sum] = i;
        }
        return ans;
    }
};