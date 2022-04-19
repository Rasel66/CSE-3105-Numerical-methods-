#include<iostream>
#include<math.h>
using namespace std;
float secant(float x)
{
    return pow(x,3)-x-1;
}
int main()
{
    float x0,x1,c,accuracy=0.0001;
    int i=1;
    cout<<"Enter two number: "<<endl;
    cin>>x0>>x1;

    if(x0<x1 && secant(x0)*secant(x1)<0)
    {
        while(1)
        {
            c = x1 - ((x1-x0)/(secant(x1)-secant(x0)))*secant(x1);
            cout<<"Iteration: "<<i<<"--> C = "<<c<<endl;
            if(fabs(secant(c))<=accuracy)
            {
                cout<<"Root is: "<<c;
                break;
            }
            else
            {
                x0=x1;
                x1=c;
            }
            i++;
        }
    }
    else
    {
        cout<<"Unable to find the root";
    }
}

