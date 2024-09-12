#include <iostream>
#include <vector>
#include <queue>
#include "二叉树定义.cpp"

using namespace std;

void swapTree(TreeNode* currentNode)
{
    if (currentNode != nullptr)
    {
        TreeNode* temp = currentNode->left;
        currentNode->left = currentNode->right;
        currentNode->right = temp;
    }
}

void invertTree(TreeNode* currentNode)
{
    if (currentNode == nullptr)
    {
        return;
    }

    swapTree(currentNode);
    invertTree(currentNode->left);
    invertTree(currentNode->right);
}

vector<vector<int>> levelOrder(TreeNode* root)
{
    queue<TreeNode*> qt;
    vector<vector<int>> result;
    TreeNode* currentNode = root;
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

    vector<vector<int>> result = levelOrder(root);
    
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    invertTree(root);
    result = levelOrder(root);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
}