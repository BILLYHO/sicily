#include <iostream>
#include <cstdio>

using namespace std;

int arr[1001];
int ans[1001][1001];

int dp(int left, int right)
{
    if(left == right)
        return -arr[left];
    if(ans[left][right] != 0)
        return ans[left][right];

    if((right - left + 1)%2 == 1)
    {
        if(arr[left] >= arr[right])
            ans[left][right] = dp(left+1, right) - arr[left];
        else
            ans[left][right] = dp(left, right-1) - arr[right];
    }
    else
    {
        ans[left][right] = max(dp(left, right-1)+arr[right], dp(left+1, right)+arr[left]);
    }
    return ans[left][right];
}

int main()
{
    int n, count=1;
    cin >> n;
    while(n != 0)
    {
        for(int i=0; i<n; i++)
            cin >> arr[i];
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                ans[i][j] = 0;

        printf("In game %d, the greedy strategy might lose by as many as %d points.\n", count++, dp(0, n-1));
        cin >> n;
    }
    return 0;
}
