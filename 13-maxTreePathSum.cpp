/*
�����Ķ���(�벻Ҫ�ڴ����ж��������)
struct TreeNode {
    int val;
    vector<TreeNode*> children;  //�ý��Ķ��ӽ��
 };
*/
// ����root��β��·�����ֵ
// ��¼root�������У���root��β������֧
int maxTreePathSumRec(TreeNode *root, int &maxp)
{
    if (!root)
        return 0;
    
    int max1 = 0,max2 = 0; // ��¼������֧
    for (int i = 0; i < root->children.size(); ++i)
    {
        int tmp = maxTreePathSumRec(root->children[i], maxp);
        if (tmp > max1)
        {
            max2 = max1;
            max1 = tmp;
        }
        else if (tmp > max2)
            max2 = tmp;
    }
    
    maxp = max(maxp, root->val + max1 + max2);
    
    return root->val + max1;
}
int maxTreePathSum(TreeNode *root) {
    int maxp = 0;
    maxTreePathSumRec(root, maxp);
    return maxp;
}