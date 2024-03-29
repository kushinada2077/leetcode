class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        int begin = 0;
        int end = 0;
        vector<int> mx_idxs;
        int cnt = 0;
        long long ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];

            if (n == mx) {
                mx_idxs.push_back(i);
                cnt++;

                if (cnt > k) {
                    begin++;
                    end++;
                    ans += mx_idxs[begin] + 1;
                } else if (cnt == k) {
                    ans += mx_idxs[begin] + 1;
                } else {
                    end++;
                }
            } else if (mx_idxs.size() && cnt >= k) {
                ans += mx_idxs[begin] + 1;
            }
        }

        return ans;
    }
};