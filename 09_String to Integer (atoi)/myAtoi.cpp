class Solution {
public:
    int myAtoi(string str) 
    {
        int len = str.length();
        if(len == 0)
            return 0;
            
        //const int INT_MAX = 2147483647;
        //const int INT_MIN = -2147483648;
        
        int flag = 1;
        long temp = 0;
        int i = 0;
        while(str[i] == ' ' && i < len)
            ++i;

        if(i == len)
            return 0;
            
        if(str[i] == '-')
        {
            flag = -1;
            ++i;
        }
        else if(str[i] == '+')
            ++i;
        
        while(i < len && (str[i] >= '0' && str[i] <= '9'))
        {
            temp = temp * 10 + str[i] - '0';
            
            if(flag == 1 && temp > INT_MAX)
                return INT_MAX;
            if(flag == -1 && -temp < INT_MIN )
                return INT_MIN;
            ++i;
        }
        
        return flag * temp;
    }
};