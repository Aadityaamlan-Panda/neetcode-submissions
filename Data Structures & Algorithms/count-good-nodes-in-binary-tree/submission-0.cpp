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
private:
    void dfs(int &ans,TreeNode* curr, int mxm){
        if (!curr) return;
        if (curr->val >= mxm) ans = ans+1;
        dfs(ans, curr->left, max(mxm,curr->val));
        dfs(ans, curr->right, max(mxm,curr->val));
    }
public:
    int goodNodes(TreeNode* root) {
        int ans = 0;
        int mxm = INT_MIN;
        dfs(ans,root,mxm);
        return ans;
    }
};
