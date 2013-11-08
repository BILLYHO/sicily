#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main ()
{
    int t, m, a, b, i, j;
    int v[1001];
    memset(v,0,sizeof(int)*1001);
    scanf("%d%d",&t,&m);
    for(i=0; i<m; i++)
    {
        scanf("%d%d",&a,&b);
        for(j=t; j>=a; j--)
        {
            if(v[j-a] + b > v[j])
                v[j] = v[j-a] + b;
        }
    }
    printf("%d\n",v[t]);
    return 0;
}
