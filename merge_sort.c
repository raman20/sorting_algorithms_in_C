// merge sort algorithm in C lang.

#include<stdio.h>

void merge(int A[],int p,int q,int r)
{
	int n1 = q-p+1;
	int n2 = r-q;
	int i,j,k;
	int l[n1],z[n2];
	for(i=0;i<n1;i++)
	{ l[i] = A[p+i]; }
	for(j=0;j<n2;j++)
	{ z[j] = A[q+j+1]; }

	i=0;j=0;k=p;

	while(i<n1 && j<n2 )
	{
		if(l[i]<=z[j])
			{A[k]=l[i];i++;}
		else
			{A[k]=z[j];j++;}
		k++;
	}
	while(i<n1)
	{
		A[k]=l[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		A[k]=z[j];
		j++;
		k++;
	}
}

void merge_sort(int A[],int p,int r)
{
	if(p < r)
	{
		int q = (p+r) / 2;
		merge_sort(A,p,q);
		merge_sort(A,q+1,r);
		merge(A,p,q,r);
	}
}

void main()
{
	int a[]={10,9,8,7,6,5,4,3,2,1};
	int arr_size = sizeof(a)/sizeof(a[0]);
	printf("given array.......\n");
	for(int i=0;i<arr_size;i++)
        {
                printf("%d ",a[i]);
        }
        printf("\n");
	merge_sort(a,0,arr_size-1);
	printf("sorting........\n");
	for(int i=0;i<arr_size;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
