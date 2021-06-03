#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* reverse(ListNode* head)
{
    ListNode* pre=nullptr;
    ListNode* cur=head;
    while(cur!=nullptr)
    {
        ListNode* next=cur->next;
        cur->next=pre;
        pre=cur;
        cur=next;
    }
    return pre;
}
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* dummy=new ListNode();
    dummy->next=head;
    ListNode* pre=dummy;
    ListNode* end=dummy;
    while(end!=nullptr)
    {
        for(int i=0;i<k&&end!=nullptr;i++)
        {
            end=end->next;
        }
        if(end==nullptr)
        {
            break;
        }
        ListNode* start=pre->next;
        ListNode* next=end->next;
        end->next=nullptr;
        ListNode* temp=reverse(start);
        pre->next=temp;
        start->next=next;
        pre=start;
        end=start;
    }
    return dummy->next;
}