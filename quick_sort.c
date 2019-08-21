#include<stdio.h>

int partition(int a[],int m,int n)
{
	int pivot = a[n];
	int i = m;
	int temp;
	for(int j = m;j < n;j++)
	{
		if(a[j] < pivot)
		{
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
			i++;
		}
	}

	temp = a[n];
	a[n] = a[i];
	a[i] = temp;

	return i;
}

void quicksort(int a[],int m,int n)
{
	if(m<n)
	{
		int p = partition(a,m,n);
		quicksort(a,m,p-1);
		quicksort(a,p+1,n);
	}
}

void main()
{
	int a[] = {1,9,8,7,6,5,4,3,2,10};
	printf("given array: ");
	for(int i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}

	printf("\nafter sorting:");

	quicksort(a,0,9);
	for(int i=0;i<10;i++)
        {
		printf("%d ",a[i]);
	}
	printf("\n");
}

