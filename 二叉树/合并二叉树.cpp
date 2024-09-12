#include <iostream>
#include <vector>
#include <queue>
#include "二叉树定义.cpp"

using namespace std;

class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        queue<TreeNode *> qt;
        TreeNode *node1 = root1;
        TreeNode *node2 = root2;

        while (qt.size() != 0)
        {
            node1 = qt.front();
            qt.pop();
            node2 = qt.front();
            qt.pop();

            node1->value += node2->value;

            if (node1 == nullptr && node2 != nullptr)
            {
                node1->value = node2->value;
            }
            if (node1 != nullptr && node2 == nullptr)
            {
                node1->value = node1->value;
            }

            qt.push(node1->left);
            qt.push(node2->left);
            qt.push(node1->right);
            qt.push(node2->right);
        }
    }
};