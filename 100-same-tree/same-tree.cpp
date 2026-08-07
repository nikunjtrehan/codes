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
 int c=1;
    void traverse(TreeNode* p, TreeNode* q) {
        
        if(p==NULL && q==NULL){
            return;
        }
        
        if(p!=NULL && q==NULL ||p==NULL && q!=NULL ){
            c=0;
        }
        if(p!=NULL && q!=NULL){

        if(p->val!=q->val) {
            c=0;
        }
        traverse(p->left,q->left);
         traverse(p->right,q->right);}


    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        
         traverse(p,q);
        if(c==1){
            return true;
        }
        else{
            return false;
        }
        
    }
};