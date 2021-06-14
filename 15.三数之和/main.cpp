#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> > threeSum(vector<int>& nums)
{
    vector<vector<int> > ans;
    if(nums.size()<3)
    {
        return ans;
    }
    sort(nums.begin(),nums.end());
    
    for(int i=0;i<nums.size()-1;i++)
    {
        if(i>0 && nums[i]==nums[i-1])
        {
            continue;
        }
        int target=0-nums[i];
        int left=i+1;
        int right=(int)nums.size()-1;
        while(left<right)
        {
            if(nums[left]+nums[right]<target)
            {
                left+=1;
            }
            else if(nums[left]+nums[right]>target)
            {
                right-=1;
            }
            else
            {
                ans.push_back(std::vector<int>{nums[i],nums[left],nums[right]});
                while(left<right&&nums[left]==nums[left+1])
                {
                    left++;
                }
                while(left<right&&nums[right]==nums[right-1])
                {
                    right--;
                }
                left++;
                right--;
            }
            
        }
    }
    return ans;
}
int main()
{
    vector<int> nums={0,0,0,0};
    vector<vector<int>>=threeSum(nums);
    return 0;
}