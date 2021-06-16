动态规划
$$dp[i]=
\begin{cases}
dp[i-1] \\
prices[i]-min
\end{cases}
$$
第i天的最大收益是max(第i-1天的最大收益,第i天的价格减去前i-1天的最低价格)