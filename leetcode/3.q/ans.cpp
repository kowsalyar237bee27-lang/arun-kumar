#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        // Use an array for ASCII characters to store last seen positions
        std::vector<int> last_seen(256, -1);
        int max_len = 0;
        int left = 0; // Left boundary of the sliding window

        for (int right = 0; right < s.length(); right++) {
            char current = s[right];

            // If we've seen this char before and it's inside our current window
            if (last_seen[current] >= left) {
                // Move the left boundary to skip the duplicate
                left = last_seen[current] + 1;
            }

            // Update the last seen position of the character
            last_seen[current] = right;

            // Calculate the window size and update max_len
            max_len = std::max(max_len, right - left + 1);
        }

        return max_len;
    }
};
