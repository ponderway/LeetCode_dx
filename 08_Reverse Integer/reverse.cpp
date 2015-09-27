

class Solution {
public:
	int reverse(int x)
	{

		const int maxInt = 0x7fffffff;
		const int minInt = 0x80000000;

		int long temp = 0;
		while (x)
		{
			temp = temp * 10 + x % 10;
			x = x / 10;
		}

		if (temp > maxInt || temp < minInt)
			return 0;

		return temp;
	}
};