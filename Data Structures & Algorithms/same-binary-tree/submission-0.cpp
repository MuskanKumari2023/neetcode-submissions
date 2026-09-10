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
bool isSame=true;
void preorder(TreeNode* p, TreeNode* q){
    if(!p and !q){
       return ;
    }
    if(!p or !q){
        isSame=false;
        return ;
    }
    if(p->val != q->val){
        isSame=false;
        return ;
    }
    preorder(p->left,q->left);
    preorder(p->right,q->right);
}
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p or !q)return p==q;
        preorder(p,q);
        return isSame;
    }
};
