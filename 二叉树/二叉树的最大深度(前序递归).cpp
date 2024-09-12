#include <iostream>
#include "二叉树定义.cpp"

using namespace std;

void getDepth(TreeNode* node, int depth)
{
    if (node->left != nullptr)
    {
        depth++;
        getDepth(node->left, depth);
        depth--;
    }
    if (node->right != nullptr)
    {
        depth++;
        getDepth(node->right, depth);
        depth--;
    }
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

    int depth = 1;
    getDepth(root, depth);
    cout << depth;
}