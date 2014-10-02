// 要求O(1)空间，就不能用map了
// 先原地复制结点next指针，挂在原结点的后面，比如1->2->3 复制为1->1->2->2->3->3
// 然后复制random指针
// 最后再拆开链表

/**
链表结点的定义(请不要在代码中定义该类型)
struct ListNode {
    ListNode *next;
    ListNode *random;
};
*/

// 复制next指针
void doubleList(ListNode *head)
{
    ListNode *node = head;
    while (node)
    {
        ListNode *tmp = new ListNode;
        tmp->next = node->next;
        node->next = tmp;
        node = node->next->next;
    }
}
// 复制random指针
void copyRandom(ListNode *head)
{
    ListNode *node = head;
    while (node)
    {
        if (node->random)
            node->next->random = node->random->next;
        node = node->next->next;
    }
}
// 拆开两个链表
ListNode *breakList(ListNode *head)
{
    if (!head) return NULL;
    
    ListNode dummy;
    ListNode *node = head;
    ListNode *node2 = &dummy;
    while (node)
    {
        node2->next = node->next;
        node->next = node->next->next;
        node = node->next;
        node2 = node2->next;
    }
    return dummy.next;
}

// 返回复制的新链表头结点
ListNode* copyListWithRandomPtr(ListNode *head) {
    if (!head)
        return NULL;
    
    doubleList(head);
    copyRandom(head);
    return breakList(head);
}