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

    vector<int> preorder(Node* root) {
        if(root == NULL)
        {
            return vector<int>{};
        }
        vector<int> result;
        stack<Node*> st;
        st.push(root);
        while(!st.empty())
        {
            Node* node = st.top();
            st.pop();
            result.push_back(node->val);
            for(int i = (int)node->children.size() - 1; i >= 0; i--)
            {
                st.push(node->children[i]);
            }
        }
        return result;
    }
};
