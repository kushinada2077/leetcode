class Solution {
public:
    bool isPalindrome(int x) {
        vector<char> nums;
        int copy = x;

        if (copy < 0) return false;
        
        while (copy > 0) {
            nums.push_back(copy % 10);
            copy /= 10;
        } 

        int left = 0, right = nums.size() - 1;

        while (left < right) {
            if (nums[left++] != nums[right--]) return false;
        }

        return true;
    }
};