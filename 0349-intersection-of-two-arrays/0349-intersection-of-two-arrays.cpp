class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        vector<int> ans;

        for (auto i : nums2) {
            if (set1.find(i) != set1.end()) {
                ans.push_back(i);
                set1.erase(i);
            }
        }

        return ans;
    }
};