#include <iostream>
#include <vector>
#include "二叉树定义.cpp"

using namespace std;

class Solution
{
private:

    vector<int> result;
    void traversal(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }

        traversal(root->left);
        result.push_back(root->value);
        traversal(root->right);
    }

public:

    bool isValidBST(TreeNode* root)
    {
        traversal(root);

        for (int i = 0; i < result.size(); i++)
        {
            for (int j = i + 1; j < result.size(); j++)
            {
                if (result[i] >= result[j])
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(7);

    TreeNode *root = node4;
    root->Left(node2)->Right(node5);
    node2->Left(node1)->Right(node3);

    Solution solution;
    bool result = solution.isValidBST(root);

    if (result)
    {
        cout << "是";
    }
    else
    {
        cout << "不是";
    }
}