// ��һ��С���Ѹ����ϲ�
// ʱ�临�Ӷ�O(nlogk)

/*������Ķ���(�벻Ҫ�ڴ����ж��������)
struct ListNode {
  int val;
  ListNode *next;
};
*/

struct cmpList {
    bool operator ()(ListNode *n1, ListNode *n2)
    {
        return (n1->val > n2->val);
    }
};

//lists����k�������ͷ���,���غϲ�������ͷ���
ListNode* merge(vector<ListNode*> &lists) {
    if (lists.empty()) return NULL;
    
    priority_queue<ListNode *, vector<ListNode *>, cmpList> heap;
    for (int i = 0; i < lists.size(); ++i)
        if (lists[i])
            heap.push(lists[i]);
    
    ListNode dummy;
    ListNode *node = &dummy;
    while (!heap.empty())
    {
        ListNode *tmp = heap.top();
        heap.pop();
        
        node->next = tmp;
        node = node->next;
        
        if (tmp->next)
            heap.push(tmp->next);
    }
    return dummy.next;
}