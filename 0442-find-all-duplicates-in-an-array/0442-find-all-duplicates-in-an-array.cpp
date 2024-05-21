class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        nums.push_back(0);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] != nums[nums[i]])
                swap(nums[i], nums[nums[i]]);
        }

        for (int i = 1; i < n; i++) {
            cout << nums[i] << " ";
            if (i != nums[i])
                ans.push_back(nums[i]);
        }

        return ans;
    }
};