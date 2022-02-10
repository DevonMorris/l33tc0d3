class Solution {
  public:
    void setZeroes(vector<vector<int>>& matrix) {
      // Boolean to track setting 0,0
      bool set_zerozero = false;
      bool set_zerorow = false;
      bool set_zerocolumn = false;

      // Identify rows/cols
      for (int i = 0; i < matrix.size(); ++i)
      {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
          if (matrix[i][j] == 0)
          {
            if (i == 0 || j == 0)
            {
              set_zerozero = true;
              if (i == 0)
              {
                set_zerorow = true;
              }
              if (j == 0)
              {
                set_zerocolumn = true;
              }
            }
            else
            {
              matrix[i][0] = 0;
              matrix[0][j] = 0;
            }
          }
        }
      }

      // Fill rows with 0
      for (int i = 1; i < matrix.size(); ++i)
      {
        if (matrix[i][0] == 0)
        {
          for (int j = 1; j < matrix[i].size(); ++j)
          {
            matrix[i][j] = 0;
          }
        }
      }

      // Fill columns with 0
      for (int j = 1; j < matrix[0].size(); ++j)
      {
        if (matrix[0][j] == 0)
        {
          for (int i = 1; i < matrix.size(); ++i)
          {
            matrix[i][j] = 0;
          }
        }
      }

      // If 0,0 is zero fill first row and column
      if (matrix[0][0] == 0)
      {
        for (int i = 0; i < matrix.size(); ++i)
        {
          matrix[i][0] = 0;
        }
        for (int j = 0; j < matrix[0].size(); ++j)
        {
          matrix[0][j] = 0;
        }
      }

      if (set_zerozero)
      {
        matrix[0][0] = 0;
      }

      if (set_zerorow)
      {
        for (int j = 0; j < matrix[0].size(); ++j)
        {
          matrix[0][j] = 0;
        }
      }
      if (set_zerocolumn)
      {
        for (int i = 0; i < matrix.size(); ++i)
        {
          matrix[i][0] = 0;
        }
      }
    }
};

// this is the more clear solution imo
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        std::unordered_set<int> zero_rows{};
        std::unordered_set<int> zero_columns{};

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 0) {
                    zero_rows.emplace(i);
                    zero_columns.emplace(j);
                }
            }
        }
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (zero_rows.find(i) != zero_rows.end()) {
                    matrix[i][j] = 0;
                }
                if (zero_columns.find(j) != zero_columns.end()) {
                    matrix[i][j] = 0;
                }
            }
        }
        return;
    }
};
