#include <climits>  // INT_MAX INT_MIN
// ���������
// ��¼ÿ���ڵ�����ֵ ��Сֵ�߽�

/*
�����Ķ���(�벻Ҫ�ڴ����ж���ýṹ)
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