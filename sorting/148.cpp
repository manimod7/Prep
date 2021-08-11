ListNode *sortList(ListNode *head)
{
  if (head == nullptr || head->next == NULL)
    return head;
  ListNode *fast = head->next->next, *slow = head;
  while (fast && fast->next)
  {
    fast = fast->next->next;
    slow = slow->next;
  }
  ListNode *r = sortList(slow->next);
  slow->next = NULL;
  ListNode *l = sortList(head);
  return merge(l, r);
}

ListNode *merge(ListNode *l, ListNode *r)
{
  ListNode *dummy = new ListNode(0), *node;
  node = dummy;
  while (l && r)
  {
    if (l->val < r->val)
    {
      node->next = l;
      l = l->next;
    }
    else
    {
      node->next = r;
      r = r->next;
    }
    node = node->next;
  }
  if (l)
    node->next = l;
  else
    node->next = r;
  return dummy->next;
}