//先复制数组，然后排序，找到元素
//然后在原始数组中找到其位置

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> temp(nums);
        sort(temp.begin(), temp.end());
        int len = nums.size();
        int low = 0, high = len - 1;
        while(low < high)
        {
            if(temp[low] + temp[high] == target)
                break;
            else if(temp[low] + temp[high] < target)
                ++low;
            else
                --high;
        }
        
        int index1, index2;
        for(int i = 0; i < len; ++i)
        {
            if(nums[i] == temp[low])
                index1 = i;
        }
        
        for(int i = 0; i < len; ++i)
        {
            if(i != index1 && nums[i] == temp[high])
                index2 = i;
        }
        
        if(index1 > index2)
            swap(index1, index2);
            
        vector<int> res;
        res.push_back(index1 + 1);
        res.push_back(index2 + 1);
        
        return res;
    }
};