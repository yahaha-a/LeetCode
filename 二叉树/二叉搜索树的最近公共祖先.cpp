#include <iostream>
#include "二叉树定义.cpp"

using namespace std;

class Solution
{
private:

    TreeNode* traversal(TreeNode* node, int p, int q)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        if (node->value < p && node->value < q)
        {
            TreeNode* result = traversal(node->right, p, q);
            if (result != nullptr)
            {
                return result;
            }
        }

        if (node->value > p && node->value > q)
        {
            TreeNode* result = traversal(node->left, p, q);
            if (result != nullptr)
            {
                return result;
            }
        }

        return node;
    }

public:

    TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q)
    {
        TreeNode* result = traversal(root, p, q);
        return result;
    }
};

int main()
{
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node6 = new TreeNode(6);
    TreeNode *node8 = new TreeNode(8);
    TreeNode *node9 = new TreeNode(9);
    TreeNode *node10 = new TreeNode(10);
    TreeNode *node11 = new TreeNode(11);
    TreeNode *node12 = new TreeNode(12);

    node10->Left(node5)->Right(node11);
    node5->Left(node3)->Right(node8);
    node3->Left(node1);
    node8->Left(node6)->Right(node9);
    node11->Left(node12);

    Solution solution;

    TreeNode* result = solution.lowestCommonAncestor(node10, 6, 9);
    cout << result->value;
}