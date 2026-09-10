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
int dfs(TreeNode* root){
    if(!root)return 0;
    int left=dfs(root->left);
    int right=dfs(root->right);
    if(left==-1 or right==-1)return -1;
    if(abs(left-right)>1)return -1;
    return max(left,right)+1;
}
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        int hh=dfs(root);
        if(hh==-1)return false;
        return true;
    }
};
