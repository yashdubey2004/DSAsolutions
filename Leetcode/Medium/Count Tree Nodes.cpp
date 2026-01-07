class Solution {
public:
    void help(TreeNode* root, int& count){
        if(!root) return;
        count++;
        if(root->left){
            help(root->left, count);
        } 
        if(root->right) {
            help(root->right, count);
        }
    }

    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int count = 0;
        help(root, count);
        return count;
    }
};
