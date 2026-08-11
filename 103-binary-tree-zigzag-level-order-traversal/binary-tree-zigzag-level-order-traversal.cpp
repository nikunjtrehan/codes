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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
         if(root==NULL) return ans;
        deque<TreeNode*> q;
        q.push_back(root);
         bool c=0;
        while(!q.empty()){
           
            int size=q.size();
            vector<int> v;
            for(int i=0;i<size;i++){
                TreeNode* node;
                if(c==0){
                  node=q.front();
                q.pop_front();
                
                if(node->left !=NULL) q.push_back(node->left);
                if(node->right !=NULL) q.push_back(node->right);
                }
                
                else{
                 node=q.back();
                q.pop_back();
                
                if(node->right !=NULL) q.push_front(node->right);
                if(node->left !=NULL) q.push_front(node->left);
                }
 
                v.push_back(node->val);

            }
           c = !c;
            ans.push_back(v);
        }
        return ans;
    }
};