class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> levels;
        std::queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
          int num_nodes_level = q.size();
          vector<int> level;
          for (int i = 0; i < num_nodes_level; ++i) {
            Node* node = q.front();
            q.pop();
            level.push_back(node->val);
            for (const auto child : node->children) {
                q.push(child);
            }
          }
          levels.push_back(level);
        }
        return levels;
    }
};
