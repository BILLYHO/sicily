#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

struct period
{
    int begin, end, total;
    double average;
};

bool cmp (period a, period b)
{
    if(a.average != b.average)
        return a.average > b.average;
    else
    { 
        if(a.total != b.total)
            return a.total > b.total;
        else
            return a.end < b.end;
    }
}

int main ()
{
    int t, n, num, spend, count, tt;
    cin >> t;

    for(int tt=0; tt<t; tt++)
    {
        cin >> n >> num >> spend;
        int a[400];
        for(int i=0; i<n; i++)
            cin >> a[i];
        period p[30000];
        count = 0;

        for(int i=spend; i<=n; i++)
        {
            for(int j=0; j<=n-i; j++)
            {
                int sum=0;
                for(int k=j; k<j+i; k++)
                    sum += a[k];
                p[count].average = (sum*1.0)/i;
                //printf("%.2f\n", p[count].average);
                p[count].begin = j+1;
                p[count].end = j+i;
                p[count].total = i;
                count++;
            }
        }
        //if(count > 1)
        //{
            sort(p, p+count, cmp);
            cout << "Result for run " << tt+1 << ":" << endl;
            for(int i=0; i<count && i<num; i++)
            cout << p[i].begin << "-" << p[i].end << endl;
        //}
        /*else
        {
            cout << "Result for run " << tt+1 << ":" << endl;
            cout << p[0].begin << "-" << p[0].end << endl;
        }*/
    }
    return 0;
}
