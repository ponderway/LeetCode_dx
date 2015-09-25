// 对1进行了改进
// 当出现重复字符时，从第一个重复字符的下一位置开始
// 可以大大减小运算量
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
	{
		if(s.length() == 0)
		   return 0;
	        
		int res = 1;
		int flags[256] = {0};
		int start = 0;
		for(int i = 0; i < s.length(); ++i)
		{
			if(flags[s[i]])
			{
				res = (res > i - start) ? res : i - start;
				while(start < s.length() && s[start] != s[i])
				{
				    flags[s[start]] = 0;
					++start;
				}
				++start;
			}
			else
				flags[s[i]] = 1;
			
		}
		res = res > s.length() - start ? res : s.length() - start;
		return res ;
    }
};
