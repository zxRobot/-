#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int findKthLargest1(vector<int>& nums, int k) {
    priority_queue<int,vector<int>,greater<int> > q;
    for(int i=0;i<k;i++)
    {
        q.push(nums[i]);
    }
    for(int i=k;i<nums.size();i++)
    {
        if(nums[i]>q.top())
        {
            q.pop();
            q.push(nums[i]);
        }
    }
    return q.top();
}

void swap(vector<int>& nums,int i,int j)
{
    int temp=nums[i];
    nums[i]=nums[j];
    nums[j]=temp;
}

//切分
int partition(vector<int>& nums,int left,int right)
{
    int pivot=nums[left];
    int j=left;
    for(int i=left+1;i<nums.size();i++)
    {
        if(nums[i]<pivot)
        {
            j++;
            swap(nums,i,j);
        }
    }
    swap(nums,left,j);
    return j;
}

int findKthLargest2(vector<int>& nums, int k)
{
    int len=nums.size();
    int target=len-k;
    int left=0;
    int right=len-1;
    while(true)
    {
        int index=partition(nums,left,right);
        if(target==index)
        {
            return nums[index];
        }
        else if(target>index)
        {
            left=index+1;
        }
        else
        {
            right=index-1;
        }
    }
}

int main(int argc, const char * argv[]) 
{
    vector<int> nums = {3,5,1,2,6,4};
    int res=findKthLargest2(nums, 2);
    std::cout << res;
    return 0;
}
