#include<iostream>
#include<math.h>
using namespace std;
float falsi(float x)
{
    return pow(x,3)-x-1;
}
int main()
{
    float a,b,c,accuracy=0.0001;
    int i=1;
    cout<<"Enter two number: "<<endl;
    cin>>a>>b;

    if(a<b && falsi(a)*falsi(b)<0)
    {
        while(1)
        {
            c=(a*falsi(b)- b*falsi(a))/(falsi(b)-falsi(a));;
            cout<<"Iteration: "<<i<<"--> C = "<<c<<endl;
            if(fabs(falsi(c))<=accuracy)
            {
                cout<<"Root is: "<<c;
                break;
            }
            else
            {
                if(falsi(a)*falsi(c)<0)
                {
                    b=c;
                }
                else
                {
                    a=c;
                }
            }
            i++;
        }
    }
    else
    {
        cout<<"Unable to find the root";
    }
}

