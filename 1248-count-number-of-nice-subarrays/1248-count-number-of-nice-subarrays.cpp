class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> n2i;
        int cnt = 0, ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            if (n % 2)
                cnt++;
            n2i[cnt] = i;
            if (cnt == k)
                ans += n2i[cnt - k] + 2;
        }
        return ans;
    }
};