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
    int checkheight(TreeNode* root){
        if(root == NULL){
            return false;
        }
        int lh = checkheight(root -> left);
        int rh = checkheight(root -> right);
        
        if(abs(lh - rh) > 1) return -1;
        if(lh == -1 || rh == -1) return -1;

        return max(lh,rh) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(checkheight(root) == -1) return false;
        return true;
    }
};
