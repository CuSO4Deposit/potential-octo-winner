// 0 ms (< 100.00%), 78.82 MB (< 32.16%)
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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    long long rootSum = 0;
    long long max = 0;
public:
    int updateSum(TreeNode* root) {
        if (!root) return 0;
        int left = updateSum(root->left);
        int right = updateSum(root->right);
        int sum = left + right + root->val;
        root->val = sum;
        return sum;
    }

    void maxProductTraverse(TreeNode* root) {
        if (!root) return;
        long long cut = root->val;
        int coCut = rootSum - cut;
        long long current = cut * coCut;
        max = max > current ? max : current;
        maxProductTraverse(root->left);
        maxProductTraverse(root->right);
    }

    int maxProduct(TreeNode* root) {
        const int modulo = 1E9 + 7;
        rootSum = updateSum(root);
        maxProductTraverse(root);
        return max % modulo;
    }
};
