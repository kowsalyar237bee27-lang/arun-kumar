#include <string>
#include <vector>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        // Edge case: if rows is 1 or string is short, no zigzag happens
        if (numRows <= 1 || s.length() <= numRows) return s;

        std::vector<std::string> rows(std::min(numRows, (int)s.length()));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            
            // If we hit the top or bottom row, change direction
            if (curRow == 0 || curRow == numRows - 1) {
                goingDown = !goingDown;
            }
            
            // Move the cursor
            curRow += goingDown ? 1 : -1;
        }

        // Combine all rows into a single string
        std::string result;
        for (const std::string& row : rows) {
            result += row;
        }
        
        return result;
    }
};
