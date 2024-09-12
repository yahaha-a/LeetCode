#include <iostream>
#include <vector>
#include "二叉树定义.cpp"

using namespace std;

class Solution
{
public:

    vector<int> result;
    void traversal(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }

        traversal(root->left);
        result.push_back(root->value);
        traversal(root->right);
    }

    int getMinimumDifference(TreeNode* root)
    {
        traversal(root);
        int minNumber = INT_MAX;
        for (int i = 1; i < result.size(); i++)
        {
            minNumber = min(minNumber, result[i] - result[i - 1]);
        }
        return minNumber;
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