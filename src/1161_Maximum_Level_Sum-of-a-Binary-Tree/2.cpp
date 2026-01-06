// 0 ms (< 100.00%), 109.62 MB (< 13.47%)
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
#include <queue>

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
    int maxLevelSum(TreeNode* root) {
        std::vector<int> levelSum;
        std::queue<TreeNode*> queue;
        if (root) queue.push(root);

        while(!queue.empty()) {
            int size = queue.size();
            int sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* node = queue.front();
                queue.pop();
                sum += node->val;

                if (node->left) queue.push(node->left);
                if (node->right) queue.push(node->right);
            }
            levelSum.push_back(sum);
        }
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
