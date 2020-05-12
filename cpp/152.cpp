class Solution {
  public:
    int maxProduct(vector<int>& nums) {
      int max_val = nums[0];
      int min_val = nums[0];
      int max_product = nums[0];
      for (int i = 1; i < nums.size(); ++i)
      {
        const int num = nums[i];
        if (num < 0)
        {
          swap(max_val, min_val);
        }
        max_val = max(max_val * num, num);
        min_val = min(min_val * num, num);

        max_product = max(max_product, max_val);
      }
      return max_product;
    }
};
