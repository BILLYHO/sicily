#include<iostream>
#include<algorithm>


bool cmp (int a, int b)
{
    return a < b;
}

using namespace std;

int main (void)
{
    int t, n;
    int a[1100];
    cin >> t;
    for(int i=0; i<t; i++)
    {
        cin >> n;
        for(int j=0; j<n; j++)
            cin >> a[j];
        sort(a,a+n,cmp);
        for(int j=0; j<n; j++)
            cout << a[j] << endl;
    }
    return 0;
}
