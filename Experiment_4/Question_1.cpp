#include<iostream>
using namespace std;

template<typename T>
T max(T a,T b,T c)
{
    T Max;
    if (a>=b)
    {
        if (b>=c)
        {
            Max = a;
        }
        else
        {
            if (a>=c)
            {
                Max = a;
            }
            else
            {
                Max = c;
            }
        }
        
    }
    else
    {
        if (b>=c)
        {
            Max = b;
        }
        else
        {
            Max = c;
        }
    }
    return Max;
}

int main()
{
    cout << max(114, 514, 1919) << endl;
    cout << max(114.514, 1919.810, 233.23333) << endl;
}