class Solution {
  public:
    int maxProfit(vector<int>& prices) {
      int lowest_price_to_date = std::numeric_limits<int>::max();
      int max_profit = 0;
      for (const auto& price: prices)
      {
        if (price < lowest_price_to_date)
        {
          lowest_price_to_date = price;
        }
        int potential_profit = price - lowest_price_to_date;
        if (max_profit < potential_profit)
        {
          max_profit = potential_profit;
        }
      }
      return max_profit;
    }
}
