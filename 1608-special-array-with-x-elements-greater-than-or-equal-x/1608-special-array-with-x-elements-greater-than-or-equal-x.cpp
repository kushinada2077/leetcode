class Solution {
public:
    int specialArray(vector<int>& nums) {
        int mx = nums.size();
        for (int x = 0; x <= mx; x++) {
            int cnt = 0;
            for (int i = 0; i < mx; i++) {
                if (nums[i] >= x) cnt++;
            }
            if (cnt == x) return x;
        }    

        return -1;
    }
};