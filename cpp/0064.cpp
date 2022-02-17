class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<int>> dp;
        for (int i = 0; i < m + 1; ++i) {
            dp.push_back(std::vector<int>(n + 1, std::numeric_limits<int>::max()));
        }

        dp[m-1][n-1] = grid[m-1][n-1];

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i == m - 1 && j == n - 1) {
                    continue;
                }
                dp[i][j] = grid[i][j] + std::min(dp[i + 1][j], dp[i][j + 1]);
            }
        }

        return dp[0][0];

    }
};
