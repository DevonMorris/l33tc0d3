/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p) {
            return p;
        }
        if (root == q) {
            return q;
        }
        if (root->left == nullptr) {
            return lowestCommonAncestor(root->right, p, q);
        }
        if (root->right == nullptr) {
            return lowestCommonAncestor(root->left, p, q);
        }
        bool isLeftPAncestor = isDescendant(root->left, p);
        bool isLeftQAncestor = isDescendant(root->left, q);
        bool isRightPAncestor = isDescendant(root->right, p);
        bool isRightQAncestor = isDescendant(root->right, q);

        bool isLeftCommonAncestor = isLeftPAncestor && isLeftQAncestor;
        bool isRightCommonAncestor = isRightPAncestor && isRightQAncestor;
        if (isLeftCommonAncestor) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (isRightCommonAncestor) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }

    bool isDescendant(TreeNode* root, TreeNode* p) {
        if (m_dp.find(root) == m_dp.end()) {
            m_dp.emplace(root, std::unordered_map<TreeNode*, bool>());
        }
        if (m_dp[root].find(p) != m_dp[root].end()) {
            return m_dp[root][p];
        }
        if (root == nullptr) {
            return false;
        }
        if (root == p) {
            return true;
        }

        m_dp[root][p] = isDescendant(root->left, p) || isDescendant(root->right, p);
        return m_dp[root][p];
    }

    std::unordered_map<TreeNode*, std::unordered_map<TreeNode*, bool>> m_dp;
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root == p || root == q) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left == nullptr) {
            return right;
        }
        if (right == nullptr) {
            return left;
        }

        return root;
    }

};
