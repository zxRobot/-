$$\begin{cases}
l1[0]+mergeList(l1->next,l2)\\
l2[0]+mergeList(l1,l2->next)\\
\end{cases}
$$

递归边界：  
任意一个链表为空