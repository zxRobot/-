***购买股票必须售出之前的股票
dp[i][0]:第i天手中没有股票的最大利润
dp[i][1]:第i天手中有股票的最大利润
dp[0][0]=0
dp[0][1]=-nums[0]

dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i])
dp[i][1]=max(dp[i-1][0]-prices[i],dp[i-1][1])
