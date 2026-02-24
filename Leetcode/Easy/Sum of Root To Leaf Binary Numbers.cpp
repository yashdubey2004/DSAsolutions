class Solution {
public:
    int calc(string s){
        long long mul = 1;
        int val = 0;
        int i = s.length() - 1;

        while(i >= 0){
            if(s[i] == '1'){
                val += mul;
            }
            mul *= 2;
            i--;
        }
        return val;
    }

    void help(TreeNode* root, vector<string>& bins, string s){
        char c = root->val + '0';
        s += c;

        if(!root->left && !root->right){
            bins.push_back(s);
            return;
        }

        if(root->left) help(root->left, bins, s);
        if(root->right) help(root->right, bins, s);
    }

    int sumRootToLeaf(TreeNode* root) {
        if(!root) return 0;

        vector<string> bins;

        help(root, bins, "");

        int sum = 0;
        for(int i = 0; i < bins.size(); i++){
            sum += calc(bins[i]);
        }

        return sum;
    }
};
