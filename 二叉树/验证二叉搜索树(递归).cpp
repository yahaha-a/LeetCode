#include <iostream>
#include "二叉树定义.cpp"

class Solution
{
public:

    int minCount = INT_MIN;
    bool isValidBST(TreeNode* root)
    {
        if (root == nullptr)
        {
            return true;
        }

        bool left = isValidBST(root->left);
        if (root->value <= minCount)
        {
            return false;
        }
        else
        {
            minCount = root->value;
        }
        bool right = isValidBST(root->right);
        bool result = left && right;
        return result;
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