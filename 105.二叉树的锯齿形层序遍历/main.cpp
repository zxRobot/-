vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
         if(root==nullptr)
    {
        return res;
    }
    queue<TreeNode*> q;
    q.push(root);
    int flag=0;
    while(!q.empty())
    {
        int size = q.size();
        vector<int> ans;
        for(int i=0;i<size;i++)
        {
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left!=nullptr)
            {
                q.push(temp->left);
            }
            if(temp->right!=nullptr)
            {
                q.push(temp->right);
            }
            ans.push_back(temp->val);
        }
        if(flag%2==0)
        {
            res.push_back(ans);
            ans.clear();
        }
        else
        {
            reverse(ans.begin(),ans.end());
            res.push_back(ans);
            ans.clear();
        }
        flag++;
    }
    return res;
    }