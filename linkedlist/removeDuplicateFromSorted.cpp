// * Remove duplicate elements from sorted Linked Lists

struct Node *current = head;

/* Pointer to store the next pointer of a node to be deleted*/
struct Node *next_next;

/* do nothing if the list is empty */
if (current == NULL)
  return;

/* Traverse the list till last node */
while (current->next != NULL)
{
  /* Compare current node with next node */
  if (current->data == current->next->data)
  {
    /* The sequence of steps is important*/
    next_next = current->next->next;
    free(current->next);
    current->next = next_next;
  }
  else /* This is tricky: only advance if no deletion */
  {
    current = current->next;
  }
}