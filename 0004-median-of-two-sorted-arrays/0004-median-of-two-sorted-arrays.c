double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) 
{
	int m=nums1Size;
    int n=nums2Size;
    int total = m+n;
	int i=0,j=0,k=0;
	int res[m+n];
	while(i<m && j<n)
	{
		
		if(nums1[i]<=nums2[j])
		{
			res[k]=nums1[i];		
			i++;
			k++;
		}
		else
		{
			res[k]=nums2[j];
			j++;
			k++;
		}
	}
	
     while(i<m)
    {
	res[k]=nums1[i];
	i++;
	k++;
    }
	
	while(j<n)
    {
	res[k]=nums2[j];
	j++;
	k++;
    }

    if(total % 2 ==1)
    return res[total/2];
    else 
    {
        return (res[total/ 2 - 1] + res[total/ 2]) / 2.0; 
    }

}