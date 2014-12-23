#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
    int t,n,m;
    cin >> t;
    for(int a=1; a<=t; a++)
    {
        cin >> n >> m;
        unsigned long long dp[n+1][m+1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                dp[i][j] = 0;
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=pow(2,i-1); j<=m; j++)
            {
                if(i==1)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    for(int k=pow(2,i-2); k<=j/2; k++)
                    {
                        dp[i][j] += dp[i-1][k];
                    }
                }
            }
        }

        unsigned long long sum = 0;
        for(int i=pow(2,n-1); i<=m; i++)
            sum += dp[n][i];
        cout << "Case " << a << ": n = " << n << ", m = " << m << ", # lists = " << sum << endl;
    }
    return 0;
}
