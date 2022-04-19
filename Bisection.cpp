#include<iostream>
#include<math.h>
using namespace std;
float bisection(float x)
{
    return pow(x,3)-x-1;
}
int main()
{
    float a,b,c,accuracy=0.0001;
    int i=1;
    cout<<"Enter two number: "<<endl;
    cin>>a>>b;

    if(a<b && bisection(a)*bisection(b)<0)
    {
        while(1)
        {
            c = (a+b)/2;
            cout<<"Iteration: "<<i<<"--> C = "<<c<<endl;
            if(fabs(bisection(c))<=accuracy)
            {
                cout<<"Root is: "<<c;
                break;
            }
            else
            {
                if(bisection(a)*bisection(c)<0)
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
