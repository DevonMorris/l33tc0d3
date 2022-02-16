// Unique paths
class Solution {
public:
    long long uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1) {
            return 0;
        }

        std::vector<std::vector<long long>> solutionGrid;
        for (int i = 0; i < obstacleGrid.size() + 1; ++i) {
            solutionGrid.push_back(std::vector<long long>(n + 1, 0));
        }
        solutionGrid[m - 1][n - 1] = 1;

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i == m - 1 && j == n - 1) {
                    continue;
                }
                if (obstacleGrid[i][j] != 1) {
                    solutionGrid[i][j] = solutionGrid[i + 1][j] + solutionGrid[i][j + 1];
                }
            }
        }
        return solutionGrid[0][0];
    }
};
