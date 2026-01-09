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
    void fill(TreeNode* root, vector<int>& result){
        if(!root) return;
        result.push_back(root -> val);
        if(root -> left) fill(root -> left, result);
        if(root -> right) fill(root -> right, result);
    }

    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        vector<int> result;
        fill(root, result);
        sort(result.begin(), result.end());
        int n = result[k - 1];
        return n;
    }
};
