#include <iostream>
#include <queue>
#include <string>
#include <set>

using namespace std;

int origin = 12348765;

//记录魔板状态的结构体
struct node
{
    int code;
    string path;
};

//A操作
int A(int n)
{
    int a,b;
    a = n/10000;
    b = n%10000;
    return b*10000+a;
}

//B操作
int B(int n)
{
    int a,b;
    int x,y,z,w;
    a = n/10000;
    b = n%10000;
    x = a/10;
    y = a%10;
    z = b/10;
    w = b%10;
    return (y*1000+x)*10000+w*1000+z;
}

//C操作
int C(int n)
{
    int a[8];
    for(int i=0; i<8; i++)
    {
        a[i] = n%10;
        n /= 10;
    }
    return a[7]*10000000+a[2]*1000000+a[6]*100000+a[4]*10000+a[3]*1000+a[1]*100+a[5]*10+a[0];
}

//BFS遍历
void bfs(int n, int end)
{
    node begin,cur,next;
    begin.code = origin;
    begin.path = "";
    queue<node> q;
    set<int> vis;
    q.push(begin);
    vis.insert(origin);
    while(!q.empty())
    {
        cur = q.front();
        q.pop();
        if(cur.path.size()>n)
        {
            cout << "-1" << endl;
            return;
        }
        if(cur.code == end)
        {
            cout << cur.path.size() << " " << cur.path << endl;
            return;
        }

		//当前状态执行A操作后的新状态
        next.code = A(cur.code);
        //判断是否遍历过
        if(vis.find(next.code) == vis.end())
        {
            next.path = cur.path + "A";	//记录操作
            q.push(next);				//加入队列
            vis.insert(next.code);		//标记为已遍历
        }

		//当前状态执行B操作后的新状态
        next.code = B(cur.code);
        if(vis.find(next.code) == vis.end())
        {
            next.path = cur.path + "B";
            q.push(next);
            vis.insert(next.code);
        }
        
        //当前状态执行C操作后的新状态
        next.code = C(cur.code);
        if(vis.find(next.code) == vis.end())
        {
            next.path = cur.path + "C";
            q.push(next);
            vis.insert(next.code);
        }

    }
}

int main ()
{
    int n,end,tmp;
    while(cin>>n, n!=-1)
    {
        end = 0;
        for(int i=0; i<8; i++)
        {
            cin >> tmp;
            end = end*10 + tmp;
        }
        bfs(n,end);
    }
    return 0;
}
