// Ҫ��O(1)�ռ䣬�Ͳ�����map��
// ��ԭ�ظ��ƽ��nextָ�룬����ԭ���ĺ��棬����1->2->3 ����Ϊ1->1->2->2->3->3
// Ȼ����randomָ��
// ����ٲ�����

/**
������Ķ���(�벻Ҫ�ڴ����ж��������)
struct ListNode {
    ListNode *next;
    ListNode *random;
};
*/

// ����nextָ��
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
// ����randomָ��
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
// ����������
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

// ���ظ��Ƶ�������ͷ���
ListNode* copyListWithRandomPtr(ListNode *head) {
    if (!head)
        return NULL;
    
    doubleList(head);
    copyRandom(head);
    return breakList(head);
}