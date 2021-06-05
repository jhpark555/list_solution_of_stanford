#include<stdio.h>

int Max(int a[],int index,int l)
{
  int m;

	if( index>=l-2 ) {
		if(a[index]>a[index+1])
		  return a[index];
		else
	  	return	a[index+1];
	}
	 m=Max(a,index+1,l);
	 if(a[index]>m) return a[index];
	 else return m;

}

int Min(int a[],int index,int l)
{
  int m;

	if( index>=l-2 ) {
		if(a[index]<a[index+1])
		  return a[index];
		else
	  	return	a[index+1];
	}
	 m=Min(a,index+1,l);
	 if(a[index]<m) return a[index];
	 else return m;

}

int Max_arr(int a[],int n)
{
  int m = a[0];
	int i;

	for(i=1;i<n;i++)
	if(a[i] <m) m=a[i];

	return m;

}
int main()
{
	int arr[]={70, 250, 50, 80, 140, 12, 14 };

//	int m=Max(arr,0,7);
	int m=Min(arr,0,7);

	printf("**%d \n",m);

	return 0;
}
