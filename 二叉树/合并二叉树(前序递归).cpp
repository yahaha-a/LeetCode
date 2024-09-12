#include <iostream>
#include <vector>
#include <queue>
#include "二叉树定义.cpp"

using namespace std;

class Solution
{
public:
    TreeNode *MergeTree(TreeNode *node1, TreeNode *node2)
    {
        if (node1 == nullptr)
        {
            return node2;
        }

        if (node2 == nullptr)
        {
            return node1;
        }

        node1->value += node2->value;

        node1->left = MergeTree(node1->left, node2->left);
        node1->right = MergeTree(node1->right, node2->right);

        return node1;
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
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node6 = new TreeNode(6);
    TreeNode *node7 = new TreeNode(7);

    TreeNode *root1 = node1;
    root1->Left(node2)->Right(node3);
    node2->Left(node4)->Right(node5);
    node3->Left(node6);
    node4->Left(node7);

    TreeNode *node11 = new TreeNode(1);
    TreeNode *node21 = new TreeNode(2);
    TreeNode *node31 = new TreeNode(3);
    TreeNode *node41 = new TreeNode(4);
    TreeNode *node51 = new TreeNode(5);
    TreeNode *node61 = new TreeNode(6);
    TreeNode *node71 = new TreeNode(7);

    TreeNode *root2 = node11;
    root2->Left(node21)->Right(node31);
    node21->Left(node41)->Right(node51);
    node31->Left(node61);
    node41->Left(node71);

    Solution solution;

    TreeNode *root = solution.MergeTree(root1, root2);

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