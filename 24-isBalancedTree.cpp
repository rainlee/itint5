// 边求树深 边判断

/*
树结点的定义(请不要在代码中定义该结构)
struct TreeNode {
  TreeNode *left;
  TreeNode *right;
}*/

// 
bool isBalancedTreeRec(TreeNode *root, int &deep)
{
    if (!root)
    {
        deep = 0;
        return true;
    }
    int ldeep,rdeep;
    if (!isBalancedTreeRec(root->left, ldeep) || !isBalancedTreeRec(root->right, rdeep))
        return false;
    
    deep = max(ldeep, rdeep) + 1;
    if (abs(ldeep - rdeep) > 1)
        return false;
    else
        return true;
}

bool isBalancedTree(TreeNode *root) {
    int deep = 0;
    return isBalancedTreeRec(root, deep);
}