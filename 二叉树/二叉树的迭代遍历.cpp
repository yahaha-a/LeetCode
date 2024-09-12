#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include "二叉树定义.cpp"

using namespace std;

vector<int> preorderTraversal(TreeNode *root)
{
    stack<TreeNode *> st;
    vector<int> result;

    TreeNode *currentNode = root;
    st.push(currentNode);

    while (st.size() != 0)
    {
        currentNode = st.top();
        st.pop();
        if (currentNode->right != nullptr)
        {
            st.push(currentNode->right);
        }
        if (currentNode->left != nullptr)
        {
            st.push(currentNode->left);
        }
        result.push_back(currentNode->value);
    }

    return result;
}

vector<int> inorderTraversal(TreeNode *root)
{
    stack<TreeNode *> st;
    vector<int> result;

    TreeNode *currentNode = root;

    while (st.size() != 0 || currentNode != nullptr)
    {
        while (currentNode != nullptr)
        {
            st.push(currentNode);
            currentNode = currentNode->left;
        }

        currentNode = st.top();
        st.pop();
        result.push_back(currentNode->value);
        currentNode = currentNode->right;
    }

    return result;
}

vector<int> postorderTraversal(TreeNode* root)
{
    stack<TreeNode*> st;
    vector<int> result;
    TreeNode* currentNode = root;
    st.push(currentNode);

    while (st.size() != 0)
    {
        currentNode = st.top();
        st.pop();
        result.push_back(currentNode->value);

        if (currentNode->left != nullptr)
        {
            st.push(currentNode->left);
        }
        if (currentNode->right != nullptr)
        {
            st.push(currentNode->right);
        }
    }

    reverse(result.begin(), result.end());
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

    vector<int> result = preorderTraversal(root);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << "\n";

    result = inorderTraversal(root);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << "\n";

    result = postorderTraversal(root);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}