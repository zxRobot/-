bool hasCycle(ListNode *head)
{
   
    if(head==nullptr || head->next==nullptr)
    {
        return false;
    }
    ListNode* fast=head->next;
    ListNode* slow=head;
    while(fast!=slow)
    {
        if(fast==nullptr||fast->next==nullptr)
        {
            return false;
        }
        fast=fast->next->next;
        slow=slow->next;
    }
    return true;
}