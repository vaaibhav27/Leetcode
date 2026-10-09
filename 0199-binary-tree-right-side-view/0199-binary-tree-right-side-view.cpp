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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        map<int, int> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int x = p.second;
            if(mp.find(x) == mp.end()) mp[x] = node->val;
            //mp[x] = node->val;
            if(node->right) q.push({node->right, x+1});
            if(node->left) q.push({node->left, x+1});
        }
        
        for(auto &col: mp) {
            ans.push_back(col.second);
        }
        return ans;
    }
};