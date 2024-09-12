#include <iostream>
#include "二叉树定义.cpp"

using namespace std;

class Solution
{

public:
    int sumOfLeftLeaves(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        if (node->left == nullptr && node->right == 0)
        {
            return 0;
        }

        int leftSum = sumOfLeftLeaves(node->left);

        if (node->left != nullptr && node->left->left == nullptr && node->left->right == nullptr)
        {
            return node->left->value;
        }

        int rightSum = sumOfLeftLeaves(node->right);

        return leftSum + rightSum;
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

    int result = solution.sumOfLeftLeaves(root);

    cout << result;
}