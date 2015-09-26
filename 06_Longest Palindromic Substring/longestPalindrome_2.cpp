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
			
			string tempStr1 = ExpandTwoSides(s, i , i);
			if(tempStr1.length() > maxLen)
			{
				res = tempStr1;
				maxLen = tempStr1.length();
			}
			
			string tempStr2 = ExpandTwoSides(s, i, i + 1);
			if(tempStr2.length() > maxLen)
			{
				res = tempStr2;
				maxLen = tempStr2.length();
			}			
			
		}
		
		return res;
    }
	
private:
	string ExpandTwoSides(string &s, int left, int right)
	{
		while(left >= 0 && right < s.length() && s[left] == s[right])
		{
			--left;
			++right;
		}
		return s.substr(left + 1, right - left - 1);
	}
};