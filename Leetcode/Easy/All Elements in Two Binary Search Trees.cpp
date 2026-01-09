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
    void trav(TreeNode* root, vector<int>& elements){
        if(!root) return;
        elements.push_back(root -> val);
        if(root -> left) trav(root -> left, elements);
        if(root -> right) trav(root -> right, elements);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> elements;
        trav(root1, elements);
        trav(root2, elements);
        sort(elements.begin(), elements.end());
        return elements;
    }
};
