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
    int result = 0;
    int giveNum(string s) 
    {
        int num = 0;
        for(int i = 0; i < s.size(); i++) 
        {
            num = num * 2 + (s[i] - '0');
        }
        return num;
    }
    void dfs(TreeNode* root, string s) {
        if(root == NULL) return;
        s = s + char(root->val + '0');
        if(root->left == NULL && root->right == NULL) {
            result += giveNum(s);
            return;
        }
        dfs(root->left, s);
        dfs(root->right, s);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        dfs(root, "");
        return result;
    }
};