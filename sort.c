
#include <stdio.h>
#define N 10


void bubble_sort(int arr[],int n)
{
  int i,j,temp,flag=0;

  for(i=0;i<n;i++)
  	{
      for(j=0;j<n-i-1;j++)
      	{
          if(arr[j]>arr[j+1])
          	{
              flag=1;
			  temp=arr[j];
			  arr[j]=arr[j+1];
			  arr[j+1]=temp;
          	}
      	}
	  if(flag==0) return; //array is alreay sorted


  	}


}

void insertion_sort(int arr[],int n)
{
   int i,j,temp;

   for(i=1;i<n;i++)
   	{
      temp=arr[i];
	  j=i-1;
	  while((temp <arr[j]) && (j>=0))
	  	{
             arr[j+1]=arr[j];
			 j--;
	  	}
	  arr[j+1]=temp;

   	}

}
int smallest(int arr[],int k,int n)
{
   int pos=k,small=arr[k],i;

   for(i=k+1;i<n;i++)
   	{
      if(arr[i]< small)
      	{
      	 small=arr[i];
		 pos=i;
      	}
   	}
   return pos;

}
void selection_sort(int arr[], int n)
{
   int k,pos,temp;

   for(k=0;k<n;k++)
   	{
     pos=smallest(arr,k,n);
	 temp = arr[k];
	 arr[k]=arr[pos];
	 arr[pos]=temp;
   	}

}


void merge(int arr[],int beg,int mid,int end)
{
    int i=beg,j=mid+1,index=beg,temp[N],k;

    while((i<=mid) &&(j<=end))
    	{
          if(arr[i]<arr[j] ) {
              temp[index++]=arr[i++];
          	}
		  else{
              temp[index++]=arr[j++];
		  	}
    	}
    if(i>mid)
    	{
         while(j<=end)
         	{
              temp[index++]=arr[j++];

         	}

    	}
	else
		{
         while(i<=mid)
         	{
         	  temp[index++]=arr[i++];
         	}

		}
    for(k=beg;k<index;k++)
		{
		arr[k]=temp[k];
    	}


}

void merge_sort(int arr[],int beg,int end)
{
     int mid;

	 if(beg<end)
	 	{
             mid=(beg+end)/2;

			 merge_sort(arr,beg,mid);
			 merge_sort(arr,mid+1,end);
			 merge(arr,beg,mid,end);

	 	}

}

int main()
{
  int i,temp,j,arr[N]={29,9,45,63,18,81,108,54,72,36};

 // for(i=0;i<N;i++)  arr[i]=rand();


#if 0
  for(i=0;i<N;i++)
  	{
     for(j=0;j<N-i-1;j++)
     	{
          if(arr[j]>arr[j+1])
          	{
          	temp=arr[j+1];
			arr[j+1]=arr[j];
			arr[j]=temp;
          	}
     	}

  	}
#endif
  for(i=0;i<N;i++) printf("%d ",arr[i]);
printf("\n");
//  bubble_sort(arr,N);
//  for(i=0;i<N;i++) printf("%d ",arr[i]);

//  insertion_sort(arr,N);
//  for(i=0;i<N;i++) printf("%d ",arr[i]);

  //  selection_sort(arr,N);
 // for(i=0;i<N;i++) printf("%d ",arr[i]);

     merge_sort(arr,0,N-1);
  for(i=0;i<N;i++) printf("%d ",arr[i]);

  return 0;

}
