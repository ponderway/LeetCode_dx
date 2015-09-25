// 对1进行了改进
// 当出现重复字符时，从第一个重复字符的下一位置开始
// 可以大大减小运算量
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
	{
		int res = 1;
		int flags[256] = {0};
		int start = 0;
		for(int i = 0; i < s.length(); ++i)
		{
			if(flags[s[i]])
			{
				res = (res > i - start + 1) ? res : i - start + 1;
				while(start < s.length() && s[start] != s[i])
					++start;
				++start;
			}
			else
				flags[s[i]] = 1;
			
		}
		return res;
    }
};