#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_water = 0;

        while (left < right) {
            // Calculate current width and height
            int width = right - left;
            int current_height = min(height[left], height[right]);
            
            // Update max area if current is larger
            max_water = max(max_water, current_height * width);

            // Move the pointer that points to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_water;
    }
};
