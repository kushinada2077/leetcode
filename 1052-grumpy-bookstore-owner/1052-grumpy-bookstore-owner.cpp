class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int st = 0, en = minutes, sum = 0, n = customers.size();
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0)
                sum += customers[i];
            else if (i < en)
                sum += customers[i];
        }
        int ans = sum;
        cout << ans;
        for (; en < n;) {
            if (grumpy[st++])
                sum -= customers[st];
            if (grumpy[en++])
                sum += customers[en - 1];
            ans = max(ans, sum);
        }

        return ans;
    }
};