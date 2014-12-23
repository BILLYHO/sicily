#include <iostream>

using namespace std;

int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        int price[m], value[m];
        unsigned long long bag[n+1];

        for(int i=0; i<m; i++)
        {
            int v, p;
            cin >> v >> p;
            price[i] = v;
            value[i] = v*p;
        }

        for(int i=0; i<=n; i++)
            bag[i] = 0;

        for(int i=0; i<m; i++)
        {
            for(int j=n; j>=0; j--)
            {
                if(j >= price[i] && bag[j-price[i]] + value[i] > bag[j])
                    bag[j] = bag[j-price[i]] + value[i];
            }
        }
        cout << bag[n] << endl;
    }
    return 0;
}
