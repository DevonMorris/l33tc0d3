class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return {};
        }
        if (root->left == nullptr && root->right == nullptr) {
            if (root->val == targetSum) {
                return {{root->val}};
            } else {
                return {};
            }
        }

        auto left_paths = pathSum(root->left, targetSum - root->val);
        auto right_paths = pathSum(root->right, targetSum - root->val);
        left_paths.insert(left_paths.end(), right_paths.begin(), right_paths.end());
        for (auto& path : left_paths) {
            // This is bad with std::vector, but for some reason push_back and reverse were
            // giving the wrong answer :/
            path.insert(path.begin(), root->val);
        }
        return left_paths;
    }
};
