class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<int, int>> fractions;
        int sz = arr.size();
        for (int i = 0; i < sz - 1; i++) {
            for (int j = i + 1; j < sz; j++) {
                fractions.push_back({arr[i], arr[j]});
            }
        }

        sort(fractions.begin(), fractions.end(),
             [](pair<int, int> a, pair<int, int> b) {
                 return (double)a.first / (double)a.second <
                        (double)b.first / (double)b.second;
             });

            return {fractions[k-1].first, fractions[k-1].second};
    }
};