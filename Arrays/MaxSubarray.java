/* program to find maximum subarray with contiguous elements */
import java.util.*;

class MaxSubarray
{
	public static int maxSubarrayWithContiguousElements(int []arr)
	{
		int len=arr.length;
		int maxLen=1,max=0,min=0;
		
		for(int i=0;i<len;i++)
		{
			HashSet<Integer> set = new HashSet<Integer>();
			set.add(arr[i]);
			max=arr[i];
			min=arr[i];
			for(int j=i+1;j<len;j++)
			{
				if(set.contains(arr[j]))
					break;
				max=arr[j]>max?arr[j]:max;
				min=arr[j]<min?arr[j]:min;
				if(max-min == j-i && maxLen< j-i+1)
				{
					maxLen=j-i+1;
				}
					
			}
		}
		return maxLen;
	}
	public static void main(String args[])
	{
		int arr[]={10,12,11,12,58,57,59,56};
		System.out.println("Max subarray sum is: "+ maxSubarrayWithContiguousElements(arr));
	}
}

/* Output:
Max subarray sum is: 4
*/