// First Try
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return targetSum == root->val;
        }

        int newTarget = targetSum - root->val;
        return hasPathSum(root->left, newTarget) || hasPathSum(root->right, newTarget);
    }
};
