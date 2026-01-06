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
    void help(TreeNode* root, unordered_map<int, int>& freq, int level){
        if(!root) return;
        freq[level] += root -> val;
        if(root && root -> left) help(root -> left, freq, level + 1);
        if(root && root -> right) help(root -> right, freq, level + 1);
    }

    int maxLevelSum(TreeNode* root) {
        int level = 1;
        int sum = 0;
        unordered_map<int, int> freq;
        freq[1] = root -> val;
        if(root -> left) help(root -> left, freq, level + 1);
        if(root -> right) help(root -> right, freq, level + 1);
        int maxi = INT_MIN;
        int result = 1;
        for(auto& it: freq){

            if(it.second > maxi){
                maxi = it.second;
                result = it.first;
            }
            if(it.second == maxi){
                if(it.first < result){
                    result = it.first;
                }
            }
        }
        return result;
    }
};
