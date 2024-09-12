#include <iostream>
#include <vector>
#include <queue>
#include "二叉树定义.cpp"

using namespace std;

void levelOrder(TreeNode* cur, vector<vector<int>> result, int depth)
{
    if (result.size() == depth)
    {
        vector<int> vec;
        result.push_back(vec);
    }

    result[depth].push_back(cur->value);
    if (cur->left != nullptr)
    {
        levelOrder(cur->left, result, depth + 1);
    }
    if (cur->right != nullptr)
    {
        levelOrder(cur->right, result, depth + 1);
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
    node3->Left(node6)->Right(node7);

    int depth = 0;
    vector<vector<int>> result;

    levelOrder(root, result, depth);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
}