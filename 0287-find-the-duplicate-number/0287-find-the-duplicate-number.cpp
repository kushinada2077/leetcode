class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int d[100001];
        fill(d, d + 100001, 0);

        for (auto n : nums) {
            if (d[n]) return n;
            d[n]++;
        }

        return 0;
    }
};