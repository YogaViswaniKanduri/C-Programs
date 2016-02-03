import java.io.*;

public class AreAnagrams
{
	public static boolean checkAnagrams(String str1, String str2)
	{
		int len1=str1.length();
		int len2=str2.length();
		char c;
		int index;
		if(len1!=len2)
			return false;
		for(int i=0;i<len1;i++)
		{
			c=str1.charAt(i);
			index=str2.indexOf(c);
			if(index==-1)
				return false;
			str2=str2.replace(c,'*');			
		}
		for(int i=0;i<len2;i++)
		{
			if(str2.charAt(i)!='*')
				return false;
		}
		return true;
	}
	public static void main(String args[])
	{
		String str1=new String("abcd");
		String str2=new String("cbad");
		System.out.println(checkAnagrams(str1,str2));
	}
}