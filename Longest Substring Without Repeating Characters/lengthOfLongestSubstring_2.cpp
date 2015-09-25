// ��1�����˸Ľ�
// �������ظ��ַ�ʱ���ӵ�һ���ظ��ַ�����һλ�ÿ�ʼ
// ���Դ���С������
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