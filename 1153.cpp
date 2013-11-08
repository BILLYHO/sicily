#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int next[8][2] = {{-2,-1}, {-2,1}, {-1,-2}, {-1,2}, {1,-2}, {1,2}, {2,-1}, {2,1}};
int vis[8][8];
int route[64];

struct Node
{
    int x;
    int y;
    int outDegree;
}node[65];

bool cmp (Node a, Node b)
{
    return a.outDegree < b.outDegree;
}


bool isValid(int x, int y)
{
    return x>=0 && x<8 && y>=0 && y<8 && vis[x][y]==0;
}

int calDegree(int x, int y)
{
    int c=0;
    for(int i=0; i<8; i++)
    {
        if(isValid(x+next[i][0], y+next[i][1]))
            c++;
    }
    return c;
}


bool dfs(Node a, int count)
{
    vis[a.x][a.y] = 1;
    route[count] = a.x*8+a.y+1;
    if(count == 63)
        return true;
    
    vector<Node> v;
    for(int i=0; i<8; i++)
    {
        int newx = a.x+next[i][0];
        int newy = a.y+next[i][1];
        int n = newx*8+newy+1;
        if(isValid(newx, newy))
        {
            node[n].outDegree = calDegree(newx, newy);
            v.push_back(node[n]);
        }
    }
    sort(v.begin(), v.end(), cmp);
    
    for(int i=0; i<v.size(); i++)
    {
        if(dfs(v[i], count+1))
            return true;
    }

    vis[a.x][a.y] = 0;
    return false;
}

int main ()
{
    int n;
    while(cin>>n, n!=-1)
    {
        for(int i=0; i<64; i++)
            route[i] = 0;
        for(int i=0; i<8; i++)
            for(int j=0; j<8; j++)
                vis[i][j]=0;

        for(int i=1; i<=64; i++)
        {
            node[i].x = (i-1)/8;
            node[i].y = (i-1)%8;
        }

        if(dfs(node[n] ,0))
        {
            for(int i=0; i<63; i++)
                cout << route[i] << " ";
            cout << route[63] << endl;
        }
    }
}
