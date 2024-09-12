#include <iostream>
#include <vector>
#include "二叉树定义.cpp"

using namespace std;

class Solution
{
private:
    void traversal(TreeNode *node, vector<int> &path, vector<string> &result)
    {
        path.push_back(node->value);

        if (node->left == nullptr && node->right == nullptr)
        {
            string str;

            for (int i = 0; i < path.size() - 1; i++)
            {
                str += to_string(path[i]);
                str += " -> ";
            }

            str += to_string(path[path.size() - 1]);
            result.push_back(str);

            return;
        }

        if (node->left != nullptr)
        {
            traversal(node->left, path, result);
            path.pop_back();
        }

        if (node->right != nullptr)
        {
            traversal(node->right, path, result);
            path.pop_back();
        }
    }

public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<int> path;
        vector<string> result;

        traversal(root, path, result);

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

    vector<string> result;
    Solution solution;
    result = solution.binaryTreePaths(root);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
        cout << "\n";
    }
}