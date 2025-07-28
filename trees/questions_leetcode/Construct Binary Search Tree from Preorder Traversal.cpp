//good question to revise , given preorder traversal of binary tree make a bst for that
//although simple logic but was not able to write the code cause recursion pe itna hath nhi betha
code{
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

class Solution {
public:
    void join(TreeNode* root, TreeNode* curr) {
        if (curr->val < root->val) {
            if (root->left == nullptr)
                root->left = curr;
            else
                join(root->left, curr);
        } else {
            if (root->right == nullptr)
                root->right = curr;
            else
                join(root->right, curr);
        }
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);
        for (int i = 1; i < preorder.size(); i++) {
            TreeNode* curr = new TreeNode(preorder[i]);
            join(root, curr);
        }
        return root;
    }
};

}