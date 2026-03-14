#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> num_map; // Stores: value -> index

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            // Check if the complement already exists in the map
            if (num_map.find(complement) != num_map.end()) {
                return {num_map[complement], i};
            }

            // Store current number and its index
            num_map[nums[i]] = i;
        }

        return {}; // Should not reach here per constraints
    }
};
