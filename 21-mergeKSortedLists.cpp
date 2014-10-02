// 用一个小顶堆辅助合并
// 时间复杂度O(nlogk)

/*链表结点的定义(请不要在代码中定义该类型)
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

//lists包含k个链表的头结点,返回合并后链表头结点
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