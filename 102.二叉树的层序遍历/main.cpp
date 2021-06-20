#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode* root)
{
    queue<TreeNode*> s;
    vector<vector<int>> res;
    if(root==nullptr)
    {
        return res;
    }
    s.push(root);
    while(!s.empty())
    {
        int count=(int)s.size();
        for(int i=0;i<count;i++)
        {
            TreeNode* temp=s.front();
            s.pop();
            res.back().push_back(temp->val);
            if(temp->left)
            {
                s.push(temp->left);
            }
            if(temp->right)
            {
                s.push(temp->right);
            }
        }
        
    }
    return res;
}