#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//int partition(vector<int>& nums,int l,int r)
//{
//    int priot=nums[l];
//    int i=l;
//    for(int j=l;j<nums.size();j++)
//    {
//        if(nums[j]<priot)
//        {
//            i++;
//            swap(nums[i],nums[j]);
//        }
//    }
//    swap(nums[i],nums[l]);
//    return i;
//}

int partition(vector<int>& nums, int l, int r) {
    int pivot = nums[r];
    int i = l - 1;
    for (int j = l; j <= r - 1; ++j) {
        if (nums[j] <= pivot) {
            i = i + 1;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[r]);
    return i + 1;
}


int randomized_partion(vector<int>& nums,int l,int r)
{
    int i=rand()%(r-l+1)+l;
    swap(nums[i],nums[l]);
    return partition(nums,l, r);
}

void quickSort(vector<int>& nums,int l,int r)
{
    if(l<r)
    {
        int pos=partition(nums,l,r);
        quickSort(nums, l, pos-1);
        quickSort(nums, pos+1, r);
    }
   
}


vector<int> sortArray(vector<int>& nums) {
    quickSort(nums, 0, nums.size()-1);
    return nums;
}



int main(int argc, const char * argv[]) {
    vector<int> nums={3,5,1,2,4};
    //int res=partition(nums,0,4);
    sortArray(nums);
    return 0;
}
