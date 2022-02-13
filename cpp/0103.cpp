class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        bool is_reverse = false;
        vector<vector<int>> result;
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
          if (is_reverse) {
              std::reverse(level.begin(), level.end());
          }
          result.push_back(level);
          is_reverse = !is_reverse;
        }
        return result;
    }
};
