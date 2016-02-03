/* Program to find union and intersection of two sorted arrays */
/* Time Complexity = O(m+n) and space complexity = O(1)  */

#include<iostream>
#include<limits.h>

void print_solution(int uni[],int intr[],int uni_length,int intr_length)
{
	printf("\nUnion array:\n");
	for(int i=0;i<uni_length;i++)
		printf("%d\t",uni[i]);
	printf("\nIntersection array:\n");
	for(int i=0;i<intr_length;i++)
		printf("%d\t",intr[i]);
}

void findUnionAndIntr(int a[], int b[], int a_length, int b_length)
{
	int uni[10];
	int intr[10];
	int uni_index=0,intr_index=0;	
	int previous_num=INT_MIN; // previous_num is used to prevent repeatitions
	int i,j;
	for(i=0,j=0;i<a_length && j<b_length;)
	{
		
		if(previous_num==a[i])
			i++;
		else if(previous_num==b[j])
			j++;
		else 
		{
		
			if(a[i]==b[j])
			{
				intr[intr_index]=a[i];
				intr_index++;
				uni[uni_index]=a[i];
				uni_index++;
				previous_num=a[i];				
				i++;
				j++;				
			}
			else if(a[i]<b[j])
			{
				uni[uni_index]=a[i];
				uni_index++;
				previous_num=a[i];
				i++;				
			}
			else
			{
				uni[uni_index]=b[j];
				uni_index++;
				previous_num=b[j];
				j++;				
			}			
		}			
		//printf("\t scanned number:%d",previous_num);
	}
	for(;i<a_length && a[i]!=previous_num;i++)
	{
		uni[uni_index]=a[i];
		uni_index++;
		previous_num=a[i];	
	}
	for(;j<b_length && b[j]!=previous_num;j++)
	{
		uni[uni_index]=b[j];
		uni_index++;
		previous_num=b[j];		
	}
	
	print_solution(uni,intr,uni_index,intr_index);	
}


int main()
{
	int a[]={1,3,4,5,7};
	int b[]={2,3,5,6};
	int a_length=sizeof(a)/sizeof(a[0]);
	int b_length=sizeof(b)/sizeof(b[0]);
	findUnionAndIntr(a,b,a_length,b_length);
	int a2[]={1,3,5,6,7};
	int b2[]={1,3,4,5,7};
	int a2_length=sizeof(a2)/sizeof(a2[0]);
	int b2_length=sizeof(b2)/sizeof(b2[0]);
	findUnionAndIntr(a2,b2,a2_length,b2_length);
	int a3[]={1,3,5,7};
	int b3[]={1,3,5,7};
	int a3_length=sizeof(a3)/sizeof(a3[0]);
	int b3_length=sizeof(b3)/sizeof(b3[0]);
	findUnionAndIntr(a3,b3,a3_length,b3_length);
	int a4[]={1,3,5,7};
	int b4[]={1,4,7,10,11};
	int a4_length=sizeof(a4)/sizeof(a4[0]);
	int b4_length=sizeof(b4)/sizeof(b4[0]);
	findUnionAndIntr(a4,b4,a4_length,b4_length);
	return 0;
}
/*Output:
Union array:
1	2	3	4	5	6	7	
Intersection array:
3	5	
Union array:
1	3	4	5	6	7	
Intersection array:
1	3	5	7	
Union array:
1	3	5	7	
Intersection array:
1	3	5	7	
*/