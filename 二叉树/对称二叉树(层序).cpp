#include <iostream>
#include <queue>
#include "二叉树定义.cpp"

using namespace std;

bool ifSame(TreeNode* root)
{
    queue<TreeNode*> qt;
    qt.push(root->left);
    qt.push(root->right);

    TreeNode* left;
    TreeNode* right;
    while (qt.size() != 0)
    {
        left = qt.front();
        qt.pop();
        right = qt.front();
        qt.pop();

        if (left == nullptr && right == nullptr)
        {
            continue;
        }
        else if (left != nullptr && right == nullptr)
        {
            return false;
        }
        else if (left == nullptr && right != nullptr)
        {
            return false;
        }
        else if (left->value != right->value)
        {
            return false;
        }
        
        qt.push(left->left);
        qt.push(right->right);
        qt.push(left->right);
        qt.push(right->left);
    }

    return true;
}

int main()
{
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node6 = new TreeNode(5);
    TreeNode *node7 = new TreeNode(5);

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