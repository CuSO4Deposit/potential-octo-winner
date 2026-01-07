// 487 ms (< 5.63%), 90.02 MB (< 10.80%)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int updateSum(TreeNode* root) {
        if (!root) return 0;
        int left = updateSum(root->left);
        int right = updateSum(root->right);
        int sum = left + right + root->val;
        root->val = sum;
        return sum;
    }

    long long maxProductTraverse(TreeNode* root, int rootSum) {
        if (!root) return 0;
        long long left = 0; long long right = 0;
        int coLeft = rootSum; int coRight = rootSum;
        if (root->left) {
            left = root->left->val;
            coLeft -= root->left->val;
        }
        if (root->right) {
            right = root->right->val;
            coRight -= root->right->val;
        }
        long long l = left * coLeft;
        long long r = right * coRight;
        long long childL = maxProductTraverse(root->left, rootSum);
        long long childR = maxProductTraverse(root->right, rootSum);
        return std::max({l, r, childL, childR});
    }

    int maxProduct(TreeNode* root) {
        const int modulo = 1E9 + 7;
        updateSum(root);
        long long result = maxProductTraverse(root, root->val);
        return result % modulo;
    }
};
