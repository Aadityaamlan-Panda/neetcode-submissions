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
    vector<vector<int>> levelOrder(TreeNode* root) {
        unordered_map<int,vector<int>>mp;
        queue<pair<TreeNode*,int>>q;
        int lmax = 0;

        if (root==nullptr) return {};
        q.push({root,0});

        while(!q.empty()){
            TreeNode* curr  = q.front().first;
            int l = q.front().second;
            q.pop();
            lmax = max(l,lmax);
            mp[l].push_back(curr->val);
            if (curr->left) q.push({curr->left,l+1});
            if (curr->right) q.push({curr->right,l+1});
        }
        vector<vector<int>>ans;
        for(int i=0; i<=lmax; i++){
            ans.push_back(mp[i]);
        }
        return ans;
    }
};
