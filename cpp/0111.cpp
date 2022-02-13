class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int depth = 0;
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
          ++depth;
          int num_nodes_level = q.size();
          for (int i = 0; i < num_nodes_level; ++i) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left == nullptr && node->right == nullptr) {
              return depth;
            }
            if (node->right != nullptr) {
              q.push(node->right);
            }
            if (node->left != nullptr) {
              q.push(node->left);
            }
          }
        }
        return depth;
    }
};
