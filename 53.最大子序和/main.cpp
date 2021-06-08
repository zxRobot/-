#include<vector>
using namespace std;

int maxSubArray(vector<int>& nums)
{
    vector<int> dp(nums.size(),0);
    dp[0]=nums[0];
    int max=nums[0];
    int start=0;
    int end=0;
    for(int i=1;i<nums.size();i++)
    {
        if(dp[i-1]<0)
        {
            dp[i]=nums[i];
            start=i;
        }
        else
        {
            dp[i]=dp[i-1]+nums[i];
        }
        if(max<=dp[i])
        {
            max=dp[i];
            end=i;
        }
    }
    return max;
}