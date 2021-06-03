/**
 * C program to declare, define and access union.
 */

 /**
  * C program to demonstrate typedef declaration and use.
  */

 #include <stdio.h>

 // Typedef to a structure
 typedef struct point {
     int x;
     int y;
 } Point;


 // Tyepdef to a function pointer accepting two void pointers
 // and returing integer
 typedef int (* Fptr)(const void *, const void *);

int test(const void *a,const void *b)
{
    return *(int*)a - *(int*)b;
}
 int main()
 {
     // Typedef to primitive types
     typedef int Integer;

     // Typedef to a character array
     typedef char CharArray[100];

     // Creating variables for all typedef's
     Fptr functionPointer;

     functionPointer = &test;

     // Use Point typedef
     Point point = { 10, 20 };

     // Use integer typedef
     Integer num = 100;

     // Using char array typedef
     CharArray name = "Codeforwin";


     // Print all values
     printf("Point x=%d, y=%d\n", point.x, point.y);
     printf("num = %d\n", num);
     printf("name = %s\n", name);

     int k= functionPointer(&point.x,&point.y);
     printf("Functioon pointer =%d \n",k);

     return 0;
 }
