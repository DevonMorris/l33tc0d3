// Got help on this one from educative.io
// The trick here is to keep track of the path you are on and sum everything
// ending at that node
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        m_paths = 0;
        std::vector<int> path;
        pathSum(root, targetSum, path);
        return m_paths;
    }

private:
    void pathSum(TreeNode* root, int targetSum, std::vector<int>& currentPath) {
        if (root == nullptr) {
            return;
        }

        currentPath.push_back(root->val);
        int sum = 0;
        for (auto it = currentPath.rbegin(); it != currentPath.rend(); ++it) {
            sum += *it;
            if (sum == targetSum) {
                ++m_paths;
            }
        }

        pathSum(root->left, targetSum, currentPath);
        pathSum(root->right, targetSum, currentPath);

        currentPath.pop_back();
        return;
    }

    int m_paths;
};
