#include <climits>  // INT_MAX INT_MIN
// 先序遍历树
// 记录每个节点的最大值 最小值边界

/*
树结点的定义(请不要在代码中定义该结构)
struct TreeNode {
  int val;
  TreeNode *left, *right;
}*/

bool isBSTRec(TreeNode *root, int maxv, int minv)
{
    if (!root)
        return true;
    
    if ((root->val <= minv) || (root->val > maxv))
        return false;
    
    return isBSTRec(root->left, root->val, minv) && isBSTRec(root->right, maxv, root->val);
}

bool isBST(TreeNode *root) {
    return isBSTRec(root, INT_MAX, INT_MIN);
}