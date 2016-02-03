/* program to implement hashmap 

Hash map requires
a) a datastructure to hold key value pairs
b) keys should be unique, values may not be unique
c) good hash function to distribute hash keys
d) collision resoultion technique
*/
public class HashEntry
{
	private	int key;
	private int value;
	
	HashEntry(int key, int value)
	{
		this.key=key;
		this.value=value;
	}
	public int getKey()
	{
		return key;		
	}
	public int getValue()
	{
		return value;
	}
	
}


public class MyHashtable {
	private static final int SIZE=100;
	HashEntry[] obj;
	
	MyHashtable()
	{
		obj=new HashEntry[SIZE];
		for(int i=0;i<SIZE;i++)
			obj[i]=null;
	}
	public void put(int key, int value)
	{
		int hash= key % SIZE;
		while(obj[hash]!=null && obj[hash].getKey()!=key)
			hash=(hash+1)%SIZE;
		obj[hash]=new HashEntry(key,value);		
	}
	public int get(int key)
	{
		int hash=key % SIZE;
		while(obj[hash]!=null && obj[hash].getKey()!=key)
			hash=(hash+1)%SIZE;
		if(obj[hash]==null)
			return -1;
		else
			return obj[hash].getValue();
	}
	public static void main(String args[])
	{
		MyHashtable obj=new MyHashtable();
		obj.put(1, 2);
		System.out.println(obj.get(1));
	}
}
