class Solution
{
public:
  Node *copyRandomList(Node *head)
  {
    if (head == NULL)
    {
      return NULL;
    }
    Node *p = head, *r = NULL, *s = NULL;
    Node *copyHead = new Node(0);
    Node *q = copyHead;
    while (p)
    {
      q->val = p->val;
      if (p->next)
      {
        Node *temp = new Node(0);
        q->next = temp;
      }
      if (q->next)
        q = q->next;
      else
        q->next = NULL;
      p = p->next;
    }
    p = head;
    q = head;
    r = copyHead;
    s = copyHead;
    while (p)
    {
      while (q)
      {
        if (p->random == q)
        {
          r->random = s;
          break;
        }
        q = q->next;
        s = s->next;
      }
      q = head;
      s = copyHead;
      p = p->next;
      r = r->next;
    }

    return copyHead;
  }
};