/*
树结点的定义(请不要在代码中定义该类型)
struct TreeNode {
    int val;
    vector<TreeNode*> children;  //该结点的儿子结点
 };
*/
// 求以root结尾的路径最大值
// 记录root的子树中，以root结尾最大的两支
int maxTreePathSumRec(TreeNode *root, int &maxp)
{
    if (!root)
        return 0;
    
    int max1 = 0,max2 = 0; // 记录最大的两支
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