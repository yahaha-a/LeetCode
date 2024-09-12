#include <iostream>
#include <vector>
#include <queue>
#include "二叉树定义.cpp"

using namespace std;

class Solution
{
private:

    TreeNode* traversal(vector<int> vec)
    {
        TreeNode* node = new TreeNode(0);

        if (vec.size() == 1)
        {
            node->value = vec[0];
            return node;
        }

        int maxValue = INT_MIN;
        int maxValueIndex;

        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] > maxValue)
            {
                maxValue = vec[i];
                maxValueIndex = i;
            }
        }

        node->value = maxValue;
        
        if (maxValueIndex > 0)
        {
            vector<int> newVec(vec.begin(), vec.begin() + maxValueIndex);
            node->left = traversal(newVec);
        }
        if (maxValueIndex < (vec.size() - 1))
        {
            vector<int> newVec(vec.begin() + maxValueIndex + 1, vec.end());
            node->right = traversal(newVec);
        }

        return node;
    }

public:

    TreeNode* constructMaximumBinaryTree(vector<int> vec)
    {
        if (vec.size() == 0)
        {
            return nullptr;
        }

        return traversal(vec);
    }

    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode*> qt;
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
    vector<int> vec = {3, 2, 1, 6, 0, 5};
    Solution solution;

    TreeNode* root = solution.constructMaximumBinaryTree(vec);

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