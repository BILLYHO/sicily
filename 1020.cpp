#include <iostream>

using namespace std;

int main ()
{
    int t,n,b[100];
    char a[400];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=0; i<n; i++)
            cin >> b[i];
        cin >> a;
        
        cout << "(";
        for(int i=0; i<n; i++)
        {    
            int j=0, res=0;
            while(j < strlen(a))
            {
                res = 10*res + (a[j]-'0');
                res = res % b[i];
                j++;
            }
            cout << res;
            if(i == n-1)
                cout << ")" << endl;
            else
                cout << ",";
        }
    }
    return 0;
}
