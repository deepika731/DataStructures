#include<stdio.h>
#include<stdlib.h>
void display(int A[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",A[i]);
	}
	printf("\n");
}
void Merge(int A[],int temp[],int left,int mid,int right)
{
	int i,left_end,size,temp_pos;
	left_end = mid-1;
	temp_pos = left;
	size = right-left+1;
	while((left<=left_end) && (mid<=right))
	{
		if(A[left]<=A[mid])
		{
			temp[temp_pos] = A[left];
			temp_pos = temp_pos+1;
			left = left+1;
		}
		else
		{
			temp[temp_pos] = A[mid];
			temp_pos = temp_pos + 1;
			mid = mid+1;
		}
		
	}
	while(left<=left_end)
	{
		temp[temp_pos] = A[left];
		left = left+1;
		temp_pos = temp_pos + 1;
	}
	while(mid<=right)
	{
		temp[temp_pos] = A[mid];
		mid = mid + 1;
		temp_pos = temp_pos + 1;
	}
	for(i=0;i<size;i++)
	{
		A[right] = temp[right];
		right = right-1;
	}
}
		
void MergeSort(int A[],int temp[],int left,int right)
{
	int mid;
	if(right>left)
	{
		mid = (left+right)/2;
		MergeSort(A,temp,left,mid);
		MergeSort(A,temp,mid+1,right);
		Merge(A,temp,left,mid+1,right);
	}
	
}

		

int main()
{
	int A[5] = {3,5,2,8,1},temp[5];
	MergeSort(A,temp,0,5);
	display(temp,5);
}
