#include <stdio.h>

void swap(int *a, int *b)
{
	int temp;
	temp=*b;
	*b=*a;
	*a=temp;
}

void sort012(int arr[],int size)
{
 int lo=0;
 int hi=size-1;
 int mid=0;

 while(mid<=hi)
 {
	 printf("%d %d %d\n",lo,mid,hi);
	    switch(arr[mid]){
				case 0:
				    swap(&arr[lo++],&arr[mid++]);
						break;
				case 1:
				    mid++;
						break;
				case 2:
				    swap(&arr[mid],&arr[hi--]);
						break;
			}
 }

}

void sortArr(int arr[],int n)
{
	 int i,cnt0=0,cnt1=0,cnt2=0;

	 for(i=0; i<n ;i++)
	 {
		 switch(arr[i]){
			 case 0:
			   cnt0++;
				 break;
			 case 1:
			 	 cnt1++;
			   break;
			 case 2:
			   cnt2++;
			   break;
		 }
	 }

	 i=0;
	 while(cnt0>0)
	 {
		 arr[i++]=0;
		 cnt0--;
	 }
	 while(cnt1>0)
	 {
		arr[i++]=1;
		cnt1--;
	 }
 	 while(cnt2>0)
	 {
		arr[i++]=2;
		cnt2--;
	 }

}
int main()
{
	 int arr[]={0, 1, 2, 0, 1, 2};

	 int N=sizeof(arr)/sizeof(arr[0]);
   int i,j=0;

	// sort012(arr,N);
	sortArr(arr,N);

   for(i=0;i<N;i++) printf("%d ",arr[i]);
	return 0;
}
