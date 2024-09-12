#include <iostream>
#include <vector>
#include <queue>
#include "二叉树定义.cpp"

using namespace std;

class Solution
{
public:

    TreeNode* searchBST(TreeNode* root, int val)
    {
        TreeNode* currentNode = root;

        while (currentNode != nullptr)
        {
            if (currentNode->value == val)
            {
                return currentNode;
            }
            else if (currentNode->value > val)
            {
                currentNode = currentNode->left;
            }
            else if (currentNode->value < val)
            {
                currentNode = currentNode->right;
            }
        }

        return nullptr;
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
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(7);

    TreeNode *root = node4;
    root->Left(node2)->Right(node5);
    node2->Left(node1)->Right(node3);

    Solution solution;
    root = solution.searchBST(root, 2);
    vector<vector<int>> result = solution.levelOrder(root);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
}