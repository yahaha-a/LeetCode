#include <iostream>
#include "二叉树定义.cpp"

using namespace std;

class Solution
{
private:

    int result = INT_MAX;
    TreeNode* pre;

    void traversal(TreeNode* node)
    {
        if (node == nullptr)
        {
            return;
        }

        traversal(node->left);
        if (pre != nullptr)
        {
            result = min(result, node->value - pre->value);
        }
        pre = node;
        traversal(node->right);
    }

public:

    int getMinimumDifference(TreeNode* root)
    {
        traversal(root);
        return result;
    }
};

int main()
{
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(7);

    TreeNode *root = node4;
    root->Left(node2)->Right(node5);
    node2->Left(node1)->Right(node3);

    Solution solution;
    int result = solution.getMinimumDifference(root);

    cout << result;
}