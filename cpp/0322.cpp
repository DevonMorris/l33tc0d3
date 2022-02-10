class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::vector<int> dp(amount+1, amount+1);
        dp[0] = 0;

        for (int i = 1; i <= amount; ++i) {
            for (const auto& coin : coins) {
                if (coin <= i) {
                    dp[i] = std::min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        if (dp[amount] == amount + 1) {
            return -1;
        }
        return dp[amount];
    }
};
