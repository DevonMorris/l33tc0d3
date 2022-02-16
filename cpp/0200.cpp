class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nIslands = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++nIslands;
                    dfs(grid, i, j);
                }
            }
        }
        return nIslands;
    }

    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i > grid.size() - 1 || j > grid[i].size() - 1) {
            return;
        }

        if (grid[i][j] != '1') {
            return;
        }
        grid[i][j] = 'f';
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
};
