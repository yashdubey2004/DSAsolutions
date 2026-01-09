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
    void makeNumber(TreeNode* root, int num, vector<int>& results){
        int n = root -> val;
        num = (num * 10) + n;
        if(root -> left) makeNumber(root -> left, num, results);
        if(root -> right) makeNumber(root -> right, num, results);
        if(!root->left && !root->right) {
            results.push_back(num);
            return;
        }
    }

    int sumNumbers(TreeNode* root) {
        vector<int> results;
        int num = 0;
        makeNumber(root, num, results);
        int sum = 0;
        for(int i = 0; i < results.size(); i++){
            sum += results[i];
        }
        return sum;
    }
};
