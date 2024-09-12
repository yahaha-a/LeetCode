#include <iostream>
#include <vector>
#include <queue>
#include "二叉树定义.cpp"

using namespace std;

class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            TreeNode *node = new TreeNode(val);
            return node;
        }

        if (val < root->value)
        {
            root->left = insertIntoBST(root->left, val);
        }

        if (val > root->value)
        {
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }

    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> qt;
        vector<vector<int>> result;
        TreeNode *currentNode = root;
        qt.push(currentNode);

        while (qt.size() != 0)
        {
            vector<int> vec;
            int size = qt.size();

            for (int i = 0; i < size; i++)
            {
                currentNode = qt.front();
                qt.pop();
                vec.push_back(currentNode->value);
                if (currentNode->left != nullptr)
                {
                    qt.push(currentNode->left);
                }
                if (currentNode->right != nullptr)
                {
                    qt.push(currentNode->right);
                }
            }

            result.push_back(vec);
        }

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

    vector<vector<int>> result = solution.levelOrder(node10);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    TreeNode* root = solution.insertIntoBST(node10, 2);

    result = solution.levelOrder(root);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
}