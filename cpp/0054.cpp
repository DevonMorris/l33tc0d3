enum class Direction: int {
    RIGHT,
    DOWN,
    LEFT,
    UP
};

class SpiralIterator {
    public:
        SpiralIterator(int m, int n) : m_col_end(n - 1), m_row_end(m - 1), m_total_entries(m * n) {
        }

        std::pair<int, int> next()
        {
            if (m_total_entries == m_num) {
                return {-1, -1};
            }

            switch (m_current_dir) {
                case Direction::DOWN:
                    {
                        // Need to go left now
                        if (m_current_row + 1 > m_row_end)
                        {
                            m_current_dir = Direction::LEFT;
                            --m_current_col;
                            --m_col_end;
                        }
                        else
                        {
                            ++m_current_row;
                        }
                    }
                    break;
                case Direction::RIGHT:
                    {
                        // Need to go down now
                        if (m_current_col + 1 > m_col_end)
                        {
                            m_current_dir = Direction::DOWN;
                            ++m_current_row;
                            ++m_row_begin;
                        }
                        else
                        {
                            ++m_current_col;
                        }

                    }
                    break;
                case Direction::LEFT:
                    {
                        // Need to go up now
                        if (m_current_col - 1 < m_col_begin)
                        {
                            m_current_dir = Direction::UP;
                            --m_current_row;
                            --m_row_end;
                        }
                        else
                        {
                            --m_current_col;
                        }

                    }
                    break;
                case Direction::UP:
                    {
                        // Need to go right now
                        if (m_current_row - 1 < m_row_begin)
                        {
                            m_current_dir = Direction::RIGHT;
                            ++m_current_col;
                            ++m_col_begin;
                        }
                        else
                        {
                            --m_current_row;
                        }
                    }
                    break;
            }
            ++m_num;
            return {m_current_row, m_current_col};
        }

    private:
        int m_col_begin = 0;
        int m_row_begin = 0;
        int m_col_end;
        int m_row_end;
        int m_current_row = 0;
        int m_current_col = 0;
        int m_total_entries;
        int m_num = 1;
        Direction m_current_dir = Direction::RIGHT;

};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        SpiralIterator it(matrix.size(), matrix.front().size());

        std::vector<int> out;

        int m = 0;
        int n = 0;
        while (m != -1 || n != -1)
        {
            std::cout << matrix[m][n] << std::endl;
            out.push_back(matrix[m][n]);
            auto next = it.next();
            m = next.first;
            n = next.second;
        }
        return out;
    }
};
