#include <iostream>
#include <vector>
#include <queue>
#include "二叉树定义.cpp"

using namespace std;

vector<float> averageOfLevels(TreeNode* root)
{
    queue<TreeNode*> qt;
    vector<float> result;
    TreeNode* currentNode = root;
    qt.push(currentNode);

    float sum;
    int size;

    while (qt.size() != 0)
    {
        size = qt.size();
        sum = 0;

        for (int i = 0; i < size; i++)
        {
            currentNode = qt.front();
            qt.pop();
            sum += currentNode->value;
            
            if (currentNode->left != nullptr)
            {
                qt.push(currentNode->left);
            }
            if (currentNode->right != nullptr)
            {
                qt.push(currentNode->right);
            }
        }
        result.push_back(sum / size);
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
    node3->Left(node6)->Right(node7);

    vector<float> result = averageOfLevels(root);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}