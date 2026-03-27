#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        // Start with the first string as the potential prefix
        string prefix = strs[0];
        
        for (int i = 1; i < strs.size(); i++) {
            // Shorten the prefix until it matches the start of strs[i]
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
                
                // If prefix becomes empty, there's no common ground
                if (prefix.empty()) return "";
            }
        }
        
        return prefix;
    }
};
