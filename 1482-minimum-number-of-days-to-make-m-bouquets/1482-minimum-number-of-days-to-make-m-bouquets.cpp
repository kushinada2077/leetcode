class Solution {
public:
    int numBouquet(vector<int>& bloomDay, int k, int d) {
        int seq = 0, ret = 0;
        for (auto day : bloomDay) {
            if (day > d) {
                seq = 0;
                continue;
            }
            if (++seq == k) {
                ret++;
                seq = 0;
            }
        }

        return ret;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (m > n / k) return -1;
        int lo = 0, hi = 1e9;
        while (lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            int num = numBouquet(bloomDay, k, mid);
            if (num >= m) hi = mid;
            else lo = mid;
        } 
        return hi;
    }
};