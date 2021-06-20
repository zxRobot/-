int maxProfit(vector<int>& prices)
{
    //dp[][0][0]  是否持有股票，卖出过几次
    vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,0)));
    dp[0][0][0]=0;
    dp[0][0][1]=0;
    dp[0][0][2]=-1;
    dp[0][1][0]=-prices[0];
    dp[0][1][1]=0;
    dp[0][1][2]=-1;
    dp[1][0][2]=-1;
    dp[1][1][2]=-1;
    for(int i=1;i<prices.size();i++)
    {
        dp[i][0][0]=0;
        dp[i][0][1]=max(dp[i-1][0][1],dp[i-1][1][0]+prices[i]);
        dp[i][0][2]=max(dp[i-1][0][2],dp[i-1][1][1]+prices[i]);
        dp[i][1][0]=max(dp[i-1][1][0],dp[i-1][0][0]-prices[i]);
        dp[i][1][1]=max(dp[i-1][1][1],dp[i-1][0][1]-prices[i]);
        dp[i][1][2]=-1;
    }
    return max(dp[prices.size()-1][0][0],max(dp[prices.size()-1][0][1],dp[prices.size()-1][0][2]));
}