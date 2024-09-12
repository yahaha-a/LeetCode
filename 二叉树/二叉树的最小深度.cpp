#include <iostream>
#include <vector>
#include <queue>
#include "二叉树定义.cpp"

using namespace std;

int minDepth(TreeNode* root)
{
    queue<TreeNode*> qt;
    TreeNode* currentNode = root;
    qt.push(currentNode);

    int depth = 0;
    int size;
    while (qt.size() != 0)
    {
        size = qt.size();
        depth++;

        for (int i = 0; i < size; i++)
        {
            currentNode = qt.front();
            qt.pop();

            if (currentNode->left != nullptr)
            {
                qt.push(currentNode->left);
            }
            if (currentNode->right != nullptr)
            {
                qt.push(currentNode->right);
            }

            if (currentNode->left == nullptr && currentNode->right == nullptr)
            {
                return depth;
            }
        }
    }

    return depth;
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

    int depth = minDepth(root);

    cout << depth;
}