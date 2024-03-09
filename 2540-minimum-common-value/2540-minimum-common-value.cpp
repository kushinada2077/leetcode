class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> map;

        for (auto i : nums1) {
            map[i] = true;
        } 

        for (auto i : nums2) {
            if (map.find(i) != map.end()) {
                return i;
            }
        }

        return -1;
    }
};