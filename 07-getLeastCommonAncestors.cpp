/*
struct TreeNode {
    TreeNode *parent;
}
*/

//���ؽ��node1��node2�������������
// �ҵ���Ҷ�ӽڵ㵽���ڵ��·�����õ�����������
// ����ת��Ϊ�������������ཻ�ĵ�һ���ڵ�
int getPathLen(TreeNode *node)
{
    int len = 0;
    while (node)
    {
        node = node->parent;
        ++len;
    }
    return len;
}
TreeNode *getLCA(TreeNode *node1, TreeNode *node2) {
    if (!node1 || !node2)
        return NULL;
    
    int len1 = getPathLen(node1);
    int len2 = getPathLen(node2);
    int cnt;
    if (len1 > len2)
    {
        cnt = len1 - len2;
        while (cnt--)
            node1 = node1->parent;
    }
    else if (len1 < len2)
    {
        cnt = len2 - len1;
        while (cnt--)
            node2 = node2->parent;
    }
    while (node1 != node2)
    {
        node1 = node1->parent;
        node2 = node2->parent;
    }
    return node1;
}