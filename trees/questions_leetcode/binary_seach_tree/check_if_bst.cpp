//good question could have done using inorder traversal but will have take 2n, instead use a range and recursive solution
solution..
class Solution {
public:
    bool validate(TreeNode* root, long long minVal, long long maxVal) {
        if (root == nullptr) return true;

        if (root->val <= minVal || root->val >= maxVal)
            return false;

        return validate(root->left, minVal, root->val) &&
               validate(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};