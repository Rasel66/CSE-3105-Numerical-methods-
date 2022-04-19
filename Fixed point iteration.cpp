#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdlib.h>
using namespace std;
#define f(x) cos(x)-3*x+1

#define g(x) (1+cos(x))/3
int main()
{
    int n,i=1;
    float x0,x1,accuracy=0.00001;

    cout<<"Enter initial number: ";
    cin>>x0;
    cout<<"Enter maximum Iteration: ";
    cin>>n;

    do
    {
        x1 = g(x0);
        cout<<"Iteration-"<<i<<":\t x1 = "<<x1<<" and f(x1) = "<<f(x1)<<endl;
        i++;

        if(i>n)
        {
            cout<<"Unable to find any root";
            exit(0);
        }
        x0=x1;
    }while(fabs(f(x1))>accuracy);

    cout<<"Root is: "<<x1<<endl;

    return 0;
}
