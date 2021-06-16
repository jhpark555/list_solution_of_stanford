#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN(a,b) ( (a> b )?  b:a)
#define MAX(a,b) ((a>b)? a:b )
#define INPUT 7

void decimation2(float *arr,float **arr2,int size,int M)
{
    int i,j=0;
    float *ptr=*arr2;

    for (i = 0; i<size; i=i+M) {
    ptr[j++] = arr[i];

    }
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

float x[INPUT];
int i;
int lenY;
int M=2;
for(i=1;i<=INPUT;i++){
    x[i-1]=i;
  }

int sizeH= sizeof(h)/sizeof(h[0]);
int sizeX= sizeof(x)/sizeof(x[0]);

float *y= convolve(h,x,sizeH,sizeX, &lenY );
float *arr2=(float*)malloc(INPUT*sizeof(float));

//decimation(y,lenY);
decimation2(y,&arr2,lenY,M);

for(i=0;i<lenY/M;i++) printf("%f ",arr2[i]);

free(arr2);

return 0;
}
