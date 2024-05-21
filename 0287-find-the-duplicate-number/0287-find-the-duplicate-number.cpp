class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;

        do {
            int mid = (lo + hi) / 2;

            int cnt = 0;
            for (auto n : nums) {
                if (n <= mid) cnt++;
            }

            if (cnt > mid) hi = mid;
            else lo = mid;
        } while (lo + 1 < hi);

        return hi;
    }
};