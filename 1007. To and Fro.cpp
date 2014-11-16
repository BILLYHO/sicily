#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>


using namespace std;

int main (void)
{
    int i;
    while(scanf("%d",&i))
    {
        if(i==0)
            break;
        
        char a[250];
        scanf("%s",a);
        int s=( (strlen(a)/i)%2 == 1)?strlen(a)-i:strlen(a);

        for(int j=0; j<i; j++)
        {
            for(int k=0; k< s/i; k++)
            {
                printf("%c",a[j+k*i]);
                k++;
                printf("%c",a[k*i+i-1-j]);
            }
            if(s<strlen(a))
                printf("%c",a[s+j]);

        }
    printf("\n");
        
     }
    return 0;
}
