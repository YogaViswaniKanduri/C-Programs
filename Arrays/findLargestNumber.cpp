/* Arrange given numbers to form the biggest number 
Given an array of numbers, arrange them in a way that yields the largest value.
For example, if the given numbers are {54, 546, 548, 60}, the arrangement 6054854654 gives the largest value
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int compare(string a,string b)
{
    string ab=a+b;
    string ba=b+a;
    return ab.compare(ba)>0?1:0;
}

void findLargestNumber(int arr[],int len)
{
    vector<string> numbers;
	for(int i=0;i<len;i++)
	{
		numbers.push_back(to_string(arr[i]));
	}
	sort(numbers.begin(),numbers.end(),compare);
	for(int i=0;i<numbers.size();i++)
	{
	    cout<<numbers[i];
	}
}

int main()
{
	int arr[]={54,546,548,60};
	int size=sizeof(arr)/sizeof(arr[0]);
	cout<<"Largest number is: ";
	findLargestNumber(arr,size);
	return 0;
}
/*Output:
Largest number is: 6054854654
*/