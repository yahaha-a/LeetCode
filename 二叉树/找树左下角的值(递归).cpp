#include <iostream>
#include "二叉树定义.cpp"

using namespace std;

class Solution
{
public:

    int maxDepth = INT_MIN;
    int result;
    void traversal(TreeNode* node, int depth)
    {
        if (node->left == nullptr && node->right == nullptr)
        {
            if (depth > maxDepth)
            {
                maxDepth = depth;
                result = node->value;
            }
        }

        if (node->left != nullptr)
        {
            depth++;
            traversal(node->left, depth);
            depth--;
        }

        if (node->right != nullptr)
        {
            depth++;
            traversal(node->right, depth);
            depth--;
        }
    }

    int findBottomLeftValue(TreeNode* root)
    {
        traversal(root, 1);
        return result;
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

    int result = solution.findBottomLeftValue(root);
    cout << result;
}