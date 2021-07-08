//FInd the middle element of a Linked List
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
  ListNode *middleNode(ListNode *head)
  {

    ListNode *slow = head, *fast = head;
    if (!slow->next)
      return slow;
    if (!fast->next->next)
      return slow->next;
    while (fast->next && fast->next->next)
    {
      slow = slow->next;
      fast = fast->next->next;
      if (fast->next && !fast->next->next)
        slow = slow->next;
    }
    return slow;
  }
};