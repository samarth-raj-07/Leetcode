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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // if both roots are null 
        if(root1==NULL && root2==NULL){
            return true;
        }else if(root1==NULL || root2==NULL){  
            return false;
        }
        if(root1->val != root2->val){
            return false;
        }
        // check if left and right subtree are equal without flipping
        bool a = flipEquiv(root1->right,root2->right)&& flipEquiv(root1->left,root2->left);
        if(a){
            return true;
        }
        // both subtrees are not equal and we need to flip and check
        bool b=flipEquiv(root1->left,root2->right) && flipEquiv(root1->right,root2->left);
        return b;
    }
};