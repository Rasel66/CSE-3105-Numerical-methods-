#include<iostream>
#include<math.h>
using namespace std;
float stf(float x)
{
    return pow(x,3)-x-1;
}
int main()
{
    float a,b,x0,c,accuracy=0.0001;
    int i=1;
    cout<<"Enter two number: "<<endl;
    cin>>a>>b;

    if(a<b && stf(a)*stf(b)<0)
    {
        x0=(a+b)/2;
        while(1)
        {
            c = x0 - (pow(stf(x0),2))/(stf(x0+stf(x0))-stf(x0));
            cout<<"Iteration: "<<i<<"--> C = "<<c<<endl;
            if(fabs(stf(c))<=accuracy)
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


