#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2)
{
    ListNode* head=new ListNode();
    ListNode* pre=head;
    while(l1&&l2)
    {
        if(l1->val>l2->val)
        {
            head->next=l2;
            l2=l2->next;
        }
        else
        {
            head->next=l1;
            l1=l1->next;
        }
        head=head->next;
    }
    head->next=l1==nullptr?l2:l1;
    return pre->next;
}
ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2)
{
    if(l1==nullptr)
        return l2;
    else if(l2==nullptr)
        return l1;
    else if(l1->val>l2->val)
    {
        l2->next=mergeTwoLists2(l1, l2->next);
        return l2;
    }
    else
    {
        l1->next=mergeTwoLists2(l1->next, l2);
        return l1;
    }
}

int main()
{
    ListNode* l1=new ListNode(1);
    ListNode* l2=new ListNode(2);
    ListNode* l3=new ListNode(4);
    
    l1->next=l2;
    l2->next=l3;
    
    
    ListNode* l6=new ListNode(1);
    ListNode* l7=new ListNode(3);
    ListNode* l8=new ListNode(4);
    
    l6->next=l7;
    l7->next=l8;
    
    ListNode* res=mergeTwoLists2(l1, l6);

    return 0;

}