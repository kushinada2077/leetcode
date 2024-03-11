class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long long cpy = x;
        long long rev = 0;

        while (cpy > 0) {
            long long digit = cpy % 10;
            cpy /= 10;
            rev = rev * 10 + digit;
        }

        return x == rev;
    }
};