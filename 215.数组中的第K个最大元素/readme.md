## 第一种方法就是建立一个小根堆
```
priority_queue<int,vector<int>,greater<int>>
```
## 第二种方法就是快排里的快速选择，找到某个数字的位置，使得它前面的数字都比它小，后面的数字都比它大，如果某个数字的位置刚好是我们所要求的位置，这个数字便是答案
### 切分法
#### 切分法（partition）总能确定一个数字的位置，我们还可以根据这个数字的位置来进一步缩小搜索范围，达到减而治之的目的
#### 首先确定一个随机值，这里我们把数组的左边确定为随机数
```
int pratition(vector<int> nums,int left,int right)
{
    int len=nums.size();
    int pivot=nums[left];    
    int j=left;
    for(int i=left+1;i<len;i++)
    {
        if(nums[i]<pivot)
        {
            j++; 第j个被移动的数字
            swap(nums,j,i);
        }
    }
    swap(nums,left,j);
    return j;
}
```
