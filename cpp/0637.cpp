class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> levels;
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
          int num_nodes_level = q.size();
          vector<int> level;
          for (int i = 0; i < num_nodes_level; ++i) {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            if (node->left != nullptr) {
              q.push(node->left);
            }
            if (node->right != nullptr) {
              q.push(node->right);
            }
          }
          levels.push_back(level);
        }
        std::vector<double> averages;
        std::transform(levels.begin(), levels.end(), std::back_inserter(averages),
                      [](const auto& level) {
                          double avg = std::accumulate(level.begin(), level.end(), 0.0) / level.size();
                          return avg;
                      });
        return averages;
    }
};
