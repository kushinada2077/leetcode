class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> map;
        int mx = -1;
        int ans = 0;

        for (auto i : nums) {
            if (map.find(i) != map.end()) {
                map[i] += 1;
            } else {
                map[i] = 1;
                }
            if (map[i] > mx)
                mx = map[i];
        }

        for (auto kv : map) {
            int val = get<1>(kv);
            if (val == mx)
                ans += val;
        }

        return ans;
    }
};