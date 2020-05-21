// My solution O(n) time and O(1) spatial
class Solution {
  public:
    int missingNumber(vector<int>& nums) {
      int n = nums.size();
      int target_sum = n * (n + 1) / 2;
      int sum = 0;
      for (const auto& num : nums)
      {
        sum += num;
      }
      return target_sum - sum;
    }
};

// Solution with cleaner syntax
class Solution {
  public:
    int missingNumber(vector<int>& nums) {
      return (nums.size() + 1) * nums.size() / 2
        - accumulate(nums.begin(), nums.end(), 0);
    }
};
