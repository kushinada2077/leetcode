class Solution {
public:
    int sum(int a, int b) { return (a + b) * (b - a + 1) / 2; }
    int pivotInteger(int n) {
        int pivot = 1;

        while (true) {
            if (sum(1, pivot) == sum(pivot, n)) {
                return pivot;
            }
            if (pivot == n)
                return -1;
            else pivot++;
        }
    }
};