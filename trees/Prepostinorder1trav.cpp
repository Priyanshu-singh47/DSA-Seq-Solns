class Solution{
public:

    vector<vector<int>> treeTraversal(TreeNode* root){

        vector<vector<int>> ans;

        if(root == NULL)
            return ans;

        vector<int> pre, inorder, post;

        stack<pair<TreeNode*, int>> st;

        st.push({root, 1});

        while(!st.empty()){

            auto it = st.top();
            st.pop();

            if(it.second == 1){

                pre.push_back(it.first->data);

                it.second++;

                st.push(it);

                if(it.first->left)
                    st.push({it.first->left, 1});
            }

            else if(it.second == 2){

                inorder.push_back(it.first->data);

                it.second++;

                st.push(it);

                if(it.first->right)
                    st.push({it.first->right, 1});
            }

            else{

                post.push_back(it.first->data);
            }
        }

        ans.push_back(inorder);
        ans.push_back(pre);
        ans.push_back(post);

        return ans;
    }
};