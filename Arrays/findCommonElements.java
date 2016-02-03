/* Program to find common elements in two unsorted arrays*/
import java.util.*;

class FindCommonElements
{
	public static void findCommonInTwoArrays(int []arr1,int []arr2)
	{
	    int len1=arr1.length;
		int len2=arr2.length;
		int count=0;
		Hashtable<Integer,Integer> obj=new Hashtable<Integer,Integer>();
		for(int i=0;i<len1;i++)
		{
			if(obj.containsKey(arr1[i]))
			{
				count=obj.get(arr1[i]);
				obj.put(arr1[i],++count);
			}
			else
			{
				obj.put(arr1[i],1);
			}
		}
		/*Enumeration e=obj.keys();
		while(e.hasMoreElements())
		{
		    int key = (int) e.nextElement();
            System.out.println(key + " : " + obj.get(key));
		}*/
		for(int i=0;i<len2;i++)
		{
			if(obj.containsKey(arr2[i]))
			{
				count=obj.get(arr2[i]);
				System.out.println(arr2[i]);
				obj.put(arr2[i],--count);
			}			
		}
	}
	public static void findCommonInThreeArrays(int []arr1,int []arr2,int []arr3)
	{
		int len1=arr1.length;
		int len2=arr2.length;
		int len3=arr3.length;
		int count;
		Hashtable obj=new Hashtable();
		for(int i=0;i<len1;i++)
		{
			if(!obj.containsKey(arr1[i]))
				obj.put(arr1[i],1);
		}
		for(int i=0;i<len2;i++)
		{
			if(obj.containsKey(arr2[i]))
			{
				count=(int)obj.get(arr2[i]);
				obj.put(arr2[i],++count);
			}
		}
		for(int i=0;i<len3;i++)
		{
			if(obj.containsKey(arr3[i])&& obj.get(arr3[i])==2)
				System.out.println(arr3[i]);
		}
	}
	public static void main(String args[])
	{
		int arr1[]={1, 5, 10, 20, 40, 80};
		int arr2[]={6, 7, 20, 80, 100};
		int arr3[]={3, 4, 15, 20, 30, 70, 80, 120};
		System.out.println("Elements common in two arrays:");
		findCommonInTwoArrays(arr1,arr2);
		System.out.println("Elements common in three arrays:");
		findCommonInThreeArrays(arr1,arr2,arr3);
	}
}
/*
Output:
Elements common in two arrays:
20
80
Elements common in three arrays:
20
80
*/