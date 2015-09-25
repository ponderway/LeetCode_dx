//  ���ñ��λ����ͷ��ʼ���������ظ��ַ�ʱ��ͳ�Ƴ���
//  Ȼ�����һ��λ�ÿ�ʼ������
//  ʱ�临�Ӷ��е��

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