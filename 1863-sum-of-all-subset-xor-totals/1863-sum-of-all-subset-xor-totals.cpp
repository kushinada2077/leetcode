class Solution {
    int sum = 0;
public:
    void sol(int n, int res, vector<int>& nums) {
        if (n == nums.size()) {
            sum += res;
            return;
        }
        sol(n + 1, res ^ nums[n], nums);
        sol(n + 1, res, nums);
    }
    int subsetXORSum(vector<int>& nums) {
        sol(0, 0, nums);
        return sum;
    }
};