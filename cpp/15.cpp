class Solution {
  public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      if (nums.size() < 3)
      {
        return {};
      }

      sort(nums.begin(), nums.end());
      vector<vector<int>> zero_sums{};
      int i = 0;
      while (i < nums.size() - 2)
      {
        if (nums[i] > 0)
        {
          break;
        }
        if (i > 0 && (nums[i] == nums[i - 1]))
        {
          ++i;
          continue;
        }
        int j = i + 1;
        int k = nums.size() - 1;
        while (j < k)
        {
          int sum = nums[i] + nums[j] + nums[k];
          if (sum == 0)
          {
            zero_sums.push_back({nums[i], nums[j], nums[k]});
            while(j < k - 1 && (nums[j] == nums[j + 1]))
            {
              ++j;
            }
            while (k > j + 1 && (nums[k] == nums[k - 1]))
            {
              --k;
            }
            ++j;
            --k;
          }
          else if (sum < 0)
          {
            ++j;
          }
          else if (sum > 0)
          {

            --k;
          }
        }
        ++i;
      }
      return zero_sums;
    }
};
