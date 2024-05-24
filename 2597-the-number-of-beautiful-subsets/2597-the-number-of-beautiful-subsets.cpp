class Solution {
public:
    vector<int> cnt = vector<int>(4001, 0);
    int ans, n;
    void sol(int p, vector<int>& nums, int k) {
        if (p == n) {
            ans++;
            return;
        }

        int nxt = nums[p];

        sol(p + 1, nums, k);
        if (!cnt[nxt + k + 1000] && !cnt[nxt - k + 1000]) {
            cnt[nxt + 1000]++;
            sol(p + 1, nums, k);
            cnt[nxt + 1000]--;
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        n = nums.size();
        ans = -1;
        sol(0, nums, k);
        return ans;
    }
};