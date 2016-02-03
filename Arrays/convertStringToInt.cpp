/* program to convert string to integer */
#include <iostream>
#include <string>
using namespace std;

string trim(string str)
{
	int pos=str.find_last_not_of(" \n\r\t");
	str=str.substr(0,pos+1);
	pos=str.find_first_not_of(" \n\r\t");
	str=str.substr(pos);
	return str;	
}

int convertStringToInteger(string str)
{
	str=trim(str);
	int num=0,len=str.length(),res=0,mul=1;
	//cout<<str;
	for(int i=len-1;i>=0;i--)
	{
	    num=str.at(i);
	    if(i==0&& num=='-')
	        return -res;
	    else if(num>='0' && num<='9')
	    {
	        res=res+(num-'0')*mul;
	        mul=mul*10;
	    }
	    else
	    {
	        cout<<"Invalid string";
	        exit(1);
	    }
	}
	
	return res;
}


int main()
{
	string str="  -987  ";
	int res=convertStringToInteger(str);
	cout<<"Equivalent num is: "<<res;
	return 0;
}
/*output:
Equivalent num is: -987
*/