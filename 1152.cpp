#include <iostream>

using namespace std;

int next[8][2] = {{-2,-1}, {-2,1}, {-1,-2}, {-1,2}, {1,-2}, {1,2}, {2,-1}, {2,1}};
int vis[5][6];
int route[30];

bool isValid(int x, int y)
{
    return x>=0 && x<5 && y>=0 && y<6 && vis[x][y]==0;
}

bool dfs(int x, int y, int count)
{
    vis[x][y] = 1;
    route[count] = x*6+y+1;
    if(count == 29)
        return true;
    for(int i=0; i<8; i++)
    {
        int newx = x+next[i][0];
        int newy = y+next[i][1];
        if(isValid(newx, newy) && dfs(newx, newy, count+1))
            return true;
    }
    vis[x][y] = 0;
    return false;
}

int main ()
{
    int n;
    while(cin>>n, n!=-1)
    {
        for(int i=0; i<30; i++)
            route[i] = 0;
        for(int i=0; i<5; i++)
            for(int j=0; j<6; j++)
                vis[i][j]=0;
        if(dfs(n/6, n%6-1 ,0))
        {
            for(int i=0; i<29; i++)
                cout << route[i] << " ";
            cout << route[29] << endl;
        }
    }
}
