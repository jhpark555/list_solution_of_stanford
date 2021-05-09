#include <stdio.h>

#define size 10
int smallest(int arr[],int k,int n);
void selection_sort(int arr[],int n);

int smallest(int arr[],int k,int n)
{
   int pos=k,small=arr[k],i;
   
   for(i=k+1;i<n;i++)
   	{
      if(arr[i] <small ) 
      	{
      	small=arr[i];
		pos=i;
      	}
   	}
   
   return (pos);
}

void selection_sort(int arr[],int n)
{
   int k,pos,temp;

   for(k=0;k<n;k++)
   	{
      pos=smallest(arr,k,n);
	  temp=arr[k];
	  arr[k]=arr[pos];
	  arr[pos]=temp;
   	}
 
}

int interpolation_search(int arr[],int low,int high,int val)
{
   int mid;
   
  while(low<=high )
  	{
       mid=low+(high-low)*((val-arr[low])/(arr[high]-arr[low]));

	   if(val==arr[mid]) return (mid+1);

	   if(val<arr[mid]) high=mid-1;
	   else   low=mid+1;

  	}
    return -1;
}
int main(int argc, char *argv[])
{
   int i;
   int n=15;
   int num;   // search number
   int beg=0,end=n-1,mid,found =0;
   int arr[]={4,2,3,6,5,1,7,9,8,10,13,15,26,54,34};
   

   selection_sort(arr,n);

   for(i=0;i<n;i++) printf("%d ",arr[i]);

   num=10;
    
   while(beg<=end){
   	
    mid= (beg+end)/2;

	if(arr[mid] ==num)
		{
          printf("search num %d is at %d\n",num,mid+1);
		  found =1;
          break;
		}
    else if( arr[mid]>num )
    	{
          end =mid-1;
    	}
	else {
          beg=mid+1;
		}
   	}
    if(beg >end && found ==0) printf("%d is not exist \n",num);

    /* interpolation search  */

	int pos= interpolation_search(arr,beg,end,num);

	printf("Position is %d \n",pos);
	return 0;

}


