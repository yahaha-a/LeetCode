#include <iostream>
#include <vector>
#include <queue>
#include "二叉树定义.cpp"

using namespace std;

class Solution
{
private:
    TreeNode *traversal(vector<int> &inOrder, vector<int> &postOrder)
    {
        if (postOrder.size() == 0)
        {
            return nullptr;
        }

        TreeNode *root = new TreeNode(postOrder[postOrder.size() - 1]);

        if (postOrder.size() == 1)
        {
            return root;
        }

        int i;
        for (i = 0; i < inOrder.size(); i++)
        {
            if (root->value == inOrder[i])
            {
                break;
            }
        }

        vector<int> leftInOrder(inOrder.begin(), inOrder.begin() + i);
        vector<int> rightInOrder(inOrder.begin() + i + 1, inOrder.end());

        vector<int> leftPostOrder(postOrder.begin(), postOrder.begin() + leftInOrder.size());
        vector<int> rightPostOrder(postOrder.begin() + leftInOrder.size(), postOrder.end());

        root->left = traversal(leftInOrder, leftPostOrder);
        root->right = traversal(rightInOrder, rightPostOrder);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inOrder, vector<int> &postOrder)
    {
        if (inOrder.size() == 0 || postOrder.size() == 0)
        {
            return nullptr;
        }

        return traversal(inOrder, postOrder);
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
    vector<int> inOrder = {9, 3, 15, 20, 7};
    vector<int> postOrder = {9, 15, 7, 20, 3};

    Solution solution;
    TreeNode *root = solution.buildTree(inOrder, postOrder);

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