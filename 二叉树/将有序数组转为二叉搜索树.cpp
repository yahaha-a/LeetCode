#include <iostream>
#include <vector>
#include <queue>
#include "二叉树定义.cpp"

using namespace std;

class Solution
{
private:

    TreeNode* traversal(vector<int>& vec, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }

        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(vec[mid]);

        node->left = traversal(vec, left, mid - 1);
        node->right = traversal(vec, mid + 1, right);

        return node;
    }

public:

    TreeNode* createBST(vector<int> vec)
    {
        if (vec.size() == 0)
        {
            return nullptr;
        }

        return traversal(vec, 0, vec.size() - 1);
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
    vector<int> vec = {-10, -3, 0, 5, 9};

    Solution solution;

    TreeNode* root = solution.createBST(vec);
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