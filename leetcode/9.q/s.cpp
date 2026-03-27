#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        // Special cases:
        // 1. Negative numbers are not palindromes.
        // 2. If the last digit is 0, the first digit must be 0 (only true for x = 0).
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // When the length is odd, we can get rid of the middle digit by revertedNumber/10
        // For example, if x = 121, at the end of the loop: x = 1, revertedNumber = 12
        // Since the middle digit doesn't matter for palindrome, we use revertedNumber/10
        return x == revertedNumber || x == revertedNumber / 10;
    }
};
