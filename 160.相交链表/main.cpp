#include <set>
using namespace std;
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    set<ListNode*> lSet;
    ListNode* head=headA;
    while(head)
    {
        lSet.insert(head);
        head=head->next;
    }
    while(headB)
    {
        if(lSet.count(headB))
        {
            return headB;
        }
        headB=headB->next;
    }
    return nullptr;
}
int main()
{
    ListNode* l1=new ListNode(4);
    ListNode* l2=new ListNode(1);
    ListNode* l3=new ListNode(8);
    ListNode* l4=new ListNode(4);
    ListNode* l5=new ListNode(5);
    l1->next=l2;
    l2->next=l3;
    l3->next=l4;
    l4->next=l5;
    
    ListNode* l6=new ListNode(5);
    ListNode* l7=new ListNode(0);
    ListNode* l8=new ListNode(1);
    
    l6->next=l7;
    l7->next=l8;
    l8->next=l3;
    
    ListNode* ll=getIntersectionNode(l1,l6);
    return 0;
}