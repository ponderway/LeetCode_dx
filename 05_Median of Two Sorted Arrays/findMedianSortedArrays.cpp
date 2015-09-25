/*
	将原问题转化为寻找第k小的数的问题，中位数是第(m+n)小的数。
	首先假设数组A和B的元素个数都大于k/2，比较A[k/2-1]和B[k/2-1]两个元素：
	如果A[k/2-1]<B[k/2-1]，这表示A[0]到A[k/2-1]的元素都在A和B合并之后的前k小的元素中。所以可以将其抛弃；
	如果A[k/2-1]>B[k/2-1]，同理；
	当A[k/2-1]=B[k/2-1]时，找到了第k小的数。
	
	边界条件：
	如果A或者B为空，则直接返回B[k-1]或者A[k-1]；
	如果k为1，我们只需要返回A[0]和B[0]中的较小值；
	如果A[k/2-1]=B[k/2-1]，返回其中一个。
	
	参考了：http://blog.csdn.net/doc_sgl/article/details/13081925
*/


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
	{
		int len = nums1.size() + nums2.size();
		if(len & 0x1)
			return findKth(nums1, 0, nums2, 0, len / 2 + 1);
		else
			return (findKth(nums1, 0, nums2, 0, len / 2 ) + findKth(nums1, 0, nums2, 0, len / 2 + 1)) /2;
		
	}
	
	double findKth(vector<int>& nums1, int start1, vector<int>& nums2, int start2, int k)
	{
		int len1 = nums1.size() - start1;
		int len2 = nums2.size() - start2;
		if(len1 > len2)
			return findKth(nums2, start2, nums1, start1, k);
		
		if(len1 == 0)
			return nums2[start2 + k - 1];
			
		if(k == 1)
			return min(nums1[start1], nums2[start2]);
			
		int k1 = min(len1, k / 2);
		int k2 = k - k1;
		
		if(nums1[start1 + k1 - 1] < nums2[start2 + k2 - 1])
			return findKth(nums1, start1 + k1, nums2, start2, k - k1);
		else if(nums1[start1 + k1 - 1] > nums2[start2 + k2 - 1])
			return findKth(nums1, start1, nums2, start2 + k2, k - k2);
		else
			return nums1[start1 + k1 -1];
	}
};