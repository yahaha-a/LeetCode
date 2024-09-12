#include <iostream>
#include <stack>
#include "二叉树定义.cpp"

using namespace std;

class Solution
{
public:

    int sumOfLeftLeaves(TreeNode* root)
    {
        stack<TreeNode*> st;
        int result = 0;
        TreeNode* currentNode = root;
        st.push(root);

        while (!st.empty())
        {
            currentNode = st.top();
            st.pop();

            if (currentNode->left != nullptr && currentNode->left->left == nullptr && currentNode->left->right == nullptr)
            {
                result += currentNode->left->value;
            }

            if (currentNode->right != nullptr)
            {
                st.push(currentNode->right);
            }

            if (currentNode->left != nullptr)
            {
                st.push(currentNode->left);
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

    int result = solution.sumOfLeftLeaves(root);

    cout << result;
}