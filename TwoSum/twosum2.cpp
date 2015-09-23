//利用map来实现

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        map<int, int> hmap;
        vector<int> res;
        int index1, index2;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(hmap.count(target - nums[i]))
            {
                index1 = i;
                index2 = hmap[target - nums[i]];
                break;
            }
            
            if(!hmap.count(nums[i]))
            {
                hmap.insert(pair<int, int>(nums[i], i));
            }
        }
        
        if(index1 > index2)
            swap(index1, index2);
        res.push_back(index1 + 1);
        res.push_back(index2 + 1);
        return res;
    }
};