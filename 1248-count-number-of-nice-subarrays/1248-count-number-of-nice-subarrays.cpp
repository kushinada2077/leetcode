class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> n2i;
        n2i[-1] = 0;
        int cnt = 0, ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            if (n % 2)
                cnt++;
            n2i[cnt] = i + 1;
            if (cnt == k) ans++;
            if (cnt - k >= 0)
                ans += n2i[cnt - k] - n2i[cnt - k - 1];
        }
        return ans;
    }
};