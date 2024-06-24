class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int flipped = 0, ans = 0, n = nums.size();
        vector<int> isFlipped(n, 0);

        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k)
                flipped ^= isFlipped[i - k];
            if (nums[i] == flipped) {
                if (i + k > n) return -1;
                ans++;
                isFlipped[i] = 1;
                flipped ^= 1;
            }
        }
        return ans;
    }
};
