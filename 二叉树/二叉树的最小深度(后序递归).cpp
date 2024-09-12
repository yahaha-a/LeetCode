#include <iostream>
#include "二叉树定义.cpp"

using namespace std;

int getDepth(TreeNode* node)
{
    if (node == nullptr)
    {
        return 0;
    }

    int leftDepth = getDepth(node->left);
    int rightDepth = getDepth(node->right);
    int minDepth;

    if (node->left == nullptr && node->right != nullptr)
    {
        minDepth = 1 + rightDepth;
    }
    else if (node->left != nullptr && node->right == nullptr)
    {
        minDepth = 1 + leftDepth;
    }
    else
    {
        minDepth = 1 + min(leftDepth, rightDepth);
    }

    return minDepth;
}

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
    node3->Left(node6);
    node4->Left(node7);

    int depth = getDepth(root);
    cout << depth;
}