class Solution {
  public:
    int findMin(vector<int>& nums) {
      int start_idx = 0;
      int end_idx = nums.size() - 1;
      int middle_idx = (end_idx + start_idx) / 2;

      if (nums[start_idx] < nums[end_idx])
      {
        return nums[start_idx];
      }

      while (end_idx - start_idx > 1)
      {
        if (nums[middle_idx] > nums[start_idx])
        {
          start_idx = middle_idx;
        }
        else
        {
          end_idx = middle_idx;
        }
        middle_idx = (start_idx + end_idx) / 2;
      }
      return nums[end_idx];
    }
};
