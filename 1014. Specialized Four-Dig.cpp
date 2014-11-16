#include<iostream>

using namespace std;

int main (void)
{
    int dec ,duo, hex,t;
    for (int i=2990; i<10000; i++)
    {
        t = i;
        dec = 0;
        while(t)
        {
            dec += t%10;
            t /= 10;
        }
        
        t = i;
        duo = 0;
        while(t)
        {
            duo += t%12;
            t /= 12;
        }

        t = i;
        hex = 0;
        while(t)
        {
            hex += t%16;
            t /= 16;
        }

        if(dec==duo && dec==hex)
            cout << i << endl;
    }
    return 0;
}
