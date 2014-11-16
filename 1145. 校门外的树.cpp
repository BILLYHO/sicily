#include<iostream>

using namespace std;

int main  (void)
{
    int flag[100001];
    for(int i=0; i<10001; i++)
        flag[i] = 1;
    int l,m,a,b,count;
    cin >> l >> m;
    for (int i=0; i<m; i++)
    {
        cin >> a >> b;
        for(int j=a; j<=b; j++)
            flag[j] = 0;
    }
    count = 0;
    for (int i=0; i<=l; i++)
    {
        if(flag[i] == 1)
            count++;
    }
    cout << count << endl;

}
