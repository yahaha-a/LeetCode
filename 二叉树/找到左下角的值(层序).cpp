#include <iostream>
#include <queue>
#include "二叉树定义.cpp"

using namespace std;

class Solution
{
public:

    int findBottomLeftValue(TreeNode* root)
    {
        queue<TreeNode*> qt;
        TreeNode* currentNode = root;
        qt.push(currentNode);
        int result;
        int size;

        while (!qt.empty())
        {
            size = qt.size();

            for (int i = 0; i < size; i++)
            {
                currentNode = qt.front();
                qt.pop();

                if (i == 0)
                {
                    result = currentNode->value;
                }

                if (currentNode->left != nullptr)
                {
                    qt.push(currentNode->left);
                }

                if (currentNode->right != nullptr)
                {
                    qt.push(currentNode->right);
                }
            }

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

    TreeNode *root = node1;
    root->Left(node2)->Right(node3);
    node2->Left(node4)->Right(node5);
    node3->Left(node6)->Right(node7);

    Solution solution;

    int result = solution.findBottomLeftValue(root);
    cout << result;
}