#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<cstdio>

using namespace std;

int main (void)
{
    int m,n;
    string s;
    set<string> a;
    while (scanf("%d%d",&m,&n), m!=0)
    {
         
        for(int i=0; i<m; i++)
        {
            cin >> s;
            for(int j=0; j<s.length(); j++)
                s[j] = tolower(s[j]);
            a.insert(s);
        }
        for(int i=0; i<n; i++)
        {
            cin >> s;
            for(int j=0; j<s.length(); j++)
                s[j] = tolower(s[j]);
            a.erase(s);
        }
        cout << a.size() << endl;
        a.clear();
    }
}
