class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int i = 0;
        while (i <= high) {
            if (nums[i] == 0) {
                std::swap(nums[i], nums[low]);
                ++low;
                ++i;
            } else if (nums[i] == 2) {
                std::swap(nums[i], nums[high]);
                --high;
            } else {
                ++i;
            }
        }
        return;
    }
};
