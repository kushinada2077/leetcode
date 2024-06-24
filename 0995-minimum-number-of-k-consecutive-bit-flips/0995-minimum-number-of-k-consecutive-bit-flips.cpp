class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int flipped = 0, ans = 0, n = nums.size();
        vector<int> isFlipped(n, 0);
        for (int i = 0; i < n; ++i) {
            if (i >= k) {
                flipped ^= isFlipped[i - k];
            }
            if (flipped == nums[i]) {
                if (i + k > n) return -1;
                isFlipped[i] ^= 1;
                flipped ^= 1;
                ans++;
            }
        }
        return ans;
    }
};
