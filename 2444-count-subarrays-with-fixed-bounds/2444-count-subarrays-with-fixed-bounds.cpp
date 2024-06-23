#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ll ans = 0;
        deque<int> de, in;
        int l = 0, minI = -1, maxI = -1;
        for (int r = 0; r < nums.size(); ++r) {
            int v = nums[r];
            while (!de.empty() && nums[de.back()] < v)
                de.pop_back();
            de.push_back(r);
            if (v == maxK) maxI = r;
            while (!in.empty() && nums[in.back()] > v)
                in.pop_back();
            in.push_back(r);
            if (v == minK) minI = r;
            while (l < r && (nums[de.front()] > maxK || nums[in.front()] < minK)) {
                if (nums[de.front()] == nums[l])
                    de.pop_front();
                if (nums[in.front()] == nums[l])
                    in.pop_front();
                l++;
            }
            if (nums[de.front()] == maxK && nums[in.front()] == minK) {
                ans += min(minI, maxI) - l + 1;
            }
        }
        return ans;
    }
};