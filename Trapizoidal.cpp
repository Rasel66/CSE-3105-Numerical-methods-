#include<iostream>
#include<math.h>

#define f(x) 1/(1+pow(x,2))
using namespace std;
int main()
{
    float upper, lower,integration=0.00,stepSize,k;
    int i, subInterval;

    cout<<"Enter lower limit: ";
    cin>>lower;
    cout<<"Enter upper limit: ";
    cin>>upper;
    cout<<"Enter sub interval: ";
    cin>>subInterval;

    stepSize = (upper-lower)/subInterval;

    integration = f(lower)+f(upper);

    for(i=1;i<=subInterval-1;i++)
    {
        k = lower + i*stepSize;
        integration = integration + 2*(f(k));
    }
    integration = integration *stepSize/2;

    cout<<"Integration is: "<<integration<<endl;

    //Input value 0,6,6
}
