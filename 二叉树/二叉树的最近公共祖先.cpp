#include <iostream>
#include "二叉树定义.cpp"

using namespace std;

class Solution
{
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q)
    {
        if (root == nullptr)
        {
            return root;
        }

        if (root->value == p || root->value == q)
        {
            return root;
        }

        TreeNode* leftNode = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightNode = lowestCommonAncestor(root->right, p, q);

        if (leftNode != nullptr && rightNode != nullptr)
        {
            return root;
        }

        if (leftNode != nullptr && rightNode == nullptr)
        {
            return leftNode;
        }

        if (leftNode == nullptr && rightNode != nullptr)
        {
            return rightNode;
        }
        
        return nullptr;
    }
};

int main()
{
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node6 = new TreeNode(6);
    TreeNode *node7 = new TreeNode(7);
    TreeNode *node8 = new TreeNode(8);
    TreeNode *node10 = new TreeNode(10);
    TreeNode *node15 = new TreeNode(15);
    TreeNode *node20 = new TreeNode(20);

    node8->Left(node10)->Right(node4);
    node10->Left(node1)->Right(node7);
    node4->Left(node15)->Right(node20);
    node7->Left(node6)->Right(node5);

    Solution solution;

    TreeNode* result = solution.lowestCommonAncestor(node8, 6, 5);
    cout << result->value;
}