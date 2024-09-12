#include <iostream>
#include "二叉树定义.cpp"

using namespace std;

bool compareTree(TreeNode* left, TreeNode* right)
{
    if (left == nullptr && right == nullptr)
    {
        return true;
    }
    else if (left == nullptr && right != nullptr)
    {
        return false;
    }
    else if (left != nullptr && right == nullptr)
    {
        return false;
    }
    else if (left->value != right->value)
    {
        return false;
    }
    else
    {
        bool ifOutsideSame = compareTree(left->left, right->right);
        bool ifInsideSame = compareTree(left->right, right->left);
        bool ifSame = ifOutsideSame && ifInsideSame;
        return ifSame;
    }
}

bool ifSame(TreeNode* root)
{
    if (root == nullptr)
    {
        return true;
    }

    return compareTree(root->left, root->right);
}

int main()
{
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(2);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node6 = new TreeNode(5);
    TreeNode *node7 = new TreeNode(4);

    TreeNode *root = node1;
    root->Left(node2)->Right(node3);
    node2->Left(node4)->Right(node5);
    node3->Left(node6)->Right(node7);

    bool result = ifSame(root);

    if (result)
    {
        cout << "相同";
    }
    else
    {
        cout << "不同";
    }
}