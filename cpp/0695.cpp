class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                int area = 0;
                dfs(grid, i, j, area);
                maxArea = std::max(area, maxArea);
            }
        }
        return maxArea;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int& area) {
        if (i < 0 || i > grid.size() - 1 || j < 0 || j > grid[i].size() - 1) {
            return;
        }

        if (grid[i][j] != 1) {
            return;
        }
        ++grid[i][j];
        ++area;

        dfs(grid, i + 1, j, area);
        dfs(grid, i - 1, j, area);
        dfs(grid, i, j + 1, area);
        dfs(grid, i, j - 1, area);
    }
};
