/* Program to find position of set bit in a number, given only one set bit

	program to find rightmost set bit of a number
 */

#include <iostream>
#include <cmath>
using namespace std;

/*if only one set bit the int pos=(log(num)/log(2))+1 is enough if the number has more than one set bit then we have to take the rightmost set bit*/
int main()
{
	int num=52;
	int set_bit_no=(log((num)&~(num-1))/log(2))+1;
	cout<<set_bit_no;
	return 0;
}
/* output:
3
*/

