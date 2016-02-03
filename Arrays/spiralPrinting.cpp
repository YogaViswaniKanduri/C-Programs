/* program to print a matrix spirally */
#include <iostream>
#define N 5
using namespace std;

void printMatrixSpirally(int matrix[][N],int top,int bottom,int left,int right)
{
	if(top>bottom || left>right) return;
	for(int i=left;i<=right;i++)
		cout<<matrix[top][i]<<" ";
	
	top++;
	if(top>bottom || left>right) return;
	for(int i=top;i<=bottom;i++)
		cout<<matrix[i][right]<<" ";
	right--;
	
	if(top>bottom || left>right) return;
	for(int i=right;i>=left;i--)
		cout<<matrix[bottom][i]<<" ";
	bottom--;
	
	if(top>bottom || left>right) return;
	for(int i=bottom;i>=top;i--)
		cout<<matrix[i][left]<<" ";
	
	left++;
	printMatrixSpirally(matrix,top,bottom,left,right);

}
int main()
{
	int matrix[][N]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
	printMatrixSpirally(matrix,0,N-1,0,N-1);
	return 0;	
}
/*output:
1 2 3 4 5 10 15 20 25 24 23 22 21 16 11 6 7 8 9 14 19 18 17 12 13
*/
