#include <iostream>
#include <stack>
#include <vector>
#include "二叉树定义.cpp"

using namespace std;

vector<int> preorderTraversal(TreeNode* root)
{
    stack<TreeNode*> st;
    vector<int> result;
    TreeNode* currentNode = root;
    st.push(currentNode);

    while (st.size() != 0)
    {
        currentNode = st.top();
        if (currentNode == nullptr)
        {
            st.pop();
            currentNode = st.top();
            result.push_back(currentNode->value);
            st.pop();
        }
        else
        {
            st.pop();
            if (currentNode->right != nullptr)
            {
                st.push(currentNode->right);
            }
            if (currentNode->left != nullptr)
            {
                st.push(currentNode->left);
            }
            st.push(currentNode);
            st.push(nullptr);
        }
    }

    return result;
}

vector<int> inorderTraversal(TreeNode* root)
{
    stack<TreeNode*> st;
    vector<int> result;
    TreeNode* currentNode = root;
    st.push(currentNode);

    while (st.size() != 0)
    {
        currentNode = st.top();

        if (currentNode == nullptr)
        {
            st.pop();
            currentNode = st.top();
            result.push_back(currentNode->value);
            st.pop();
        }
        else
        {
            st.pop();
            if (currentNode->right != nullptr)
            {
                st.push(currentNode->right);
            }
            st.push(currentNode);
            st.push(nullptr);
            if (currentNode->left != nullptr)
            {
                st.push(currentNode->left);
            }
        }
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
        if (currentNode == nullptr)
        {
            st.pop();
            currentNode = st.top();
            result.push_back(currentNode->value);
            st.pop();
        }
        else
        {
            st.push(nullptr);
            if (currentNode->right != nullptr)
            {
                st.push(currentNode->right);
            }
            if (currentNode->left != nullptr)
            {
                st.push(currentNode->left);
            }
        }
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

    vector<int> result = inorderTraversal(root);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << "\n";

    result = preorderTraversal(root);

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