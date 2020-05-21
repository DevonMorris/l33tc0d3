// My Solution
class Solution {
  public:
    int getSum(int a, int b) {
      unsigned int ua = 0ul | a;
      unsigned int ub = 0ul | b;
      if (ua == (~ub + 1))
      {
        return 0;
      }

      unsigned int carry = (a & b);
      carry = carry << 1;
      unsigned int sum = a ^ b;
      while (carry != 0)
      {
        int temp = 0;
        temp = carry ^ sum;
        carry = (sum & carry) << 1;
        sum = temp;
      }
      int signed_sum = 0ul | sum;
      return signed_sum;
    }
};

// Cleanest solution
class Solution {
  public:
    int getSum(int a, int b) {
      if(b == 0)return a;
      int sum = a ^ b;
      int carry = static_cast<unsigned int>(a & b) << 1;
      return getSum(sum,carry);
    }
};
