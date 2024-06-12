class Solution {
public:
    int partition(vector<int>& nums, int be, int en) {
        if (be == en)
            return be;
        int mid = (be + en) / 2;
        partition(nums, be, mid);
        partition(nums, mid + 1, en);
        merge(nums, be, en);
        return be;
    }
    void merge(vector<int>& nums, int be, int en) {
        int mid = (be + en) / 2;
        int l = be;
        int r = mid + 1;
        vector<int> tmp;

        while (l <= mid && r <= en) {
            if (nums[l] <= nums[r])
                tmp.push_back(nums[l++]);
            else
                tmp.push_back(nums[r++]);
        }

        while (l <= mid)
            tmp.push_back(nums[l++]);
        while (r <= en)
            tmp.push_back(nums[r++]);
        for (int i = be; i <= en; ++i)
            nums[i] = tmp[i - be];
    }
    void sortColors(vector<int>& nums) { partition(nums, 0, nums.size() - 1); }
};