 #include<vector>
 #include<unordered_map>
 using namespace std;
 
 vector<int> twoSum(vector<int>& nums, int target)
{
    unordered_map<int,int> m;
    for(int i=0;i<nums.size();i++)
    {
        auto it=m.find(target-nums[i]);
        if(it!=m.end())
        {
            return vector<int>{i,it->second};
        }
        else
        {
            m[nums[i]]=i;
        }
    }
    return vector<int>{};
}

int main()
{
    vector<int> nums={3,5,8,6};
    vector<int> ans=twoSum(nums,11);
    return 0;
}