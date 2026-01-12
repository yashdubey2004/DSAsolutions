class Solution {
public:
    void help(TreeNode* root, int &sum){
        if(!root) return;
        if(root->left && !root->left->left && !root->left->right){
            sum += root->left->val;
        }
        help(root->left, sum);
        help(root->right, sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        help(root, sum);
        return sum;
    }
};
