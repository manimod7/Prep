// * Remove Nth Node from the end

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    ListNode *nth = head;
    for (int i = 0; i < n; i++)
    {
      nth = nth->next;
    }
    if (nth == NULL)
      return head->next;
    ListNode *p = head;
    while (nth->next)
    {
      p = p->next;
      nth = nth->next;
    }
    // ListNode *q = p->next;
    // p->next = q->next;
    // delete q;
    p->next = p->next->next;
    return head;
  }
};