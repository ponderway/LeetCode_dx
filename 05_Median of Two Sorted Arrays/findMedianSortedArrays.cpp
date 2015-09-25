/*
	��ԭ����ת��ΪѰ�ҵ�kС���������⣬��λ���ǵ�(m+n)С������
	���ȼ�������A��B��Ԫ�ظ���������k/2���Ƚ�A[k/2-1]��B[k/2-1]����Ԫ�أ�
	���A[k/2-1]<B[k/2-1]�����ʾA[0]��A[k/2-1]��Ԫ�ض���A��B�ϲ�֮���ǰkС��Ԫ���С����Կ��Խ���������
	���A[k/2-1]>B[k/2-1]��ͬ��
	��A[k/2-1]=B[k/2-1]ʱ���ҵ��˵�kС������
	
	�߽�������
	���A����BΪ�գ���ֱ�ӷ���B[k-1]����A[k-1]��
	���kΪ1������ֻ��Ҫ����A[0]��B[0]�еĽ�Сֵ��
	���A[k/2-1]=B[k/2-1]����������һ����
	
	�ο��ˣ�http://blog.csdn.net/doc_sgl/article/details/13081925
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