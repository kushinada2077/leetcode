class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) return false;

        int cpy = x;
        int rev = 0;

        while (cpy > rev) {
            rev = rev * 10 + cpy % 10;
            cpy /= 10;
        }

        return cpy == rev || cpy == rev / 10;
    }
};