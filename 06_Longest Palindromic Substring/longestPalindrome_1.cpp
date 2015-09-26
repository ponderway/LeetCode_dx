/*
	Ѱ���ַ����е���ַ���
	ʹ�ñ��������������м�������չ�����ֳ�����������ǣ�aba ��abba

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
		
		// ����aba��ʽ
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
		
		// ����abba��ʽ
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