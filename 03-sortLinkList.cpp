// Á´±í¹é²¢ÅÅÐò
ListNode *mergeList(ListNode *l1, ListNode *l2)
{
    ListNode *node1 = l1;
    ListNode *node2 = l2;
    ListNode dummy;
    ListNode *node = &dummy;
    while (node1 && node2)
    {
        if (node1->val <= node2->val)
        {
            node->next = node1;
            node1 = node1->next;
        }
        else
        {
            node->next = node2;
            node2 = node2->next;
        }
        node = node->next;
    }
    if (node1)
        node->next = node1;
    if (node2)
        node->next = node2;
    return dummy.next;
}
ListNode* sortLinkList(ListNode *head) {
    if (!head || !head->next)
        return head;
    
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *head2 = slow->next;
    slow->next = NULL;
    
    ListNode *pleft = sortLinkList(head);
    ListNode *pright = sortLinkList(head2);
    return mergeList(pleft, pright);
}