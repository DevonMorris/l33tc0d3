class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0;
        while (i < nums.size() && nums[i] < 0) {
            ++i;
        }

        std::vector<int> out{};
        int j = i - 1;
        while (out.size() < nums.size()) {
            if (i > nums.size() - 1) {
                out.push_back(nums[j] * nums[j]);
                --j;
                continue;
            }
            if (j < 0) {
                out.push_back(nums[i] * nums[i]);
                ++i;
                continue;
            }

            if (std::abs(nums[j]) < std::abs(nums[i])) {
                out.push_back(nums[j] * nums[j]);
                --j;
            } else {
                out.push_back(nums[i] * nums[i]);
                ++i;
            }

        }
        return out;
    }
};
