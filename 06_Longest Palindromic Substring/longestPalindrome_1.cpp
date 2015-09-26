/*
	寻找字符串中的最长字符串
	使用暴力搜索法，从中间向两边展开：分成两种情况考虑：aba 、abba

*/

class Solution {
public:
    string longestPalindrome(string s) 
	{
		int len = s.length();
        if( len == 0)
			return s;
		
		string res;
		int maxLen = 0;
		
		// 对于aba形式
		for(int i = 0; i < len; ++i)
		{
			int j = i;
			int k = 1;
			while(j - k >=0 && j + k < len && s[j - k] == s[j + k])
				++k;
			
			int tempLen = 2 * k - 1;
			if(tempLen > maxLen)
			{
				res = s.substr(j - k + 1, tempLen);
				maxLen = tempLen;
			}
		}
		
		// 对于abba形式
		for(int i = 0; i < len; ++i)
		{
			int j = i;
			int k = 0;
			while(j - k >= 0 && j + k + 1 < len && s[j -k] == s[j + k + 1])
				++k;
			int tempLen = 2 * k;
			if(tempLen > maxLen)
			{
				res = s.substr(j - k + 1, tempLen);
				maxLen = tempLen;
			}
		}
		return res;
    }
};