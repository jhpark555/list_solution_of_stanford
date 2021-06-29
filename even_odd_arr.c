#include <stdio.h>
#include <string.h>

void array_con(int arr[],int n)
{
    int i,k;
  for(i=0;i<n;i++)
  {
    if(i&1)    // odd,  ~i%1 : even
        arr[i]=arr[i+1];
      //  printf("%d ",arr[i]);
  }

  for(i=0;i<n-1;i++)        //  shift every even array
  {
    for(k=i+1;k<=n/2;k++)  arr[k]=arr[k+1];   // delete even array
    printf("%d ",arr[i]);
  }

}


int main()
{
//int arr[]={1,2,3,4,5,6,7,8,9};

int arr[]={0,1,2,3,4,5,6,7,8};

int i;
int Size= sizeof(arr)/sizeof(arr[0]);

    array_con(arr,Size);
    printf("\n");
for(i=0;i<Size/2+1;i++) printf("%d ",arr[i]);


    return 0;
}
