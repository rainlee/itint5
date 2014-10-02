// �������� ���ж�

/*
�����Ķ���(�벻Ҫ�ڴ����ж���ýṹ)
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