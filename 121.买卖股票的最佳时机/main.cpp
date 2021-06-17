int maxProfit(vector<int>& prices)
{
    vector<int> dp(prices.size(),0);
    int min=prices[0];
    //dp[0]=0;
    for(int i=1;i<prices.size();i++)
    {
        
        dp[i]=max(dp[i-1],prices[i]-min);
        min=prices[i]<min?prices[i]:min;
    }
    return dp[prices.size()-1];
}