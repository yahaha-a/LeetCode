#include <iostream>
#include "二叉树定义.cpp"

using namespace std;

class Solution
{
private:

    bool traversal(TreeNode* node, int count)
    {
        if (node->left == nullptr && node->right == nullptr && count == 0)
        {
            return true;
        }

        if (node->left != nullptr)
        {
            if(traversal(node->left, count - node->left->value))
            {
                return true;
            }
        }

        if (node->right != nullptr)
        {
            if(traversal(node->right, count - node->right->value))
            {
                return true;
            };
        }

        return false;
    }

public:

    bool hasPathSum(TreeNode* root, int Sum)
    {
        return traversal(root, Sum - root->value);
    }
};

int main()
{
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node6 = new TreeNode(6);
    TreeNode *node7 = new TreeNode(7);

    TreeNode *root = node1;
    root->Left(node2)->Right(node3);
    node2->Left(node4)->Right(node5);
    node3->Left(node6)->Right(node7);

    Solution solution;

    bool result = solution.hasPathSum(root, 7);

    if (result)
    {
        cout << "有";
    }
    else
    {
        cout << "没有";
    }
}