/*
	使用string数组存放每一层的元素
	其实，正确的答案应该是去寻找每个位置的规律
*/
class Solution {
public:
    string convert(string s, int numRows) 
    {
        int len = s.length();
        if(numRows == 0 || numRows == 1)
            return s;
		vector<string> vec(numRows);
		
		int index = 0;
		int flag = 0;
		for(int i = 0; i < len; ++i)
		{
		    vec[index].push_back(s[i]);
			if(flag == 0)
			{
				++index;
				if(index == numRows)
				{
					index -= 2;
					flag = 1;
				}
			}
			else
			{
				--index;
				if(index == -1)
				{
					index += 2;
					flag = 0;
				}
			}
		}
		
		string res;
		for(int i = 0; i < numRows; ++i)
			res += vec[i];
		return res;
    }
};