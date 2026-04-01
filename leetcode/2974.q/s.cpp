class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        // Sort to easily pick the minimums in order
        sort(nums.begin(), nums.end());
        
        // Swap adjacent elements (Bob's pick, then Alice's pick)
        for (int i = 0; i < nums.size(); i += 2) {
            swap(nums[i], nums[i + 1]);
        }
        
        return nums;
    }
};

