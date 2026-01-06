// 1 ms (< 76.93%), 106.92 MB (< 96.77%)
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
#include <vector>

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
    void traverse(TreeNode* root, int level, std::vector<int>& levelSum, void (*func)(TreeNode*, int, std::vector<int>&)) {
        if (!root) return;
        func(root, level, levelSum);
        traverse(root->left, level + 1, levelSum, func);
        traverse(root->right, level + 1, levelSum, func);
    }

    static void addNode(TreeNode* root, int level, std::vector<int>& levelSum) {
        while (level >= levelSum.size()) {
            levelSum.push_back(0);
        }

        levelSum[level] += root->val;
    }

    int maxLevelSum(TreeNode* root) {
        std::vector<int> levelSum;
        traverse(root, 0, levelSum, addNode);

        int max = -2147483648;
        int idx = 0;
        for (int i = 0; i < levelSum.size(); i++) {
            if (levelSum[i] > max) {
                max = levelSum[i];
                idx = i;
            }
        }

        return idx + 1;
    }
};
