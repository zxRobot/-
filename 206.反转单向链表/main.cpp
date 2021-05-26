#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



ListNode* reverseList1(ListNode* head)
{
    ListNode* pre=nullptr;
    ListNode* cur=head;
    while(cur!=nullptr)
    {
        ListNode* nex=cur->next;
        cur->next=pre;
        pre=cur;
        cur=nex;
    }
    return pre;
}
//递归
ListNode* reverseList2(ListNode* head)
{
    //终止条件
    if(head==nullptr||head->next==nullptr)
    {
        return head;
    }
    ListNode* node=reverseList2(head->next);
    head->next->next=head;
    head->next=nullptr;
    return node;
}


int main()
{
    ListNode* l1=new ListNode(1);
    ListNode* l2=new ListNode(2);
    ListNode* l3=new ListNode(3);
    ListNode* l4=new ListNode(4);
    ListNode* l5=new ListNode(5);
    l1->next=l2;
    l2->next=l3;
    l3->next=l4;
    l4->next=l5;
    ListNode* head1=l1;
    while(head1!=nullptr)
    {
        cout<<head1->val<<"-->";
        head1=head1->next;
    }
    ListNode* head2=reverseList2(l1);
    cout<<"\n";
    while(head2!=nullptr)
    {
        cout<<head2->val<<"-->";
        head2=head2->next;
    }
    return 0;
}

