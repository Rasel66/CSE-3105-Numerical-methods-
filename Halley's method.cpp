#include<iostream>
#include<cmath>
#include<math.h>
using namespace std;
float hm2(float x)
{
    return 3*x*x-1;
}
float hm1(float x)
{
    return pow(x,3)-x-1;
}
int main()
{
    float a,b,c,x0,accuracy=0.0001;
    int i=1;
    cout<<"Enter two number: "<<endl;
    cin>>a>>b;

    if(a<b && hm1(a)*hm1(b)<0)
    {
        x0 = (a + b)/2;
        while(1)
        {
            c = x0-(2*hm1(x0)*hm2(x0))/((2*pow(hm2(x0),2))-(hm1(x0)*hm2(x0)));
            cout<<"Iteration: "<<i<<"--> C = "<<c<<endl;
            if(fabs(hm1(c))<=accuracy)
            {
                cout<<"Root is: "<<c;
                break;
            }
            else
            {
                x0=c;
            }
            i++;
        }
    }
    else
    {
        cout<<"Unable to find the root";
    }
}


