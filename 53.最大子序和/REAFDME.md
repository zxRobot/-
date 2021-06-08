### 动态规划
#### 状态转移方程
$$f(n)=max(f(n-1)+nums[i],nums[i])$$
$$ f(n)=\begin{cases}
f(n-1)+nums[i],f(n-1)>=0\\
nums[i],f(n-1)<0
\end{cases}
$$

代码中设计了一个start,end来记录子串的起始和结束位置
同时此题还是股票买卖题目的母题