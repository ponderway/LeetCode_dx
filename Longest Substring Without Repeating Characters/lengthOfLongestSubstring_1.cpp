//  设置标记位，从头开始，当出现重复字符时，统计长度
//  然后从下一个位置开始，继续
//  时间复杂度有点大

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
	{
		int res = 0;
		
		for(int i = 0; i < s.length(); ++i)
		{
			int flags[256] = {0};
			flags[s[i]] = 1;
			int cnt = 1;
			int j = i + 1;
			while(j < s.length() && flags[s[j]] == 0)
			{	
				flags[s[j]] = 1;
				++cnt;
				++j;
			}
			if(cnt > res)
				res = cnt;
		}
		return res;
    }
};