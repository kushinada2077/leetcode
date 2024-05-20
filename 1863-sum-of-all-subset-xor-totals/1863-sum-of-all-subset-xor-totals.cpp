class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int len = nums.size(), brute = (1 << len), ans = 0;
        for (int i = 0; i < brute; i++) {
            int XOR = 0;
            for (int j = 0; j < len; j++) {
                if (i & (1 << j)) {
                    XOR ^= nums[j];
                }
            }
            ans += XOR;
        }

        return ans;
    }
};