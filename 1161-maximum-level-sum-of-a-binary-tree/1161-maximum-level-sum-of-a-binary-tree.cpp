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
    int maxLevelSum(TreeNode* root) {
        int c = 0,max = INT_MIN,s,ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size(),s = 0;
            for(int i = 0;i < n;i++) {
                TreeNode *r = q.front();
                if(r->left != NULL) q.push(r->left);
                if(r->right != NULL) q.push(r->right);
                q.pop();
                s += r->val;
            }
            c++;
            if(s > max) {
                max = s;
                ans = c;
            }
        }
        return ans;
    }
};