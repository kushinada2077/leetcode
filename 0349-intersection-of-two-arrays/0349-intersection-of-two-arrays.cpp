class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        vector<int> ans;

        for (auto i : nums1) {
            map[i] = map.count(i) + 1;
        }
        for (auto i : nums2) {
            if (map.count(i)) {
                map.erase(i);
                ans.push_back(i);
            } 
        }

        return ans;
    }
};