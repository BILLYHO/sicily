#include<iostream>

using namespace std;

int main (void)
{
    long int a,max;
    int i;
    while(1)
    {
        cin >> i;
        if (i==0)
            break;
        max = -2147483647;
        for(int j=0; j<i; j++)
        {
            cin >> a;
            if(a>max)
                max = a;
        }
        cout << max << endl;
    }

    return 0;
}
