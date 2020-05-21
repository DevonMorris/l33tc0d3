class Solution {
  public:
    int search(vector<int>& nums, int start_idx, int end_idx, int target)
    {
      if (start_idx > end_idx)
      {
        return -1;
      }
      int mid_idx = (end_idx + start_idx) / 2;

      if (nums[mid_idx] == target)
      {
        return mid_idx;
      }

      if (nums[mid_idx] >= nums[0])
      {
        if (target >= nums[0] && target < nums[mid_idx])
        {
          return search(nums, start_idx, mid_idx - 1, target);
        }
        return search(nums, mid_idx + 1, end_idx, target);
      }

      if (target > nums[mid_idx] && target <= nums[end_idx])
      {
        return search(nums, mid_idx + 1, end_idx, target);
      }

      return search(nums, start_idx, mid_idx - 1, target);
    }

    int search(vector<int>& nums, int target) {
      int start_idx = 0;
      int end_idx = nums.size() - 1;
      return search(nums, start_idx, end_idx, target);
    }
};
