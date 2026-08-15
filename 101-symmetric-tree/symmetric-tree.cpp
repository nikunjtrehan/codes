class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        
        if (!root) return true;
        
        
        return checkMirror(root->left, root->right);
    }
    

    bool checkMirror(TreeNode* leftNode, TreeNode* rightNode) {
       
        if (!leftNode && !rightNode) return true;
        
        
        if (!leftNode || !rightNode) return false;
        
        
        return (leftNode->val == rightNode->val) &&
               checkMirror(leftNode->left, rightNode->right) && 
               checkMirror(leftNode->right, rightNode->left);  
    }
};