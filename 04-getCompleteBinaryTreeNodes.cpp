//ʹ��getLeftChildNode(TreeNode)�������ӽ��
//ʹ��getRightChildNode(TreeNode)����Ҷ��ӽ��
//ʹ��isNullNode(TreeNode)�жϽ���Ƿ�Ϊ��
/*
int sum = 0;
int count_complete_binary_tree_nodes(TreeNode root) {
    if (isNullNode(root))
        return sum;
    ++sum;
    count_complete_binary_tree_nodes(getLeftChildNode(root));
    count_complete_binary_tree_nodes(getRightChildNode(root));
    return sum;
}
*/

// ��2���۲���ȫ�����������Һ��ӵĸ߶�������1
// hleft == hright ��ʱ��������һ������������
// hleft > hright (hleft == hright+1)��������һ������������
// �������������ĸ߶ȣ������жϳ����һ������Ҷ�ڵ��λ�ã��Ϳ��Խ��ж��֡�
// ʱ�临�Ӷ�O(2 log n)

// �����һֱ������
int getHeight(TreeNode root) {
    int h = 0;
    while (!isNullNode(root))
    {
        ++h;
        root = getLeftChildNode(root);
    }
    return h;
}

// �����������Ľڵ����
int count_perfect_binary_tree_nodes(int height) {
    return pow(2, height) - 1;
}

int count_complete_binary_tree_nodes(TreeNode root) {
    int count = 0;
    while (!isNullNode(root)) {
        int hleft = getHeight(getLeftChildNode(root));
        int hright = getHeight(getRightChildNode(root));
        
        count += count_perfect_binary_tree_nodes(hright) + 1;  // 1 means root
        
        if (hleft == hright)  // left subtree is perfect binary tree
            root = getRightChildNode(root);
        else
            root = getLeftChildNode(root);
    }
    return count;
}