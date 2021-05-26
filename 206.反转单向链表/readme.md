递归的问题多可以用递推公式来表示
譬如最简单的斐波那契数列
1.递推公式：
F(n)=F(n-1)+F(n-2)
2.终止条件：
if(n<=2) return 1;
3.递归代码：
int f(int)
{
    if(n<=2)
    {
        return 1;
    }
    return f(n-1)+f(n-2);
}
在本题中，反转单向链表
1.递推公式
假设F(n)表示反转第n个节点到最后一个节点，F(n-1)表示反转第n-1个节点到最后一个节点，得：
F(n)=F(n-1)+(第n-1个节点指向第n个节点)，代码为
head->next->next=head;
head->next=nullptr;
2.终止条件
当没有节点或者下一个节点为空节点时，代码为：
if(head==nullptr||head->next==nullptr)
{
    return head;
}
