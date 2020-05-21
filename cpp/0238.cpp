class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int forward_prod = 1;
      int backward_prod = 1;
      int size = nums.size();
      vector<int> forward_prods{};
      vector<int> backward_prods{};
      vector<int> output{};

      forward_prods.push_back(forward_prod);
      backward_prods.push_back(backward_prod);
      for (int i = 0; i < size - 1; ++i)
      {
        forward_prod *= nums[i];
        backward_prod *= nums[size - 1 - i];
        forward_prods.push_back(forward_prod);
        backward_prods.push_back(backward_prod);
      }

      for (int i = 0; i < size; ++i)
      {
        output.push_back(forward_prods[i] * backward_prods[size - 1 - i]);
      }
      return output;
    }
};
