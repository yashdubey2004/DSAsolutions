class Solution {
public:
    bool check(TreeNode* root, int value){
        if(root->val != value) return false;

        if(root->left){
            if(check(root->left, value) == false) return false;
        }
        if(root->right){
            if(check(root->right, value) == false) return false;
        }
        return true;
    }

    bool isUnivalTree(TreeNode* root) {
        if(root->left){
            if(check(root->left, root->val) == false) return false;
        }
        if(root->right){
            if(check(root->right, root->val) == false) return false;
        }
        return true;
    }
};
