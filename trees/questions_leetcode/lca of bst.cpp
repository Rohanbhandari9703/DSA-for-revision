//good question done by me simple logic 
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
    TreeNode* lowest(TreeNode* root, TreeNode* mini, TreeNode* maxi) {
        if ((root->val > mini->val && root->val < maxi->val) || (root->val == mini->val || root->val == maxi->val)) {
            return root;
        }
        if (root->val > mini->val && root->val > maxi->val) {
            return lowest(root->left, mini, maxi);
        }
        if (root->val < mini->val && root->val < maxi->val) {
            return lowest(root->right, mini, maxi);
        }
        return nullptr;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* mini;
        TreeNode* maxi;
        TreeNode* ans;

        if (p->val < q->val) {
            mini = p;
            maxi = q;
        } else {
            mini = q;
            maxi = p;
        }

        ans = lowest(root, mini, maxi);
        return ans;
    }
};