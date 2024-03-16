class Solution {
public:
    int sign(int a, int b) {
        if ((a >= 0 && b >= 0) || (a <= 0 && b <= 0)) return 1;
        return -1;
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        unordered_map<int, int> map;
        vector<int> ans;
        int product = 1;
        int product_without_zero = 1;
        int zero_count = 0;

        for (auto i : nums) {
            if (!i) zero_count++; 
            else product_without_zero *= i;
            product *= i;
        }      

        if (zero_count > 1) map[0] = 0;
        else map[0] = product_without_zero;

        int pos_product = abs(product);
        for (int i = 1, j = pos_product; i * i <= pos_product; i++, j--) {
            if (pos_product % i) continue;
            while (i * j != pos_product && j >= i) j--;
            map[i] = j;
            map[j] = i;
        }


        for (auto i : nums) {
            ans.push_back(sign(i, product) * map[abs(i)]);
        }
        
        return ans;
    }
};