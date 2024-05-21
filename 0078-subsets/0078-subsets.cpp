class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = (1 << nums.size());
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            vector<int> tmp;
            for (int j = 0; j < nums.size(); j++) {
                if (i & (1 << j)) {
                    tmp.push_back(nums[j]);
                }
            }
            ans.push_back(tmp);
        } 

        return ans;
    }
};