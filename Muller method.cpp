#include <stdio.h>
#include<iostream>
#include <math.h>
#include<stdlib.h>
using namespace std;
const int MAX = 10000;
float f(float x)
{
   return pow(x,3)-x-1;
}
int muller(float a, float b, float c)
{
   int i;
   float result;
   for (i = 0;;++i)
    {
      float f1 = f(a);
      float f2 = f(b);
      float f3 = f(c);
      float d1 = f1 - f3;
      float d2 = f2 - f3;
      float h1 = a - c;
      float h2 = b - c;
      float a0 = f3;
      float a1 = (((d2*pow(h1, 2)) - (d1*pow(h2, 2))) / ((h1*h2) * (h1-h2)));
      float a2 = (((d1*h2) - (d2*h1))/((h1*h2) * (h1-h2)));
      float x = ((-2*a0) / (a1 + abs(sqrt(a1*a1-4*a0*a2))));
      float y = ((-2*a0) / (a1-abs(sqrt(a1*a1-4*a0*a2))));

      if (x >= y)
         result = x + c;
      else
         result = y + c;

         float m = result*100;
         float n = c*100;
         m = floor(m);
         n = floor(n);
         if (m == n)
         break;
         a = b;
         b = c;
         c = result;
         if (i > MAX) {
            printf("Unable to find the root\n");
            break;
         }
   }
   if (i <= MAX)
   printf("The root is %f", result);
   return 0;
}
int main() {
   float a , b, c;
   cout<<"Enter three numbers: ";
   cin>>a>>b>>c;
   muller(a, b, c);
   return 0;
}
