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
int dfs(TreeNode* root, int maxi){
    if(!root)return 0;
    int is_good=(root->val>=maxi)?1:0;
    maxi=max(maxi,root->val);
    return is_good+dfs(root->left,maxi)+dfs(root->right,maxi);
}
    int goodNodes(TreeNode* root) {
        if(!root)return 0;
        return dfs(root,root->val);
    }
};
