// Bottom up
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }
        if (nums.size() == 1)
        {
            return nums.front();
        }

        vector<int> cash(nums.size(), 0);
        cash[0] = nums.front();
        cash[1] = std::max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i)
        {
            cash[i] = std::max(nums[i] + cash[i - 2], cash[i - 1]);
        }
        return cash.back();
    }
};
