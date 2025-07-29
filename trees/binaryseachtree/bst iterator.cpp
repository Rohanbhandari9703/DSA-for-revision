//using stack , like how can we figure out two functions next and hasnext good question
//for revision follow :-https://www.youtube.com/watch?v=D2jMcmxU4bs (ctrl+ click);
code{
    class BSTIterator {
private:
    stack<TreeNode*> st;

    // Helper to push all left children to stack
    void pushLeft(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

public:
    // Constructor
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    // Return next smallest element
    int next() {
        TreeNode* node = st.top();
        st.pop();
        if (node->right) {
            pushLeft(node->right);
        }
        return node->val;
    }

    // Check if there is a next element
    bool hasNext() {
        return !st.empty();
    }
};

}
// Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
// Calling next() will return the next smallest number in the BST.
// Implement:

// BSTIterator(TreeNode* root)

// int next()

// bool hasNext()

// ✅ Core Idea:
// A BST Inorder traversal gives nodes in ascending order.

// Instead of storing all values beforehand, we simulate inorder traversal using a stack, giving O(h) space (where h is the tree height).