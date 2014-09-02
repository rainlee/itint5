//使用getLeftChildNode(TreeNode)获得左儿子结点
//使用getRightChildNode(TreeNode)获得右儿子结点
//使用isNullNode(TreeNode)判断结点是否为空
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

// 法2：观察完全二叉树，左右孩子的高度相差不超过1
// hleft == hright 的时候，左子树一定是满二叉树
// hleft > hright (hleft == hright+1)，右子树一定是满二叉树
// 根据左右子树的高度，可以判断出最后一层最右叶节点的位置，就可以进行二分。
// 时间复杂度O(2 log n)

// 求树深，一直往左走
int getHeight(TreeNode root) {
    int h = 0;
    while (!isNullNode(root))
    {
        ++h;
        root = getLeftChildNode(root);
    }
    return h;
}

// 求满二叉树的节点个数
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