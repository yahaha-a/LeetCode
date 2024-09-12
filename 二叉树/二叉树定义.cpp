#include <iostream>

using namespace std;

struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : value(x), left(nullptr), right(nullptr){}

    TreeNode* Left(TreeNode* l)
    {
        left = l;
        return this;
    }

    TreeNode* Right(TreeNode* r)
    {
        right = r;
        return this;
    }
};
