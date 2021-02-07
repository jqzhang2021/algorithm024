/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == nullptr)
        {
            return vector<vector<int>>{};
        }
        vector<vector<int>> result;
        deque<Node*> que;
        que.push_back(root);
        while(!que.empty())
        {
            vector<int> inner;
            int size = (int)que.size();
            while(size-- > 0)
            {
                Node* node = que.front();
                inner.push_back(node->val);
                que.pop_front();
                for(int i = 0; i < node->children.size(); i++)
                {
                    que.push_back(node->children[i]);
                }
            }
            result.push_back(inner);
        }
        return result;
    }
};
