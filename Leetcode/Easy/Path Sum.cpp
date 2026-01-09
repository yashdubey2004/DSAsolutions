class Solution {
public:
    bool check(TreeNode* root, int targetSum, int sum){
        if(!root) return false;

        int n = root->val;
        sum += n;

        if(root->left == nullptr && root->right == nullptr){
            if(sum == targetSum) return true;
            return false;
        }

        bool t1 = false;
        bool t2 = false;

        if(root->left)
            t1 = check(root->left, targetSum, sum);

        if(root->right)
            t2 = check(root->right, targetSum, sum);

        if(t1 == true || t2 == true) return true;
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return check(root, targetSum, 0);
    }
};
