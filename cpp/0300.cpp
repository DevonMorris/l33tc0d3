class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> longest(nums.size(), 1);
        int max_longest = 1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (nums[i] < nums[j])
                {
                    longest[i] = std::max(longest[i], 1 + longest[j]);
                }
            }
            max_longest = std::max(max_longest, longest[i]);
        }
        return max_longest;
    }
};
