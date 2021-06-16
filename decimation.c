#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN(a,b) ( (a> b )?  b:a)
#define MAX(a,b) ((a>b)? a:b )

void decimation(float arr[],int n)
{
  int i,k;
  for(i=0;i<n;i++)
  {
    if(i%2 ==1)
        arr[i]=arr[i+1];
  }

  for(i=0;i<n-1;i++)
  {
    for(k=i+1;k<n;k++)  arr[k]=arr[k+1];
  }

}

float *decimation2(float arr[],int size,int M)
{
    float *arr2=(float*)calloc(1,sizeof(float));
    int i,j=0;

    for (i = 0; i<size; i=i+M) {
      arr2[j++] = arr[i];
    }

  return arr2;
}

float* convolve(float h[], float x[], int lenH, int lenX, int* lenY)
{

      int nconv = lenH+lenX-1;
  (*lenY) = nconv;
  int i,j,h_start,x_start,x_end;

  float *y = (float*) calloc(nconv, sizeof(float));

  for (i=0; i<nconv; i++)
  {
    x_start = MAX(0,i-lenH+1);
    x_end   = MIN(i+1,lenX);
    h_start = MIN(i,lenH-1);
    for(j=x_start; j<x_end; j++)
    {
      y[i] += h[h_start--]*x[j];
    }
  }
  return y;

}

int main()
{
float h[]= {-0.01452123, -0.0155227 ,  0.01667252,  0.01800633, -0.01957209,
       -0.0214361 ,  0.02369253,  0.02647989, -0.03001054, -0.03462755,
        0.04092347,  0.05001757, -0.06430831, -0.09003163,  0.15005272,
        0.45015816,  0.45015816,  0.15005272, -0.09003163, -0.06430831,
        0.05001757,  0.04092347, -0.03462755, -0.03001054,  0.02647989,
        0.02369253, -0.0214361 , -0.01957209,  0.01800633,  0.01667252,
       -0.0155227 , -0.01452123};

float x[]={1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0};
int i;
int lenY;
int M=2;
for(i=0;i<32;i++) x[i]=i;

int sizeH= sizeof(h)/sizeof(h[0]);
int sizeX= sizeof(x)/sizeof(x[0]);


int Size= sizeof(x)/sizeof(x[0]);
   float *y= convolve(h,x,sizeH,sizeX, &lenY );

//decimation(y,lenY);
float *arr2 = decimation2(y,lenY,M);

for(i=0;i<lenY/M;i++) printf("%f ",arr2[i]);

return 0;
}
