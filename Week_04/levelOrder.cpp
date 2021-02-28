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
    void dfs(vector<vector<int>>& result, int level, TreeNode* node)
    {
        if(node == nullptr)
        {
            return;
        }
        if(result.size() < (level + 1))
        {
            result.push_back(vector<int>{});
        }
        result[level].push_back(node->val);
        dfs(result, level + 1, node->left);
        dfs(result, level + 1, node->right);
    }

    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> result;
        dfs(result, 0, root);
        return result;
    }
};
