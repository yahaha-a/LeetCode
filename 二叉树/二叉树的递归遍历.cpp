#include <iostream>
#include <vector>
#include "二叉树定义.cpp"

using namespace std;

void preorder_traversal(TreeNode* currentNode, vector<int> &s)
{
    if (currentNode == nullptr)
    {
        return;
    }
    s.push_back(currentNode->value);
    preorder_traversal(currentNode->left, s);
    preorder_traversal(currentNode->right, s);
}

void inorder_traversal(TreeNode* currentNode, vector<int> &s)
{
    if (currentNode == nullptr)
    {
        return;
    }
    inorder_traversal(currentNode->left, s);
    s.push_back(currentNode->value);
    inorder_traversal(currentNode->right, s);
}

void postorder_traversal(TreeNode* currentNode, vector<int> &s)
{
    if (currentNode == nullptr)
    {
        return;
    }
    postorder_traversal(currentNode->left, s);
    postorder_traversal(currentNode->right, s);
    s.push_back(currentNode->value);
}

vector<int> traverse(TreeNode* root)
{
    vector<int> s;
    preorder_traversal(root, s);
    return s;
}

int main()
{
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);

    TreeNode* root = node1;
    root->Left(node2)->Right(node3);
    node2->Left(node4)->Right(node5);
    node3->Left(node6)->Right(node7);

    vector<int> preorder_traversal_vec = traverse(root);

    for (int i = 0; i < preorder_traversal_vec.size(); i++)
    {
        cout << preorder_traversal_vec[i] << " ";
    }
}